//
//  HashChain.cpp
//  Actividad_5.1
//
//  Created by Arturo Sosa on 27/11/20.
//

#include "HashChain.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

template <class K, class V>
class HashChain {
    int _capacity = 0;
    
    std::vector<std::vector<std::pair<K, V>>> colisions;
    std::vector<K> _keys;
    std::vector<V>  _values;
    std::vector<std::string> _status;
    
    int _size = 0;
    int hash_function(K) const;
    
public:
    HashChain(int);
    ~HashChain();
    
    bool empty() const;
    int size() const;
    
    bool put(K,V);
    bool rehash(std::vector<std::pair<K, V>>, K & , V &);
    V get(K);
};

template <class K, class V>
HashChain<K,V>::HashChain(int capacity)
{
    this->_capacity = capacity;
    this->_status = std::vector<std::string>(capacity);
    this->_keys = std::vector<K>(capacity);
    this->_values = std::vector<V>(capacity);
    std::vector<std::vector<std::pair<K, V>>> colisions(capacity);
    fill(_status.begin(), _status.end(), "vacio");
}

template <class K, class V>
HashChain<K,V>::~HashChain()
{
    /*
    delete this->_status;
    delete this->_values;
    delete this->_keys;
     */
}

template <class K, class V>
bool HashChain<K,V>::empty() const
{
    return this->_size == 0;
}

template <class K, class V>
int HashChain<K,V>::size() const
{
    return this->_size;
}

template <class K, class V>
int HashChain<K,V>::hash_function(K key) const
{
    return key % this->_capacity;
}

template <class K, class V>
bool HashChain<K,V>::put(K key,V value)
{
    int indice = hash_function(key);

    if (this->_status[indice] == "vacío") {
        this->_keys[indice] = key;
        this->_values[indice] = value;
        this->_status[indice] = "ocupado";
    }
    
    if (rehash(colisions.at(indice), key, value)){
        return true;
    }
    
    return false;
}

template <class K, class V>
bool HashChain<K,V>::rehash(
                          std::vector<std::pair<K, V>> lista,
                          K & key,
                          V & value)
{
    
    for(auto l : lista){
        if(l.first == key){
            std::cout<< "Value "<< value <<"Was not added "<<std::endl<<"Can not duplicate key "<<key<<std::endl;
            return false;;
        }
    }
    std::pair<K, V> node(key, value);
    lista.push_back(node);
    return true;
}

template <class K, class V>
V HashChain<K,V>::get(K key)
{
    bool found = false;
    int steps = 0;
    
    int indice = hash_function(key);
    
    while (!found && steps < this->_capacity) {
        if (this->_status[indice] == "ocupado") {
            if (this->_keys[indice] == key) {
                found = true;
            }
            else {
                found = false;
                ++indice;
                if (indice == this->_capacity) indice = 0;
            }
        }
        else {
            ++indice;
            if (indice == this->_capacity) indice = 0;
        }
        
        ++steps;
    }
   
    if (found) return this->_values[indice];
    else
        return -1;
}



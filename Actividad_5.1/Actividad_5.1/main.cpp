//
//  main.cpp
//  HashMap
//
//  Created by Vicente Cubells on 20/11/20.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "HashMap/HashMap.cpp"
#include "HashMap/HashChain.cpp"

int main(int argc, const char * argv[]) {
    
    int capacity = 5;
    
//    /* Crear un HashMap */
    HashMap<int, int> * mapa = new HashMap<int, int>(capacity);

    /* Insertar elementos */
    mapa->put(1, 1);
    mapa->put(5, 5);
    mapa->put(11, 11);
    mapa->put(15, 15);
    mapa->put(2, 2);
    mapa->put(8, 8);

    std::cout << mapa->get(5) << std::endl;
    std::cout << mapa->get(15) << std::endl;
    std::cout << mapa->get(8) << std::endl;
    
    HashChain<int, int> * tabla = new HashChain<int, int>(capacity);
    
    /* Insertar elementos */
    tabla->put(1, 1);
    tabla->put(5, 5);
    tabla->put(11, 11);
    tabla->put(15, 15);
    tabla->put(2, 2);
    tabla->put(8, 8);
    
//    std::cout << tabla->get(5) << std::endl;
//    std::cout << tabla->get(15) << std::endl;
//    std::cout << tabla->get(8) << std::endl;
    
    /* Eliminar la tabla */
    delete mapa;
    delete tabla;
    
    return 0;
}

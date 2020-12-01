//
//  ConexionesComputadora.hpp
//  Actividad 2.2
//
//  Created by Arturo Sosa on 13/10/20.
//  Copyright © 2020 Arturo Sosa. All rights reserved.
//

#ifndef ConexionesComputadora_hpp
#define ConexionesComputadora_hpp
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include "Registro.hpp"
#include "Queue.hpp"
#include "Stack.hpp"


class ConexionesComputadora {
private:
    std::string ip;
    std::string nombre;
    Stack<std::string> ConexionesEntrantes;
    Queue<std::string> ConexionesSalientes;
    
public:
    /* Constructores */
    ConexionesComputadora() {};
    ConexionesComputadora(const std::string Ip,
                          const std::string Nombre,
                          const Stack<std::string> Entrantes,
                          const Queue<std::string> Salientes)
    {
        this->ip = Ip;
        this->nombre = Nombre;
        this->ConexionesEntrantes = Entrantes;
        this->ConexionesSalientes = Salientes;
    }
    ConexionesComputadora(Registro r){
        this->ip = r.getOrigen();
        this->nombre = r.getNombreOrigen();
        this->ConexionesSalientes.enqueue(r.getDestino());
    }
    
    /* Destructor */
    //~ConexionesComputadora();
    
    /* Setters */
    void setIp(std::string Ip);
    void setNombre(std::string Nombre);
    
    /* Getters */
    std::string getIp(std::string Ip);
    std::string getNombre(std::string Nombre);
    
    /* Inserción */
    void insertConexionesEntrantes(const std::string value);
    void insertConexionesSaientes(const std::string value);
    void insertConexionesSaientesFront(const std::string value);
    
    /* sizeOf() */
    int sizeOfConexionesEntrantes();
    int sizeOfConexionesSalientes();
    
    /* Getters de las listas */
    std::string getConexionesEntrantes();
    std::string getConexionesSalientes();
};

/* Destructor */
//ConexionesComputadora::~ConexionesComputadora(){
//    ip = nullptr;
//    nombre = nullptr;
//    ConexionesEntrantes.clear();
//    ConexionesSalientes.clear();
//}

/* Setters */
void ConexionesComputadora::setIp(std::string Ip){
    this->ip =Ip;
}
void ConexionesComputadora::setNombre(std::string Nombre) {
    this->nombre = Nombre;
}


/* Getters */
std::string ConexionesComputadora::getIp(std::string Ip){
    return this->ip;
}
std::string ConexionesComputadora::getNombre(std::string Nombre) {
    return this->nombre;
}


/* Inserción */
void ConexionesComputadora::insertConexionesEntrantes(const std::string value) {
    this->ConexionesEntrantes.push(value);
}
void ConexionesComputadora::insertConexionesSaientes(const std::string value) {
    this->ConexionesSalientes.enqueue(value);
}
void ConexionesComputadora::insertConexionesSaientesFront(const std::string value) {
    this->ConexionesSalientes.reverse();
    this->ConexionesSalientes.enqueue(value);
    this->ConexionesSalientes.reverse();
}


/* sizeOf() */
int ConexionesComputadora::sizeOfConexionesEntrantes(){
        return this->ConexionesEntrantes.size();
    }
int ConexionesComputadora::sizeOfConexionesSalientes(){
    return this->ConexionesSalientes.size();
    }


/* Getters de las listas */
std::string ConexionesComputadora::getConexionesEntrantes() {
    std::string value;
    //value = *ConexionesEntrantes.top() -> getInfo();
    this->ConexionesEntrantes.pop();
    return value;
}
std::string ConexionesComputadora::getConexionesSalientes() {
    return this->ConexionesSalientes.dequeue() -> getInfo();
}

#endif /* ConexionesComputadora_hpp */

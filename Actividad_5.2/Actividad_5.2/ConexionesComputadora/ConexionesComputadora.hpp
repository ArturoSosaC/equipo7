//
//  ConexionesComputadora.hpp
//  Actividad 2.2
//
//  Created by Arturo Sosa on 13/10/20.
//  Copyright © 2020 Arturo Sosa. All rights reserved.
//

#ifndef ConexionesComputadora_hpp
#define ConexionesComputadora_hpp
#include <stdio.h>
#include <iostream>
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
    ConexionesComputadora(std::string Ip,
                          std::string Nombre,
                          Stack<std::string> Entrantes,
                          Queue<std::string> Salientes);}
    ConexionesComputadora(Registro r);
    
    /* Destructor */
    virtual ~ConexionesComputadora();

    /* Setters */
    void setIp(std::string Ip);
    void setNombre(std::string Nombre);

    /* Getters */
    std::string getIp(std::string Ip);
    std::string getNombre(string Nombre);
    
    /* Insert to Queue and Stack */
    void insertConexionesEntrantes(const T & value);
    void insertConexionesSaientes(const T & value);
    void insertConexionesSaientesFront(const T & value);
    
    /* Get sizes */
    int sizeOfConexionesEntrantes();
    int sizeOfConexionesSalientes();
    
    /* Obtener conexiones de entrada y salida */
    std::string getConexionesEntrantes();
    std::string getConexionesSalientes();
    
};

/* Constructores */
ConexionesComputadora() {};

ConexionesComputadora(std::string Ip,
                      std::string Nombre,
                      Stack<std::string> Entrantes,
                      Queue<std::string> Salientes) {
    ip = Ip;
    nombre = Nombre;
    ConexionesEntrantes = Entrantes;
    ConexionesSalientes = Salientes;
}

ConexionesComputadora::ConexionesComputadora(Registro r) {
    ip = r.getOrigen();
    nombre = r.getNombreOrigen();
}
 

/* Destructor */
virtual ~ConexionesComputadora(){
    ~std::string ip;
    ~std::string nombre;
    ~Stack<std::string> ConexionesEntrantes;
    ~Queue<std::string> ConexionesSalientes;
}


/* Setters */
void ConexionesComputadora::setIp(std::string Ip){
    ip =Ip;
}

void ConexionesComputadora::setNombre(std::string Nombre) {
    nombre = Nombre;
}
    
    
/* Getters */
std::string ConexionesComputadora::getIp(std::string Ip){
    return ip;
}

std::string ConexionesComputadora::getNombre(std::string Nombre) {
    return nombre;
}
    
    
/* Insert to Queue and Stack */
void ConexionesComputadora::insertConexionesEntrantes(const std::string value) {
    ConexionesEntrantes.push(value);
}

void ConexionesComputadora::insertConexionesSalientes(const std::string value) {
    ConexionesSalientes.enqueue(value);
}

void ConexionesComputadora::insertConexionesSalientesFront(const std::string value) {
    ConexionesSalientes.reverse();
    ConexionesSalientes.enqueue(value);
    ConexionesSalientes.reverse();
}
    

/* Get sizes */
std::string ConexionesComputadora::sizeOfConexionesEntrantes(){
    return ConexionesEntrantes.size();
}
        
std::string ConexionesComputadora::sizeOfConexionesSalientes(){
    return ConexionesSalientes.size();
}
    

/* Obtener conexiones de entrada y salida */
std::string ConexionesComputadora::getConexionesEntrantes() {
    std::string value;
    value = *ConexionesEntrantes.top() -> getInfo();
    ConexionesEntrantes.pop();
    return value;
}

std::string getConexionesSalientes() {
    return ConexionesSalientes.dequeue() -> getInfo();
}
    

#endif /* ConexionesComputadora_hpp */

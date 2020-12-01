//
//  Registro.hpp
//  Actividad 2.2
//
//  Created by Arturo Sosa on 14/10/20.
//  Copyright © 2020 Arturo Sosa. All rights reserved.
//

#ifndef Registro_hpp
#define Registro_hpp
#include <stdio.h>
#include <iostream>

class Registro {
private:
    std::string fecha, hora, origen, destino;
    std::string puertoOrigen, nombreOringen, puertoDestino, nombreDestino;
    
public:
    Registro(){}
    
    Registro(std::string f, std::string h, std::string no, std::string po,          std::string o, std::string nd, std::string pd, std::string d):
    fecha(f), hora(h), origen(o), destino(d),
    puertoOrigen(po), nombreOringen(no),
    puertoDestino(pd), nombreDestino(nd) {}
    
    std::string getDestino(){
        return nombreDestino;
    }
    std::string getOrigen(){
        return nombreOringen;
    }
    std::string getNombreDestino(){
        return destino;
    }
    std::string getNombreOrigen(){
        return origen;
    }
    std::string Fecha(){
        return fecha;
    }
    
    std::string getPuertoOrigen(){
        return puertoOrigen;
    }
    
    std::string getPuertoDestino(){
        return puertoDestino;
    }
    
    friend std::ostream & operator<<(std::ostream & os, const Registro & registro);
    bool operator != (const Registro & registro){
        return
            registro.destino != destino &&
            registro.fecha != fecha &&
            registro.hora != hora &&
            registro.origen != origen &&
            registro.puertoOrigen != puertoOrigen &&
            registro.nombreOringen != nombreOringen &&
            registro.puertoDestino != puertoDestino &&
            registro.nombreDestino != nombreDestino;
    }
    bool operator == (const Registro & registro){
        return
            registro.destino == destino &&
            registro.fecha == fecha &&
            registro.hora == hora &&
            registro.origen == origen &&
            registro.puertoOrigen == puertoOrigen &&
            registro.nombreOringen == nombreOringen &&
            registro.puertoDestino == puertoDestino &&
            registro.nombreDestino == nombreDestino;
    }
};



#endif /* Registro_hpp */

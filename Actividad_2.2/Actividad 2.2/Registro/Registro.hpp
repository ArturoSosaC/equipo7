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
    
    Registro(std::string f, std::string h, std::string o, std::string po,          std::string d, std::string no, std::string pd, std::string nd):
    fecha(f), hora(h), origen(o), destino(d),
    puertoOrigen(po), nombreOringen(no),
    puertoDestino(pd), nombreDestino(nd) {}
    
    std::string Destino(){
        return puertoDestino;
    }
    std::string Origen(){
        return puertoOrigen;
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

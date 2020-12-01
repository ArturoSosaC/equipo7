//
//  Registro.cpp
//  Actividad 2.2
//
//  Created by Arturo Sosa on 14/10/20.
//  Copyright © 2020 Arturo Sosa. All rights reserved.
//

#include "Registro.hpp"

std::ostream & operator<<(std::ostream & os, const Registro & registro){
    
    os << registro.fecha << " - ";
    os << registro.hora << " - ";
    os << registro.origen << " - ";
    os << registro.destino << " - ";
    os << registro.puertoOrigen << " - ";
    os << registro.nombreOringen << " - ";
    os << registro.puertoDestino << " - ";
    os << registro.nombreDestino << " - ";
    os << std::endl;
    
    return os;
}

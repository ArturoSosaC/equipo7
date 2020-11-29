//
//  main.cpp
//  Actividad 5.2
//
//  Created by Arturo Sosa on 13/10/20.
//  Copyright © 2020 Arturo Sosa. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <set>
#include "Registro.hpp"
#include "ConexionesComputadora.hpp"


auto read_csv_strings(std::string filename){
    
    /* Crear un vector de vector de strings */
    std::vector< std::vector<std::string> > lineas;

    /* Crear un input filestream para leer el archivo CSV */
    std::ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw std::runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    std::string linea;
    
    /* Leer datos línea a línea */
    while(std::getline(file, linea))
    {
        /* Crear un steam de la línea */
        std::stringstream ss(linea);
    
        /* Variable que almacena cada campo leído */
        std::string campo;
        
        /* Definir un vector para almacenar cada campo */
        std::vector<std::string> fila;
        
        /* Iterar sobre la línea para extraer cada campo */
        while(std::getline(ss, campo, ','))
        {
            fila.push_back(campo);
        }
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(fila);
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}
                
auto read_csv_registro(std::string filename)
{
    /* Crear un vector de vector de strings */
    std::vector< Registro > lineas;

    /* Crear un input filestream para leer el archivo CSV */
    std::ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw std::runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    std::string linea;
    
    /* Leer datos línea a línea */
    while(std::getline(file, linea))
    {
        /* Crear un steam de la línea */
        std::stringstream ss(linea);
    
        /* Variables que almacenan cada campo leído */
        std::string fecha;
        std::string hora;
        std::string origen;
        std::string destino;
        std::string puertoOrigen;
        std::string nombreOringen;
        std::string puertoDestino;
        std::string nombreDestino;
        
        /* Iterar sobre la línea para extraer cada campo */
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, origen, ',');
        getline(ss, destino, ',');
        getline(ss, puertoOrigen, ',');
        getline(ss, nombreOringen, ',');
        getline(ss, puertoDestino, ',');
        getline(ss, nombreDestino, ',');
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(Registro(fecha, hora, origen, destino, puertoOrigen, nombreOringen, puertoDestino, nombreDestino));
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}


int main(int argc, const char * argv[]){
    ConexionesComputadora<Registro> conexiones =
    ConexionesComputadora<Registro>();
    string value = "192.168.57.";
    
    /* Lectura de los datos como un objeto Registros */
    std::vector< Registro > registros = read_csv_registro("equipo7.csv");
    
//    int sizeOfRegistros = (int)registros.size();
//    std::set< std::string > setNombres;
//    std::set< std::string > setDirecciones;
//    std::string nombre;
//    map <string, std::string>  mapa;
//    std::map<std::string, std::string>::iterator it;
//
//    for(int i = 0; i<sizeOfRegistros; i++){
//        nombre = registros.at(i).getNombreOrigen();
//        if(nombre.find("reto.com") == string::npos){
//            std::cout<<i<<std::endl;
//            setNombres.insert(nombre);
//            std::pair<std::string, std::string> nuevoSitio(nombre, registros.at(i).getOrigen());
//            mapa.insert(nuevoSitio);
//        }
//    }
//
//    for (auto d : setNombres) {
//        std::cout << d << std::endl;
//    }
    
    
//    set.clear();
//    conexiones.clear();
//    registros.clear();
    
    std::cout << "--- Set de dominios ----" << std::endl;
    
    std::set<std::string> dominios;
    std::set<std::string> reto;
    std::map <std::string, ConexionesComputadora<Registro> > mapa;
    std::vector< std::string > ipsReto;
    
    for (auto r : registros) {
        std::string sitio = r.getNombreOrigen();
        std::string ip = r.getOrigen();
        
        if (sitio.find("reto.com") == std::string::npos) {
            dominios.insert(sitio);
            ConexionesComputadora<Registro> *conexiones = new ConexionesComputadora<Registro>(r);
            mapa.insert(pair<std::string, ConexionesComputadora<Registro>>(sitio, conexiones));
        }
        else{
            reto.insert(sitio);
            ipsReto.push_back(ip);
        }
        
        std::string destino = r.getNombreDestino();
        std::string destinoIp = r.getDestino();
        
        if (destino.find("reto.com") == std::string::npos) {
            dominios.insert(destino);

        }
        else{
            reto.insert(sitio);
            ipsReto.push_back(ip);
        }
    }
    
    for (auto d : dominios){
        std::cout << d << std::endl;
    }
    
    std::cout << std::endl;
    int count = 0;
    
    for (auto d : dominios){
        if(d != "lrf8nxdjzhwvscbf49mh.org")
            break;
        else
            count++;
    }
    

    
    /* Eliminar todos los registros */
    registros.clear();
    dominios.clear();
    
    return 0;
}
    


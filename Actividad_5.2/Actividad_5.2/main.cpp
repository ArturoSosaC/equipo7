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
        
    /* Lectura de los datos como un objeto Registros */
    std::vector< Registro > registros = read_csv_registro("equipo7.csv");
    
    /* Creación de estructuras auxiliares */
    std::set<std::string> dominios;
//    std::set<std::string> reto;
    std::map <std::string, ConexionesComputadora > mapa;
//    std::map <std::string, std::string> sitio_ip;
    std::vector<std::string> ips_dominios;
    std::vector<std::string> conexiones_entrantes;
    std::vector< std::pair<int, int> > puertos;
    int computadoras_con_conexiones_entrantes = 0;
    
    
    /* Recorrido de registros y llenado de estructuras auxiliares */
    for (auto r : registros) {
        std::string sitio = r.getNombreOrigen();
        std::string ip = r.getOrigen();
        
        if (sitio.find("reto.com") == std::string::npos) {
            
            if(std::find(dominios.begin(),
                         dominios.end(),
                         sitio) == dominios.end())
            {
                ips_dominios.push_back(ip);
//                ConexionesComputadora conexiones(r);
//                std::pair<std::string, ConexionesComputadora> datos(sitio, conexiones);
//                mapa.insert(datos);
            }
            
//            else{
//                mapa[sitio].insertConexionesSalientes(r.getDestino());
//            }
            
            dominios.insert(sitio);
//            sitio_ip.insert(std::pair<std::string, std::string>(sitio, ip));
        }
        
//        else{
//            reto.insert(sitio);
//            sitio_ip.insert(std::pair<std::string, std::string>(sitio, ip));
//        }
        
        std::string destino = r.getNombreDestino();
        std::string destinoIp = r.getDestino();
        
        if (destino.find("reto.com") == std::string::npos) {
            if(std::find(dominios.begin(),
                         dominios.end(),
                         destino) == dominios.end())
            {
                ips_dominios.push_back(destinoIp);
//                ConexionesComputadora conexiones(r);
//                std::pair<std::string, ConexionesComputadora> datos(sitio, conexiones);
//                mapa.insert(datos);
            }
            
//            else{
//                mapa[destino].insertConexionesEntrantes(r.getOrigen());
//            }
            
            dominios.insert(destino);
            
            if(std::find(conexiones_entrantes.begin(),
                         conexiones_entrantes.end(),
                         destino) == conexiones_entrantes.end())
            {
                conexiones_entrantes.push_back(destino);
//                puertos.push_back(std::make_pair(stoi(r.getPuertoOrigen()), stoi(r.getDestino())));
                computadoras_con_conexiones_entrantes++;
            }
        }
        
//        else{
//            reto.insert(sitio);
//        }
    }
    /* Fin del loop */
    
    /* Impresión de sitios que no terminan en reto.com */
    int size=0;
    std::cout << "--- 1. Set de dominios ----" << std::endl;
    for (auto d : dominios){
        size++;
        std::cout << d << std::endl;
    }

    std::cout << std::endl;
    int count = 0;

    for (auto d : dominios){
        if(d == "lrf8nxdjzhwvscbf49mh.org")
            break;
        else
            count++;
    }
    dominios.clear();

    std::cout << "--- 2. Ip de lrf8nxdjzhwvscbf49mh.org ----" << std::endl;
//    std::cout<< "Tamaño del veector:"<<ips_dominios.size() <<std::endl;
//    std::cout<< "Tamaño de dominios:"<<size <<std::endl;
    std::cout<< ips_dominios.at(count) <<std::endl<<std::endl;
//    std::cout<< sitio_ip["rf8nxdjzhwvscbf49mh.org"] <<std::endl;


    std::cout << "--- 3. Computadoras con conexiones entrantes ----" << std::endl;
    std::cout<< computadoras_con_conexiones_entrantes <<std::endl<<std::endl;
    
    
    /* Eliminar todos los registros */
    conexiones_entrantes.clear();
    ips_dominios.clear();
//    sitio_ip.clear();
    puertos.clear();
    registros.clear();
//    reto.clear();
    
    mapa.clear();
    return 0;
}
    


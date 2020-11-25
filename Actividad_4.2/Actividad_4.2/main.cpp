//
//  main.cpp
//  Actividad_4.2
//
//  Created by Arturo Sosa on 22/11/20.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Graph/Graph.hpp"
#include "Registro/Registro.hpp"

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

bool duplicated(std::string tempString, std::vector< std::string > aux){
    int length = (int)aux.size();
    for(int i = 0; i<length; i++){
        if(tempString == aux.at(i))
            return true;
    }
    return false;
}


int main(int argc, const char * argv[]) {
    std::vector< Registro > registros = read_csv_registro("equipo7.csv");
    std::vector< std::string > auxiliar_ips;
    std::vector< std::string > auxiliar_nombres;
    std::string nombre;
    std::string ip;
    Graph< std::string, std::string > * ips = new Graph< std::string, std::string >();
    Graph< std::string, std::string > * nombres = new Graph< std::string, std::string >();
    int length = (int)registros.size();
    Registro registro_temp;


    for(int i=0; i<length; i++){
        registro_temp = registros.at(i);
        nombre = registro_temp.getNombreOrigen();
        ip = registro_temp.getOrigen();
        auxiliar_ips.push_back(ip);
        auxiliar_nombres.push_back(nombre);

        if(duplicated(ip, auxiliar_ips) || duplicated(nombre, auxiliar_nombres)){
            ips->addVertex(new Vertex<std::string, std::string>(ip));
            nombres->addVertex(new Vertex<std::string, std::string>(nombre));

        }
    }
    auxiliar_ips.empty();
    auxiliar_nombres.empty();
    
    
//    for(int i=0; i<length; i++){
//        registro_temp = registros.at(i);
//
//        ips->addEdge(
//                     new Vertex<std::string, std::string>(registro_temp.getOrigen()),
//                     new Vertex<std::string, std::string>(registro_temp.getDestino()), "");
//
//        nombres->addEdge(
//                         new Vertex<std::string, std::string>(registro_temp.getNombreOrigen()),
//                         new Vertex<std::string, std::string>(registro_temp.getNombreDestino()), "");
//    }
    
    
    
    
    std::cout<< *ips <<std::endl;
    int a;
    std::cin>> a;
    std::cout<< *nombres <<std::endl;
    
    delete ips;
    delete nombres;
    return 0;
}

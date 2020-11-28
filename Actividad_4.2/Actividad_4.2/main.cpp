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
#include <set>
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


int main(int argc, const char * argv[]) {
    // Leer Csv en un vector
    std::vector< Registro > registros = read_csv_registro("equipo7.csv");
    
    
    //Estructuras auxiliares para crear vectores
    std::vector< std::string > auxiliar_ips;
    std::vector< std::string > auxiliar_nombres;
    std::string nombre;
    std::string ip;
    
    

    //Definir vectores
    Graph< std::string, std::string > * ips = new Graph< std::string, std::string >();
    Graph< std::string, std::string > * nombres = new Graph< std::string, std::string >();
    
    //Llenar vectores
    for(auto r : registros){
        nombre = r.getNombreOrigen();
//        ip = r.getOrigen();
        //std::cout<<"IP: "<<r.getOrigen()<<std::endl;
//        std::cout<<"Nombre: "<<nombre<<std::endl;
        if(std::find(auxiliar_nombres.begin(), auxiliar_nombres.end(), nombre) == auxiliar_nombres.end()){
            
//            ips->addVertex(new Vertex<std::string, std::string>(r.getOrigen()));
            nombres->addVertex(new Vertex<std::string, std::string>(nombre));
//            auxiliar_ips.push_back(ip);
            auxiliar_nombres.push_back(nombre);
        }
        if(std::find(auxiliar_ips.begin(), auxiliar_ips.end(), ip) == auxiliar_ips.end()){
            std::cout<<r.getOrigen()<<std::endl;
            ips->addVertex(new Vertex<std::string, std::string>(r.getOrigen()));
            auxiliar_ips.push_back(ip);
        }
    }
    
    //Vaciar estructuras auxiliares
    auxiliar_nombres.empty();
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
    
    
    
    
//    std::cout<< *ips <<std::endl;
//    std::string a;
//    std::cout<<"Press enter to continue: ";
//    std::cin>> a;
//    std::cout<< *nombres <<std::endl;
    
    delete ips;
    delete nombres;
    return 0;
}

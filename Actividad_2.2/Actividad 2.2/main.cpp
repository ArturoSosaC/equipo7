//
//  main.cpp
//  Actividad 2.2
//
//  Created by Arturo Sosa on 13/10/20.
//  Copyright © 2020 Arturo Sosa. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>
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
    Registro temp1;
    string tempString1;
    Registro temp2;
    string tempString2;
    int sizeOfConexionesEntrantes;
    int sizeOfConexionesSalientes;
    int sizeOfRegistros;
    int sizeOfRandom;
    int random = 0;
    int counter = 1;
    string randomToString;
    
    string value = "192.168.57.";
    bool comparer = true;
    
    std::cout << std::endl << std::endl;
    
    /* Lectura de los datos como un objeto Registros */
    std::vector< Registro > registros = read_csv_registro("equipo7.csv");
    sizeOfRegistros = (int)registros.size();
    
    /* Imprimir el vector */
//    std::copy(registros.begin(), registros.end(), std::ostream_iterator<Registro>(std::cout));

    while(random<1 || random>150){
        system("clear");
        cout<<"Introduzca una dirección IP entre 1 y 150: ";
        cin>>random;
    }
    
    randomToString = to_string(random);
    sizeOfRandom = (random % 10) + 1;
    
    for(int i = 0; i < sizeOfRandom; i++)
        value.push_back(randomToString.at(i));
    
    
    for(int i = 0; i<sizeOfRegistros; i++){
        
        if(!registros.at(i).Destino().compare(value))
            conexiones.insertConexionesEntrantes(registros.at(i));
        
        else if(!registros.at(i).Origen().compare(value))
            conexiones.insertConexionesSaientes(registros.at(i));
        
    }
    
    cout<<"Se está utilizando la dirección IP: "<<value<<endl;
    
    temp1 = conexiones.getConexionesEntrantes();
    tempString1 = temp1.Origen();
    
    for(int i = 11; i < (sizeOfRandom+11); i++){
        if(!value.compare(tempString1))
            comparer = false;
    }
    
    cout<<"La dirección IP de la última conexión que recibió esta computadora es: " << tempString1 << "Esta conexión es ";
    
    if(comparer)
        cout<<"Interna"<<endl;
    
    else
        cout<<"Externa"<<endl;
    
    sizeOfConexionesEntrantes = conexiones.sizeOfConexionesEntrantes();
    sizeOfConexionesSalientes = conexiones.sizeOfConexionesSalientes();
    
    cout<<"Esta computadora tiene" << sizeOfConexionesEntrantes << "conexiones entrantes"<<endl;
    
    cout<<"Esta computadora tiene" << sizeOfConexionesSalientes << "conexiones salientes"<<endl;
    
    temp1 = conexiones.getConexionesSalientes();
    tempString1 = temp1.Destino();
    temp2 = conexiones.getConexionesSalientes();
    tempString2 = temp2.Destino();
    comparer = false;
    
    
    for(int i = 0; i<sizeOfConexionesSalientes; i++){
        if(tempString1.compare(tempString2) &&
           ((tempString1.at(11) == 8 && tempString1.at(12) == 0) ||
            (tempString1.at(11) == 4 && tempString1.at(12) == 4 && tempString1.at(13) == 3))){
            
            counter++;
            if(counter == 3){
                comparer = true;
                break;
            }
        }
        else{
            counter = 1;
            temp1 = temp2;
            tempString1 = tempString2;
        }
        
        temp2 = conexiones.getConexionesSalientes();
        tempString2 = temp2.Destino();
    }
    
    if(comparer)
        cout<<"Hay 3 conexiones seguidas a un mismo sitio web"<<endl;
    else
        cout<<"No hay 3 conexiones seguidas a un mismo sitio web"<<endl;
    

    conexiones.clear();
    registros.clear();
    return 0;
}

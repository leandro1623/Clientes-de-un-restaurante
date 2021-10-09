#include<fstream>
#include<iostream>
#include"archivos.h"



//get and set
template<class global>
void archivo::set_dato(global dato1){
	dato=dato1;
}
global archivo::get_dato(){
	return dato;
}
//atrivutos
template<class global>
void archivo::guardar(){
	ofstream archivo;
	archivo.open("Clientes de un restaurante.txt",std::ios::out);
	if(archivo.fail()){
		std::cout<<"No se pudo abrir el archivo\n";
	}
	archivo<<cont<<" "<<get_dato;
	cont+=1;
	archivo.close();
}
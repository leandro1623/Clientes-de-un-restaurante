#include<fstream>
#include<iostream>

class archivo{
	public:
	//atrivutos
		void guardar(int id,char nombre[60],int edad,char pedido[999]){
			std::ofstream archivo;
			archivo.open("Clientes de un restaurante.txt",std::ios::app);
			if(archivo.fail()){
				std::cout<<"No se pudo abrir el archivo\n";
			}
			archivo<<id<<" "<<nombre<<" "<<edad<<" "<<pedido;
			archivo.close();
		}
		
		void mostrar(){
			char id[10],nombre[60],edad[2],pedido[999];
			std::ifstream archivo;
			archivo.open("Clientes de un restaurante.txt",std::ios::in);
			if(archivo.fail()){
				std::cout<<"No se pudo abrir el archivo\n";
			}
			
			std::cout<<"\n ID | NOMBRE 	| EDAD | PEDIDO\n";
			while(!archivo.eof()){
				archivo>>id>>nombre>>edad>>pedido;
				std::cout<<id<<" | "<<nombre<<" | "<<edad<<" | "<<pedido<<"\n";
			}
};
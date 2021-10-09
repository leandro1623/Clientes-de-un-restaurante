#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
											/* Programaa Finalizado */ 

struct Persona{
	char nombre[50],pedido[200];
	int edad,pin;
};

struct Nodo{
	Persona dato;
	Nodo *siguiente;
};

//prototipos de funcion
bool strcmp1(char palabra1[],char palabra2[]);
void menu();
void lista_de_personas(Nodo *&,Nodo *&,Persona);
void mostrar_lista(Nodo *,Nodo *);
void nueva_persona(Persona &);
void eliminar_cliente(Nodo *&,Nodo *&);
int id_unico();
void buscar_persona(Nodo *);
void busca_por_ID(Nodo *);
void buscar_por_nombre(Nodo *);
void buscar_por_pedido(Nodo *);

Nodo *frente=NULL,*fin=NULL;//lista

int main(){
	menu();
	
	return 0;
}

//menu del programa
void menu(){
	char opc;
	do{
		system("color 1");
		int pin2;
		Persona dato;
		system("cls");
		std::cout<<"\t .:MENU PRINCIPAL:. \n";
		std::cout<<"\n1. Agregar un nuevo cliente";
		std::cout<<"\n2. Mostra lista de clientes";
		std::cout<<"\n3. Eliminar un cliente";
		std::cout<<"\n4. Buscar un cliente";
		std::cout<<"\n5. Salir";
		std::cout<<"\nDigite una opcion: ";std::cin>>opc;
		
		switch(opc){
			case '1': nueva_persona(dato);lista_de_personas(frente,fin,dato);break;
			case '2': std::cout<<"\n .:Mostrando lista de los clientes:. \n";mostrar_lista(frente,fin);break;
			case '3': eliminar_cliente(frente,fin);break;
			case '4': buscar_persona(frente);break;
			case '5': std::cout<<"\n ~~PROGRAMA FINALIZADO~~\n\n";break;
			default: std::cout<<"\n~~OPCION INVALIDA~~\n\n";break;
		}
		std::cout<<"\n\n";
		system("pause");
	}while(opc!='5');
}

//lista de clientes por llegada
void lista_de_personas(Nodo *&frente,Nodo *&fin,Persona dato){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=dato;
	nuevo_nodo->siguiente=NULL;
	
	if(frente==NULL){
		frente=nuevo_nodo;
		fin=nuevo_nodo;
	}
	else{
		fin->siguiente=nuevo_nodo;
		fin=nuevo_nodo;
	}
}

//muestra la lista delos clientes 
void mostrar_lista(Nodo *frente,Nodo *fin){
	Nodo *aux=frente;
	if(aux==NULL){
		std::cout<<"\n .: La lista esta vacia :.\n\n";
	}
	else{
		system("cls");
		std::cout<<"\n ID | NOMBRE 	| PEDIDO\n";
		while(aux!=NULL){
			std::cout<<aux->dato.pin<<" | "<<aux->dato.nombre<<" | "<<aux->dato.pedido<<"\n";
			aux=aux->siguiente;
		}
	}
}


//pidiendo los datos de los clientes
void nueva_persona(Persona &dato){
	Persona *nueva_persona=new Persona();
	nueva_persona->pin=id_unico();//id unico
	fflush(stdin);
	std::cout<<"\nDigite su nombre: ";std::cin.getline(nueva_persona->nombre,50,'\n');
	std::cout<<"\nDigite su edad: ";std::cin>>nueva_persona->edad;
	fflush(stdin);
	std::cout<<"\nQue desea pedir (Digite su pedido): ";std::cin.getline(nueva_persona->pedido,200,'\n');
	
	dato=*nueva_persona;
}

//elimina a un cliente de la lista
void eliminar_cliente(Nodo *&frente,Nodo *&fin){
	int pin;
	Nodo *aux=frente,*aux2;
	if(aux==NULL){
		std::cout<<"\n~~LA LISTA ESTA VACIA~~\n\n";
	}
	else{
		mostrar_lista(frente,fin);
		std::cout<<"\n\n\nDigite el ID del cliente a eliminar: ";std::cin>>pin;
		if(aux->dato.pin==pin){
			frente=frente->siguiente;
			delete aux;
		}
		else{
			aux2=aux;
			aux=aux->siguiente;
			while((aux!=NULL) && (aux->dato.pin != pin)){
				aux2=aux;
				aux=aux->siguiente;
			}
			
			if(aux->dato.pin==pin){
				aux2->siguiente=aux->siguiente;
				delete aux;
			}
			else{
				std::cout<<"\nEl cliente NO fue encontrado\n\n";
			}
		}
			std::cout<<"\n\n.:Cliente eliminado satisfactoriamente:.\n\n";
	}
}

//id de cada persona esta fincion va en nueva_persona
int id_unico(){
	long x,y,id;
	srand(time(NULL));
	x=500+rand()%(999);
	y=500+rand()%(999);
	id=x+y;
	return id;
}

//busca un cliente en la cola
void buscar_persona(Nodo *frente){
	if(frente==NULL){
		std::cout<<"\nLa lista esta vacia";
	}
	else{
		char opc;
		std::cout<<"\n1. Busca por el ID";
		std::cout<<"\n2. Busca por el Nombre";
		std::cout<<"\n3. Busca por el  pedido";
		std::cout<<"\n4. Volver al menu principal";
		std::cout<<"\nOpcion: ";std::cin>>opc;
		
		switch(opc){
			case '1': busca_por_ID(frente);break;
			case '2': buscar_por_nombre(frente);break;
			case '3': buscar_por_pedido(frente);break;
			case '4': break;
			default: std::cout<<"\n*OPCION INVALIDA\n\n";
		}
	}
	
}

//busca a un cliente por su ID
void busca_por_ID(Nodo *frente){
	Nodo *aux=frente;
	int ID;
	std::cout<<"\nDigite ID: ";std::cin>>ID;
	while(aux!=NULL && ID!=aux->dato.pin){
		aux=aux->siguiente;
	}
	
	if(aux==NULL){
		std::cout<<"\nEl cliente NO existe";
	}
	else{
		std::cout<<"\n.:Cliente encontrado:.\n\n";
		std::cout<<" ID | NOMBRE | PEDIDO \n";
		std::cout<<aux->dato.pin<<" | "<<aux->dato.nombre<<" | "<<aux->dato.pedido<<"\n\n";
	}
}

//busca a un cliente por su nombre
void buscar_por_nombre(Nodo *frente){
	fflush(stdin);
	Nodo *aux=frente;
	char nombre[50];
	std::cout<<"\nDigite el nombre: ";std::cin.getline(nombre,50,'\n');
	
	//recorriendo lista
		while((aux!=NULL) && (strcmp1(nombre,aux->dato.nombre)==false)){
			aux=aux->siguiente;
		}
	
	if(aux==NULL){
		std::cout<<"\nEl cliente NO existe\n";
	}
	else{
		std::cout<<"\n.:Cliente encontrado:.\n\n";
		std::cout<<" ID | NOMBRE | PEDIDO \n";
		std::cout<<aux->dato.pin<<" | "<<aux->dato.nombre<<" | "<<aux->dato.pedido<<"\n\n";
	}
}

//busca a un cliente por su pedido
void buscar_por_pedido(Nodo *frente){
	fflush(stdin);
	Nodo *aux=frente;
	char pedido[200];
	std::cout<<"\nDigite el pedido: ";std::cin.getline(pedido,200,'\n');
	//recorriendo lista
	while((aux!=NULL) && (strcmp1(pedido,aux->dato.pedido)==false)){
		aux=aux->siguiente;
	}
	
	if(aux==NULL){
		std::cout<<"\nEl cliente NO existe\n";
	}
	else{
		std::cout<<"\n.:Cliente encontrado:.\n\n";
		std::cout<<" ID | NOMBRE | PEDIDO \n";
		std::cout<<aux->dato.pin<<" | "<<aux->dato.nombre<<" | "<<aux->dato.pedido<<"\n\n";
	}
}

//comparacion de cadenas
bool strcmp1(char palabra1[],char palabra2[]){
	int tam1,tam2;
	tam1=strlen(palabra1);
	tam2=strlen(palabra2);
	bool band=false;
	
	if(tam1==tam2){
		for(int i=0;i<tam1;i++){
			if(palabra1[i]==palabra2[i]){
				band=true;
			}
			else{
				band=false;
				break;
			}
		}
		
		if(band==true){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}	
}
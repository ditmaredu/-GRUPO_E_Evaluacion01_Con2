#include <iostream>
#include <string>

using namespace std;  
 
const int MAX_ESTUDIANTES = 15;

struct Estudiante {
	float nota;
	int id;
	string nombre;
};

void agregarEstudiante (Estudiante estudiantes[], int& contador, int id, float nota, string nombre) {
	for (int i = 0; i < contador; i++) {
		if (estudiantes[i].id == id) {
			cout<<"ESTE ESTUDIANTE YA ESTA REGISTRADO"<<endl;
			return;
		}
	}
	if (contador < MAX_ESTUDIANTES) {
		estudiantes[contador].id = id;
		estudiantes[contador].nota = nota;
		estudiantes[contador].nombre = nombre;
		contador++;
	
		cout<<"El estudiante con ID: "<<id<<", nombre"<<nombre<<", Notas = "<<nota<<endl;
	} else {
		cout<<"No se pueden agregar mas Estudiantes"<<endl;
	}
}

Estudiante* buscarEstudiante(Estudiante estudiantes[], int contador, int id) {
	for (int i =0; i < contador; i++){
		if (estudiantes[i].id == id) {
		 return &estudiantes[i];
		}
	}
}

void actualizarNotaEstudiante(Estudiante& estudiante,  float nuevaNota) {
	estudiante.nota = nuevaNota;
}

void mostrarEstudiantes(Estudiante estudiantes[], int contador) {
	for (int i = 0; i < contador; i++) {
		cout<<"Estudiante con ID: "<<estudiantes[i].id<<", nombre: "<<estudiantes[i].nombre<<", Notas: "<<estudiantes[i].nota<<endl;
	}
}

int main () {
	Estudiante estudiantes[MAX_ESTUDIANTES];
	int opcion;
	int contador = 0;
	float nota;
	int buscarId;
	string nombre;
	int id;
	do {
		cout<<"\n----MENU PRINCIPAL---\n"<<endl;
		cout<<"1.- Ingresar Estudiante"<<endl;
		cout<<"2.- Buscar un Estudiante"<<endl;
		cout<<"3.- Actualizar Notas"<<endl;
		cout<<"4.- Mostrar total de estudiantes"<<endl;
		cout<<"5.- Salir"<<endl;
		cin>>opcion;
		
		switch (opcion) {
			case 1: {
				cout<<"Ingrese ID del estudiante para agregar"<<endl;
				cin>>id;
				cout<<"Ingrese nota del estudiante"<<endl;
				cin>>nota;
				cout<<"Ingrese nombre del estudiante"<<endl;
				cin.ignore();
				getline(cin, nombre);
				agregarEstudiante(estudiantes, contador, id, nota, nombre);
				break;
			}
			case 2: {
				cout<<"Ingrese ID del estudiante para actualizar"<<endl;
				cin>>buscarId;
				Estudiante* est = buscarEstudiante(estudiantes, contador, buscarId);
				if (est) {
					cout<<"Estudiante encontrado con ID: "<<est->id<<", nombre: "<<est->nombre<<", notas: "<<est->nota<<endl;
				} else {
					cout<<"Estudiante con ID"<<buscarId<<" no encontrado"<<endl;
				}
				break;
			}
			case 3: {
				cout<<"Ingrese ID del estudiante"<<endl;
				cin>>buscarId;
				Estudiante* est = buscarEstudiante(estudiantes, contador, buscarId);
				if (est) {
					cout<<"Ingresar nueva nota"<<endl;
					float nuevaNota;
					cin>>nuevaNota;
					actualizarNotaEstudiante(*est, nuevaNota);
				cout<<"Notas de estudiante Actualizado"<<endl;
				} else {
					cout<<"Estudiante"<<buscarId<<" no encontrado"<<endl;
				}
				break;
			}
			case 4: {
				cout<<"Estudiantes actuales registrados"<<endl;
				mostrarEstudiantes(estudiantes, contador);
				break;
			}
			case 5: {
				cout<<"Saliendo del programa"<<endl;
				break;
			}
			default:
				cout<<"Invalido, vuelva a intentarlo"<<endl;
		}
	}while (opcion !=5);
	return 0;
}

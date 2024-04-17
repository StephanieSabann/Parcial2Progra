#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Empleados {
public:
	Empleado(string nom,string ape,int ed, int sal) {
        nombre = nom;
        apellido = ape;
        edad = ed;
        salario = sal;
    }
    void escribir(string datos);
    void sobreescribir(int posicion, string datos);
    string leer();

private:
    fstream archivo;
    string nombre;
    string apellido;
    int edad;
    int salario;
};

void Empleados::escribir(string datos) {
    archivo.open("Empleados.txt", ios::out | ios::binary);

    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    archivo.write(datos.c_str(), datos.size());

    archivo.close();
}


string Empleados::leer() {
    archivo.open("Empleados.txt", ios::in | ios::binary);

    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return "";
    }

    string datosLeidos;
    char* buffer = new char[1000]; // Tamaño máximo del archivo
    archivo.read(buffer, 1000);
    datosLeidos = buffer;

    delete[] buffer;

    archivo.close();

    return datosLeidos;
}

int main() {
    Empleados archivo;
    
    string datos;
    cout << "Ingresa los datos para escribir en el archivo, en este caso nombre, apellido, edad, y salario: ";
    getline(cin, datos);
    archivo.escribir(datos);
    
    string datosLeidos = archivo.leer();
    cout << "Datos leidos del archivo: " << datosLeidos << endl;

    return 0;
}

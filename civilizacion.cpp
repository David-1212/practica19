#include "civilizacion.h"
#include<algorithm>
#include <fstream>

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre, int x, int y, int puntuacion)
{
    this->nombre = nombre;
    this->x = x;
    this->y = y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}
void Civilizacion::setX(int v)
{
    x = v;
}
void Civilizacion::setY(int v)
{
    y = v;
}
void Civilizacion::setPuntuacion(int v)
{
    puntuacion = v;
}



string Civilizacion::getNombre()
{
    return nombre;
}
int Civilizacion::getX()
{
    return x;
}
int Civilizacion::getY()
{
    return y;
}
int Civilizacion::getPuntuacion()
{
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::print()
{
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(22) << "Edad";
    cout << setw(20) << "Genero";
    cout << setw(10) << "Salud";
    cout << endl;
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
         cout << *it <<endl;
    }
       
}
void Civilizacion::eliminarNombre(const string &nombre)
{
     for(auto it = aldeanos.begin(); it != aldeanos.end();it++){
         Aldeano &j= *it;
         if(nombre == j.getNombre()){
             aldeanos.erase(it);
             break;
         }
     }
}
void Civilizacion::eliminarSalud(size_t n)
{
    aldeanos.remove_if([n](const Aldeano &a){return a.getSalud()<n;});
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if([](const Aldeano &a){ return a.getEdad()>=60;});
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2 )
    {return a1.getNombre() > a2.getNombre();});
}
bool comparadorEdad(const Aldeano &j1,const Aldeano &j2)
{
    return j1.getEdad()>j2.getEdad();
}
void Civilizacion::ordenarEdad()
{
   aldeanos.sort([](const Aldeano &a1, const Aldeano &a2 ){return
    a1.getEdad()>a2.getEdad();});
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2 ){return
    a1.getSalud()>a2.getSalud();});
}
Aldeano* Civilizacion::buscara(const string& a)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end();it++){
         Aldeano &j= *it;
         if(a == j.getNombre()){
            return &(*it);
             break;
         }
         else
         {
            cout<<"No encontrado"<<endl;
            

         }
         
     }
     return 0;
    
}
void Civilizacion::respaldar_aldeanos()
{
    ofstream aldeanos (getNombre() + ".txt", ios::out);
    
    for (auto it = this->aldeanos.begin(); it != this->aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        aldeanos << aldeano.getNombre() << endl;
        aldeanos << aldeano.getEdad()   << endl;
        aldeanos << aldeano.getGenero() << endl;
        aldeanos << aldeano.getSalud()  << endl;
    }
    aldeanos.close();
}

void Civilizacion::recuperar_aldeanos(string civ){
    ifstream archivo1(civ);
    if(archivo1.is_open()){
        string temp;
        size_t edad;
        float salud;
        string aux;
        Aldeano a;
        while(true){
            getline(archivo1,temp);//nombre
            if(archivo1.eof()){
                break;
            }
            aux = temp;
            a.setNombre(aux);

            getline(archivo1,temp);//edad
            edad =stoi(temp);
            a.setEdad(edad);

            getline(archivo1,temp);//genero
            aux = temp;
            a.setGenero(aux);

            getline(archivo1,temp);//salud
            salud = stof(temp);
            a.setSalud(salud);

            agregarFinal(a);

        }
    }
    archivo1.close();
}

 
#include "Videogame.h"
#include <fstream>
#include<algorithm>
videogame::videogame()
{
    
}
void videogame::agregarCivilizacion(const Civilizacion  &p)
{
    civilizaciones.push_back(p);
    
}
void videogame::setNombre_usuario(const string &v)
{
    nombre_usuario=v;
}
string videogame::getNombre_usuario()
{
    return nombre_usuario;
}
void videogame::mostrar()
{
    cout << left ;
    cout <<setw(12)<<"Nombre";
    cout <<setw(13)<<"ubicacion x";
    cout <<setw(13)<<"ubicacion y";
    cout <<setw(13)<<"puntuacion";
    cout <<endl;
    for(size_t i=0;i<civilizaciones.size(); i ++){
        Civilizacion &p=civilizaciones[i];
        cout <<p;
       
    }
}
Civilizacion videogame::primero()
{
    return civilizaciones.front();
}
Civilizacion videogame::ultimo()
{
    return civilizaciones.back();
}

void videogame::respaldar_tabla()
{
     
    ofstream archivo("civilizaciones_tabla.txt");
    if(archivo.is_open()){
        archivo << left ;
        archivo <<setw(12)<<"Nombre";
        archivo <<setw(13)<<"ubicacion en x";
        archivo <<setw(13)<<"ubicacion en y";
        archivo <<setw(13)<<"puntuacion";
        archivo <<endl;
        
        for(size_t i=0;i<civilizaciones.size(); i ++){
                Civilizacion &p=civilizaciones[i];
                archivo <<p;
        }
}
archivo.close();
}


void videogame::insertar(const Civilizacion&p, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos,p);
}
size_t videogame::total()
{
    return civilizaciones.size();
}

void videogame::inicializar(const Civilizacion&p,size_t n)
{
    civilizaciones=vector<Civilizacion>(n, p);
}
 Civilizacion* videogame::eliminar(const Civilizacion &p)
{
    auto it =find(civilizaciones.begin(),civilizaciones.end(),p);
    if(it == civilizaciones.end()){
        return nullptr;
    }
    else
    {
        civilizaciones.erase(it);
        return 0;
    }
    
}
void videogame::ordenar_nombre()
{
   sort(civilizaciones.begin(),civilizaciones.end());
   
}
void videogame::ordenarUbicacion_x()
{
    sort(civilizaciones.begin(),civilizaciones.end(),[]( Civilizacion p1, Civilizacion p2)
    {return p1.getX()> p2.getX();});
}
void videogame::ordenarUbicacion_y()
{
    sort(civilizaciones.begin(),civilizaciones.end(),[]( Civilizacion p1, Civilizacion p2)
    {return p1.getY()> p2.getY();});
}
void videogame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(),civilizaciones.end(),[]( Civilizacion p1, Civilizacion p2)
    {return p1.getPuntuacion()< p2.getPuntuacion();});
}
    


Civilizacion*videogame::buscar(const Civilizacion &p)
{
    auto it = find(civilizaciones.begin(),civilizaciones.end(), p);
    if(it ==civilizaciones.end()){
        return nullptr;
    }
    else
    {
        return &(*it);
    }
    
}
void videogame::respaldar()
{
    ofstream archivo("civilizaciones.txt", ios::out);

    for (int i = 0; i < civilizaciones.size(); ++i) {
        Civilizacion &c = civilizaciones[i];
        archivo << c.getNombre() << endl;
        c.respaldar_aldeanos();
        archivo << c.getX() << endl;
        archivo << c.getY() << endl;
        archivo << c.getPuntuacion() << endl;
    }
    archivo.close();
}

void videogame::recuperar(){
    ifstream archivo("civilizaciones.txt");
    if(archivo.is_open()){
        string temp;
        string aux;
        double ubicacion;
        float puntuacion;
        
        while(true){
            
            Civilizacion c;

            getline(archivo,temp);//nombre
            if(archivo.eof()){ break;}
            c.setNombre(temp);
            aux = temp + ".txt";
            c.recuperar_aldeanos(aux);

            getline(archivo,temp);//ubicacionX
            ubicacion = stod(temp);
            c.setX(ubicacion);

            getline(archivo,temp);//ubicacionY
            ubicacion = stod(temp);
            c.setY(ubicacion);

            getline(archivo,temp);//puntuacion
            puntuacion = stof(temp);
            c.setPuntuacion(puntuacion);

            agregarCivilizacion(c);
            aux = "";
        }

    }
    archivo.close();

}
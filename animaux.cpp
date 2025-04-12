#include <iostream>
#include <vector>


#include "animaux.hpp"
//#include "game.hpp"
#include "constants.hpp"



using namespace std;

/*
_________________________________CLASSE ANIMAL____________________________________________

*/

Animal::Animal(coords coord, double probReproduction, Population *p):_id{-1}, _coords{coord}, _alive{true},
_probReproduction{probReproduction}, _p {p}
{
    
}

coords Animal::get_coord() const{
    return _coords;
    
}

Population* Animal::getPopulation() const{
    return _p;
    
}

int Animal::get_id() const{
    return _id;
    
}

bool Animal::isAlive() const{
    return _alive;
    
}

void Animal::setId(int id){
    _id = id;
}


/*
_________________________________CLASSE LAPIN_____________________________________________

*/

Lapin::Lapin(coords coord, double probReproduction, Population *p, int id): Animal(coord, probReproduction, p)
{
    setId(id);
}

void Lapin::afficheAnimal() const{
    cout << "Lapin (Id " << get_id() << " )" << endl;
    cout << "Coordonnees : " << get_coord() << endl;
    cout << "Population : " << getPopulation()->get_name() << endl;
}

void Lapin::reproduce() const{
    cout << "Lapin " << get_id() << " essaie de se reproduire." << endl;
    // a completer
    
}

/*
_________________________________CLASSE RENARD____________________________________________

*/

Renard::Renard(coords coord, double probReproduction, Population *p, int id): Animal(coord, probReproduction, p), _hunger{FOODINIT}
{
    setId(id);
}

void Renard::reproduce() const{
     cout << "Renard " << get_id() << " essaie de se reproduire." << endl;
    // a completer
}

/*
_________________________________CLASSE POPULATION________________________________________

*/



Population::Population(string name):_name{name}, _animaux{} { }

/*
A revoir (systeme d'attribution naif)
*/



int Population::reserve() const{
    
    if (getNbIndividus() == 0) return 1; // id numero 1 si la population est vide
    else{
        int res = _animaux[0]->get_id();
        for(Animal *i: _animaux) if (res > i->get_id()) res = i->get_id();
        return res + 1;
        
    }
    
}

string Population::get_name() const{
    return _name;
    
}

int Population::getNbIndividus() const{ return _animaux.size();}

int Population::getNbLapins() const{

    int res = 0;
    for(Animal *i: _animaux) if(dynamic_cast<Lapin*>(i)) res++;
    return res;
    
}

int Population::getNbRenards() const{

    int res = 0;
    for(Animal *i: _animaux) if(dynamic_cast<Renard*>(i)) res++;
    return res;
    
}

void Population::set(Animal *a){

    for(Animal *i: _animaux){
        if(i->get_id() == a->get_id()) throw invalid_argument("Cet animal est deja dans la population.");

    }
    if(dynamic_cast<Lapin*>(a)) cout << "Ajoute lapin a la population " << get_name() << endl;
    if(dynamic_cast<Renard*>(a)) cout << "Ajoute renard a la population " << get_name() << endl;
    _animaux.push_back(a);
    
}


void Population::getAnimal(int id) const{
    for(Animal *i: _animaux){
        if(i->get_id() == id){
            i->afficheAnimal();
        }
    }
    cout << "Cet animal n'existe pas dans la population." << endl;
}


void Population::affichePopulation() const{
    cout << "Population: " << get_name() << endl;
    for(Animal *i: _animaux){
        if(dynamic_cast<Lapin*>(i)){
            cout << "\tLapin (Id " << i->get_id() << " )" << endl;
        }
        if(dynamic_cast<Renard*>(i)){
            cout << "\tRenard (Id " << i->get_id() << " )" << endl;
        }

    }
    
}

Population::~Population(){
    
    for (Animal* a : _animaux) {
            delete a;
        }
    }
    

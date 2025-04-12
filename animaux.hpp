#ifndef ANIMAUX
#define ANIMAUX

#include <vector>

#include "coords.hpp"

enum class direction {n, s, e, w, ne, nw, se, sw};
enum class typeAnimal {lapin, renard};

class Population;
// classe abstraite
class Animal {

    public:
        Animal() = delete;
        Animal(coords coord, double probReproduction, Population *p);
        void deplacement(direction d);
        virtual void reproduce() const = 0;
        virtual void afficheAnimal() const = 0;
        coords get_coord() const;
        Population* getPopulation() const;
        int get_id() const;
        bool isAlive() const;
        void meurt();
        void setId(int id);

    private:
        int _id;
        coords _coords;
        bool _alive;
        double _probReproduction;
        Population *_p;

};

class Lapin: public Animal {
    using Animal::Animal;

    public:
        Lapin() = delete;
        Lapin(coords coord, double probReproduction, Population *p, int id);
        void afficheAnimal() const override;
        void reproduce() const override;
};

class Renard: public Animal {
    using Animal::Animal;

    public:
        Renard() = delete;
        Renard(coords coord, double probReproduction, Population *p, int id);
        void afficheAnimal() const override;
        void reproduce() const override;
        void mangeLapin(int idLapin) const;
    private:
        int _hunger;
};

class Population {
    public:
        Population() = delete;
        Population(std::string name);
        ~Population();
        std::string get_name() const;
        int getNbIndividus() const;
        int getNbLapins() const;
        int getNbRenards() const;
        void getAnimal(int id) const;
        void affichePopulation() const;
        int reserve() const;
        void set(Animal* a);
        void supprime(int id);

    private:
        std::string _name;
        std::vector<Animal*> _animaux;
};

#endif

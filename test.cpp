#include <iostream>

#include "animaux.hpp"
//#include "game.hpp"
#include "constants.hpp"
#include "coords.hpp"

using namespace std;

int main(){
    srand(time(NULL));
    
    Population p("MyPopulation");
    p.affichePopulation();
    int id1 = p.reserve();
    
    Lapin a1(coords {9, 25}, 0.32, &p, id1);
    p.set(&a1);
    //p.getAnimal(id1)->reproduce();
    /*
    int id2 = p.reserve();
    Lapin a2(coords {9, 25}, 0.32, &p, id2);
    p.set(a2);
    int id3 = p.reserve();
    Renard a3(coords {9, 25}, 0.12, &p, id3);
    p.set(a3);
    int id4 = p.reserve();
    Renard a4(coords {9, 25}, 0.12, &p, id4);
    p.set(a4);
    int id5 = p.reserve();
    Renard a5(coords {9, 25}, 0.12, &p, id5);
    p.set(a5);
    */
    p.affichePopulation();
    
    return 0;
}
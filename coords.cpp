#include<sstream>
#include "coords.hpp"
using namespace std;

coords::coords(int a, int b): x{a}, y{b}
{ 
    if(a<0) x = -a;
    if(b<0) x = -b;

}

int coords::getX() const {return x;}

int coords::getY() const {return y;}

bool coords::operator==(const coords &b) const{
    return (x==b.x && y==b.y);
}

bool coords::operator<(const coords &b) const{
    if(y>= b.y) return false;
    else if(y== b.y && x>= b.x) return false;
    else return true;
}

std::ostream& operator<<(std::ostream& out, const coords &c){
    out << "(" << c.x << "," << c.y << ")";
    return out;
    
}
#ifndef COORDS
#define COORDS

#include<sstream>

class coords {
    public:
        coords() = delete;
        coords(int a, int b);
        int getX() const;
        int getY() const;
        bool operator==(const coords &b) const;
        bool operator<(const coords &b) const;
        friend std::ostream& operator<<(std::ostream& out, const coords &c);
    private:
        int x;
        int y;
};

#endif
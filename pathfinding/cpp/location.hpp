#ifndef LOCATION_HPP
#define LOCATION_HPP

struct Location
{
    int x;
    int y;

    Location() : x(0), y(0) {}
    Location(int posx, int posy) : x(posx), y(posy) {}
    
    bool operator== (const Location& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
};


#endif 
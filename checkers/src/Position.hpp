#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

struct Position {
    int x, y;
    Position() : x(0), y(0) {};
    Position(int setX, int setY) : x(setX), y(setY) {};

    bool isValid() {
        if (x >= 0 && x <= 7 && y >=0 && y <= 7) return true;
        else return false;
    }

    bool isLastRow(bool isUser) {
        if ((isUser && y == 7) || (!isUser && y == 0)) return true;
        else return false;
    }

    bool operator==(Position &p) {
        if (x == p.x && y == p.y) return true;
        else return false;
    }

    bool operator!=(Position &p) {
        if (x != p.x || y != p.y) return true;
        else return false;
    }

};

inline bool operator==( const Position &a, const Position &b ){
    if (a.x == b.x && a.y == b.y) return true;
    return false;
}

#endif // POSITION_HPP

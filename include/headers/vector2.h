#pragma once

class vector2{
public:
    vector2(){}
    vector2(double x, double y) {
        this->x = x;
        this->y = y;
    }

    vector2 operator*(double k){
        return vector2(x*k, y*k);
    }

    vector2 operator+(vector2 b){
        return vector2(x+b.x, y+b.y);
    }

    vector2 operator-(vector2 b){
        return vector2(x-b.x, y-b.y);
    }

    double x;
    double y;
};
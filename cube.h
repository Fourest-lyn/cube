//
// Created by Fourest on 2020/12/31.
//

#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H

#include "block.h"

//enum Direction{_x,_y,_z};

using std::string;

class Cube
{

private:
    std::map<Position,Block> blocks;

    Cube& operator*=(const Matrix&);
    Cube operator*(const Matrix &);

    bool validRotate(char);
    void R(bool);
    void L(bool);
    void U(bool);
    void D(bool);
    void F(bool);
    void B(bool);
    void E(bool);
    void M(bool);
    void S(bool);

public:
    Cube() =default;
    Cube(const string &);
    ~Cube(){}

    void multiRotate(const string&);
    void display();

};


#endif //CUBE_CUBE_H

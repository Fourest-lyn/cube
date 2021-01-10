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

    bool validRotate(char);
    Cube& operator*=(const Matrix&);


public:
    Cube() =default;
    Cube(const string &);
    Cube operator*(const Matrix &);

//Operators.
    void multiRotate(const string&);
    void R(bool);
    void L(bool);
    void U(bool);
    void D(bool);
    void F(bool);
    void B(bool);
    void E(bool);
    void M(bool);
    void S(bool);
    //void M(bool, Direction);
/*
    void r(bool);
    void l(bool);
    void u(bool);
    void d(bool);
    void f(bool);
    void b(bool);

    void x(bool);
    void y(bool);
    void z(bool);*/

//    void turn(int,int,int,bool);

    ~Cube();

};


#endif //CUBE_CUBE_H

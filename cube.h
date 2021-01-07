//
// Created by Fourest on 2020/12/31.
//

#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H

#include "Block.h"

//enum Direction{_x,_y,_z};

class Cube
{
    RotationBlock *cube[3][3][3];

public:
    Cube()=default;

//Operators.
    void cycle(std::string str);
    void R(bool);
    void L(bool);
    void U(bool);
    void D(bool);
    void F(bool);
    void B(bool);
    void M(bool, Direction);

    void r(bool);
    void l(bool);
    void u(bool);
    void d(bool);
    void f(bool);
    void b(bool);

    void x(bool);
    void y(bool);
    void z(bool);


    void turn(int,int,int,bool);

};


#endif //CUBE_CUBE_H

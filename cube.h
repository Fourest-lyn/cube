//
// Created by Fourest on 2020/12/31.
//

#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H

#include "block.h"

//enum direction{_x,_y,_z};

class cube
{
    block *blo[3][3][3];

public:
    cube()=default;

//Operators.
    void cycle(std::string str);
    void R(bool);
    void L(bool);
    void U(bool);
    void D(bool);
    void F(bool);
    void B(bool);
    void M(bool,direction);

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

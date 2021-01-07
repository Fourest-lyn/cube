//
// Created by Fourest on 2020/12/31.
//

#include "cube.h"

void cube::R(bool dir=true)
{
    block *temp;
    temp=blo[1+1][1+1][1+1];
    for(int i=0;i<9;i+=3)
    {

    }

    temp=blo[0+1][1+1][1+1];
    for(int i=0;i<9;i+=3)
    {

    }
}

void cube::L(bool dir=true)
{
}

void cube::U(bool dir=true)
{

}

void cube::D(bool dir=true)
{

}

void cube::F(bool dir=true)
{

}

void cube::B(bool dir=true)
{

}

void cube::M(bool dir=true,direction point=_x)
{

}

void cube::r(bool dir=true)
{
    R(dir);
    M(dir);
}

void cube::l(bool dir=true)
{
    L(dir);
    M(!dir);
}

void cube::u(bool dir=true)
{
    U(dir);
    M(dir,_y);
}

void cube::d(bool dir=true)
{
    D(dir);
    M(!dir,_y);
}

void cube::f(bool dir=true)
{
    F(dir);
    M(dir,_z);
}

void cube::b(bool dir=true)
{
    B(dir);
    M(!dir,_z);
}

void cube::x(bool dir=true)
{
    r(dir);
    L(!dir);
}

void cube::z(bool dir=true)
{
    f(dir);
    B(!dir);
}

void cube::y(bool dir=true)
{
    u(dir);
    D(!dir);
}

void cube::turn(int x,int y,int z,bool dir)
{

}



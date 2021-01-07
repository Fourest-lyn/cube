//
// Created by Fourest on 2020/12/31.
//

#include "Cube.h"

void Cube::R(bool dir=true)
{
    Block *temp;
    temp=cube[1 + 1][1 + 1][1 + 1];
    for(int i=0;i<9;i+=3)
    {

    }

    temp=cube[0 + 1][1 + 1][1 + 1];
    for(int i=0;i<9;i+=3)
    {

    }
}

void Cube::L(bool dir=true)
{
}

void Cube::U(bool dir=true)
{

}

void Cube::D(bool dir=true)
{

}

void Cube::F(bool dir=true)
{

}

void Cube::B(bool dir=true)
{

}

void Cube::M(bool dir=true, Direction point=_x)
{

}

void Cube::r(bool dir=true)
{
    R(dir);
    M(dir);
}

void Cube::l(bool dir=true)
{
    L(dir);
    M(!dir);
}

void Cube::u(bool dir=true)
{
    U(dir);
    M(dir,_y);
}

void Cube::d(bool dir=true)
{
    D(dir);
    M(!dir,_y);
}

void Cube::f(bool dir=true)
{
    F(dir);
    M(dir,_z);
}

void Cube::b(bool dir=true)
{
    B(dir);
    M(!dir,_z);
}

void Cube::x(bool dir=true)
{
    r(dir);
    L(!dir);
}

void Cube::z(bool dir=true)
{
    f(dir);
    B(!dir);
}

void Cube::y(bool dir=true)
{
    u(dir);
    D(!dir);
}

void Cube::turn(int x, int y, int z, bool dir)
{

}

void Cube::cycle(std::string str)
{

}



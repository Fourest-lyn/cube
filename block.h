//
// Created by Fourest on 2020/12/31.
//


/*
 * The middle of the cube's position is (0,0,0).
 */

#ifndef CUBE_BLOCK_H
#define CUBE_BLOCK_H

#include <unordered_set>

enum colour{orange=0,white=1,blue=2,green=3,yellow=4,red=5};
enum direction{x_pos,x_neg,y_pos,y_neg,z_pos,z_neg};

//Errors:
class WrongPlace{};
class WrongColour{};
class WrongKind{};

//This class is defined to describe a coloured paper.
class paper
{
    colour col;

};

class block
{
protected:
    int x,y,z;


public:
    block(int xx,int yy,int zz):x(xx),y(yy),z(zz){}

    virtual bool check() =0;

    virtual ~block()= default;

    virtual void TurnDirection()=0;
};



class corner: public block
{
    std::unordered_set<colour> col;
    const static int num=3;

public:
    corner(int xx,int yy,int zz,std::initializer_list<colour> il);

    virtual bool check() override;

};



class edge: public block
{
    std::unordered_set<colour> col;
    const static int num=2;

public:
    edge(int xx,int yy,int zz,std::initializer_list<colour> il);

    virtual bool check() override;
};



class middle: public block
{
    std::unordered_set<colour> col;
    const static int num=1;

public:
    middle(int xx,int yy,int zz,std::initializer_list<colour> il);

    virtual bool check() override;
};

#endif //CUBE_BLOCK_H

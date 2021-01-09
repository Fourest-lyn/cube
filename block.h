//
// Created by Fourest on 2020/12/31.
//


/*
 * The Middle of the Cube's position is (0,0,0).
 */

#ifndef CUBE_BLOCK_H
#define CUBE_BLOCK_H

#include <unordered_set>
#include <cassert>
#include <map>
#include "error.h"
#include <initializer_list>
#include <iostream>

//Fourest: Declare classes here.
class Matrix;
class BaseType;
class Paper;
class Block;



class BaseType
{
    friend Matrix;
//    friend std::istream &operator>>(std::istream &,BaseType &);

private:
    int x,y,z;

public:
    BaseType(int x=0,int y=0,int z=0):x(x),y(y),z(z){}

    bool operator ==(BaseType &base) {return x==base.x && y==base.y && z==base.z;}
    bool operator !=(BaseType &base) {return !((*this)==base);}
    int ToInteger() const {return x*1+y*3+z*9;}
};


//only has 6 different possible value:
//(1,0,0) (-1,0,0) (0,1,0) (0,-1,0) (0,0,1) (0,0,-1)
typedef BaseType Direction;


//only has 7 different possible value, include no colour:
//(1,0,0) (-1,0,0) (0,1,0) (0,-1,0) (0,0,1) (0,0,-1) (0,0,0)
//orange  red      white   yellow   green   blue     black
typedef BaseType Colour;
const Colour orange(1,0,0),red(-1,0,0);
const Colour white(0,1,0),yellow(0,-1,0);
const Colour blue(0,0,1),green(0,0,-1);
const Colour black(0,0,0);
enum ColourNumber {ORANGE=1,RED=6,WHITE=2,YELLOW=5,BLUE=3,GREEN=4,BLACK=0};



//Fourest: This class is used for define a rotation Matrix.
class Matrix
{

private:
    enum AXIS {_x=0,_y=1,_z=2};
    int a[3][3]={0};
    int Layer;//-1,0,1 Question: when should "Layer" be used? It decides whether to rotate a block.

public:
    Matrix(const Direction &,const int &);

    BaseType operator *(const BaseType &);
    Paper operator *(const Paper &);
    Block operator *(const Block &);
};



//This class is defined to describe a coloured Paper.
class Paper
{
    friend Block;
    friend Matrix;
//    friend std::istream &operator >>(std::istream &,Paper &);

private:
    const Colour col;
    Direction dir;

public:
    Paper(Direction _dir,Colour _col=Colour(0,0,0)):dir(_dir),col(_col){}
    Colour colour(){return col;}
    Direction direction(){return dir;}
};

enum BlockKind {Corner=3,Edge=2,Middle=1,Inside=0};

//This class is defined to describe a real block that has 6 paper and can translate and rotate.
class Block
{
    friend Matrix;
//    friend std::istream &operator >>(std::istream &,Block &);

private:
    BaseType position;
    std::map<Direction,Paper> papers;
    BlockKind kind=Inside;

public:
    //todo: To complete the construct function.
    Block(const BaseType &,std::initializer_list<Paper>);
    Colour CheckColour(Direction _dir) {return papers[_dir].col;}


};


#endif //CUBE_BLOCK_H

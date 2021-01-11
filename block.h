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
//#include <initializer_list>
#include <iostream>
#include <vector>

//Fourest: Declare classes here.
class Matrix;
class BaseType;
class Paper;
class Block;

namespace Private
{

}


class BaseType
{
    friend Matrix;

private:
    int x=0,y=0,z=0;

public:
    BaseType() =default;
    BaseType(int);
    BaseType(int,int,int);

    bool operator< (const BaseType &) const;
    operator int() const {return x*9+y*3+z*1;}
};


//This type could describe a block's position in a MagicCube.
//Elements in this type can only be -1 or 0 or 1.
typedef BaseType Position;


/*
 * This type describe a paper's direction by declare the position of the block
 * that in the middle of the surface it belongs.
 * This type only has 6 different possible value.
 * (1,0,0) (-1,0,0) (0,1,0) (0,-1,0) (0,0,1) (0,0,-1)
 */
typedef BaseType Direction;


//This type describe the colours that a paper can have.
//This type only has 7 different possible value, include NoColour(=Black).
typedef BaseType Colour;
const Colour orange(1,0,0),red(-1,0,0);
const Colour white(0,1,0),yellow(0,-1,0);
const Colour blue(0,0,1),green(0,0,-1);
const Colour black(0,0,0);
enum ColourNumber {ORANGE=9,RED=-9,WHITE=3,YELLOW=-3,BLUE=1,GREEN=-1,BLACK=0};



//This class is used for define a rotation Matrix.
class Matrix
{

private:
    enum AXIS {_x=0,_y=1,_z=2};
    int a[3][3]={0};

    //The "Layer" decides which layer of the cube is processed by the "Matrix".
    int Layer=0;
    AXIS direction;

public:
    Matrix(const Direction &,const int &);

    int direct() const{return direction;}
    int layer() const{return Layer;}
    BaseType operator *(const BaseType &) const;
    Paper operator *(const Paper &) const;
    Block operator *(const Block &) const;
};



//This class is defined to describe a coloured Paper that paste on one surface of a block.
class Paper
{
    friend Block;
    friend Matrix;

private:
    const Colour col;
    Direction dir;

public:
    Paper(const Direction &,const Colour &);
    Colour colour() const {return col;}
    Direction direction() const {return dir;}
};

//This enum describe how many papers can the block have.
enum BlockKind {Corner=3,Edge=2,Middle=1,Inside=0};

//This class is defined to describe a real block that has 6 papers.
class Block
{
    friend Matrix;

private:
    Position position;
    std::map<Direction,Paper> papers;
    BlockKind kind=Inside;

public:
    Block(const Position &,const std::vector<Paper> &);
    Block(const Block &){}

    Colour CheckColour(const Direction &_dir) {return papers[_dir].col;}
    bool operator <(const Block &) const;
};


#endif //CUBE_BLOCK_H
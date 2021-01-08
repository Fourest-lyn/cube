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

private:
    int x,y,z;

public:
    BaseType(int x=0,int y=0,int z=0):x(x),y(y),z(z){}

    bool operator ==(BaseType &base) {return x==base.x && y==base.y && z==base.z;}
    bool operator !=(BaseType &base) {return !((*this)==base);}
};


//only has 6 different possible value:
//(1,0,0) (-1,0,0) (0,1,0) (0,-1,0) (0,0,1) (0,0,-1)
typedef BaseType Direction;

//only has 7 different possible value, include no colour:
//(1,0,0) (-1,0,0) (0,1,0) (0,-1,0) (0,0,1) (0,0,-1) (0,0,0)
//orange  red      white   yellow   green   blue     black
typedef BaseType Colour;
//enum  _colour {orange,red,white,yellow,green,blue,black};


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

private:
    BaseType position;
    std::map<Direction,Paper> papers;
    BlockKind kind=Inside;

public:
    //todo: To complete the construct function.
    Block(const BaseType &,std::initializer_list<Paper>);
    Colour CheckColour(Direction _dir) {return papers[_dir].col;}


};

/*
class Block {
protected:
    int x, y, z;


public:
    Block(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {}

    virtual bool check() = 0;

    virtual ~Block() = default;

    virtual void TurnDirection() = 0;
};



class Corner : public Block {
    std::unordered_set<Colour> col;
    const static int num = 3;

public:
    Corner(int xx, int yy, int zz, std::initializer_list<Colour> il);

    virtual bool check() override;

};


class Edge : public Block {
    std::unordered_set<Colour> col;
    const static int num = 2;

public:
    Edge(int xx, int yy, int zz, std::initializer_list<Colour> il);

    virtual bool check() override;
};


class Middle : public Block {
    std::unordered_set<Colour> col;
    const static int num = 1;

public:
    Middle(int xx, int yy, int zz, std::initializer_list<Colour> il);

    virtual bool check() override;
};
*/

#endif //CUBE_BLOCK_H

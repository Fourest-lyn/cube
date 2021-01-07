//
// Created by Fourest on 2020/12/31.
//


/*
 * The Middle of the Cube's position is (0,0,0).
 */

#ifndef CUBE_BLOCK_H
#define CUBE_BLOCK_H

#include <unordered_set>
#include<cassert>

class BaseType
{
friend Matrix;
public:
    BaseType(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
private:
    int x,y,z;
};

//only has 6 different possible value
typedef BaseType Direction;

//only has 7 different possible value, include no colour
typedef BaseType Colour;

//Fourest: This class is used for define a rotation matrix.
class Matrix
{
public:
    Matrix(Direction,int);
private:
    int a[3][3];
//    Direction direction;
    int UpDown;//-1,0,1 Question: when should "UpDown" be used? It decides whether to rotate a block.
};
/*
class BaseBlock
{
public:
    BaseBlock(const BaseType &blockDirection):block_direction(blockDirection){};

    BaseBlock(int x=0,int y=0,int z=0):block_direction(x,y,z){};

    friend BaseBlock operator*(const Matrix &matrix,const BaseBlock &baseBlock)
    {

    };

    friend BaseBlock operator*(const BaseBlock &baseBlock,const Matrix &matrix)
    {
        return matrix*baseBlock;
    };
private:
    BaseType block_position;

};
*/

/*enum Colour {
    orange = 0, white = 1, blue = 2, green = 3, yellow = 4, red = 5
};*/

//Errors:
class WrongPlace{};

class WrongColour{};

class WrongKind{};

//This class is defined to describe a coloured Paper.
class Paper
{
private:
    Colour col;
    Direction direction;
};

//This class is defined to describe a real block that has 6 paper and can translate and rotate.
class RotationBlock
{
public:
    friend RotationBlock operator*(const Matrix &matrix,const RotationBlock &rotationBlock)
    {

    };

    friend RotationBlock operator*(const RotationBlock &rotationBlock,const Matrix &matrix)
    {
        return matrix*rotationBlock;
    };
private:
    BaseBlock block;
    Paper paper0,paper1,paper2,paper3,paper4,paper5;//FIXME This isn't a good idea.It can't represent these papers' quality.
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

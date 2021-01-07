//
// Created by Fourest on 2020/12/31.
//

#include "block.h"

//Corner blocks.
/*

Corner::Corner(int xx,int yy,int zz,std::initializer_list<Colour> il): Block(xx, yy, zz)
{
    if(il.size()!=num) throw WrongKind();
    if(x!=-1 || x!=1 && y!=1 || y!=-1 && z!=1 || z!=-1) throw WrongPlace();
    auto it=il.begin();
    while(it!=il.end())
    {
        if(col.find(*it)==col.end()) throw WrongColour();
        col.insert(*it);
    }
}

bool Corner::check()
{
    if(col.size()!=num) throw WrongKind();
    if(x!=-1 || x!=1 && y!=1 || y!=-1 && z!=1 || z!=-1) throw WrongPlace();
    return true;
}

//Edge blocks.

Edge::Edge(int xx,int yy,int zz,std::initializer_list<Colour> il): Block(xx, yy, zz)
{
    if(il.size()!=num) throw WrongKind();
    if(!((x==0 && y!=0 && z!=0) || (x!=0 && y==0 && z!=0) || (x!=0 && y!=0 && z==0))) throw WrongPlace();
    auto it=il.begin();
    while(it!=il.end())
    {
        if(col.find(*it)==col.end()) throw WrongColour();
        col.insert(*it);
    }

}

bool Edge::check()
{
    if(col.size()!=num) throw WrongKind();
    if(!((x==0 && y!=0 && z!=0) || (x!=0 && y==0 && z!=0) || (x!=0 && y!=0 && z==0))) throw WrongPlace();
    return true;
}

//Middle blocks.

Middle::Middle(int xx,int yy,int zz,std::initializer_list<Colour> il): Block(xx, yy, zz)
{
    if(il.size()!=num) throw WrongKind();
    if(!((x==0 && y==0 && z!=0) || (x!=0 && y==0 && z==0) || (x==0 && y!=0 && z==0))) throw WrongPlace();
    auto it=il.begin();
    while(it!=il.end())
    {
        if(col.find(*it)==col.end()) throw WrongColour();
        col.insert(*it);
    }

}

bool Middle::check()
{
    if(col.size()!=num) throw WrongKind();
    if(!((x==0 && y==0 && z!=0) || (x!=0 && y==0 && z==0) || (x==0 && y!=0 && z==0))) throw WrongPlace();
    return true;
}

*/

Matrix::Matrix(Direction,int)
{
    //todo:
}

Block operator*(const Matrix &,const Block &)
{
    //todo:
    return Block();
}

Block operator*(const Block &,const Matrix &)
{
    //todo:
    return Block();
}


Paper operator*(const Paper &,const Matrix &)
{
    //todo:
    return Paper(BaseType());
}

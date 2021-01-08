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

Matrix::Matrix(const Direction & _dir,const int & _layer):Layer(_layer)
{
    if(_dir.x!=0)
    {
        a[_x][_x]=1;
        a[_y][_z]=-_dir.x; a[_z][_y]=_dir.x;
    }
    if(_dir.y!=0)
    {
        a[_y][_y]=1;
        a[_z][_x]=-_dir.y; a[_x][_z]=_dir.y;
    }
    if(_dir.z!=0)
    {
        a[_z][_z]=1;
        a[_x][_y]=-_dir.z; a[_y][_x]=_dir.z;
    }
}

BaseType Matrix::operator*(const BaseType & _base)
{
    BaseType temp;
    temp.x=a[_x][_x]*_base.x+a[_x][_y]*_base.y+a[_x][_z]*_base.z;
    temp.y=a[_y][_x]*_base.x+a[_y][_y]*_base.y+a[_y][_z]*_base.z;
    temp.z=a[_z][_x]*_base.x+a[_z][_y]*_base.y+a[_z][_z]*_base.z;
    return temp;
}

Paper Matrix::operator*(const Paper &_paper)
{
    Paper temp(_paper);
    temp.dir=(*this)*temp.dir;
    return temp;
}

Block Matrix::operator*(const Block &_block)
{
    Block temp(_block);

    std::map<Direction,Paper> NewPapers;
    auto it=temp.papers.begin();
    while(it!=temp.papers.end())
    {
        Paper TempPaper=(*this)*it->second;
        NewPapers.insert({TempPaper.dir,TempPaper});
        ++it;
    }
    temp.papers=NewPapers;
    temp.position=(*this)*temp.position;
    return temp;
}


Block::Block(const BaseType & _pos,std::initializer_list<Paper> il):position(_pos)
{
    int num=0;
    Colour standard(0,0,0);
    if(il.size()>6) throw Error(WrongKind);
    auto it=il.begin();
    while(it!=il.end())
    {
        if(it->col!=standard) ++num;//fixme: This position is wrong?
        papers.insert({it->dir,*it});
        ++it;
    }
    if(num>3) throw Error(WrongKind);
    kind=BlockKind(num);
}





















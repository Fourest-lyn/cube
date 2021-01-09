//
// Created by Fourest on 2020/12/31.
//

#include "block.h"

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
        if(it->col.ToInteger()!=0) ++num;//fixme: Are the codes here wrong?
        papers.insert({it->dir,*it});
        ++it;
    }
    if(num>3) throw Error(WrongKind);
    kind=BlockKind(num);
}

//std::istream &operator>>(std::istream &is,BaseType &_base)
//{
//    is>>_base.x>>_base.y>>_base.z;
//    return is;
//}


//std::istream &operator>>(std::istream &is,Paper &_paper)
//{
//    is>>_paper.dir;
//
//    return is;
//}

//std::istream &operator>>(std::istream &is,Block &_block)
//{
//    return is;
//}














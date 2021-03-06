
//
// Created by Fourest on 2020/12/31.
//

#include "block.h"

Matrix::Matrix(const Direction & _dir,const int & _layer):Layer(_layer)
{
    if(_layer>1 || _layer<-1) throw Error(WrongConstruct);
    if(_dir.x!=0)
    {
        a[_x][_x]=1;
        a[_y][_z]=-_dir.x; a[_z][_y]=_dir.x;
        direction=_x;
    }
    if(_dir.y!=0)
    {
        a[_y][_y]=1;
        a[_z][_x]=-_dir.y; a[_x][_z]=_dir.y;
        direction=_y;
    }
    if(_dir.z!=0)
    {
        a[_z][_z]=1;
        a[_x][_y]=-_dir.z; a[_y][_x]=_dir.z;
        direction=_z;
    }
}

BaseType Matrix::operator*(const BaseType & _base) const
{
    BaseType temp;
    temp.x=a[_x][_x]*_base.x+a[_x][_y]*_base.y+a[_x][_z]*_base.z;
    temp.y=a[_y][_x]*_base.x+a[_y][_y]*_base.y+a[_y][_z]*_base.z;
    temp.z=a[_z][_x]*_base.x+a[_z][_y]*_base.y+a[_z][_z]*_base.z;
    return temp;
}

Paper Matrix::operator*(const Paper &_paper) const
{
    Paper temp(_paper);
    temp.dir=(*this)*temp.dir;
    return temp;
}

Block Matrix::operator*(const Block &_block) const
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


Block::Block(const Position & _pos,const std::vector<Paper> &vt):position(_pos)
{
    int num=0;
    if(vt.size()!=6) throw Error(WrongConstruct);
    auto it=vt.begin();
    while(it!=vt.end())
    {
        if(int(it->col)!=0) ++num;
        papers.insert({it->dir,*it});
        ++it;
    }
    if(num>3) throw Error(WrongConstruct);
    kind=BlockKind(num);
}

bool Block::operator<(const Block &_block) const
{
    return position<_block.position;
}


BaseType::BaseType(int _x,int _y,int _z):x(_x),y(_y),z(_z)
{
    if(x>1 || x<-1 || y>1 || y<-1 || z>1 || z<-1) throw Error(WrongConstruct);
}

BaseType::BaseType(int _base)
{
    if(_base>13 || _base<-13) throw Error(WrongConstruct);
    _base+=13;
    x=_base%3-1;
    _base/=3;
    y=_base%3-1;
    _base/=3;
    z=_base-1;
}

bool BaseType::operator<(const BaseType &_base) const
{
    return int(*this)<int(_base);
    return false;
}


Paper::Paper(const Direction &_dir,const Colour &_col=Colour()):dir(_dir),col(_col){}

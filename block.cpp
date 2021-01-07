//
// Created by Fourest on 2020/12/31.
//

#include "block.h"

//Corner blocks.

corner::corner(int xx,int yy,int zz,std::initializer_list<colour> il):block(xx,yy,zz)
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

bool corner::check()
{
    if(col.size()!=num) throw WrongKind();
    if(x!=-1 || x!=1 && y!=1 || y!=-1 && z!=1 || z!=-1) throw WrongPlace();
    return true;
}

//Edge blocks.

edge::edge(int xx,int yy,int zz,std::initializer_list<colour> il):block(xx,yy,zz)
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

bool edge::check()
{
    if(col.size()!=num) throw WrongKind();
    if(!((x==0 && y!=0 && z!=0) || (x!=0 && y==0 && z!=0) || (x!=0 && y!=0 && z==0))) throw WrongPlace();
    return true;
}

//Middle blocks.

middle::middle(int xx,int yy,int zz,std::initializer_list<colour> il):block(xx,yy,zz)
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

bool middle::check()
{
    if(col.size()!=num) throw WrongKind();
    if(!((x==0 && y==0 && z!=0) || (x!=0 && y==0 && z==0) || (x==0 && y!=0 && z==0))) throw WrongPlace();
    return true;
}


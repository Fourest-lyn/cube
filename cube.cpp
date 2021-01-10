//
// Created by Fourest on 2020/12/31.
//

#include "cube.h"

void Cube::R(bool dir=true)
{
    Matrix mat((-1,0,0),1);




//    if(dir) *this *= Matrix((0, -1, 0), -1);//注意：这些矩阵可能是有问题的！根据矩阵的定义而变。
//    else *this *= Matrix((0, -1, 0), -1);
}

void Cube::L(bool dir=true)
{
    *this*=Matrix((0,-1,0),-1);
}

void Cube::U(bool dir=true)
{

}

void Cube::D(bool dir=true)
{

}

void Cube::F(bool dir=true)
{

}

void Cube::B(bool dir=true)
{

}

void Cube::E(bool dir=true)
{

}

void Cube::M(bool dir=true)
{

}

void Cube::S(bool dir=true)
{

}
/*
void Cube::M(bool dir = true, Direction point = _x) {

}*/
/*

void Cube::r(bool dir = true) {
    R(dir);
    M(dir);
}

void Cube::l(bool dir = true) {
    L(dir);
    M(!dir);
}

void Cube::u(bool dir = true) {
    U(dir);
    M(dir, _y);
}

void Cube::d(bool dir = true) {
    D(dir);
    M(!dir, _y);
}

void Cube::f(bool dir = true) {
    F(dir);
    M(dir, _z);
}

void Cube::b(bool dir = true) {
    B(dir);
    M(!dir, _z);
}

void Cube::x(bool dir = true) {
    r(dir);
    L(!dir);
}

void Cube::z(bool dir = true) {
    f(dir);
    B(!dir);
}

void Cube::y(bool dir = true) {
    u(dir);
    D(!dir);
}
*/

Cube &Cube::operator*=(const Matrix &_mat)
{
    *this=(*this)*_mat;
    return *this;
}

bool Cube::validRotate(char c)
{
    return c=='R' || c=='L' || c=='U' ||
           c=='D' || c=='F' || c=='B' ||
           c=='E' || c=='M' || c=='S' ||
           c=='r' || c=='l' || c=='u' ||
           c=='d' || c=='f' || c=='b' ||
           c=='x' || c=='y' || c=='z';
}

void Cube::multiRotate(const string &str)
{
    if(str.length()==0) return;
    if(str.length()==1)
    {
        char c=str[0];
        if(!validRotate(c)) throw Error("WrongString");
        switch(c)
        {
            case 'R':
                R();
                break;//重载*=？
            case 'L':
                L();
                break;
            case 'U':
                U();
                break;
            case 'D':
                D();
                break;
            case 'F':
                F();
                break;
            case 'B':
                B();
                break;
            case 'E':
                E();
                break;
            case 'M':
                M();
                break;
            case 'S':
                S();
                break;
            case 'r':
                R();
                M();
                break;
            case 'l':
                L();
                M();
                break;
            case 'u':
                U();
                E();
                break;
            case 'd':
                D();
                E();
                break;
            case 'f':
                F();
                S();
                break;
            case 'b':
                B();
                S();
                break;
            case 'x':
                //FIXME
                break;
            case 'y':
                //FIXME
                break;
            case 'z':
                //FIXME
                break;
            default :
                assert(false);
        }
    }
    if(str[1]=='2')
    {
        const string s=str.substr(0,1);
        multiRotate(s);
        multiRotate(s);
        multiRotate(str.substr(2));

    }
    if(str[1]=='\'')
    {
        const string s=str.substr(0,1);
        multiRotate(s);
        multiRotate(s);
        multiRotate(s);
        //sjm is too lazy. fix this later.
        multiRotate(str.substr(2));
    }
    multiRotate(str.substr(1));
}

Cube Cube::operator*(const Matrix &_mat)
{
    Cube temp,&sub=*this;
    int x=0,y=0,z=0,*i,*j;

    if(_mat.direct()==0)
    {
        i=&y;
        j=&z;
        x=_mat.layer();
    }
    if(_mat.direct()==1)
    {
        i=&z;
        j=&x;
        y=_mat.layer();
    }
    if(_mat.direct()==2)
    {
        i=&x;
        j=&y;
        z=_mat.layer();
    }

    for(*i=-1; *i<=1; ++(*i))
        for(*j=-1; *j<=1; ++(*j))
        {
            Position pos(x,y,z);
            temp.blocks[pos]=_mat*sub.blocks[pos];
        }
    return temp;
}

Cube::Cube(const string & str)
{
    /*auto intChanger = [](int x)->int{
        if (x<0 || x>6) throw Error(WrongString);
        switch (x){
        case 0:
            return int(BaseType(0,0,0));
        case 1:
            return int(BaseType())
        }
    };*/
    //enum ColourNumber {ORANGE=9,RED=-9,WHITE=3,YELLOW=-3,BLUE=1,GREEN=-1,BLACK=0};
    const int BTNum[7] = {0,9,-9,3,-3,1,-1};//Be careful:black is 0!
    if (str.size() >= 27*7-1) throw Error(WrongString);//I'm mercy.You can end with anything.I don't care.You can also use " " to cut string.
    for (int iblock = 0; iblock < 27; ++iblock) {
        int list[7];
        for (int jpaper = 0; jpaper <= 5; ++jpaper) {
            int charnum = str[iblock * 7 + jpaper] - '0';
            if (charnum < 0 || charnum > 6) throw Error(WrongString);
            list[jpaper] = BTNum[charnum];
        }
        blocks[iblock] = Block(iblock - 13,
                               {Paper(BTNum[1], list[0]), Paper(BTNum[2], list[1]), Paper(BTNum[3], list[2]),
                                Paper(BTNum[4], list[3]), Paper(BTNum[5], list[4]),
                                Paper(BTNum[6], list[5])});
    }
}






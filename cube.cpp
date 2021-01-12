//
// Created by Fourest on 2020/12/31.
//

#include "cube.h"

void Cube::R(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((-direct,0,0),1);
}

void Cube::L(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((direct,0,0),-1);
}

void Cube::U(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((0,-direct,0),1);
}

void Cube::D(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((0,direct,0),-1);
}

void Cube::F(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((0,0,-direct),1);
}

void Cube::B(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((0,0,direct),-1);
}

void Cube::E(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((0,direct,0),0);
}

void Cube::M(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((direct,0,0),0);
}

void Cube::S(bool dir=true)
{
    int direct=dir?1:-1;
    *this*=Matrix((0,0,-direct),0);
}


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
            case 'R': R(); break;
            case 'L': L(); break;
            case 'U': U(); break;
            case 'D': D(); break;
            case 'F': F(); break;
            case 'B': B(); break;
            case 'E': E(); break;
            case 'M': M(); break;
            case 'S': S(); break;
            case 'r': R(); M(false); break;
            case 'l': L(); M(); break;
            case 'u': U(); E(false); break;
            case 'd': D(); E(); break;
            case 'f': F(); S(); break;
            case 'b': B(); S(false); break;
            case 'x': R(); M(false); L(false); break;
            case 'y': U(); E(false); D(false); break;
            case 'z': F(); S(); B(false); break;
            default :
                assert(false);
        }
    }
    const string s=str.substr(0,1);
    multiRotate(s);
    if(str.length()>1 && str[1]=='2')
    {
        multiRotate(s);
        multiRotate(str.substr(2));
    }
    else if(str.length()>1 && str[1]=='\'')
    {
        multiRotate(s);
        multiRotate(s);
        //sjm is too lazy. fix this later.
        multiRotate(str.substr(2));
    }
    else multiRotate(str.substr(1));
}

Cube Cube::operator*(const Matrix &_mat)
{
    Cube temp=*this,&sub=*this;
    int layer=_mat.layer(),dir=_mat.direct();
    int x=layer,y=layer,z=layer,*i,*j;

    if(_mat.direct()==0) {i=&y; j=&z;}
    if(_mat.direct()==1) {i=&z; j=&x;}
    if(_mat.direct()==2) {i=&x; j=&y;}

    for(*i=-1; *i<=1; ++(*i))
        for(*j=-1; *j<=1; ++(*j))
        {
            Position pos(x,y,z);
            temp.blocks[pos]=_mat*sub.blocks[pos];
        }
    return temp;
}

Cube::Cube(const string &str)
{
    //enum ColourNumber {ORANGE=9,RED=-9,WHITE=3,YELLOW=-3,BLUE=1,GREEN=-1,BLACK=0};
    const int BTNum[7]={0,9,-9,3,-3,1,-1};//Be careful:black is 0!
    if(str.size()>=27*7-1) throw Error(WrongString);//I'm mercy.You can end with anything.I don't care.You can also use " " to cut string.
    for(int iBlock=0; iBlock<27; ++iBlock)
    {
        int list[7];
        for(int jPaper=0; jPaper<=5; ++jPaper)
        {
            int charNum=str[iBlock*7+jPaper]-'0';
            if(charNum<0 || charNum>6) throw Error(WrongString);
            list[jPaper]=BTNum[charNum];
        }
        std::vector<Paper> vt;
        for(int i=0;i<6;++i) vt.push_back(Paper(BTNum[i+1],list[i]));
        blocks[iBlock]=Block(iBlock-13,vt);
    }
}

Cube::operator string()const{
    const int BTNum[7]={0,9,-9,3,-3,1,-1};//Be careful:black is 0!
    const map<int,string> BTMap = {{0,"0"},{9,"1"},{-9,"2"},{3,"3"},{-3,"4"},{1,"5"},{-1,"6"}};
    string str;
    for(int iBlock=0; iBlock<27; ++iBlock)
    {
        for(int jPaper=0; jPaper<=5; ++jPaper)
        {
            try{
                str += BTMap.at(blocks.at(Position(iBlock)).CheckColour(BTNum[jPaper + 1]));
            } catch(std::out_of_range){
                throw Error("WrongConstruct");
            }
        }
        str += ' ';
    }
}

void Cube::display()
{
    //todo: To complete this function. The function is used for showing the present
    //      situation of the MagicCube. If possible, we should show the cube in colourful picture.
}







#include "othello16.h"
#include <assert.h>

const int othello16::direction[8][2]={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
const int othello16::MAXN = 16;

#define ASSERTCOLOR(color) assert(0<=color && color<=2)
#define ASSERTUSERCOLOR(color) assert(0<color && color<=2)
#define ASSERTRANGE(x,y) assert(0<=x && x<MAXN && 0<=y && y<MAXN)

void othello16::set(int color, int x, int y)
{
    ASSERTRANGE(x,y);
    this->map[x][y]=color;
}

void othello16::init()
{
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++)
            this->map[i][j]=0;
    mycolor = 0;
}

void othello16::init(int color, string s)
{
    assert(s.size()==MAXN*MAXN);
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++)
            this->map[i][j]=s[i*MAXN+j]-'0';
    mycolor = color;
}

int othello16::count(int color)
{
    int cnt = 0;
    ASSERTCOLOR(color);
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++)
            cnt += this->map[i][j]==color;
    return cnt;
}

bool othello16::is(int color, int x, int y)
{
    ASSERTRANGE(x,y);
    ASSERTCOLOR(color);
    return color==this->map[x][y];
}

bool othello16::canmove(int color, int x, int y)
{
    ASSERTRANGE(x,y);
    ASSERTUSERCOLOR(color);
    if(this->map[x][y]!=0)
        return false;
    for(int k=0; k<8; k++)///8 direction
    {
        int i=x,j=y,r=false;
        do{
            i+=direction[k][0],j+=direction[k][1];
            if((3^color) == this->map[i][j])
                r=true;
            else if(r==true && color == this->map[i][j])
                return r;
            else
                break;
        }while(0<=i&&i<MAXN && 0<=j&&j<MAXN);
    }
    return false;
}

bool othello16::canmove(int color)
{
    ASSERTUSERCOLOR(color);
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++)
            if(canmove(color,i,j))
                return true;
    return false;
}

vector<pair<int, int> > othello16::allmove(int color)
{
    ASSERTUSERCOLOR(color);
    vector<pair<int, int> > vec;
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++)
            if(canmove(color, i, j))
                vec.push_back(make_pair(i,j));
    return vec;
}

bool othello16::play(int turn, int &x, int &y)///confuse why use reference
{
    ASSERTUSERCOLOR(turn);
    ASSERTRANGE(x,y);
    bool cm=false;///canmove
    if(this->map[x][y])
        return cm;
    for(int k=0; k<8; k++)
    {
        int i=x,j=y,r=0;
        do{
            i+=direction[k][0],j+=direction[k][1];
            if((3^turn) == this->map[i][j])
                r=1;
            else if(r==1 && turn == this->map[i][j])
            {
                r=2;
                break;
            }
            else
                break;
        }while(0<=i&&i<MAXN && 0<=j&&j<MAXN);
        if(r==2)
        {
            do{
                i-=direction[k][0],y-=direction[k][0];
                this->map[i][j] = turn;
            }while(i!=x && j!=y);
            cm=true;
        }
    }
    return cm;
}

string othello16::tostring()
{
    string s;
    for(int i=0;i<MAXN;i++)
        for(int j;j<MAXN;j++)
            s.push_back(this->map[i][j]+'0');
    return s;
}

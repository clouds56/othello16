#include "othello16.h"
#include "gamti.h"
#include <iostream>
#include <assert.h>

#if defined _T_DEBUG || defined _RELEASE
struct othello16x:public othello16
{
    bool play(int turn, const int &x, const int &y);
};
struct othello_ai
{
    othello16x o;
    void init(int color, string s);
    void move(int color, int x, int y);
    pair<int, int> get();
};
#else
#ifdef _AI1
#include "../ai1.cpp"
#endif // _AI1
#ifdef _AI2
#include "../ai2.cpp"
#endif // AI2
#endif // defined

using namespace std;

ostream &operator<<(ostream&o,othello16&a)
{
    const char c[3]={'.','O','X'};
    string s=a.tostring();
    for(int i=0;i<16;i++,o<<endl)
        for(int j=0;j<16;j++)
            o<<c[s[i*16+j]-'0'];
    return o;
}

ostream &printall(ostream&o,vector<pair<int,int> >vec)
{
    o<<"All:"<<vec.size()<<endl;
    for(vector<pair<int,int> >::iterator it=vec.begin(); it!=vec.end(); it++)
    {
        o<<it->first<<','<<it->second<<'\t';
        if((it-vec.begin())%5==4 && (vec.end()-it)!=1)
            o<<endl;
    }
    return o;
}

int main()
{
    pair<int,int> pt;
    int color,turn;
    string s;
    othello_ai ai;
#ifdef _RELEASE
    othello_ai ai2;
#endif // _RELEASE
    othello16 o;
    //cout<<"color,turn,string>";
    //cin>>color>>turn>>s;
    o.init();
    turn=1,color=1,s=o.tostring();
#ifdef _AI1
    color=1;
    o.init(1,s);
#endif // _AI1
#ifdef _AI2
    color=2;
    o.init(2,s);
#endif // _AI2
    //o.init(color, s);
    ai.init(color, s);
#ifdef _RELEASE
    ai2.init(3^color,s);
#endif // _RELEASE
    while(true)
    {
        if(o.canmove(turn))
        {
            int x,y;
            if(turn == color)
            {
                cerr<<"----------------------------"<<endl;
                reset_time();
                pt=ai.get();
                cerr<<"----------------------------"<<endl
                    <<"Time: "<<get_time()<<endl;
                x=pt.first,y=pt.second;
                cerr<<"Return: "<<x<<','<<y<<endl;
                cout<<x<<' '<<y<<endl;
            }else{
#ifndef _RELEASE
                vector<pair<int,int> >vec=o.allmove(turn);
                printall(cerr<<"============================"<<endl,vec)<<endl<<'>';
#ifndef _T_DEBUG
                cin>>x>>y;
                cerr<<"Get: "<<x<<','<<y<<endl;
#else
                unsigned ch;
                cin>>ch;
                x=vec[ch].first,y=vec[ch].second;
                assert(0<=ch && ch<vec.size());
                cout<<x<<' '<<y<<endl;
#endif // _T_DEBUG
#else
                cerr<<"****************************"<<endl;
                reset_time();
                pt=ai2.get();
                cerr<<"****************************"<<endl
                    <<"Time usage:"<<get_time()<<endl;
                x=pt.first,y=pt.second;
                cerr<<"Return value:"<<x<<','<<y<<endl;
                cout<<x<<' '<<y<<endl;
#endif // _RELEASE
            }
            o.play(turn,x,y);
            ai.move(turn,x,y);
#ifdef _RELEASE
            ai2.move(turn,x,y);
#endif
            assert(ai.o.tostring()==o.tostring());
            cerr<<256-o.count(0)<<"->"<<o.count(1)<<":"<<o.count(2)<<endl<<o.tostring()<<endl<<o;
        }else if(!o.canmove(3^turn)){
            break;
        }
        turn=3^turn;
    }
    return 0;
}

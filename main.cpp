#include "othello16.h"
#include "gamti.h"
#include <iostream>
#include <assert.h>

using namespace std;

class othello_ai
{
    public:
    othello16 o;//ÊµÀý»¯othello16Àà

    void init(int color, string s);
    void move(int color, int x, int y);
    pair<int, int> get();
};

ostream &operator<<(ostream&o,othello16&a)
{
    const char c[3]={'.','O','X'};
    string s=a.tostring();
    for(int i=0;i<16;i++,o<<endl)
        for(int j=0;j<16;j++)
            o<<c[s[i*16+j]-'0'];
    return o;
}

int main()
{
    pair<int,int> pt;
    int color;
    string s;
    othello_ai ai;
    othello16 o;
    cin>>color>>s;
    o.init();
    o.init(color, s);
    ai.init(color, s);
    int turn = color;
    while(true)
    {
        if(o.canmove(turn))
        {
            int x,y;
            if(turn == color)
            {
                reset_time();
                pt=ai.get();
                x=pt.first,y=pt.second;
                cout<<x<<' '<<y<<endl;
            }else{
                cin>>x>>y;
            }
            o.play(turn,x,y);
            ai.move(turn,x,y);
            assert(ai.o.tostring()==o.tostring());
            cerr<<o.tostring()<<endl<<o<<endl;
        }else if(!o.canmove(3^turn)){
            break;
        }
        turn=3^turn;
    }
    return 0;
}

#include "Gun.h"

int main(){
    Gun g1(30, "ak47", 2.5f, true);
    Gun g2(30, "m4a4", 3.5f, true);
    Gun g3;
    Gun g4;

    g1++;
    cout<<g1<<endl;

    ++g2;
    cout<<g2<<endl;

    g1--;
    cout<<g1<<endl;

    --g2;
    cout<<g2<<endl;
    bool isEqual = g1 == g2;
    bool isNotEqual = g1 != g2;

    cout<<isEqual<<endl<<isNotEqual<<endl<<endl;

    g1 *= 2;
    cout<<g1<<endl;
    g1 * 2;
    cout<<g1<<endl;
    g1 /=2;
    cout<<g1<<endl;
    g1/2;
    cout<<g1<<endl;

    g1+=g2;
    cout<<g1<<endl;

    g3 = g2;
    cout<<g3<<endl;

    g2 + g1;
    cout<<g2<<endl;

    g3[35];
    cout<<g3<<endl;

    cin>>g4;
    cout<<g4<<endl;

    return 0;
}


#include <iostream>
using namespace std;
void serieDeNumeros(int a, int b){
    if(a<b){
        cout<<a<<", ";
        serieDeNumeros(a+1, b);
    }
}
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    serieDeNumeros(a,b);
    return 0;
}

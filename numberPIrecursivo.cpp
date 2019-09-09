#include <iostream>
#include <cmath>
using namespace std;

float aproxPIrecursivo(int k, int n){
    float aprox = 4*((pow(-1,k))/(2*k + 1));
    if(n>0){
        if(k%2 != 0)
            return aprox + aproxPIrecursivo(k+1, n-1);
        return aprox + aproxPIrecursivo(k+1, n-1);
    }
    return aprox;
}
int main()
{
    int k, n;
    cout<<"ingrese k ";cin>>k;
    cout<<"ingrese n: ";cin>>n;
    cout<<"la aproximacion es: "<<aproxPIrecursivo(k,n);
    return 0;
}

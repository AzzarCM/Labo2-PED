#include <iostream>
#include <cmath>
using namespace std;

float aproxPIrecursivo(int k, int n){
    //variable auxiliar que me ira acumulando el resultado
    float aprox = 4*((pow(-1,k))/(2*k + 1));
    if(n>0){
        return aprox + aproxPIrecursivo(k+1, n-1);
    }
    return aprox;
}
int main()
{
    //k es desde donde inicia la sumatoria
    int k = 0;
    int n;
    cout<<"ingrese un numero (hasta donde llegara la sumatoria): ";cin>>n;
    cout<<"la aproximacion es del numero PI es: "<<aproxPIrecursivo(k,n);
    return 0;
}

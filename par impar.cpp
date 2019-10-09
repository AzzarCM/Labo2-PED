#include <iostream>
#include <string>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio;

class listaEnlazada{
    public:
        listaEnlazada(){
            inicio = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }
        
        void agregarNodo(int valor){
            Nodo *n = crearNodo(valor), *temp;
            if(!inicio)
                inicio = n;
            else{
                for(temp=inicio; temp->sig; temp = temp->sig);
                temp->sig = n;
            }
        }
        void mostrarLista(){
            Nodo* temp = inicio;
            if(!inicio)
                cout<<"Lista Vacia"<<endl;
            else
                while(temp){
                    cout<<temp->dato<<", ";
                    temp = temp->sig;
                }
        }
        int sumarElementos(Nodo *temp, int &pares, int &impares){
            if(!temp){
                return 0;
            }
            else{
                if(temp->dato%2==0){
                    pares += temp->dato;
                    return sumarElementos(temp->sig, pares, impares);
                }else{
                    impares += temp->dato;
                    return sumarElementos(temp->sig, pares, impares);
                }
                
            }
        }
        int recibirDatos(listaEnlazada *s, int& pares, int &impares){
            return sumarElementos(inicio, pares, impares);
        }
};

int main()
{
    int par, impar =0;
    listaEnlazada l1;
    l1.agregarNodo(3);
    l1.agregarNodo(3);
    l1.agregarNodo(3);
    l1.agregarNodo(5);
    l1.agregarNodo(1);
    l1.agregarNodo(2);
    l1.agregarNodo(8);
    l1.agregarNodo(4);
    l1.mostrarLista();
    l1.recibirDatos(&l1,par,impar);
    cout<<impar;
    cout<<par;
    
}

#include <iostream>
#include <string>

using namespace std;

struct Nodo{
    string titulo;
    int numPaginas;
    Nodo *sig;
}*pilanicio, *fin;


class Pila{
    public:
        Pila(){
            pilanicio=nullptr;
        }
        Nodo* crearNodo(int paginas,string titulo){
            Nodo *n = new Nodo;
            n->titulo = titulo;
            n->numPaginas = paginas;
            n->sig = nullptr;
            return n;
        }
        void push(int paginas, string titulo){
            Nodo *n = crearNodo(paginas, titulo);
            n->sig = pilanicio;
            pilanicio = n;
        }
        void pop(){
            Nodo *temp = pilanicio;
            pilanicio = pilanicio->sig;
            free(temp);
        }
        void mostrarPila(){
            Nodo *temp = pilanicio;
            if(!pilanicio)
                cout << "Pila vacia" << endl;
            else
                while(temp){
                    cout << temp->titulo << ",";
                    temp = temp->sig;
                }
        }
        int paginas(Nodo *temp, string libro){
            if(!temp){
                return 0;
            }
            else{
                if(temp->titulo == libro)
                    return temp->numPaginas;
                return paginas(temp->sig, libro);
            }
        }
        
        int auxiliar(Pila *s, string libro){
            return paginas(pilanicio, libro);
        }

};

int main()
{
    Pila c;
    c.push(1, "hola");
    c.push(2, "hola2");
    c.push(3, "hola3");
    cout << "Cola"<<endl;
    c.mostrarPila();
    cout << c.auxiliar(&c, "hola3");
    cout << endl;
    return 0;
}

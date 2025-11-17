#include <iostream>
#include <stack>
using namespace std;

void listarpila(stack<int> lista){
    if (lista.empty()){
        cout<<"la lista eesta vacia"<<endl<<endl;
    }
    while(!lista.empty()){
        cout<<lista.top()<<endl;
        lista.pop();
    }
    cout<<endl;
}


int main(){

        stack<int>pila;
        int opcion,valor;

        do{
                cout<<" 1 Añadir Elemento a la pila"<<endl<<endl;
                cout<<" 2 Quitar Elemento a la pila"<<endl<<endl;
                cout<<" 3 listar Elemento a la pila"<<endl<<endl;
                cout<<" 4 mostar elemento en la cima de la pila"<<endl<<endl;
                cout<<" 5 Salir"<<endl<<endl;
                cin>>opcion;
                switch(opcion){
                    case 1:
                        cout<<"ingrese un valor: "<<endl<<endl;
                        cin>>valor;
                        pila.push(valor);
                        cout<<" se añadio correctamente "<< valor <<"a la pila"<<endl<<endl;
                        break;
                    case 2:
                        if (pila.empty())
                            cout<<"la pila eesta vacia"<<endl<<endl;
                        else
                        cout<<" se quito el elemento:"<<pila.top()<<endl<<endl;
                        pila.pop();
                        break;
                    case 3:
                        listarpila(pila);

                        break;
                    case 4:
                        cout<<"elemento de la cima es :"  <<pila.top()<<endl<<endl;
                        
                        break;

                }
        }while(opcion !=5);
}
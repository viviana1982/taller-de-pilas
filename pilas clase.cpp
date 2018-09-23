#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte;
};

typedef struct nodo *puntero;
class pila{
public:
    pila(void);
    void apilar(int);
    int Desapilar(void);
    void Cima(void);
    bool pilaVacia(void);
    void mostrarPila(void);
    void destruirPila(void);

private:
    puntero cima;
};

pila::pila(void){
    cima=NULL;
}

bool pila::pilaVacia(void){
    if(cima==NULL){
        return true;
    }else{
        return false;
    }
}

void pila::apilar(int x){
    puntero p_aux;
    p_aux=new(struct nodo);
    p_aux->nro=x;
    p_aux->sgte=cima;
    cima=p_aux;
}
void pila::Cima(){
    int x;
    if(cima==NULL){
        cout<<"\n\n\tpilavacia...!";
    }else{
        x=cima->nro;
        cout<<"\n\tLa Cima es :"<<x<<endl;
    }
}

int pila::Desapilar(void){
    int x;
    puntero p_aux;
    if(cima==NULL){
        cout<<"\n\n\tpila vacia...!!";
    }else{
        p_aux=cima;
        x=p_aux->nro;
        cima=cima->sgte;
        delete(p_aux);
    }
    return x;
}

void pila::mostrarPila(void){
    puntero p_aux;
    p_aux=cima;

    while(p_aux!=NULL){
        cout<<"\t"<<p_aux->nro<<endl;
        p_aux=p_aux->sgte;
    }
}

void pila::destruirPila(void){
    puntero p_aux;

    while(cima!=NULL){
        p_aux=cima;
        cima=cima->sgte;
        delete(p_aux);
    }
}
void menu(void){
    cout<<"\t------------------------------------------\n";
    cout<<"\t|       IMPLEMENTACION DE UNA PILA        |\n";
    cout<<"\t------------------------------------------|\n";
    cout<<"\t|                                          |"<<endl;
    cout<<"\t|  1. APILAR                               |"<<endl;
    cout<<"\t|  2. DESAPILAR                            |"<<endl;
    cout<<"\t|  3. MOSTRAR PILA                         |"<<endl;
    cout<<"\t|  4. DESTRUIR PILA                        |"<<endl;
    cout<<"\t|  5. MOSTRAR CIMA                         |"<<endl;
    cout<<"\t|  6. SALIR                                |"<<endl;
    cout<<"\t|                                          |"<<endl;
    cout<<"\t------------------------------------------|\n";
    cout<<"\t ingrese opcion: ";
}

int main(void)
{
    system("color 0a");
    pila pila;
    int x;
    int op;
    do{
        menu(); cin>>op;
        switch(op)
        {
            case 1: cout<<"\n\t INGRESE NUMERO A PILAR: "; cin>> x;
            pila.apilar(x);
            cout<< "\n\n\t\tnumero " << x << " apilado...\n\n";
            break;

            case 2:
                if(pila.pilaVacia()==true){
                   cout << "\n\n\tpila Vacia....";
                }else{
                    x=pila.Desapilar();
                    cout<< "\n\n\t\tnumero " <<x<< " desapilado\n";
                }
                break;
            case 3:
                cout << "\n\n\t MOSTRANDO PILA \n\n";
                if(pila.pilaVacia()!=true)
                   pila.mostrarPila();
                else
                    cout << "\n\n\tpila Vacia.."<<endl;
                    break;

                case 4:
                    pila.destruirPila();
                    cout << "\n\n\tpila eliminada..";
                    break;
                case 5:
                    pila.Cima();
                    break;
        }
        cout<<endl<<endl;
        system("pause"); system("cls");

    }while(op!=6);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte;
};
void Apilar(nodo *&, int x);
int  Desapilar(nodo *&);
void MostrarPila(nodo *&);
void DestruirPila(nodo *&);
void menu();

int main()
{
    nodo *pila= NULL;
    pila;
    int x;
    int op;

    do{
            menu();
            scanf("%d",&op);



        switch(op)
        {
            case 1: printf("\n\t INGRESE EL NUMERO A APILAR: ");
            scanf("%d",&x);
            Apilar(pila, x);
            printf("\n\tIngrese otro dato: ");
            scanf("%d",&x);
            Apilar(pila, x);

            printf("\n\n\t\tnumero %d apilado.. \n\n");
            break;

           case 2: printf("\n\n\tnumero %d desapilado \n");
           Desapilar(pila);

            case 3: printf("mostrar el elemento de la pila \n\n");
            MostrarPila(pila);
            break;

            case 4: printf("sacar el elemento de la pila");
            DestruirPila(pila);

        }
        printf("\n");
        system("pause");
        system("cls");
    }while(op!=0);

    return 0;
}
void menu(){
    printf("\t------------------------------------------\n");
    printf("\t|         MENU PILA                      |\n");
    printf("\t-----------------------------------------|\n");
    printf("\t|                                        |\n");
    printf("\t|   1. APILAR                            |\n");
    printf("\t|   2. DESAPILAR                         |\n");
    printf("\t|   3. MOSTRAR PILA                      |\n");
    printf("\t|   4. DESTRUIR PILA                     |\n");
    printf("\t|   5. SALIR                             |\n");
    printf("\t|                                        |\n");
    printf("\t-----------------------------------------|\n");
    printf("\t ingrese opcion: ");


}

void Apilar(nodo *&pila, int x){

    nodo *p_aux;
    p_aux=new(struct nodo);
    p_aux->nro=x;
    p_aux->sgte=pila;
    pila=p_aux;
    printf("el dato %d se agrego a la pila ");

}
int Desapilar(nodo *&pila){
    int x;
    nodo *p_aux;
    if(pila==NULL){
        printf("\n\n\tpila vacia ");
    }else{
        p_aux=pila;
        x=p_aux->nro;
        pila=pila->sgte;
        delete(p_aux);
    }
    return x;

}

void MostrarPila(nodo *&pila){
    nodo *p_aux;
    p_aux = pila;

    while(p_aux !=NULL){
        printf("%d",p_aux->nro);
        p_aux=p_aux->sgte;
    }

}

void DestruirPila(nodo *&pila){
    nodo *p_aux;

    while(pila != NULL){
        p_aux=pila;
        pila=pila->sgte;
        delete(p_aux);
    }
}



#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<conio.h>

struct Nodo{
    int dato;

    struct Nodo *sig;
};

struct Nodo *Inicio = NULL;

void agregarValor(int valor){
    struct Nodo *nuevo;

    nuevo = malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->sig =NULL;

    if(Inicio == NULL){
        Inicio = nuevo;
    }else{
        struct Nodo *ultimo = Inicio;
        while(ultimo->sig!=NULL){
            ultimo = ultimo->sig;
        }
        ultimo->sig = nuevo;
    }
    puts("-----------------------------");
    puts("�Valor agregado con �xito!");
    puts("-----------------------------");
    system("pause");
}

void nodoMedio() {
    struct Nodo *tortuga = Inicio;
    struct Nodo *liebre = Inicio;

    if (Inicio == NULL) {
        printf("La lista est� vac�a.\n");
    } else {
        while (liebre != NULL && liebre->sig != NULL) {
            tortuga = tortuga->sig;
            liebre = liebre->sig->sig;
        }

        printf("Nodo medio: %d\n", tortuga->dato);
    }
    puts("--------------------------------------");
    system("pause");
}

verLista(){
    struct Nodo *actual = Inicio;

    if(actual == NULL){
        puts("�La lista est� vacia!");
        puts("---------------------");
    }else{
        puts("Lista Actual: ");
        while(actual!=NULL){
            printf("%d --> ",actual->dato);
            actual = actual->sig;
        }
        printf( "NULL\n\n" );
    }
    puts("--------------------------------------");
}

void Menu(){
    puts("Men�: \n");
    puts("1. Agregar n�mero");
    puts("2. Ver lista");
    puts("3. Salir");
    puts("-----------------");
    printf("Elegir opci�n: ");
}

int main()
{
    int op,op2,op3,valor;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    puts("CONSIGNA:\nEncontrar el nodo medio: Encuentra el nodo medio de una lista enlazada.\nSi la lista tiene un n�mero par de nodos, devuelve el segundo nodo del par medio");
    puts("--------------------------------------------------------------------------------");
    system("pause");

    do{
        system("cls");
        Menu();
        scanf("%d",&op);
        while(op>3 || op<1){
            puts("------------------------------------");
            puts("�Opci�n no valida, intente de nuevo!");
            puts("------------------------------------");
            printf("Elegir opci�n: ");
            scanf("%d",&op);
        }
        switch(op){
            case 1:
                do{
                    system("cls");
                    printf("Ingrese un valor entero: ");
                    scanf("%d",&valor);
                    agregarValor(valor);
                    system("cls");
                    puts("�Desea agregar otro valor?\n1.Si\n2.No");
                    puts("-----------------");
                    printf("Elegir opci�n: ");
                    scanf("%d",&op2);
                    while(op>2 || op<1){
                        puts("------------------------------------");
                        puts("�Opci�n no valida, intente de nuevo!");
                        puts("------------------------------------");
                        printf("Elegir opci�n: ");
                        scanf("%d",&op2);
                    }
                }while(op2!=2);
                break;
            case 2:
                system("cls");
                verLista();
                nodoMedio();
                break;
            case 3:
                system("cls");
                puts("�Est� seguro que desea salir?\n1.Si\n2.No");
                puts("-----------------");
                printf("Elegir opci�n: ");
                scanf("%d",&op3);
                while(op3>2 || op3<1){
                    puts("------------------------------------");
                    puts("�Opci�n no valida, intente de nuevo!");
                    puts("------------------------------------");
                    printf("Elegir opci�n: ");
                    scanf("%d",&op3);
                }
                switch(op3){
                case 1:
                    system("cls");
                    puts("Saliendo del programa...");
                    sleep(2);
                    break;
                case 2:
                    system("cls");
                    puts("Volviendo al men�...");
                    sleep(2);
                    op=1;
                    break;
                }
                break;
        }
    }while(op!=3);

    return 0;
}

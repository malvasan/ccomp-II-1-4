#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>

#define TAMANO      20
#define ARRIBA      72
#define ABAJO       80
#define IZQUIERDA   75
#define DERECHA     77

using namespace std;

void movimiento(int (*A)[4],int (*a)[4],int *B,int *b,int** ptr)
{
    int* temp_fila;
    int* temp_columna;
    int tecla=0;
    tecla=getch();
    if(tecla==ARRIBA){
        if(a==A)
            return;
        a--;
        b=b-4;
        B=*a;
    }
    if(tecla==ABAJO){
        if(a-A==3)
            return;
        a++;
        b=b+4;
        B=*a;
    }
}

int main()
{
    int arreglo[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
    int(* A)[4];
    int(* a)[4];
    int* B;
    int* b;
    A=arreglo;
    a=A;
    B=*arreglo;
    b=B;
    a=A+3;
    b=*a+3;
    for(int i=0;i<4;i++){
        for(int o=0;o<4;o++){
            cout<<*(*(arreglo+i)+o);
        }
        cout<<endl;
    }
    cout<<**a<<endl;
    cout<<*b<<endl;
    cout << "Hello world!" << endl;
    return 0;
}

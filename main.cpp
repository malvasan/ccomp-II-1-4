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

void movimiento(int (* &A)[4],int (* &a)[4],int * &B,int * &b,int tecla=0)
{
    int* temp_fila;
    int* temp_columna;
    int temp_valor=0;
    if(tecla==0)
        tecla=getch();
    if(tecla==ARRIBA){
        if(a==A){
            system("cls");
            return;
        }
        a--;
        temp_valor=*(b-4);
        *b=temp_valor;
        b=b-4;
        *b=0;
        B=*a;
    }
    if(tecla==ABAJO){
        if(a-A==3){
            system("cls");
            return;
        }
        a++;
        temp_valor=*(b+4);
        *b=temp_valor;
        b=b+4;
        *b=0;
        B=*a;
    }
    if(tecla==DERECHA){
        if(b-B==3){
            system("cls");
            return;
        }
        temp_valor=*(b+1);
        *b=temp_valor;
        b++;
        *b=0;
    }
    if(tecla==IZQUIERDA){
        if(b==B){
            system("cls");
            return;
        }
        temp_valor=*(b-1);
        *b=temp_valor;
        b--;
        *b=0;
    }
    system("cls");
}

void imprimir (int (*mat)[4])
{
    for(int i=0;i<4;i++){
            for(int o=0;o<4;o++){
                cout<<*(*(mat+i)+o)<<"    ";
            }
        cout<<endl;
    }
}

bool ganar(int (* &A)[4],int (* &a)[4],int * &B,int * &b,int (*mat)[4])
{
    int cont=1;
    if(b-B==3 && a-A==3){
        for(int i=0;i<4;i++){
            for(int o=0;o<4;o++){
                if(cont!=*(*(mat+i)+o))
                    return true;
                cont++;
                if(cont==16)
                    cont=0;
            }
    }
    return false;
    }
    return true;
}

int main()
{
    int arreglo[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
    int(* A)[4];
    int(* a)[4];
    int* B;
    int* b;
    bool seguir=true;
    A=arreglo;
    a=A;
    B=*(A+3);
    b=B;
    a=A+3;
    b=*a+3;
    movimiento(A,a,B,b,ARRIBA);
    movimiento(A,a,B,b,ARRIBA);
    movimiento(A,a,B,b,IZQUIERDA);
    movimiento(A,a,B,b,ARRIBA);
    imprimir(arreglo);
    while(seguir!=false){
        movimiento(A,a,B,b);
        imprimir(arreglo);
        seguir=ganar(A,a,B,b,arreglo);
        Sleep(70);
    }
}

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

void movimiento(int *a[4],int** ptr,int* ptr2)
{
    int temp_fila;
    int temp_columna;
    int tecla=0;
    tecla=getch();


}

int main()
{
    int a[4][4];
    int(* ptr)[4];
    int* ptr2;
    ptr=a+3;
    ptr2=*ptr+3;
    int temp=1;
    for(int i=0;i<4;i++){
        for(int o=0;o<4;o++){
            *(*(a+i)+o)=temp;
            temp++;
        }
    }
    *(*(a+3)+3)=0;
    for(int i=0;i<4;i++){
        for(int o=0;o<4;o++){
            cout<<*(*(a+i)+o);
        }
        cout<<endl;
    }
    cout<<**ptr<<endl;
    cout<<*ptr2<<endl;
    cout << "Hello world!" << endl;
    return 0;
}

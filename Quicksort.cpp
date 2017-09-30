#include <iostream>

using namespace std;

void intercambiar(int* x,int* y)
{
    int c =*x;
    *x=*y;
    *y=c;
}

void quicksort(int* pnt,int tam)
{
    int* in=pnt;
    int* fin=pnt+(tam-1);
    int* pivot=pnt+tam/2;
    while(pnt<fin)
    {
        if(*pnt<*pivot)
            pnt++;
        if(*fin>*pivot)
            fin--;
        else if(*pnt>=*pivot && *fin<=*pivot){
            intercambiar(pnt,fin);
            pnt++;
            fin--;
        }
        for(int i=0;i<tam;++i)
            cout<<*(in+i)<<" ";
        cout<<endl;
    }
    if(tam/2==1)
        return;

    quicksort(in,1+tam/2);
    quicksort(in+1+(tam/2),tam-tam/2-1);
}

int main()
{
    int arr[]={1,12,5,26,7,14,3,7,2};
    int tam=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<tam;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    quicksort(arr,tam);
    for(int i=0;i<tam;++i)
        cout<<arr[i]<<" ";
    return 0;
}

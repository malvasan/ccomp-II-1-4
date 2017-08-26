#include <iostream>

using namespace std;

class mes
{
    public:
        double dias;
        double semanas;
        mes(int dias_total=30)
        {
            dias=dias_total;
            semanas=dias_total/7;
        }
        void cambiar(int dia_especifico)
        {
            dias=dia_especifico;
        }
};

class ano
{
    public:
        mes meses[12];
		int anos;

        ano(int anio)
        {
            meses[0].cambiar(31);
            meses[2].cambiar(31);
            meses[4].cambiar(31);
            meses[6].cambiar(31);
            meses[7].cambiar(31);
            meses[9].cambiar(31);
            meses[11].cambiar(31);
            if(anio%4==0)
                meses[1].cambiar(29);
            else
                meses[1].cambiar(28);
        }


};

double cal_dias(int dia1,int mes1,int ano1,int dia2,int mes2,int ano2)
{
    ano primer(ano1);
    ano segundo(ano2);
    double dias_en_total=0;
    dias_en_total=primer.meses[mes1-1].dias-dia1;
    ++mes1;
    if(mes1==mes2 && ano1==ano2){
            dia1=dia2;
            dias_en_total+=dia2;
    }
    while(dia1!=dia2 || mes1 != mes2 || ano1!=ano2)
    {
        if (mes1>12){
            mes1=1;
            ano1++;
            if(ano1%4==0 && primer.anos%4!=0){
                dias_en_total++;
			}
			else if (primer.anos%4==0 && ano1%4!=0)
				--dias_en_total;
				
        }
        dias_en_total+=primer.meses[mes1-1].dias;
        mes1++;
        if(mes1==mes2 && ano1==ano2){
            dia1=dia2;
            dias_en_total+=dia2;
        }
		
    }
    return dias_en_total;
}

double cal_semanas(int dias)
{
    return dias/7;
}

double cal_meses(int dias)
{
    return dias/30.4;
}

double cal_ano(int dias)
{
    return dias/365;
}

double cal_horas(int dias)
{
    return dias*24;
}

double cal_min(int dias)
{
    return dias*1440;
}

long double cal_segundos(long double dias)
{
    return dias*86400;

}

void diferencia(int dia1,int mes1,int ano1,int dia2,int mes2,int ano2)
{

}


int main()
{
    cout << "Hello world!" << endl;
    int c=cal_dias(21,12,1980,26,8,2017);
    cout<<"DIAS: "<<++c<<endl;
    cout<<"SEMANAS: "<<cal_semanas(c)<<endl;
    cout<<"MESES: "<<cal_meses(c)<<endl;
    cout<<"ANOS: "<<cal_ano(c)<<endl;
	cout<<"SEGUNDOS: "<<c*86400<<endl;
	cout<<"MINUTOS: "<<c*1440<<endl;
	cout<<"HORAS: "<<c*24<<endl;
	
    return 0;
}

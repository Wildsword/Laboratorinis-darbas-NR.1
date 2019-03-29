#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cctype>
#include <stdio.h>
#include<limits>
#include<algorithm>

using namespace std;


int j, i, n, p, t=0, w=1, ats, c, g;
    double h[15];
    double med[15];
    double b[15];
    double o;
    double nd[15];
    string vardas[15], pavarde[15];


void duomenys ( )
{
        while (w==1)
        {
            j=0;
            cout<<"Studento varda ir pavarde :"<<endl;
            cin>>vardas[t]>>pavarde[t];
            cout<<"Iveskite visus gautus pazymius uz namu darbus. Jei pazymiu nebera, veskite <0> :"<<endl;

                    while(1)
                    {
                        cin>>nd[j];
                        while(cin.fail() || nd[j]>10)
                                {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout<<"Veskite is naujo"<<endl;
                                cin>>nd[j];
                                }
                        if(nd[j]==0)
                            break;
                        else
                        {
                            h[t]=h[t]+nd[j];
                            j++;
                        }
                    }

            if(j==0)
                h[t]=0;
            else
            h[t]=h[t]/j;
            cout<<"Iveskite pazymi uz egzamina :";
            cin>>nd[j+1];
            while(cin.fail() || nd[j+1]>10)
                    {
                    cin.clear();
                     cin.ignore(256,'\n');
                    cout<<"Veskite is naujo"<<endl;
                    cin>>nd[j+1];
                    }

            b[t]=nd[j+1]*0.6+h[t]*0.4;

            sort(nd, nd+j+1);


        g=j+1;
        if(g%2>0)
        {
            o=g;
            o=o/2+0.5;
            p=o;
            med[t]=nd[p];
        }
            else
            {

                o=g/2;
                p=o;
                med[t]=(nd[p]+nd[p+1])/2;
            }
            t++;
            cout<<" Ar norite testi? Veskite <1> jei taip. ";
            cin>>w;
        }


};


void lentele1()
{
    cout <<setw(15)<<left<<"Vardas " <<setw(15)<<left<<"Pavarde "<<setw(20)<<right<<"Galutinis balas "<< endl;
    cout.fill('-');
    cout.width(50);
    cout<<"-"<<endl;
    cout.fill(' ');
        for(i=0; i<t; i++)
            cout<<setw(15)<<left<<vardas[i]<<setw(15)<<left<<pavarde[i]<<setw(20)<<setprecision(3)<<right<<b[i]<<endl;
    cout.fill('-');
    cout.width(50);
    cout<<"-"<<endl;
};

void lentele2()
{
    cout <<setw(15)<<left<<"Vardas " <<setw(15)<<left<<"Pavarde "<<setw(15)<<right<<"Mediana "<< endl;
    cout.fill('-');
    cout.width(45);
    cout<<"-"<<endl;
    cout.fill(' ');
        for(i=0; i<t; i++)
            cout<<setw(15)<<left<<vardas[i]<<setw(15)<<left<<pavarde[i]<<setw(15)<<setprecision(3)<<right<<med[i]<<endl;
    cout.fill('-');
    cout.width(45);
    cout<<"-"<<endl;
}





int main()
{

    duomenys();
    cout<<"Iveskite <1> jei norite suzinoti vidurki arba <2> jei Mediana"<<endl;
    cin>>ats;
    if(ats == 1)
            lentele1();
        else
            lentele2();

    return 0;
}

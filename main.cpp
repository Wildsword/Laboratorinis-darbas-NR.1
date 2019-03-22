#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int j, i, k, n;
    double h[15];
    double E, nd;
    double b[15];
    string vardas[15], pavarde[15];

    cout<<"Iveskite studentu skaiciu :"<<endl;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Studento varda ir pavarde :"<<endl;
        cin>>vardas[i]>>pavarde[i];
        cout<<" Kiek namu darbu studentas atliko per laikotarpi?"<<endl;
        cin>>k;
        if(k>0)
        cout<<"Iveskite visus gautus pazymius uz namu darbus :"<<endl;
        for(j=0; j<k; j++)
        {
                cin>>nd;
                h[i]=h[i]+nd;
        }
        h[i]=h[i]/k;
        cout<<"Iveskite pazymi uz egzamina :";
        cin>>E;
        b[i]=(E+h[i])/2;
        t=(k+1)/2;
        if(t%2>0)
        {
            l=t+0.5;
        }
        else
            o=t+(t+1)

    }

    cout <<setw(15)<<left<<"Vardas " <<setw(15)<<left<<"Pavarde "<<setw(20)<<right<<"Galutinis balas "<< endl;
    cout.fill('-');
    cout.width(50);
    cout<<"-"<<endl;
    cout.fill(' ');
    for(i=0; i<n; i++)
        cout<<setw(15)<<left<<vardas[i]<<setw(15)<<left<<pavarde[i]<<setw(20)<<setprecision(3)<<right<<b[i]<<endl;

    return 0;
}

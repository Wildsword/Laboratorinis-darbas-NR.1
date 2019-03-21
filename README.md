# Namų darbas
---
## V 0.1

Pirmas įkėlimas

```cpp
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

---

#Antras įkėlimas

```cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int j, i, k, n, p, t;
    double h[15];
    double nd[15];
    double med[15];
    double b[15];
    double o;
    string vardas[15], pavarde[15];

    cout<<"Iveskite studentu skaiciu :"<<endl;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"Studento varda ir pavarde :"<<endl;
        cin>>vardas[i]>>pavarde[i];
        cout<<" Kiek namu darbu studentas atliko per laikotarpi?"<<endl;
        cin>>k;
        if(k>0)
        cout<<"Iveskite visus gautus pazymius uz namu darbus :"<<endl;
        for(j=1; j<=k; j++)
        {
                cin>>nd[j];
                h[i]=h[i]+nd[j];
        }
        h[i]=h[i]/k;
        cout<<"Iveskite pazymi uz egzamina :";
        cin>>nd[k+1];
        b[i]=(nd[k+1]+h[i])/2;
        t=k+1;

        if(t%2>0)
        {
            o=t/2+0.5;
            p=o;
            med[i]=nd[p];
        }
        else
        {
            o=t/2;
           p=o;
          med[i]=(nd[p]+nd[p+1])/2;
          cout<<p<<" "<<nd[p]<<" "<<nd[p+1]<<endl;
        }

    }

    cout <<setw(15)<<left<<"Vardas " <<setw(15)<<left<<"Pavarde "<<setw(20)<<right<<"Galutinis balas "<<setw(15)<<right<<"Mediana "<< endl;
    cout.fill('-');
    cout.width(65);
    cout<<"-"<<endl;
    cout.fill(' ');
    for(i=1; i<=n; i++)
        cout<<setw(15)<<left<<vardas[i]<<setw(15)<<left<<pavarde[i]<<setw(20)<<setprecision(3)<<right<<b[i]<<setw(15)<<setprecision(3)<<right<<med[i]<<endl;

    return 0;
}

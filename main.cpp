#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct student
{
    vector <int> nd;
    string vardas, pavarde;
    double mediana, balas;
};




int main()
{
    student a;
    vector<student>isvestis;
    int pazimys=1, suma=0, E, ats;
    string ArTesti={"y"};
    while(ArTesti=="y")
    {
        cout << "Áveskite studento varda ir pavarde: " << endl;
        cin>>a.vardas>>a.pavarde;
        cout<<"Veskite pazymius uz namu darbus. Kuomet noresite baigti, spauskite <0>"<<endl;
        pazimys=1;
        a.nd.clear();
        suma=0;
            while(pazimys!=0)
            {
                cin>>pazimys;
                    while(cin.fail() || pazimys>10 || pazimys <0)
                    {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout<<"Veskite is naujo"<<endl;
                    cin>>pazimys;
                    }
                a.nd.push_back(pazimys);
                suma=suma+pazimys;
            }
    a.nd.erase(a.nd.end()-1);
    cout<<"Koki pazymi gavo uz egzamina? "<<endl;
    cin>>E;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Veskite is naujo"<<endl;
        cin>>E;
    }

    else
        a.nd.push_back(E);

    a.balas=E*1.0*0.6+suma/(a.nd.size()-1)*1.0*0.4;

    sort(a.nd.begin(), a.nd.end());

    if(a.nd.size()%2==0)
    {
        a.mediana=(a.nd[a.nd.size()/2-1]+a.nd[a.nd.size()/2])/2;
    }
    else
        a.mediana=a.nd[a.nd.size()/2];

    cout<<a.vardas<<" "<<a.pavarde<<" "<<a.nd.size()<<" "<<suma<<" "<<a.balas<<" "<<a.mediana<<endl;

    cout<<"Jei norite testi, spauskite <y>. Noredami pereiti prie duomenu isvedimo spauskite <n>"<<endl;
    klausimas:
    cin>>ArTesti;
    if(ArTesti!="y" && ArTesti!="n")
    {
        cout<<"Tokio pasirinkimo nebuvo, veskite is naujo:"<<endl;
        goto klausimas;
    }
        isvestis.push_back(a);
    }

    cout<<"Iveskite <1> jei norite suzinoti galutini ivertinima arba <2> jei Mediana"<<endl;
    cin>>ats;
    if(ats == 1)
        {
    cout <<setw(15)<<left<<"Vardas " <<setw(15)<<left<<"Pavarde "<<setw(20)<<right<<"Galutinis balas "<< endl;
    cout.fill('-');
    cout.width(50);
    cout<<"-"<<endl;
    cout.fill(' ');
        //for(i=0; i<a.vardas.size(); i++)
        for (student x : isvestis)
            cout<<setw(15)<<left<<x.vardas<<setw(15)<<left<<x.pavarde<<setw(20)<<setprecision(3)<<right<<x.balas<<endl;
    cout.fill('-');
    cout.width(50);
    cout<<"-"<<endl;
        }
        else
            {
    cout <<setw(15)<<left<<"Vardas " <<setw(15)<<left<<"Pavarde "<<setw(15)<<right<<"Mediana "<< endl;
    cout.fill('-');
    cout.width(45);
    cout<<"-"<<endl;
    cout.fill(' ');
        //for(i=0; i<a.vardas.size(); i++)
        for (student x : isvestis)
            cout<<setw(15)<<left<<x.vardas<<setw(15)<<left<<x.pavarde<<setw(15)<<setprecision(3)<<right<<x.mediana<<endl;
    cout.fill('-');
    cout.width(45);
    cout<<"-"<<endl;
}

    return 0;
}

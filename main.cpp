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
    int pazymys=1, suma=0, E, i, ats, sk;
    string ArTesti={"y"};
    string pasirinkimas1, pasirinkimas2, eilute;

    cout<<"Noredami svieziu skaiciu, spauskite <y>, noredami juos nuskaityti is failo, spauskite <n>"<<endl;
    klausimas:
    cin>>pasirinkimas1;
     if(pasirinkimas1!="y" && pasirinkimas1!="n")
    {
        cout<<"Tokio pasirinkimo nebuvo, veskite is naujo:"<<endl;
        goto klausimas;
    }
    if(pasirinkimas1=="n")
    {
        ifstream in ("Kursiokai.txt");
        getline(in, eilute);
        while(in.good())
        {
            a.nd.clear();
            suma=0;
            in>>a.vardas>>a.pavarde;
        while(in>>pazymys)
            {
            in>>pazymys;
            a.nd.push_back(pazymys);
            suma=suma+pazymys;
            }
            in>>E;
            a.nd.push_back(E);
            a.balas=E*1.0*0.6+suma/(a.nd.size()-1)*1.0*0.4;

    sort(a.nd.begin(), a.nd.end());

    if(a.nd.size()%2==0)
    {
        a.mediana=(a.nd[a.nd.size()/2-1]+a.nd[a.nd.size()/2])*1.0/2;
    }
    else
        a.mediana=a.nd[a.nd.size()/2];
        isvestis.push_back(a);
        }
        in.close();
    //sort(a.pavarde.begin(), a.pavarde.end());
    cout <<setw(15)<<left<<"Vardas " <<setw(15)<<left<<"Pavarde "<<setw(15)<<left<<"Mediana "<<setw(15)<<right<<"Galutinis balas"<< endl;
    cout.fill('-');
    cout.width(60);
    cout<<"-"<<endl;
    cout.fill(' ');
        for (student x : isvestis)
            cout<<setw(15)<<left<<x.vardas<<setw(15)<<left<<x.pavarde<<setw(15)<<setprecision(2)<<fixed<<left<<x.mediana<<setw(15)<<setprecision(2)<<fixed<<right<<x.balas<<endl;
    cout.fill('-');
    cout.width(60);
    cout<<"-"<<endl;
    }
    if(pasirinkimas1=="y")
    while(ArTesti=="y")
    {
        cout << "Áveskite studento varda ir pavarde: " << endl;
        cin>>a.vardas>>a.pavarde;
    cout<<"Jei norite pazymius vesti patys, spauskite <y>. Noredami sugeneruotu automatiskai, spauskite <n>: "<<endl;
    klausimas1:
    cin>>pasirinkimas2;
    if(pasirinkimas2!="y" && pasirinkimas2!="n")
    {
        cout<<"Tokio pasirinkimo nebuvo, veskite is naujo:"<<endl;
        goto klausimas1;
    }
    if(pasirinkimas2=="y")
    {
        cout<<"Veskite pazymius uz namu darbus. Kuomet noresite baigti, spauskite <0>"<<endl;
        pazymys=1;
        a.nd.clear();
        suma=0;
            while(pazymys!=0)
            {
                cin>>pazymys;
                    while(cin.fail() || pazymys>10 || pazymys <0)
                    {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout<<"Veskite is naujo"<<endl;
                    cin>>pazymys;
                    }
                a.nd.push_back(pazymys);
                suma=suma+pazymys;
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
    }
    else if(pasirinkimas2=="n")
    {
     cout<<"Kiek norite pazymiu uz namu darbus?"<<endl;
     cin>>sk;
     for (i=0; i<sk; i++)
        {
            pazymys=(rand()%10)+1;
            a.nd.push_back(pazymys);
            suma=suma+pazymys;
        }
            E=(rand()%10)+1;
            a.nd.push_back(E);
    }
    a.balas=E*1.0*0.6+suma/(a.nd.size()-1)*1.0*0.4;

    sort(a.nd.begin(), a.nd.end());

    if(a.nd.size()%2==0)
    {
        a.mediana=(a.nd[a.nd.size()/2-1]+a.nd[a.nd.size()/2])/2;
    }
    else
        a.mediana=a.nd[a.nd.size()/2];

    cout<<"Jei norite testi, spauskite <y>. Noredami pereiti prie duomenu isvedimo spauskite <n>"<<endl;
    klausimas2:
    cin>>ArTesti;
    if(ArTesti!="y" && ArTesti!="n")
    {
        cout<<"Tokio pasirinkimo nebuvo, veskite is naujo:"<<endl;
        goto klausimas2;
    }
        isvestis.push_back(a);
}
if(pasirinkimas1=="y" && ArTesti=="n")
{
  cout<<"Iveskite <1> jei norite suzinoti galutini ivertinima arba <2> jei Mediana"<<endl;
    cin>>ats;
    if(ats == 1)
        {
    cout <<setw(15)<<left<<"Vardas " <<setw(15)<<left<<"Pavarde "<<setw(20)<<right<<"Galutinis balas "<< endl;
    cout.fill('-');
    cout.width(50);
    cout<<"-"<<endl;
    cout.fill(' ');
        for (student x : isvestis)
            cout<<setw(15)<<left<<x.vardas<<setw(15)<<left<<x.pavarde<<setw(20)<<setprecision(3)<<fixed<<right<<x.balas<<endl;
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
        for (student x : isvestis)
            cout<<setw(15)<<left<<x.vardas<<setw(15)<<left<<x.pavarde<<setw(15)<<setprecision(3)<<fixed<<right<<x.mediana<<endl;
    cout.fill('-');
    cout.width(45);
    cout<<"-"<<endl;
    }
}
    return 0;
}

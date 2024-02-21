#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
using namespace std;

struct Pazymiai{
    string var;
    string pav;
    double vid=0.0;
    int egz;
    vector<int> paz;
    double galutinis;
    double med;
    };
int main ()
{
    int pasirinkimas;
    int c;
    int x;
    int s;
    int i=0;
    double laiku_suma = 0.0;
    vector<Pazymiai> P;

    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, pavardes ir pazymius" << endl;
        cout << "4. Nuskaityti is failo" << endl;
        cout << "5. Baigti programa" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas){
            case 1:{

                Pazymiai C;
                do{

                    double suma=0.0;

                    cout<<"Iveskite "<<i+1<<" pavarde (noretume baigti spauskite 4):   "<<endl;
                    cin>>C.pav;
                    if(C.pav=="4" || C.var=="4"){
                        break;
                    }
                    cout<<"Iveskite "<<i+1<<" varda (noretume baigti spauskite 4):   "<<endl;
                    cin>>C.var;
                    if(C.pav=="4" || C.var=="4"){
                        break;
                    }

                    int j=0;

                    do{
                        cout<<"Iveskite "<<j+1<<" pazymi (noredami baigti spauskite 11):  "<<endl;
                        cin>>x;

                        if(x==11){
                            break;
                        }

                        while (cin.fail() || x < 1 || x > 10) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite " << j + 1 << " pazymi nuo 1 iki 10: ";
                            cin >> x;
                        }

                        C.paz.push_back(x);
                        suma = suma + x;
                        j++;
                    } while(x!=11);

                    C.vid=suma/j;

                    cout <<"Iveskite egzamino rezultata: "<<endl;
                    cin>>C.egz;

                    while (cin.fail() || C.egz < 1 || C.egz > 10) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                        cin >> C.egz;
                    }

                    C.galutinis=(C.vid*0.4)+(0.6*C.egz);
                    sort(C.paz.begin(), C.paz.end());

                    int vidurys = j / 2;
                    if (j%2==0){
                        C.med = (C.paz[vidurys-1] + C.paz[vidurys])/2.0;
                    }
                    else{
                        C.med = C.paz[vidurys];
                    }

                    P.push_back(C);
                    i++;
                } while(C.pav!="4" || C.var!="4");

                cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                for(const auto &studentas : P){
                    cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                         << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                         << setprecision(2) << studentas.med << endl;
                }
                break;
            }

            case 2:{

                Pazymiai C;
                do  {
                    double suma = 0.0;

                    cout << "Iveskite " << i + 1 << " pavarde (noredami sustoti iveskite 4):   " << endl;
                    cin >> C.pav;
                    if (C.pav == "4" || C.var == "4") {
                        break;
                    }

                    cout << "Iveskite " << i + 1 << " varda (noredami sustoti iveskite 4):   " << endl;
                    cin >> C.var;
                    if (C.pav == "4" || C.var == "4") {
                        break;
                    }

                    cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
                    cout << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";

                    while (!(cin >> x) || (x != 1 && x != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    if (x == 1) {
                        string y;
                        int h = 0;
                        while (y != "Ne") {
                            C.paz.push_back((rand() % 10) + 1);
                            cout << "Pazymis " << h + 1 << " : " << C.paz[h] << endl;
                            cout << "Ar norite testi generavima? Taip arba Ne: ";
                            cin >> y;
                            cout << endl;
                            suma = suma + C.paz[h];
                            h++;
                        }
                        C.vid = suma / h;

                        sort(C.paz.begin(), C.paz.end());

                        if (h % 2 == 0) {
                            int pirmas = h / 2 - 1;
                            int antras = h / 2;
                            C.med = (C.paz[pirmas] + C.paz[antras]) / 2.0;
                        }
                        else {
                            int vidurys = h / 2;
                            C.med = C.paz[vidurys];
                        }
                    }

                    if (x == 2) {
                        int k;
                        cout << "Iveskite pazymiu kieki: ";

                        while (!(cin >> k) || (k < 1)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite skaiciu nuo 1: ";
                        }
                        for (int l = 0; l < k; l++) {
                            C.paz.push_back((rand() % 10) + 1);
                            cout << "Pazymis " << l + 1 << " : " << C.paz[l] << endl;
                            suma = suma + C.paz[l];
                        }

                        C.vid = suma / k;

                        sort(C.paz.begin(), C.paz.end());

                        if (k % 2 == 0) {
                            int pirmas = k / 2 - 1;
                            int antras = k / 2;
                            C.med = (C.paz[pirmas] + C.paz[antras]) / 2.0;
                        }
                        else {
                            int vidurys = k / 2;
                            C.med = C.paz[vidurys];
                        }
                    }

                    int w;
                    cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
                    cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
                    cout << "Jusu pasirinkimas: ";

                    while (!(cin >> w) || (w != 1 && w != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    if (w == 1) {
                        C.egz = (rand() % 10) + 1;
                        cout << "Egzamino rezultatas: " << C.egz << endl;
                    }

                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: ";

                        while (!(cin >> C.egz) || (C.egz <1 || C.egz >10)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                        }
                        cout << endl;
                    }

                    C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);
                    P.push_back(C);
                    i++;
                } while (C.pav != "4" || C.var != "4");

                cout << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"
                    << " / " << setw(17) << "Galutinis (Med.)" << endl;
                cout << "--------------------------------------------------------" << endl;

                for (const auto &studentas : P) {
                    cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                        << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                        << setprecision(2) << studentas.med << endl;
                }
                break;
            }

            case 3:{
                int qq = 0;
                string vardai[] = {"Paulina", "Adriana", "Gitanas", "Donald", "Ugne", "Kamile", "Rugile", "Roberta", "Valdemaras", "Jurgis"};
                string pavardes[] = {"Podgaiska", "Obama", "Trump", "Nauseda", "Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte", "Jankauskas"};

                while (qq != 1) {
                    Pazymiai C;
                    C.pav = pavardes[rand() % 10];
                    C.var = vardai[rand() % 10];
                    cout << "Pavarde ir vardas: " << C.pav << " " << C.var << endl;

                    cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
                    cout<< "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> x) || (x != 1 && x != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    if (x == 1) {
                        string y;
                        int h = 0;
                        double suma = 0.0;

                        while (y != "Ne") {
                            C.paz.push_back((rand() % 10) + 1);
                            cout << "Pazymis " << h + 1 << " : " << C.paz[h] << endl;
                            cout << "Ar norite testi generavima? Taip arba Ne: ";
                            cin >> y;
                            cout << endl;
                            suma = suma + C.paz[h];
                            h++;
                        }
                        C.vid = suma / h;

                        sort(C.paz.begin(), C.paz.end());

                        if (h % 2 == 0) {
                            int pirmas = h / 2 - 1;
                            int antras = h / 2;
                            C.med = (C.paz[pirmas] + C.paz[antras]) / 2.0;
                        }
                        else {
                            int vidurys = h / 2;
                            C.med = C.paz[vidurys];
                        }
                    }

                    if (x == 2) {
                        double suma = 0.0;
                        int k;
                        cout << "Iveskite pazymiu kieki: ";

                        while (!(cin >> k) || (k < 1 )) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite skaiciu nuo 1 : ";
                        }

                        for (int l = 0; l < k; l++) {
                            C.paz.push_back((rand() % 10) + 1);
                            cout << "Pazymis " << l + 1 << " : " << C.paz[l] << endl;
                            suma = suma + C.paz[l];
                        }

                        C.vid = suma / k;

                        sort(C.paz.begin(), C.paz.end());

                        if (k % 2 == 0) {
                            int pirmas = k / 2 - 1;
                            int antras = k / 2;
                            C.med = (C.paz[pirmas] + C.paz[antras]) / 2.0;
                        }
                        else {
                            int vidurys = k / 2;
                            C.med = C.paz[vidurys];
                        }
                    }

                    int w;
                    cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
                    cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> w) || (w != 1 && w != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    if (w == 1) {
                        C.egz = (rand() % 10) + 1;
                        cout << "Egzamino rezultatas: " << C.egz << endl;
                    }

                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: ";

                        while (!(cin >> C.egz) || (C.egz < 1 || C.egz > 10)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                        }
                        cout << endl;
                    }

                    C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);

                    cout << "Noredami baigti studentu generavima spauskite 1, noredami testi spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";

                    while (!(cin >> qq) || (qq != 1 && qq != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }

                    P.push_back(C);
                }

                cout << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"
                    << " / " << setw(17) << "Galutinis (Med.)" << endl;
                cout << "------------------------------------------------------------" << endl;

                for (const auto &studentas : P) {
                    cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                        << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                        << setprecision(2) << studentas.med << endl;
                }

                break;
            }
            case 4:{

                Pazymiai C;

                int z;
                int o;
                int stud;
                string hoe;
                int xyz;
                int pv=0;
                int numirelis;
                string wp;
                double laiku_suma=0.0;

                cout<<"Pasirinkite is kurio failo norite nuskaityti: "<<endl;
                cout<<"1. studentai10000 "<<"2. studentai100000 "<<"3. studentai1000000 "<<"4. kursiokai5 "<<endl;

                while (!(cin >> numirelis) || numirelis < 1 || numirelis > 4) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if(numirelis==1){
                    wp="studentai10000.txt";
                    do{
                        cout<<"Kiek nuskaityti studentu? "<<endl;

                        while (!(cin >> stud)) {
                            cout << "Klaida. Iveskite skaiciu nuo 1 iki 10 000." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                    }while(stud>10000);

                }

                if(numirelis==2){
                    wp="studentai100000.txt";
                    do{
                        cout<<"Kiek nuskaityti studentu? "<<endl;

                        while (!(cin >> stud)) {
                            cout << "Klaida. Iveskite skaiciu nuo 1 iki 100 000." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }while(stud>100000);

                }

                if(numirelis==3){
                    wp="studentai1000000.txt";
                    do{
                        cout<<"Kiek nuskaityti studentu? "<<endl;

                        while (!(cin >> stud)) {
                            cout << "Klaida. Iveskite skaiciu nuo 1 iki 1 000 000." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }while(stud>1000000);

                }

                if(numirelis==4){
                    wp="kursiokai.txt";
                    do{
                        cout<<"Kiek nuskaityti studentu? "<<endl;

                        while (!(cin >> stud)) {
                            cout << "Klaida. Iveskite skaiciu nuo 1 iki 5." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }while(stud>5);

                }

                ifstream F(wp);

                auto start = chrono::steady_clock::now();

                while( hoe != "Egz."){
                    F>>hoe;
                    pv++;
                }

                pv=pv-3;

                for(int l=0; l<stud; l++){
                    double suma=0.0;
                    C.paz.clear();
                    F>>C.pav>>C.var;

                    for(int i=0; i<pv; i++){
                        F>>z;
                        C.paz.push_back(z);
                        suma=suma+z;
                    }

                    sort(C.paz.begin(), C.paz.end());

                    C.vid=suma/pv;

                    F>>C.egz;

                    C.galutinis=(C.vid*0.4)+(0.6*C.egz);

                    int vidurys = pv / 2;

                    if (pv%2==0){
                        int pirmas=vidurys-1;
                        int antras=vidurys;
                        C.med = (C.paz[pirmas] + C.paz[antras])/2.0;
                    }
                    else{
                        C.med = C.paz[vidurys];
                    }

                    P.push_back(C);

                }

                vector<double> laikai;

                F.close();
                auto end = chrono::steady_clock::now();
                double laikas=chrono::duration <double> (end - start).count();
                laikai.push_back(laikas);
                cout<<"Trukme: "<< laikas << " s"<<endl;

                /*for (auto laikas : laikai) {
                    laiku_suma += laikas;
                }
                double laiku_vidurkis =(laikai.size() > 0) ? (laiku_suma / laikai.size()) : 0.0;
                cout << "Vidutine trukme: " << laiku_vidurkis << " s" << endl;
                */

                cout<<"Jeigu norite rusiuoti pagal pavarde spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal varda spauskite 2: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 3: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 4: "<<endl;

                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if(xyz==1){
                    sort(C.pav.begin(),C.pav.end());
                }
                if(xyz==2){
                    sort(C.var.begin(),C.var.end());
                }
                if(xyz==3){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.galutinis < b.galutinis;
                    });
                }
                if(xyz==4){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });
                }

                cout<<"Jeigu norite isvesti i ekrana- spauskite 1: "<<endl;
                cout<<"Jeigu norite isvesti i faila- spauskite 2: "<<endl;
                cout<<"Jusu pasirinkimas: ";

                while (!(cin >> o)) {
                    cout << "Klaida. Iveskite skaiciu 1 arba 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if(o==1){

                    cout << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"<< " / " << setw(17) << "Galutinis (Med.)" << endl;
                    cout << "--------------------------------------------------------" << endl;

                    for (const auto &studentas : P) {
                        cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                            << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                            << setprecision(2) << studentas.med << endl;
                    }
                }
                if(o==2){

                    ofstream R("isvestis.txt");

                    R << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"
                        << " / " << setw(17) << "Galutinis (Med.)" << endl;
                    R << "--------------------------------------------------------" << endl;

                    for (const auto &studentas : P) {
                        R << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                            << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                            << setprecision(2) << studentas.med << endl;

                    }
                    R.close();
                }

                break;
            }

            case 5:{
                cout<<"Programa baigta."<<endl;
                return 0;
                break;
            }
        }
    }
    return 0;
}

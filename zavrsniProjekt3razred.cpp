#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Meso {
    private:
        int ID;
        double cijena_po_kg;
        string vrsta;
    public:
        Meso (int id, double cpg, string v){
            ID=id;
            cijena_po_kg=cpg;
            vrsta=v;
        }

        void getAll(){            
            cout<<"\nID: "<<ID;
            cout<<"\nNaziv artikla: "<<vrsta;
            cout<<"\nCijena: "<<cijena_po_kg<<" KM/kg";
            cout<<"\n-------------------------------------------------------------------";
        }

        int getID(){
            return ID;
        }

        int getCPG(){
            return cijena_po_kg;
        }

        string getV(){
            return vrsta;
        }
};

class Biljka {
    private:
        int ID;
        double koeficjent_kvaliteta, cijena_po_kg;
        string vrsta;
    public:
        Biljka (int id, double cpg, double kk, string v){
            ID=id;
            cijena_po_kg=cpg;
            koeficjent_kvaliteta=kk;
            vrsta=v;
        }

        void getAll(){
            cout<<"\nID: "<<ID;
            cout<<"\nNaziv artikla: "<<vrsta;
            cout<<"\nCijena: "<<cijena_po_kg*koeficjent_kvaliteta<<" KM/kg";
            cout<<"\nKoeficjent kvaliteta: "<<koeficjent_kvaliteta<<" / 1";
            cout<<"\n-------------------------------------------------------------------";
        }

        int getID(){
            return ID;
        }

        int getCPG(){
            return cijena_po_kg*koeficjent_kvaliteta;
        }

        double getKK(){
            return koeficjent_kvaliteta;
        }

        string getV(){
            return vrsta;
        }
};

int main()
{
    cout<<"Dobrodosli u trgovinu domacih mesnatih i biljnih proizvoda!";
    vector<Meso> mesnati_proizvodi;
    vector<Biljka> biljni_proizvodi;

    fstream data_file;

    data_file.open("biljke.txt", ios::in);
    if (data_file.is_open()) {
        int i=0;
        string data[4];
        while (getline(data_file, data[i])) {
            cout << data << '\n';
            //unos
            i++;
            if(i==4){
                i=0;
                biljni_proizvodi.push_back(Biljka(stoi(data[0]), stod(data[1]), stod(data[2]), data[3]));
            }
        }
        data_file.close();
    }

    data_file.open("meso.txt", ios::in);
    if (data_file.is_open()) {
        int i=0;
        string data[3];
        while (getline(data_file, data[i])) {
            cout << data << '\n';
            //unos
            i++;
            if(i==3){
                i=0;
                mesnati_proizvodi.push_back(Meso(stoi(data[0]), stod(data[1]), data[3]));
            }
        }
        data_file.close();
    }

    
    while(1){
        system("cls");
        int t;
        cout<<"\n----------------------------------------------------------------------------------------------------------";
        cout<<"\n     1. Lista svih proizvoda";
        cout<<"\n     2. Lista mesnatih proizvoda";
        cout<<"\n     3. Lista biljnih proizvoda";
        cout<<"\n     4. Cijena mesnatog proizvoda sa zeljenom kolicinom (5 [ID] [kg])";
        cout<<"\n     5. Cijena biljnog proizvoda sa zeljenom kolicinom (5 [ID] [kg])";
        cout<<"\n     6. Kraj programa";
        cout<<"\n----------------------------------------------------------------------------------------------------------";
        cin>>t;

        if(t==1){
            system("cls");
            for(int i=0;i<mesnati_proizvodi.size();i++)
                mesnati_proizvodi.at(i).getAll();
            for(int i=0;i<biljni_proizvodi.size();i++)
                biljni_proizvodi.at(i).getAll();
            cout<<endl;
            system("pause");
        }

        if(t==2){
            system("cls");
            for(int i=0;i<mesnati_proizvodi.size();i++)
                mesnati_proizvodi.at(i).getAll();
            cout<<endl;
            system("pause");
        }

        if(t==3){
            system("cls");
            for(int i=0;i<biljni_proizvodi.size();i++)
                biljni_proizvodi.at(i).getAll();
            cout<<endl;
            system("pause");
        }

        if(t==4){
            int id;
            double kg;
            cin>>id>>kg;
            system("cls");
            cout<<"-------------------------------------------------------------------";
            cout<<"\nID: "<<biljni_proizvodi.at(id).getID();
            cout<<"\nNaziv artikla: "<<biljni_proizvodi.at(id).getV();
            cout<<"\nCijena "<<kg<<"kg: "<<mesnati_proizvodi.at(id).getCPG()*kg<<"KM";
            cout<<"\n-------------------------------------------------------------------";
            cout<<endl;
            system("pause");

        }

        if(t==5){
            int id;
            double kg;
            cin>>id>>kg;
            system("cls");
            cout<<"-------------------------------------------------------------------";
            cout<<"\nID: "<<biljni_proizvodi.at(id).getID();
            cout<<"\nNaziv artikla: "<<biljni_proizvodi.at(id).getV();
            cout<<"\nCijena "<<kg<<"kg: "<<biljni_proizvodi.at(id).getCPG()*biljni_proizvodi.at(id).getKK()*kg<<" KM";
            cout<<"\n-------------------------------------------------------------------";
            cout<<endl;
            system("pause");

        }
        
        if(t==6){
            system("cls");
            goto x;
        }
    }
    x:
    system("cls");
    cout<<"Program je ugasen!";
    
}
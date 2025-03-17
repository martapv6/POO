#include <iostream>//probleme la cout produs imi mananca prima litera
//de la nume recolvat dar am scos in.getline()
//problema2 la concatenarea + a cuptorului nu da bine la afisare
//problema 3 operatorul + intre 2 clase diferite trebuie in afara claselor si
//trecute cu friend
// functionalitate client sa o treci cu :: ca  ai uitat
#include <cstring>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

class Brutarie
{
private:
    const int id;
    static int CONTORID;
    char zona;
    char* numeBrutarie;
    string proprietar;
    int nrAngajati;
    bool disponibilitate;
    int anDeschidere;
    int lungimeTel;
    int* nrTel;

public:
     Brutarie();
     Brutarie(char zona, char* numeBrutarie, string proprietar,
              int nrAngajati, bool disponibilitate,int* nrTel,
              int anDeschidere,int lungimeTel);

     Brutarie(string,int,bool);
     Brutarie( string proprietar):id(CONTORID++) { this->proprietar=proprietar; }
    //copy-constructerul
    Brutarie(const Brutarie& obj):id(obj.id)
    {
        this->zona = obj.zona;
        this->numeBrutarie = new char[strlen(obj.numeBrutarie) + 1];
        strcpy(this->numeBrutarie, obj.numeBrutarie);
        this->proprietar = obj.proprietar;
        this->nrAngajati = obj.nrAngajati;
        this->disponibilitate = obj.disponibilitate;
        this->anDeschidere=obj.anDeschidere;
        this->lungimeTel=obj.lungimeTel;
        this->nrTel=new int[obj.lungimeTel];
        for (int i = 0; i < this->lungimeTel; i++)
        {
            this->nrTel[i] = obj.nrTel[i];
        }

    }

    //set

     void setNrTel(int * nrTel)
    {
      if(this->nrTel!=0)
       delete []this->nrTel;
      this->nrTel = new int[this->lungimeTel ];
      for (int i = 0; i < lungimeTel; i++)
        {
            this->nrTel[i] = nrTel[i];
        }
    }

     void setDisponibilitate(bool disponibilitate) { this->disponibilitate = disponibilitate; }
     void setanDeschidere(int anDeschidere) { this->anDeschidere = anDeschidere; }
     void setZona(char zona) { this->zona = zona; }
     void setnrAngajati(int nrAngajati){ this->nrAngajati =nrAngajati;}
     void setproprietar(string proprietar) { this-> proprietar = proprietar; }
     void setnumeBrutarie(char *numeBrutarie)
     {
        if (this->numeBrutarie != NULL)
            delete[] this->numeBrutarie;
        this->numeBrutarie = new char[strlen(numeBrutarie) + 1];
        strcpy(this->numeBrutarie, numeBrutarie);
    }
    //get
    int getId() { return id; }
    const int * getNrTel() { return nrTel;}
    int getAnDeschidere() { return anDeschidere; }
    bool getDisponibilitate() { return disponibilitate; }
    char getZona(){ return zona; }
    const char* getnumeBrutarie() { return numeBrutarie; }
    int getnrAngajati(){ return nrAngajati; }
    int getLungimeTel(){ return lungimeTel;}
    string getProprietar() { return proprietar; }
    //operatori
    Brutarie& operator = (const Brutarie& obj);
    Brutarie operator+(const Brutarie &obj) //cu 2 obiecte din clasa
    {
        Brutarie copie = *this;
        copie.proprietar = copie.proprietar + " " + obj.proprietar;
        copie.nrAngajati=copie.nrAngajati+obj.nrAngajati;
        copie.disponibilitate=abs(copie.disponibilitate-obj.disponibilitate);
        return copie;
    }
    Brutarie operator-(const Brutarie &obj) //cu 2 obiecte din clasa
    {
        Brutarie copie = *this;
        copie.nrAngajati=abs(copie.nrAngajati-obj.nrAngajati);
        copie.disponibilitate=abs(copie.disponibilitate-obj.disponibilitate);
        copie.anDeschidere=2024-obj.anDeschidere;
        return copie;
    }

    Brutarie operator+(string s)//cu  obiect din alta clasa in dreapta
    {
        Brutarie copie = *this;
        copie.proprietar = copie.proprietar + " " + s;
        return copie;
    }
    friend Brutarie operator +(string s, Brutarie obj); //in stanga

    Brutarie& operator++()//pre
    {
        this -> nrAngajati++;
        this->lungimeTel++;
        int* vect=new int[this->lungimeTel];
        for(int i=0; i<this->lungimeTel;i++)
            vect[i]=this->nrTel[i];
        vect[this->lungimeTel-1]=0;
        if(this->nrTel!=NULL)
            delete[] this->nrTel;
        this->nrTel=vect;

        return *this;
    }

    Brutarie operator++(int) //post    ++(*this);
    {
        Brutarie copie = *this;
        this -> nrAngajati++;
        int* vect=new int[this->lungimeTel];
        for(int i=0; i<this->lungimeTel;i++)
            vect[i]=this->nrTel[i];
        vect[this->lungimeTel-1]=0;
        if(this->nrTel!=NULL)
            delete[] this->nrTel;
        this->nrTel=vect;
        return copie;
    }
    //cast
    operator string() // implicit
    {
        return this->proprietar;
    }
    operator string()const // explicit -
    {
        return this->proprietar;
    }
    //indexare
    int operator[] (int index)
    {
        if(index>=0 && index<this->lungimeTel)
            return this->nrTel[index];
        else throw runtime_error("Index invalid");
    }
     bool operator < (const Brutarie &obj){ return (this->lungimeTel < obj.lungimeTel) && (this->nrAngajati < obj.nrAngajati);}
     bool operator > (const Brutarie &obj)
      {
        int nrVocaleThis=0;
        int nrConsoaneThis=0;
        int nrVocaleObj=0;
        int nrConsoaneObj=0;
        for (int i = 0; this->numeBrutarie[i] != '\0'; i++)
        {
            char ch=tolower(this->numeBrutarie[i]);
            if (ch == 'a'||ch=='e'||ch=='i'||ch == 'o'||ch=='u')
                nrVocaleThis++;
             else if (ch >= 'a'&&ch <='z')
                nrConsoaneThis++;
        }
        for (int i = 0; obj.numeBrutarie[i] != '\0'; i++)
        {
            char ch=tolower(obj.numeBrutarie[i]);
            if (ch=='a'||ch=='e'||ch=='i'||ch =='o'||ch=='u')
                  nrVocaleObj++;
             else if (ch>='a' && ch<='z')
                nrConsoaneObj++;
        }

        return (nrVocaleThis + nrConsoaneThis) > (nrVocaleObj + nrConsoaneObj);
    }
    bool operator == (const Brutarie &obj)
    {
        return
        {
        this->proprietar ==obj.proprietar &&
        this->nrAngajati==obj.nrAngajati &&
        this->disponibilitate == obj.disponibilitate
        };
    }
    //destructor
    ~Brutarie()
    {
        if(this->numeBrutarie!=NULL)
                delete[] this->numeBrutarie;
        if(this->nrTel!=NULL)
            delete[] this->nrTel;
    }

   friend ostream& operator << (ostream&, const Brutarie&);
   friend istream& operator>>(istream&in, Brutarie &obj);
   friend  void functionalitate(int *numar,int lungime,Brutarie b);

};
  void functionalitate(const int *numar,int lungime,Brutarie b)
  {
      if(lungime!=10)
        cout<< "numar de telefon invalid";
      else
      {
            if (numar[0]==0 && numar[1]==7 && numar[2]==5)
              cout<<"numar valid: Orange";
            else
              if (numar[0]==0 && numar[1]==7 && numar[2]==2)
                cout<<"numar valid: Vodafone";

      }
  }

Brutarie operator +(string s, Brutarie obj)
{
    obj.proprietar=obj.proprietar + " " + s;
    return obj;
}
//constructori
Brutarie :: Brutarie():id(CONTORID++)
    {
        this->zona='X';
        this->proprietar="Anonim";
        numeBrutarie = new char[strlen("anonim") + 1];
        strcpy(numeBrutarie, "anonim");
        this->nrAngajati=0;
        this->disponibilitate=NULL;
        this->anDeschidere=0;
        this->lungimeTel=0;
        nrTel=NULL;

    }
Brutarie ::  Brutarie( string proprietar,int nrAngajati,
                       bool disponibilitate):id(CONTORID++),proprietar(proprietar),nrAngajati(nrAngajati),disponibilitate(disponibilitate)
    {
        numeBrutarie = new char[strlen("anonim") + 1];
        strcpy(numeBrutarie, "anonim");
        nrTel=NULL;
        this->zona='X';
        this->anDeschidere=0;
        this->lungimeTel=0;
    }
  Brutarie ::  Brutarie(char zona, char* numeBrutarie, string proprietar,
                     int nrAngajati, bool disponibilitate,int* nrTel,
                     int anDeschidere,int lungimeTel):id(CONTORID++)
    {
        this->zona=zona;
        this->numeBrutarie=new char[strlen(numeBrutarie)+1];
        strcpy(this->numeBrutarie,numeBrutarie);
        this->proprietar=proprietar;
        this->nrAngajati=nrAngajati;
        this->disponibilitate=disponibilitate;
        this->anDeschidere=anDeschidere;
        this->lungimeTel=lungimeTel;
        this->nrTel = new int[this->lungimeTel];
        for(int i=0; i<this->lungimeTel; i++)
                this->nrTel[i]=nrTel[i];

    }
Brutarie& Brutarie :: operator = (const Brutarie& obj)
    {
        if(this != &obj)
        {
        if (this->numeBrutarie != NULL)
            delete[] this->numeBrutarie;
        if(this->nrTel != NULL)
            delete[] this->nrTel;
        this->zona = obj.zona;
        this->numeBrutarie = new char[strlen(obj.numeBrutarie) + 1];
        strcpy(this->numeBrutarie, obj.numeBrutarie);
        this->proprietar = obj.proprietar;
        this->nrAngajati = obj.nrAngajati;
        this->disponibilitate = obj.disponibilitate;
        this->anDeschidere=obj.anDeschidere;
        this->lungimeTel=obj.lungimeTel;
        for(int i=0; i<obj.lungimeTel; i++)
                this->nrTel[i]=obj.nrTel[i];

        }
        return *this;
    }


ostream& operator<<(ostream &out, const Brutarie &obj)
{
    out << "Id:" << obj.id << endl;
    out << "Zona: " << obj.zona << endl;
    out << "Nume brutarie: " << obj.numeBrutarie << endl;
    out << "proprietar: " << obj.proprietar << endl;
    out << "Numar angajati: " << obj.nrAngajati << endl;
    out << "Disponibilitate: " << obj.disponibilitate << endl;
    out << "An de deschidere:" << obj.anDeschidere << endl;
    out << "Lungime numar de telefon:" << obj.lungimeTel << endl;
    for (int i=0; i<obj.lungimeTel; i++)
        out << "Numar de telefon:" << obj.nrTel[i] << endl;

    return out;
}
istream& operator >> (istream &in, Brutarie &obj)
{
    cout << "Zona: ";
    in >> obj.zona;
    char nume[100];
    in.get();
    cout << "Nume brutarie: ";
    in.getline(nume, 100);
    if(obj.numeBrutarie != NULL)
        delete[] obj.numeBrutarie;
    obj.numeBrutarie = new char[strlen(nume) + 1];
    strcpy(obj.numeBrutarie, nume);

    cout << "Proprietar: ";
    in >> obj.proprietar;
    cout << "Numar angajati: ";
    in >> obj.nrAngajati;
    cout << "Disponibilitate: ";
    in >> obj.disponibilitate;
    cout << "An de deschidere: ";
    in >> obj.anDeschidere;
    cout << "Lungime numar de telefon:";
    in >> obj.lungimeTel;
    if (obj.lungimeTel > 0)
    {
        if(obj.nrTel != 0)
            delete[] obj.nrTel;
        obj.nrTel = new int[obj.lungimeTel];
        cout << "Numar de telefon:";
        for (int i = 0; i < obj.lungimeTel; i++)
            in >> obj.nrTel[i];
    }
    return in;
}

int Brutarie::CONTORID=0;
class Cuptor
{
private:
    int nrLocuri;
    int* locuriOcupate;
    bool deschidere; //daca cuptorul e inchis sau deschis
    float temperatura;
    int anFabricatie;
    int garantie;
public:

    Cuptor(int nrLocuri,int* locuriOcupate,bool deschidere,
           float temperatura,int anFabricatie,int garantie);
        Cuptor():nrLocuri(0),deschidere(0),temperatura(0),anFabricatie(0),garantie(0)
    {
        locuriOcupate=NULL;

    }
    Cuptor(int nrLocuri,int* locuriOcupate,float temperatura):nrLocuri(nrLocuri),temperatura(temperatura)
    {

        this->locuriOcupate=new int[nrLocuri+1];
        for(int i=0; i<nrLocuri; i++)
                this->locuriOcupate[i]=locuriOcupate[i];
        this->garantie=0;
        this->anFabricatie=0;
        this->deschidere=0;
    }
    Cuptor(const Cuptor& obj)
    {
        this->nrLocuri = obj.nrLocuri;
        this->locuriOcupate = new int[obj.nrLocuri + 1];
        for (int i = 0; i < obj.nrLocuri; i++)
        {
            this->locuriOcupate[i] = obj.locuriOcupate[i];
        }
        this->deschidere = obj.deschidere;
        this->temperatura=obj.temperatura;
        this->anFabricatie=obj.anFabricatie;
        this->garantie=obj.garantie;
    }

    //set
    void setanFabricatie(int anFabricatie ) { this->anFabricatie=anFabricatie; }
    void setGarantie(int garantie ) { this->garantie=garantie; }
    void setnrLocuri(int nrLocuri ) { this->nrLocuri=nrLocuri; }
    void setDeschidere(bool deschidere) { this->deschidere=deschidere; }
    void setTemperatura(float temperatura) { this->temperatura=temperatura; }
    void setlocuriOcupate(int * locuriOcupate)
    {
      if(this->locuriOcupate!=0)
       delete []this->locuriOcupate;
      this->locuriOcupate = new int[this->nrLocuri + 1];
      for (int i = 0; i < this->nrLocuri; i++)
        {
            this->locuriOcupate[i] = locuriOcupate[i];
        }
    }
   //get
   int getGarantie(){ return garantie; }
   int getAnFabricatie(){ return anFabricatie; }
   float getTemperatura() { return temperatura; }
   int getnrLocuri(){ return nrLocuri;}
   bool getdeschidere() { return deschidere; }
   const int* getlocuriOcupate() { return locuriOcupate; }
    //operatori
     Cuptor& operator = (const Cuptor& obj)
    {
            if(this != &obj)
        {
                        if(this->locuriOcupate!=NULL)
                delete[] this->locuriOcupate;

        this->temperatura=obj.temperatura;
        this->deschidere=obj.deschidere;
        this->nrLocuri = obj.nrLocuri;
        this->locuriOcupate = new int[obj.nrLocuri + 1];
        for (int i = 0; i < obj.nrLocuri; i++)
        {
            this->locuriOcupate[i] = obj.locuriOcupate[i];
        }
        this->anFabricatie=obj.anFabricatie;
        this->garantie=obj.garantie;
        }

        return *this;
    }
    Cuptor operator+(const Cuptor &obj)// cu 2 obiecte din clasa
    {
        Cuptor copie = *this;
        copie.nrLocuri=copie.nrLocuri+obj.nrLocuri;
        copie.deschidere=abs(copie.deschidere-obj.deschidere);
        int* newlocuriOcupate = new int[copie.nrLocuri];
        for (int i = 0; i < this->nrLocuri ; i++)
            newlocuriOcupate[i]=this->locuriOcupate[i];
        for (int i = this->nrLocuri; i < copie.nrLocuri ; i++)
            newlocuriOcupate[i]=obj.locuriOcupate[i-this->nrLocuri];
        copie.garantie=copie.garantie+obj.garantie;

        return copie;
    }
    Cuptor operator-(const Cuptor &obj)// cu 2 obiecte din clasa
    {
        Cuptor copie = *this;
        copie.nrLocuri=abs(copie.nrLocuri-obj.nrLocuri);
        copie.deschidere=abs(copie.deschidere-obj.deschidere);
        copie.garantie=copie.garantie-obj.garantie;
        copie.anFabricatie=2024-copie.anFabricatie+obj.anFabricatie;

        return copie;
    }
    Cuptor& operator++()//pre
    {
        this -> nrLocuri++;
        int* vect = new int[this -> nrLocuri];
        for (int i = 0; i < nrLocuri ; i++)
            vect[i] = this -> locuriOcupate[i];
        vect[this -> nrLocuri - 1] = 0;
        if (this -> locuriOcupate != NULL)
            delete[] this -> locuriOcupate;
        this -> locuriOcupate = vect;
        this->temperatura++;
        this->anFabricatie++;
        this->garantie++;
        return *this;
    }

    Cuptor operator++(int) // post
    {
        Cuptor copie = *this;
        this -> nrLocuri++;
        int* vect = new int[this -> nrLocuri];
        for (int i = 0; i < nrLocuri - 1; i++)
            vect[i] = this -> locuriOcupate[i];
        vect[this -> nrLocuri - 1] = 0;
        if (this -> locuriOcupate != NULL)
            delete[] this -> locuriOcupate;
        this -> locuriOcupate = vect;
        this->temperatura++;
        this->anFabricatie++;
        this->garantie++;

        return copie;
    }
        Cuptor operator +(int s) //cu ob din afara clasei in dr
    {
        Cuptor copie=*this;
        copie.temperatura=copie.temperatura  + s;
        copie.anFabricatie=copie.anFabricatie + s;
        copie.garantie=copie.garantie + s;
        return copie;
    }
    //CAST
    operator float() // implicit
    {
        return this->temperatura;

    }
    operator float() const // explicit
    {
        return this->temperatura;

    }
    int operator[] (int index)
    {
        if(index>=0 && index<this->nrLocuri)
            return this->locuriOcupate[index];
        else throw runtime_error("Index invalid");
    }
    bool operator < (const Cuptor &obj)
    {
        return this->garantie<obj.garantie;
    }
        bool operator > (const Cuptor &obj)
    {
        return this->anFabricatie>anFabricatie;
    }

    bool operator == (const Cuptor &obj)
    {
        return this->nrLocuri==obj.nrLocuri;
    }


    friend Cuptor operator +(int s, Cuptor obj);
    friend ostream& operator << (ostream&, const Cuptor&);
    friend istream& operator >> (istream&in, Cuptor &obj);
     ~Cuptor()
    {
        if(this->locuriOcupate!=NULL)
                delete[] this->locuriOcupate;

    }
};
    Cuptor operator +(int s,Cuptor obj) //cu ob din afara clasei in st
    {

        obj.temperatura=obj.temperatura  + s;
        obj.anFabricatie=obj.anFabricatie + s;
        obj.garantie=obj.garantie + s;
        return obj;
    }
    Cuptor :: Cuptor(int nrLocuri,int* locuriOcupate,bool deschidere,
           float temperatura,int anFabricatie,int garantie)
    {
        this->nrLocuri=nrLocuri;
        this->locuriOcupate=new int[nrLocuri+1];
        for(int i=0; i<nrLocuri; i++)
                this->locuriOcupate[i]=locuriOcupate[i];
        this->deschidere=deschidere;
        this->temperatura=temperatura;
        this->anFabricatie=anFabricatie;
        this->garantie=garantie;

    }
    void functionalitateCuptor(int locuri,const int*locurio,int g,int an,Cuptor c,bool deschidere)
    {
        int nr=0;
        for(int i=0;i<locuri;i++)
          if (locurio[i] == 1)
            nr++;
        if (nr<locuri/2 && deschidere==0)
         cout<<"ineficienta:asteapta umplerea cuptorului"<<endl;
        else
            cout<<"cuptor folosit eficient"<<endl;
        if (g < 2024-an )
         cout<<"garantie invalida"<<endl;
        else cout<<"garantie valida"<<endl;


    }

ostream& operator << ( ostream &out, const Cuptor &obj)
{
    out << "Numar locuri: " << obj.nrLocuri << endl;
     for(int i = 0; i < obj.nrLocuri; i ++)
        if(obj.locuriOcupate[i] == 0)
            out << "Locul " << i+1 << " este liber" << endl;
        else
            out << "Locul " << i+1 << " nu este liber" << endl;

    out << "Deschidere: " << obj.deschidere << endl;
    out << "Temperatura: " << obj.temperatura << endl;
    out << "An de fabricatie:" << obj.anFabricatie << endl;
    out << "Garantie:" << obj.garantie << endl;

    return out;
}
istream& operator >> (istream &in, Cuptor &obj)
{

    cout << "Numar locuri: ";
    in >> obj.nrLocuri;
    if(obj.locuriOcupate != NULL)
        delete[] obj.locuriOcupate;
    obj.locuriOcupate = new int[obj.nrLocuri];
    for(int i = 0; i < obj.nrLocuri; i ++) {
        cout << "Loc ocupat: ";
        in >> obj.locuriOcupate[i];
    }
    cout << "Deschidere: ";
    in >> obj.deschidere;
    cout << "Temperatura:" ;
    in >> obj.temperatura;
    cout<< "An de fabricatie:";
    in >> obj.anFabricatie ;
    cout << "Garantie:";
    in>> obj.garantie;

    return in;
}
class Produs
{
private:
    class Client;
    string nume;
    bool tip1; //de post=0 sau normal=1
    bool tip2 ;//ciocolata=0 sau vanilie=1
    double pret;
    float greutate;
    float timpCoacere;
    int nrIngrediente;
    int *ingrediente;
    int nrVanzari;
public:
    friend  Client operator+(Client& obj,const Produs& p);
    friend Produs operator +(string s, Produs obj);
    friend ostream& operator<<(ostream&, const Produs&);
    friend istream& operator>>(istream&in, Produs &obj);
    Produs()
    {
        this->nume="Anonim";
        tip1=NULL;
        tip2=NULL;
        this->pret=0;
        this->greutate=0;
        this->timpCoacere=0;
        this->nrVanzari=0;
        this->nrIngrediente=0;
        ingrediente=NULL;
    }
        Produs(string nume,bool tip1,bool tip2,double pret,float greutate,
               int nrVanzari,int nrIngrediente,int *ingrediente,float timpCoacere):nume(nume),tip1(tip1),tip2(tip2),pret(pret),
                                                greutate(greutate),nrVanzari(nrVanzari),nrIngrediente(nrIngrediente),timpCoacere(timpCoacere)
    {
        this->ingrediente = new int[this->nrIngrediente];
        for(int i=0; i<this->nrIngrediente; i++)
                this->ingrediente[i]=ingrediente[i];
    }
    Produs(string nume,double pret,float greutate):nume(nume),pret(pret),greutate(greutate)
    {
        tip1=NULL;
        tip2=NULL;
        ingrediente=NULL;
        this->timpCoacere=0;
        this->nrVanzari=0;
        this->nrIngrediente=0;
    }
    Produs(const Produs& obj)
    {
        this->nume = obj.nume;
        this->tip1=obj.tip1;
        this->tip2=obj.tip2;
        this->greutate = obj.greutate;
        this->pret = obj.pret;
        this->nrVanzari=obj.nrVanzari;
        this->nrIngrediente=obj.nrIngrediente;
        this->timpCoacere=obj.timpCoacere;
        this->ingrediente = new int[obj.nrIngrediente];
        for(int i=0; i<this->nrIngrediente; i++)
                this->ingrediente[i]=obj.ingrediente[i];

    }

    //get
    const int* getIngrediente() { return ingrediente; }
    float getTimpCoacere(){ return timpCoacere; }
    int getNrVanzari() { return nrVanzari; }
    int getNrIngrediente() { return nrIngrediente;}
    string getNume() { return nume; }
    bool getTip1(){ return tip1; }
    bool getTip2() { return tip2; }
    double getPret() { return greutate; }
    float getGreutate() { return greutate; }
    //set
    void setIngrediente(int * ingrediente)
    {

      if(this->ingrediente!=0)
       delete []this->ingrediente;
      this->ingrediente = new int[this->nrIngrediente + 1];
      for (int i = 0; i < this->nrIngrediente; i++)
        {
            this->ingrediente[i] = ingrediente[i];
        }
    }
    void setNrVanzari(int nrVanzari){ this->nrVanzari=nrVanzari; }
    void setNrIngrediente(int nrIngrediente) { this->nrIngrediente=nrIngrediente; }
    void setTimpCoacere(float timpCoacere) { this->timpCoacere=timpCoacere; }
    void setnume(string nume) { this->nume=nume; }
    void settip1(bool tip1) { this->tip1=tip1; }
    void settip2(bool tip2) { this->tip2=tip2; }
    void setPret(double pret) { this->pret=pret; }
    void setGreutate(float greutate) { this->greutate=greutate; }
    //operatori
    Produs& operator = (const Produs& obj)
    {
        if(this != &obj)
        {
            if(this->ingrediente!=NULL)
                delete[] this->ingrediente;

        this->nume = obj.nume;
        this->tip1=obj.tip1;
        this->tip2=obj.tip2;
        this->greutate = obj.greutate;
        this->pret = obj.pret;
        this->nrIngrediente=obj.nrIngrediente;
        this->nrVanzari=obj.nrVanzari;
        this->timpCoacere=timpCoacere;
        this->ingrediente=new int[obj.nrIngrediente];
        for(int i=0; i<obj.nrIngrediente; i++)
                this->ingrediente[i]=obj.ingrediente[i];
        }
        return *this;
    }
    Produs operator+(const Produs &obj)
    {
        Produs copie = *this;
        copie.pret=copie.pret+obj.pret;
        copie.greutate=copie.greutate+obj.greutate;
        copie.nume=copie.nume+" "+obj.nume;
        copie.nrIngrediente=copie.nrIngrediente+obj.nrIngrediente;
        copie.nrVanzari=copie.nrVanzari+obj.nrVanzari;
        return copie;
    }
        Produs operator-(const Produs &obj)
    {
        Produs copie = *this;
        copie.pret=abs(copie.pret-obj.pret);
        copie.greutate=abs(copie.greutate-obj.greutate);
        copie.nume=copie.nume+" "+obj.nume;
        copie.nrIngrediente=abs(copie.nrIngrediente-obj.nrIngrediente);
        copie.nrVanzari=abs(copie.nrVanzari-obj.nrVanzari);
        return copie;
    }
        Produs operator+(string s) //cu ob din alt cls in dr
    {
        Produs copie = *this;
        copie.nume=copie.nume+" "+s;
        return copie;
    }
    Produs& operator++() //pre
    {
        this -> pret++;
        this -> greutate++;
        this->nrIngrediente++;
        this->nrVanzari++;
        this->timpCoacere++;
        return *this;
    }

    Produs operator++(int) //post
    {
        Produs copie = *this;
        this -> pret++;
        this -> greutate ++;
        this->nrIngrediente++;
        this->nrVanzari++;
        this->timpCoacere++;
        return copie;
    }
    //cast
    operator string() // implicit
    {
        return this->nume;
    }

    operator string()const // explicit -
    {
        return this->nume;
    }
     int operator[] (int index)
    {
        if(index>=0 && index<this->nrIngrediente)
            return this->ingrediente[index];
        else throw runtime_error("Index invalid");
    }
    bool operator < (const Produs &obj) { return this->nrIngrediente<obj.nrIngrediente; }
    bool operator > (const Produs &obj) { return this->greutate>obj.greutate; }
    bool operator == (const Produs &obj) { return this->nrVanzari==obj.nrVanzari; }
   /* Produs operator+(const Client& client)
     {
        Produs copie = *this;
        copie.nrIngrediente+=client.getNrProduse();
        copie.greutate+=client.getNrBon();
        return copie;
    }*/
    ~Produs()
    {
        if (ingrediente!=NULL) {
            delete[] ingrediente;
        }
    }
   friend Produs operator+(const Produs& produs, const Client& client);

};
Produs operator +(string s, Produs obj)
{
    obj.nume=obj.nume + " " + s;
    return obj;
}
ostream& operator<<(ostream &out, const Produs &obj)
{
    out << "Nume: " << obj.nume << endl;
    out << "de post: " << obj.tip1 << endl;
    out << "ciocolata sau vanilie: " << obj.tip2 << endl;
    out << "pret: " << obj.pret << endl;
    out << "greutate: " << obj.greutate << endl;
    out << "Numar vanzari:" << obj.nrVanzari << endl;
    out << "Timp de coacere" << obj.timpCoacere << endl;
    out << " Numar de Ingrediente:" << obj.nrIngrediente << endl;
    for(int i=0;i<obj.nrIngrediente; i++)
        if(obj.ingrediente[i]==0)
            out<<"Ingredientul "<<i<<" este folosit"<<endl;
        else
            out<<"Ingredientul "<<i<<" nu este folosit"<<endl;

    return out;
}

istream& operator>>(istream &in, Produs &obj)
{
    cout << "nume: ";
    in >> obj.nume;
    cout << "de Post: ";
    in >> obj.tip1;
    cout << "ciocolata  sau vanilie: ";
    in >> obj.tip2;
    cout << "pret: ";
    in >> obj.pret;
    cout << "greutate: ";
    in >> obj.greutate;
    cout << "Timp de coacere:";
    in >> obj.timpCoacere;
    cout << "Numar ingrediente:";
    in >> obj.nrIngrediente;
    cout << "Numar vanzari";
    in >> obj.nrVanzari;
    if(obj.ingrediente!=NULL)
        delete[] obj.ingrediente;
    obj.ingrediente=new int[obj.nrIngrediente];
    cout<<"Ingrediente: ";
    for(int i=0; i<obj.nrIngrediente; i++)
        in>>obj.ingrediente[i];

    return in;
}
void BioProdus(Produs d,int numarIngrediente,bool tip1,int timp)
{
    if (numarIngrediente>5)
        cout<<"Produsul"<<d<<" nu este bio";
    else
        if (tip1==0)//contine ciocolata
          cout<<"Produsul"<<d<<" nu este bio";
    else
        if(timp>2)
          cout<<"Produsul"<<d<<"este bio";
}


class Client
{
private:
    char* nume;
    int nrProduse;
    int *tip1;
    int *tip2;
    double cost;
    int* vanzari;
    int nrBon;
public:


    Client()
    {
        nume=new char[strlen("Anonim")+1];
        strcpy(nume,"Anonim");
        this->nrProduse=0;
        tip1=NULL;
        tip2=NULL;
        this->cost=0;
        vanzari=NULL;
        this->nrBon=0;
    }
        Client(char*nume,int nrProduse,int* tip1,int*tip2,double cost,int *vanzari,int nrBon)
    {
        nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->nrProduse=nrProduse;
        this->tip1 = new int[nrProduse+1];
        for(int i=0; i<nrProduse; i++)
            this->tip1[i]=tip1[i];
        this->tip2 = new int[nrProduse+1];
        for(int i=0; i<nrProduse; i++)
            this->tip2[i]=tip2[i];
        this->vanzari = new int[nrProduse+1];
        for(int i=0; i<nrProduse; i++)
            this->vanzari[i]=vanzari[i];
        this->nrBon=nrBon;
        this->cost=cost;
    }
    Client(int nrProduse,int* tip1,int*tip2)
    {
        nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->nrProduse=nrProduse;
        this->tip1 = new int[nrProduse + 1];
        this->tip2 = new int[nrProduse + 1];
        for(int i=0; i<nrProduse; i++)
            this->tip1[i]=tip2[i];
        for(int i=0; i<nrProduse; i++)
            this->tip2[i]=tip2[i];

        this->cost=cost;
    }
    Client(const Client& obj)
    {
        this->nume = obj.nume;
        this->nrProduse = obj.nrProduse;
        this->tip1 = new int[obj.nrProduse + 1];
        this->tip2 = new int[obj.nrProduse + 1];
        for (int i = 0; i < obj.nrProduse; i++)
        {
            this->tip1[i] = obj.tip1[i];
        }
        for (int i = 0; i < obj.nrProduse; i++)
        {
            this->tip2[i] = obj.tip2[i];
        }
        this->vanzari= new int[nrProduse+1];
        for (int i = 0; i < obj.nrProduse; i++)
        {
            this->vanzari[i] = obj.vanzari[i];
        }
        this->cost = obj.cost;
        this->nrBon=obj.nrBon;
    }

    //set
    void setVanzari(int * vanzari)
    {

      if(this->vanzari!=0)
       delete []this->vanzari;
      this->vanzari = new int[this->nrProduse + 1];
      for (int i = 0; i < this->nrProduse; i++)
        {
            this->vanzari[i] = vanzari[i];
        }
    }
    void setTip1(int * tip1)
    {

      if(this->tip1!=0)
       delete []this->tip1;
      this->tip1 = new int[this->nrProduse + 1];
      for (int i = 0; i < this->nrProduse; i++)
        {
            this->tip1[i] = tip1[i];
        }

    }
    void setTip2(int * tip2)
    {

      if(this->tip2!=0)
       delete []this->tip2;
      this->tip2 = new int[this->nrProduse + 1];
      for (int i = 0; i < this->nrProduse; i++)
        {
            this->tip2[i] = tip2[i];
        }


    }
    void setnume(char *nume)
    {
        if (this->nume != NULL)
            delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }
    void setNrBon(int nrBon){ this->nrBon=nrBon; }
    void setNrProduse(int nrProduse) { this->nrProduse=nrProduse; }
    void setCost(double nrProduse) { this->cost=cost;}
    //get
    const int* getVanzari() { return vanzari; }
    const char* getNume() { return nume; }
    const int* getTip1() { return tip1; }
    int getNrProduse() { return nrProduse; }
    double getCost() { return cost; }
    int getNrBon() { return nrBon; }
    //operatori
    Client& operator = (const Client& obj)
    {
        if(this != &obj)
        {
        if (this->nume != NULL)
            delete[] this->nume;
        this->nume = new char[strlen(obj.nume) + 1];
        strcpy(this->nume, obj.nume);
        this->nrProduse = obj.nrProduse;
        this->cost = obj.cost;
        this->tip1 = new int[obj.nrProduse + 1];
        for (int i = 0; i < obj.nrProduse; i++)
        {
            this->tip1[i] = obj.tip1[i];
        }
        this->tip2 = new int[obj.nrProduse + 1];
        for (int i = 0; i < obj.nrProduse; i++)
        {
            this->tip2[i] = obj.tip2[i];
        }
        this->nrBon=obj.nrBon;
        this->vanzari = new int[obj.nrProduse + 1];
        for (int i = 0; i < obj.nrProduse; i++)
        {
            this->vanzari[i] = obj.vanzari[i];
        }

        }
        return *this;
    }
    Client& operator++()  //pre
    {
        this -> nrProduse++;
        int* vect = new int[this -> nrProduse];
        for (int i = 0; i < nrProduse - 1; i++)
            vect[i] = this -> tip1[i];
        vect[this -> nrProduse - 1] = 0;
        if (this -> tip1!= NULL)
            delete[] this -> tip1;
        this -> tip1 = vect;
        int* vect1 = new int[this -> nrProduse];
        for (int i = 0; i < nrProduse - 1; i++)
            vect1[i] = this -> tip2[i];
        vect1[this -> nrProduse - 1] = 0;
        if (this -> tip2!= NULL)
            delete[] this -> tip2;
        this -> tip2 = vect1;
        this->cost++;
        this->nrBon++;
        return *this;
    }

    Client operator++(int)  // post
    {
        Client copie = *this;
        this -> nrProduse++;
        int* vect = new int[this -> nrProduse];
        for (int i = 0; i < nrProduse - 1; i++)
            vect[i] = this -> tip1[i];
        vect[this -> nrProduse - 1] = 0;
        if (this -> tip1 != NULL)
            delete[] this -> tip1;
        this -> tip1 = vect;
        int* vect1 = new int[this -> nrProduse];
        for (int i = 0; i < nrProduse - 1; i++)
            vect1[i] = this -> tip2[i];
        vect1[this -> nrProduse - 1] = 0;
        if (this -> tip2 != NULL)
            delete[] this -> tip2;
        this -> tip2 = vect1;
        this->cost++;
        this->nrBon++;

        return copie;
    }
        Client operator+(const Client &obj)//2 ob din clasa
    {
        Client copie = *this;
        copie.nrProduse=copie.nrProduse+obj.nrProduse;
        int* newtip1 = new int[copie.nrProduse];
        for (int i = 0; i < this->nrProduse ; i++)
            newtip1[i]=this->tip1[i];
        for (int i = this->nrProduse; i < copie.nrProduse ; i++)
            newtip1[i]=obj.tip1[i-this->nrProduse];
            if(tip1!=NULL)
                delete[] tip1;
        copie.tip1=newtip1;
        return copie;
    }
    Client operator-(const Client &obj)
    {
        Client copie = *this;
        copie.nrProduse=abs(copie.nrProduse-obj.nrProduse);
        copie.nrBon=abs(copie.nrBon-obj.nrBon);
        copie.cost=abs(copie.cost-obj.cost);
        return copie;
    }
    Client operator +(int s) //cu din alta clasa in dr
    {
        Client copie=*this;
        copie.nrBon=copie.nrBon+s;
        copie.nrProduse=copie.nrProduse+s;
        copie.cost=copie.cost+s;
        return copie;
    }
    //cast
    operator int() // implicit
    {
        return this->nrBon;
    }

    operator int()const // explicit
    {
        return this->nrProduse;
    }
     int operator[] (int index)
    {
        if(index>=0 && index<this->nrProduse)
            return this->vanzari[index];
        else throw runtime_error("Index invalid");
    }


    bool operator < (const Client &obj)
    {
       return (this->nrProduse < obj.nrProduse) &&
           (this->cost < obj.cost) &&
           (this->nrBon < obj.nrBon);
    }

    bool operator == (const Client &obj)
    {
        return (this->nrProduse == obj.nrProduse) &&
           (this->cost == obj.cost) &&
           (this->nrBon == obj.nrBon);
    }
    bool operator >(const Client &obj)
    {
        int nr=0;
        for (int i=0;i<obj.nrProduse;i++)
            if (this->tip1[i]<obj.tip1[i] &&
                this->tip2[i] < obj.tip2[i])
                 nr++;
        if(nr!=0)
            return true;
        else return false;

    }

    Client operator+( Produs& produs)
   {
       Client copie=*this;
       copie.nrProduse += produs.getNrIngrediente();
       copie.nrBon += produs.getGreutate();
       return copie;
   }
    friend Produs operator+(Produs produs,  Client client);
    friend ostream& operator<<(ostream&, const Client&);
    friend istream& operator>>(istream&in, Client &obj);
    friend  void functieClient(Client x,double cost,const int *vanzari,int bon,int nrproduse);
    friend Client operator +(int s, Client obj);
       ~Client()
    {
        if(this->nume!=NULL)
                delete[] this->nume;
        if(this->tip1!=NULL)
                delete[] this->tip1;
        if(this->tip2!=NULL)
                delete[] this->tip2;
        if(this->vanzari!=NULL)
                delete[] this->vanzari;
    }
};

    Client operator +(int s, Client obj) //in stanga
{
    obj.nrProduse=obj.nrProduse+s;
    return obj;
}
    void functieClient(Client x,double cost,const int *vanzari,int bon,int nrproduse)
    {
        int costF,mx=0,prod;
        for (int i=0;i<nrproduse;i++)
        {
            costF=cost*x.vanzari[i];
            if (costF>mx)
            {
                mx=costF;
                prod=i;
            }
        }
        cout<<"cel mai scump produs este"<<prod<<" cu costul" <<mx;
    }
ostream& operator<<(ostream &out, const Client &obj){
    out << " Nume : " <<obj.nume << endl;
    out << "Numar produse: " << obj.nrProduse << endl;
    for(int i = 0; i < obj.nrProduse-1; i ++)
    {
        if(obj.tip1[i]==0)
            out << "Produsul " <<i<< " contine ciocolata" << endl;
        if(obj.tip1[i]==1)
            out << "Produsul " <<i<< " contine vanilie" << endl;
    }
    for(int i = 0; i < obj.nrProduse-1; i ++)
    {
        if(obj.tip2[i]==0)
            out << "Produsul " <<i<< " este de post" << endl;
        if(obj.tip2[i]==1)
            out << "Produsul " <<i<< " nu este de post" << endl;
    }
    out << "cost: " << obj.cost << endl;
    out << "numarul de pe bon:" << obj.nrBon << endl;
        for(int i = 0; i < obj.nrProduse; i ++)
    {
            out << "Produsul " <<i<< " a fost vandut de " << obj.vanzari[i] <<" ori" << endl;

    }

    return out;
}

istream& operator>>(istream &in, Client &obj){

    char nume1[100];
    cout<<"Nume : ";
    in.get();
    in.getline(nume1, 100);
    if(obj.nume != NULL)
        delete[] obj.nume;
    obj.nume = new char[strlen(nume1) + 1];
    strcpy(obj.nume, nume1);
    cout<<"Numar produse: ";
    in>>obj.nrProduse;
    if(obj.tip1 != NULL)
        delete[] obj.tip1;
    obj.tip1 = new int[obj.nrProduse+1];
    for(int i = 0; i < obj.nrProduse; i ++)
    {
        cout<<"de post sau nu: ";
        in>>obj.tip1[i];
    }
    if(obj.tip2 != NULL)
        delete[] obj.tip2;
    obj.tip2 = new int[obj.nrProduse+1];
    for(int i = 0; i < obj.nrProduse; i ++) {
        cout<<"cu ciocolata sau cu vanilie: ";
        in>>obj.tip2[i];
    }
    cout<<"cost: ";
    in>>obj.cost;
    cout<<"nrBon:";
    in>>obj.nrBon;
    if(obj.vanzari != NULL)
        delete[] obj.vanzari;
    obj.vanzari = new int[obj.nrProduse+1];
    for(int i = 0; i < obj.nrProduse; i ++)
    {
        cout<<"de cate ori a fost vandut: ";
        in>>obj.vanzari[i];
    }

    return in;
}
Produs operator+( Produs produs,  Client client)
{
    Produs copie = produs;
    copie.setNrIngrediente(copie.getNrIngrediente()+client.getNrProduse());
    copie.setGreutate(copie.getGreutate() + client.getNrBon());
    return copie;
}




void afisareMeniuBrutarie() {
    cout<<"\n 1.Adauga Brutarie\n";
    cout<<"\n 2.Afiseaza Brutariile\n";
    cout<<"\n 3.Functionalitate\n";
    cout<<"\n 4.Exit\n";
    cout<<"\n 5.Stergere\n";
}
void stergeBrutarie(vector<Brutarie>& brutarii) {
    if (brutarii.empty()) {
        cout << "Nu exista brutarii de sters!\n";
        return;
    }
    int index;
    cout << "Introduceti indexul brutariei pe care doriti sa o stergeti: ";
    cin >> index;
    if (index >= 0 && index < brutarii.size())
    {
        brutarii.erase(brutarii.begin() + index);
        cout << "Brutarie stearsa cu succes!\n";
    } else
        cout << "Index invalid!\n";

}

// Funcția de procesare a opțiunilor pentru clasa Brutarie
void procesareOptiuniBrutarie(vector<Brutarie>& brutarii)
{
    bool revenire = false;

    do {
        int optiune;
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                {
                // Adaugare Brutarie
                Brutarie s;
                cin >> s;
                brutarii.push_back(s);
                break;
              }
            case 2:
                 {
                // Afisare Brutarii
                if (brutarii.empty())
                  cout << "\nNu exista brutarii de afisat!\n";


                for (int i = 0; i < brutarii.size(); i++)
                    cout << brutarii[i];
                break;
            }
            case 3:
            {
                // functionalitate
                Brutarie s;
                cin>>s;
                const int* numar=s.getNrTel();
                int lungime=s.getLungimeTel();
                functionalitate (numar,lungime,s);
            }
            case 4:
                {
                    revenire=true;
                    break;
                }
            case 5:
                {
                    //stergere
                     stergeBrutarie(brutarii);
                     break;
                }
            default:
                cout << "Optiune invalida!\n";
                break;
        }
    } while (!revenire);

}

// Funcția de afișare a meniului pentru clasa Cuptor
void afisareMeniuCuptor()
{
    cout<<"\n 1. Adauga Cuptor\n";
    cout<<"\n 2. Afiseaza Cuptoarele\n";
    cout<<"\n 3. Functionalitate\n";
    cout<<"\n 4. Exit\n";
    cout<<"\n 5.Stergere\n";

}
void stergeCuptor(vector<Cuptor>& cuptoare) {
    if (cuptoare.empty())
    {
        cout << "Nu exista cuptoare de sterse.\n";
        return;
    }

    int index;
    cout<<"Introduceti indexul cuptorului de sters: ";
    cin>>index;

    if (index < 0||index >= cuptoare.size())
    {
        cout<<"\nIndexul cuptorului este invalid.\n";
        return;
    }
   else
   {
    cuptoare.erase(cuptoare.begin() + index);
    cout << "Cuptor sters cu succes.\n";
   }
}

// Funcția de procesare a opțiunilor pentru clasa Cuptor
void procesareOptiuniCuptor(vector<Cuptor>& cuptoare)
{
    bool revenire = false;

    do {
        int optiune;
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                {
                // Adaugare Cuptor
                Cuptor s;
                cin >> s;
                cuptoare.push_back(s);
                break;
              }
            case 2:
                 {
                // Afisare Cuptoare
                for (int i = 0; i < cuptoare.size(); i++)
                    cout << cuptoare[i];
                break;
            }
            case 3:
            {
                // functionalitate
                Cuptor x;
                cin >> x;
                const int* locurio = x.getlocuriOcupate();
                int locuri = x.getnrLocuri();
                int g = x.getGarantie();
                int an = x.getAnFabricatie();
                bool deschidere = x.getdeschidere();
                functionalitateCuptor(locuri, locurio, g, an,x, deschidere);
                break;

            }
            case 4:
                {
                    revenire=true;
                    break;
                }
            case 5:
                {
                    //stergere
                    stergeCuptor(cuptoare);
                    break;
                }
            default:
                cout << "Optiune invalida!\n";
                break;
        }
    } while (!revenire);


}

// Funcția de afișare a meniului pentru clasa Client
void afisareMeniuClient() {
    cout<<"\n 1.Adauga Client\n";
    cout<<"\n 2.Afiseaza Clientii\n";
    cout<<"\n 3.Functionalitate\n";
    cout<<"\n 4.Exit\n";
    cout<<"\n 5.Stergere\n";
}
void stergeClient(vector<Client>& clienti)
{
    int index;
    cout << "Introduceti indexul clientului pe care doriti sa-l stergeti: ";
    cin >> index;

    if (index>=0 && index < clienti.size())
    {
        clienti.erase(clienti.begin() + index);
        cout << "Clientul a fost sters cu succes!\n";
    }
    else
        cout << "Indexul specificat este invalid!\n";

}


// Funcția de procesare a opțiunilor pentru clasa Client
void procesareOptiuniClient(vector<Client>& clienti)
{
    bool revenire=false;

    do {
        int optiune;
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune)
        {
            case 1:
                {
                // Adaugare Client
                Client b;
                cin >> b;
                clienti.push_back(b);
                break;
            }
            case 2:
            {
                // Afisare Clienti
                for (int i = 0; i < clienti.size(); i++)
                    cout << clienti[i];
                break;
            }
            case 3:
                {
                // Functionalitate
                  Client c;
                  cin>>c;
                  double  cost=c.getCost();
                  const int* vanzari = c.getVanzari();
                  int nrproduse=c.getNrProduse();
                  int bon=c.getNrBon();
                  functieClient(c,cost,vanzari,bon,nrproduse);

            }
            case 4:
            {
                // Revenire la meniul principal
                revenire=true;
                break;
            }
            case 5:
                {
                    //stergere
                    stergeClient(clienti);
                    break;
                }

            default:
                cout << "Optiune invalida!\n";
                break;
        }
    } while (!revenire);


}

// Funcția de afișare a meniului pentru clasa Produs
void afisareMeniuProdus() {
    cout<<"\n 1. Adauga Produs\n";
    cout<<"\n 2. Afiseaza Produsele\n";
    cout<<"\n 3. Functionalitate\n";
    cout<<"\n 4. Exit\n";
    cout<<"\n 5.Stergere\n";
}
void stergeProdus(vector<Produs>& produse)
{
    int index;
    cout << "Introduceti indexul produsului pe care doriti sa-l stergeti: ";
    cin >> index;

    if (index>=0&&index<produse.size())
    {
        produse.erase(produse.begin() + index);
        cout << "Produsul a fost sters cu succes!\n";
    } else
        cout << "Indexul specificat este invalid!\n";

}

// Funcția de procesare a opțiunilor pentru clasa Produs
void procesareOptiuniProdus(vector<Produs>& produse)
 {
    bool revenire = false;

    do {
        int optiune;
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                {
                    Produs p;
                    cin >> p;
                    produse.push_back(p);
                    break;
                }

            case 2:
                {
                    // Afisare Produse
                    for (int i = 0; i < produse.size(); i++)
                        cout << produse[i];
                    break;
                }

            case 3:
                {
                    // Functionalitate
                    Produs p;
                    cin >> p;
                    int numarIngrediente = p.getNrIngrediente();
                    bool tip1 = p.getTip1();
                    int timp = p.getTimpCoacere();
                    BioProdus(p, numarIngrediente, tip1, timp);
                    break;
                }

            case 4:
                {
                    // Revenire la meniul principal
                    revenire = true;
                    break;
                }
            case 5:
                {
                    //stergere
                    stergeProdus(produse);
                    break;
                }

            default:
                cout << "Optiune invalida!\n";
                break;
        }
    } while (!revenire);
}
int main()
{
    vector<Brutarie> brutarii;
    vector<Cuptor> cuptoare;
    vector<Client> clienti;
    vector<Produs> produse;
    int k=1;
    int optiune;
    while (k==1)
    {
        cout << "\n-- Meniu Principal --\n";
        cout << "\n 1. Meniu Brutarii\n";
        cout << "\n 2. Meniu Cuptoare\n";
        cout << "\n 3. Meniu Clienti\n";
        cout << "\n 4. Meniu Produse\n";
        cout << "\n 5. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune)
        {
            case 1:
                {
                // Afisare meniu Brutarie
                afisareMeniuBrutarie();
                // Procesare opțiuni Brutarie
                procesareOptiuniBrutarie(brutarii);
                break;
                }
            case 2:
                {
                // Afisare meniu Cuptor
                afisareMeniuCuptor();
                //Procesare optiuni Cuptor
                procesareOptiuniCuptor(cuptoare);
                break;
                }
            case 4:
                {
                // Afisare meniu Produs
                afisareMeniuProdus();
                //Procesare optiuni Produs
                procesareOptiuniProdus(produse);
                break;
                }
            case 3:
                {
                // Afisare meniu Client
                afisareMeniuClient();
                //Procesare optiuni Client
                procesareOptiuniClient(clienti);
                break;
                }
            case 5:
                {
                    //Exit
                    k=0;
                    cout<<"La revedere!";
                    break;
                }

        }
    }
        return 0;
}



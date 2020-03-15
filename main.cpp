#include <iostream>
#include <string.h>
#include <bits/stdc++.h>


using namespace std;


class Nod
{

private:
    char info;
    Nod* next;
    friend class Stiva_de_caractere;

public:
    Nod(char a = NULL, Nod* b = NULL)
    {
        this->info = a;
        this->next = b;
    }
    ~Nod()
    {
        this->info = NULL;
        this->next = NULL;
    }
};


class Stiva_de_caractere
{

private:
    Nod* varf = new Nod;

public:

    Stiva_de_caractere()
    {
        varf->info = NULL;
    }
    ~Stiva_de_caractere()
    {

        while(!this->isEmpty())
        {

            varf = varf->next;
        }



    }
    void push(char x);
    char pop();
    void top();
    bool isEmpty();
    void afisare();

    friend istream& operator >> (istream& in, Stiva_de_caractere& b);
    friend ostream& operator << (ostream& os, Stiva_de_caractere& vf);
    friend Stiva_de_caractere& operator -(Stiva_de_caractere& S1, Stiva_de_caractere& S2);

    void inversare(char str[]);
    void diferenta(Stiva_de_caractere S1, Stiva_de_caractere S2);

};


void Stiva_de_caractere::push(char x)
{

    Nod* chr = new Nod;

    chr->info = x;
    chr->next = varf;
    varf = chr;

}


char Stiva_de_caractere :: pop()
{
    if(this->isEmpty())
    {
        cout<<"Stiva e vida!"<<endl;
        return 0;
    }

    char x = varf->info;
    varf = varf->next;
    return x;
}


bool Stiva_de_caractere ::isEmpty()
{
    return varf == NULL;
}


void Stiva_de_caractere ::afisare()
{
    if(this->isEmpty())
    {
        cout<<"Stiva e vida!"<<endl;

    }


    Nod *temp = varf;
    while(temp != NULL)
    {
        cout<<temp->info<<' ';
        temp = temp->next;
        this->pop();
    }
    cout<<endl;
}

istream& operator >> (istream& in, Stiva_de_caractere& b)
{
    b.pop();
    cout<<"Dati caracter: ";
    char c;
    in>>c;
    while(c != '.')
    {

        b.push(c);
        cout<<"Dati caracter: ";
        in>>c;

    }


}


ostream& operator <<(ostream& os, Stiva_de_caractere& vf)
{
    vf.afisare();

}

void Stiva_de_caractere ::top()
{

    cout<<varf->info;

}

void Stiva_de_caractere:: inversare(char str[])
{
    int n = strlen(str);

    for (int i = 0; i<n; i++)
        this->push(str[i]);

    for (int i = 0; i<n; i++)
        str[i] = this->pop();
}


inline Stiva_de_caractere& operator -(Stiva_de_caractere& S1, Stiva_de_caractere& S2)
{


    Stiva_de_caractere S;

    char S1_caracter, S2_caracter;

    while(!S1.isEmpty() && !S2.isEmpty())
    {

        S1_caracter = S1.pop();
        S2_caracter = S2.pop();

        if(S1_caracter != NULL && S2_caracter != NULL)
        {
            if(S1_caracter > S2_caracter)

                S.push(S1_caracter);
            else

                S.push(S2_caracter);
        }

    }


    cout<<"Stiva rezultata este: ";
    Stiva_de_caractere S3;


    while(!S.isEmpty())
    {
        S3.push(S.pop());
    }
    S3.pop();
    S3.afisare();

    cout<<endl;

}





int main()
{
    Stiva_de_caractere *a, *b, c, e;
    int n=0;
    int d=0;
    char ch;


    do
    {
        int m;
        cout<<"\t\t\tMihaila Mihai-Gabriel - Grupa: 212 - Proiect: 4 - Stiva de caractere"<<endl;
        cout<<"\n\n\t\t\t\t\t\t\tMENIU\n\n";
        cout<<"========================================================================================================================"<<endl;
        cout<<"\n\t1.Popularea a n stive\n";
        cout<<"\t2.Scoaterea unui caracter dintr-o stiva\n";
        cout<<"\t3.Returnarea varfului stivei\n";
        cout<<"\t4.Verificare daca stiva este vida\n";
        cout<<"\t5.Afisarea stivei concomitent cu golirea ei\n";
        cout<<"\t6.Inversarea unui cuvant\n";
        cout<<"\t7.Diferenta a doua stive\n";
        cout<<"\t0.Iesire.\n\n";
        cout<<"========================================================================================================================\n\n";
        cout<<"\nIntroduceti o actiune: ";
        cin>>m;

        switch(m)
        {
        case 1:
            system("CLS");               /// citire stive

            cout<<"Introduceti numarul de stive: ";
            cin>>n;
            cout<<endl;
            a = new Stiva_de_caractere[n];
            cout<<"Pentru a termina citirea introduceti caracterul '.' si apasati ENTER"<<endl;
            for(int i = 0; i < n; i++)
            {
                cout<<endl<<"Introduceti caractere pentru stiva "<<i+1<<endl;
                cin>>a[i];
            }

            break;

        case 2:
            ///  pop()
            char caracterSters;
            if(n==0)
            {
                cout<<"Nu exista stiva!"<<endl;
                break;
            }
            system("CLS");
            cout<<"Din ce stiva doriti sa scoateti?"<<endl;
            cin>>d;

            while(d>n)
            {
                cout<<"Numarul stivei e invalid"<<endl<<"Introduceti un numar valid"<<endl;
                cin>>d;

            }

            caracterSters = a[d-1].pop();
            if (caracterSters == 0)
                cout<<"Eroare la stergere!"<<endl;
            else
                cout<<"Caracterul '"<<caracterSters<<"' a fost sters cu succes."<<endl;
            break;




        case 3:
            ///    top()
            if(n == 0)
            {
                cout<<"Nu exista stiva!"<<endl;
                break;
            }
            system("CLS");
            cout<<"Introduceti stiva al carei varf vreti sa il aflati: ";

            cin>>d;
            cout<<endl;
            if(!a[d-1].isEmpty())
            {
                cout<<"Varful stivei "<<d<<" este: ";

                a[d-1].top();
                cout<<endl;
            }
            else
                cout<<"Stiva e vida!"<<endl;



            break;

        case 4:
            system("CLS");                            ///      isEmpty()
            bool eVida;
            if (n==0)
            {
                cout<<"Nu exista stiva!"<<endl;
                break;
            }

            cout<<endl;
            for (int i = 0; i < n; i++)
            {
                eVida = a[i].isEmpty();
                if(eVida == 0)
                    cout<<"Stiva "<<i+1<<" nu e vida."<<endl;
                else
                    cout<<"Stiva "<<i+1<< " e vida!"<<endl;
            }

            break;

        case 5:
            system("CLS");                                     ///   cout<<
            if (n == 0)
            {
                cout<<"Nu exista stiva!"<<endl;
                break;
            }
            for(int i = 0; i< n; i++)
            {
                cout<<"Stiva "<<i+1<<" este: ";
                cout<<a[i]<<endl;
            }

            break;

        case 6:                                    /// inversare cuvand
            system("CLS");
            char str[256];
            cout<<"Introduceti cuvantul"<<endl;
            cin>>str;
            b = new Stiva_de_caractere;
            b->inversare(str);
            cout<<"In urma inversarii cuvantul a devenit: ";
            cout<<str<<endl;
            delete b;
            break;

        case 7:

            /// diferenta de stive
            system("CLS");
            cout<<"Dati valori pentru prima stiva:"<<endl;
            cin>>c;
            cout<<endl<<"Dati valori pentru a doua stiva:"<<endl;
            cin>>e;
            cout<<endl;

            c-e;

            break;

        case 0:
            cout<<endl;
            cout<<"\tExit"<<endl;
            return 0;


        default:
            cout<<"Alegere nevalida\n";
        }

        cout<<endl<<"Pentru a efectua alta operatie apasati tasta D ";
        cin>>ch;
        system("CLS");

    }
    while(ch == 'd' || ch == 'D');



    return 0;
}

/*
Se dă un şir de caractere S format din litere mari şi mici ale alfabetului englez, spaţii şi caracterul ⌂ ce are codul ASCII 127. 
Fiecare caracter al lui S se codifică printr-o succesiune de 1 şi 0 ce reprezintă codul ASCII al caracterului în baza 2. 
Codul începe cu cifra 1, astfel pentru caracterul A codificarea este 1000001. Un cuvânt poate fi format din litere şi caracterul ⌂. 
Se consideră matricea M formată din cuvintele șirului S codificate şi memorate pe câte o linie în ordinea în care se găsesc acestea în propoziție. 
Scrieţi un program care, cunoscând S şi K, rezolvă următoarele două cerinţe:
1. determină L, latura celui mai mare pătrat din matricea M ce conține doar valori de 1;
2. determină NR, câte pătrate de latura K cu toate elementele egale cu 1 există în matricea M.

Citire:
Pe prima linie cerinţa care trebuie să fie rezolvată (1 sau 2). Pe a doua linie se află șirul S, iar pe a treia linie se află valoarea K

Afișare:
Dacă cerinţa este 1, va fi scris L, latura celui mai mare pătrat din matricea M ce conține doar valori de 1.
Dacă cerinţa este 2, va fi scris NR, câte pătrate de latura K cu toate elementele egale cu 1 există în matricea M.
*/

#include <iostream>
#include <cstring>

using namespace std;

bool M[800][300];
//lMax = latura celui mai mare pătrat din matricea M ce conține doar valori de 1; 
//nr = numărul de pătrate de latura K cu toate elementele egale cu 1 există în matricea M
//nivel = numarul de cuvinte/numarul de linii a matricei binare
//jMax = numarul de litere a celui mai lung cuvant/numarul de coloane a matricei binare
int cerinta,K,jMax=1,lMax=0,nivel=0,nr=0,coloanaM;
char sirCaractere[3000];

void tobinary(int x);
bool patrat(int x,int y,int l);

int main()
{
    cin>>cerinta;
    cin.get();
    cin.getline(sirCaractere,3000);
    cin>>K;

    //tokenizarea sirului de caractere dat
    char *p=strtok(sirCaractere," ");
    while(p)
    {
        coloanaM=1;
        nivel++;
        for(int i=0; i<int(strlen(p)); i++)
            tobinary(int (p[i]));
        p=strtok(NULL," ");
    }
    
    //Afisarea matricei de cuvinte in cod binar(fiecare linie este un cuvant convertit in cod binar)
    for(int i=1;i<=nivel;i++)
    {     
        for(int j=1;j<=jMax-1;j++)
            cout<<M[i][j]<<' ';
        cout<<endl;
    }

    // se determină latura celui mai mare pătrat din matricea M ce conține doar valori de 1
    if(cerinta==1)
    {
        for(int l=1; l<=lMax+1; l++)
            for(int i=1; i<=nivel; i++)
                for(int j=1; j<=jMax; j++)
                    if(patrat(i,j,l)) 
                        lMax=l, i=nivel+1,j=jMax+1;
        cout<<lMax;
    }
    else
    // se determină câte pătrate de latura K cu toate elementele egale cu 1 există în matricea M 
    if(cerinta==2)
    {
        for(int i=1; i<=nivel; i++)
            for(int j=1; j<=jMax; j++)
                if(patrat(i,j,K))
                    nr++;
        cout<<nr;
    }

}

//convertire in cod binar 
void tobinary(int x)
{
    for(int i=64; i>=1; i/=2,coloanaM++)
    {
        if(x-i>=0)
        {
            x-=i;
            M[nivel][coloanaM]=1;
        }
        else
            M[nivel][coloanaM]=0;
    }
    if(coloanaM>jMax)
        jMax=coloanaM;
}

bool patrat(int x,int y,int l)
{
    for(int i=x;i<=x+l-1;i++)
        for(int j=y;j<=y+l-1;j++)
            if(M[i][j]==0)
                return false;
    return true;
}
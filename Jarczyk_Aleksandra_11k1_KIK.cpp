#include <iostream>
#include <cstdlib>
#include <conio.h>


using namespace std;

void komputer();

char plansza[3][3];
char symbole[2];
bool sprawdz(char symbol)
{
    if((plansza[0][0] == symbol) && (plansza[1][1] == symbol) && (plansza[2][2] == symbol)) return true;

    if((plansza[0][2] == symbol) && (plansza[1][1] == symbol) && (plansza[2][0] == symbol)) return true;



    for(int i = 0; i < 3; i++)
    {

        if((plansza[i][0] == symbol) && (plansza[i][1] == symbol) && (plansza[i][2] == symbol)) return true;

        if((plansza[0][i] == symbol) && (plansza[1][i] == symbol) && (plansza[2][i] == symbol)) return true;
    }
    return false;
}
void wyswietl_plansze()

{
    for(int i=0; i<3; i++)
    {
        cout<<"-------------------------------------------------"<<endl<<"|\t";
        for(int j=0; j<3; j++)
        {
            cout<<plansza[i][j]<<"\t|\t";
        }
        cout<<endl;
    }
    cout<<"-------------------------------------------------"<<endl;
}


int main()
{
    char opcja = ' ';
    while(opcja!='q')
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                plansza[i][j]=' ';
            }
        }

        int x,y;
        bool wygrana=false;
        char kto_wygral = ' ';
        int kto_zaczyna;
        while(true)
        {
            cout<<"Wybierz rozpoczynajacego gracza 0 - kolko, 1 - krzyzyk : ";
            cin>>kto_zaczyna;
            if(kto_zaczyna==0 || kto_zaczyna==1) break;


        }
        for(int i=0; i<9; i++)
        {
            cout<<"Tura: "<<i<<endl;
            wyswietl_plansze();
            if(i%2==kto_zaczyna)
            {
                while(true)
                {
                    cout<<"Podaj x i y: "<<endl;
                    cin>>x>>y;
                    if(plansza[x][y]==' ')
                    {
                        plansza[x][y]='O';
                        break;
                    }
                    cout<<"To miejsce jest zajete"<<endl;
                }
            }
            else
            {
                komputer();
            }

            if(sprawdz('O'))
            {
                wygrana=true;
                kto_wygral='O';
                wyswietl_plansze();
                break;
            }

            if(sprawdz('X'))
            {
                wygrana=true;
                kto_wygral='X';
                wyswietl_plansze();
                break;
            }
        }
        if(wygrana) cout<<"Zwyciezyl gracz "<<kto_wygral<<endl;
        else
        {
            wyswietl_plansze();
            cout<<"Remis"<<endl;
        }
        cout<<"Wpisz q aby przerwac lub cokolwiek by kontynuowac"<<endl;
        cin>>opcja;
    }
    return 0;
}

bool remis()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(plansza[i][j] == ' ') return false;
        }
    }
    return true;
}

//minmax


int minimax(char gracz)
{
    int m, mmx;

    if(sprawdz(gracz)) return (gracz == 'X') ? 1 : -1;

    if( remis()) return 0;


    gracz = (gracz == 'X') ? 'O' : 'X';


    mmx = (gracz == 'O') ? 100000 : -100000;


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(plansza[i][j] == ' ')
            {
                plansza[i][j] = gracz;
                m = minimax(gracz);
                plansza[i][j] = ' ';
                if(((gracz == 'O') && (m < mmx)) || ((gracz == 'X') && (m > mmx))) mmx = m;
            }
        }
    }
    return mmx;
}


void komputer()
{
    int ruch[2]= {0,0}, i, m, mmx;

    mmx = -100000;
    for(i = 0; i <3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(plansza[i][j] == ' ')
            {
                plansza[i][j] = 'X';
                m = minimax('X');
                plansza[i][j]= ' ';
                if(m > mmx)
                {
                    mmx = m;
                    ruch[0] = i;
                    ruch[1] = j;
                }
            }
        }
    }
    plansza[ruch[0]][ruch[1]] = 'X';
}


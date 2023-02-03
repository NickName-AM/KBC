#include <iostream>
using namespace std;
void gotoxy(short y,short x)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void start_page()
{

   int i;
    gotoxy(1,10);
    for(i=0;i<115;i++)
    {
        cout<<"=";
    }

    for (i=0;i<26;i++)
    {
        gotoxy(i+1,9);
        cout << "{";
        gotoxy(i+1,125);
        cout << "}";
    }

    gotoxy(26,10);
    for(i=0;i<115;i++)
    {
        cout<<"=";
    }

  	gotoxy(1,10);cout<<"▓▓   ▓▓   ▓▓▓▓▓▓       ▓▓▓▓▓▓▓   ▓▓▓▓▓▓  ▓▓    ▓▓ ▓▓    ▓▓  ▓▓▓▓▓▓ ";
    gotoxy(2,10);cout<<"▓▓   ▓▓  ▓▓    ▓▓      ▓▓    ▓▓ ▓▓    ▓▓ ▓▓▓   ▓▓ ▓▓    ▓▓ ▓▓    ▓▓";
    gotoxy(3,10);cout<<"▓▓  ▓▓   ▓▓    ▓▓      ▓▓    ▓▓ ▓▓    ▓▓ ▓▓▓▓  ▓▓  ▓▓  ▓▓  ▓▓    ▓▓";
    gotoxy(4,10);cout<<"▓▓▓▓▓    ▓▓    ▓▓      ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓ ▓▓ ▓▓ ▓▓   ▓▓▓▓   ▓▓▓▓▓▓▓▓";
    gotoxy(5,10);cout<<"▓▓  ▓▓   ▓▓    ▓▓      ▓▓    ▓▓ ▓▓    ▓▓ ▓▓  ▓▓▓▓  ▓▓  ▓▓  ▓▓    ▓▓";
    gotoxy(6,10);cout<<"▓▓   ▓▓  ▓▓    ▓▓      ▓▓    ▓▓ ▓▓    ▓▓ ▓▓   ▓▓▓ ▓▓    ▓▓ ▓▓    ▓▓";
    gotoxy(7,10);cout<<"▓▓    ▓▓  ▓▓▓▓▓▓       ▓▓▓▓▓▓▓  ▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓";
    gotoxy(9,47);cout<<" ▓▓▓▓▓▓  ▓▓▓▓▓▓▓   ▓▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓   ▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓ ▓▓▓▓▓▓";
    gotoxy(10,47);cout<<"▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓ ▓▓       ▓▓    ▓▓ ▓▓    ▓▓    ▓▓      ▓▓  ";
    gotoxy(11,47);cout<<"▓▓       ▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓ ▓▓       ▓▓    ▓▓ ▓▓    ▓▓    ▓▓      ▓▓  ";
    gotoxy(12,47);cout<<"▓▓       ▓▓▓▓▓▓▓  ▓▓    ▓▓ ▓▓▓▓▓▓▓  ▓▓▓▓▓    ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓    ▓▓      ▓▓  ";
    gotoxy(13,47);cout<<"▓▓       ▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓ ▓▓       ▓▓       ▓▓    ▓▓    ▓▓      ▓▓  ";
    gotoxy(14,47);cout<<"▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓ ▓▓       ▓▓       ▓▓    ▓▓    ▓▓      ▓▓  ";
    gotoxy(15,47);cout<<" ▓▓▓▓▓▓  ▓▓    ▓▓  ▓▓▓▓▓▓  ▓▓    ▓▓ ▓▓▓▓▓▓▓▓ ▓▓       ▓▓    ▓▓    ▓▓    ▓▓▓▓▓▓";
}

void help()
{
    int i;
    gotoxy(1,10);
    for(i=0;i<115;i++)
    {
        cout<<"=";
    }

    for (i=0;i<26;i++)
    {
        gotoxy(i+1,9);
        cout << "{";
        gotoxy(i+1,125);
        cout << "}";
    }

    gotoxy(26,10);
    for(i=0;i<115;i++)
    {
        cout<<"=";
    }

    gotoxy(3,65);cout<<"RULES";
    gotoxy(6,12);cout<<"1.Player must play fairly";
    gotoxy(7,12);cout<<"2.Enter the no displayed on the screen for input";
    gotoxy(8,12);cout<<"3.The question begins with 1k and ends with 7 crore at the 15th Question";
    gotoxy(9,12);cout<<"4.There are 2 checkpoints at 4th Question and 8th Question";
    gotoxy(10,12);cout<<"5.If you give wrong Answer you automatically fall back to your current checkpoints and your game ends";
    gotoxy(11,12);cout<<"6.You have 30 seconds until 7th question.From the begin of 8th Question you have unlimited time";
    gotoxy(12,12);cout<<"7.If your time is up then it is equivalent to wrong answer";
    gotoxy(13,12);cout<<"8.You can quit the game to play safe and you win the reward of previous question";
    gotoxy(16,60);cout<<"BEST OF LUCK!!!";
}
void symbolPrinter(char symbol, int no){
    int i;
    for (i=0; i<no; ++i)
        cout << symbol;
    cout << endl;
}
void breakthrough_box()
{
     gotoxy(24,75);symbolPrinter('_', 46);
        gotoxy(6,76);symbolPrinter('.', 45);
        gotoxy(8,76);symbolPrinter('.', 45);
        gotoxy(4,76);symbolPrinter('_', 45);

        for(int i=0;i<20;i++)
        {
             gotoxy(5+i,75) ;cout<<"|";
             gotoxy(5+i,121) ;cout<<"|";
        }
        gotoxy(4,75);cout<<"*";
        gotoxy(4,121);cout<<"*";
        gotoxy(25,75);cout<<"*";
        gotoxy(25,121);cout<<"*";
}
void draw_boundary()
{
     int i;
    gotoxy(1,10);
    for(i=0;i<115;i++)
    {
        cout<<"=";
    }

    for (i=0;i<26;i++)
    {
        gotoxy(i+1,9);
        cout << "{";
        gotoxy(i+1,125);
        cout << "}";
    }

    gotoxy(26,10);
    for(i=0;i<115;i++)
    {
        cout<<"=";
    }
    breakthrough_box();
}



string requestName()
{
    string username;
    gotoxy(18,17);
    symbolPrinter(' ',100);
    gotoxy(19,60);
    cout<<"Enter your name ";
    gotoxy(21,59);
    cout<<">>   ";
    cin>>username;
    return username;

}

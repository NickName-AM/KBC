#include <iostream>
#include<ctime>
#include<conio.h>



using namespace std;
void gotoxy(short y,short x)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void symbolPrinter(char symbol, int no){
    int i;
    for (i=0; i<no; ++i)
        cout << symbol;
    cout << endl;
}
void counter(int current,int SR)
{
   static int last=100;
        static int seconds=20;
        if(current>7)
        {
            gotoxy(2,20);cout<<"You have unlimited time ";gotoxy(12,22);
            return;
        }
        if(SR==1)
        {
            if(current>3)
            {
            seconds=40;
            }
            else
            {
                seconds=30;
            }
        }

        while(!kbhit())
        {

        gotoxy(2,36);symbolPrinter(' ',4); gotoxy(2,20);cout<<"Time Remaining: "<<seconds<<"s";gotoxy(12,22);
        Sleep(950);seconds=(seconds==0)?0:(seconds-1);
        last=current;
        }
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
    gotoxy(13,12);cout<<"8.You can Leave the game to play safe and you win the reward of previous question";
    gotoxy(14,12);cout<<"8.You cannot use another Lifeline after using X2 or 50:50 in same qustion";
    gotoxy(15,12);cout<<"9.You Have to Press enter only while Choosing Option and Lifeline else no need to press Enter";
    gotoxy(18,60);cout<<"BEST OF LUCK!!!";
}

void breakthrough_box()
{
        gotoxy(3,76);symbolPrinter('_', 45);
        gotoxy(5,76);symbolPrinter('.', 45);
        gotoxy(8,76);symbolPrinter('.', 45);
     gotoxy(24,75);symbolPrinter('_', 46);

        for(int i=0;i<23;i++)
        {
             gotoxy(2+i,75) ;cout<<"|";
             gotoxy(2+i,121) ;cout<<"|";
        }
        gotoxy(2,75);cout<<"*";
        gotoxy(2,121);cout<<"*";
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

}



string request_Name()
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

void chequeBox()
{
     gotoxy(5,23);symbolPrinter('_',87);
    gotoxy(22,24);symbolPrinter('_',86);
    for(int i=0;i<17;i++)
    {
        gotoxy(6+i,23);cout<<"|";
        gotoxy(6+i,110);cout<<"|";
    }
     gotoxy(23,23);cout<<"|";
     gotoxy(5,23);cout<<"*";gotoxy(5,110);cout<<"*";
     gotoxy(23,23);cout<<"*";gotoxy(23,110);cout<<"*";
     gotoxy(6,64);cout<<"CHEQUE";
     gotoxy(18,30);cout<<"Signed By: Abik Maharjan, Dipesh Shrestha, Palden Gurung, Saugat Maharjan";
     gotoxy(21,59);cout<<"Copyright \u00A9 2022";
     gotoxy(24,14);cout << "Quit[2]" << endl;
     gotoxy(24,114);cout<<"Next[1]";
     gotoxy(10,55);
     time_t givemetime = time(NULL);
     cout<< ctime(&givemetime); //ctime() returns given time
     gotoxy(24,68);
}

void Cheque(int currentposition)
{
    chequeBox();
    string money[] = {"0","5K", "10K", "20K", "40K", "80K", "1.6Lakh", "3.2Lakh", "6.4Lakh", "12.5Lakh", "25Lakh", "50Lakh", "1 Crore", "3 Crore", "5 Crore", "7 Crore"};
    if(currentposition==0)
    {
    gotoxy(13,56);cout<<"Sorry :( You have won RS "<<money[currentposition];
    }
    else
    {
    gotoxy(13,50);cout<<"Congratulation!!! :) You have won RS "<<money[currentposition];
    }


}
void rightAnswer()
{
            gotoxy(13,15);cout<<"You have entered correct answer";
            gotoxy(16,38);cout<<"Next  [1]";
            gotoxy(16,47);
            do
            {
                if(getch()=='1')
                    break;
            }while(true);

}
void wrongAnswer()
{
     gotoxy(13,15);cout<<"You have entered Incorrect answer";
            gotoxy(16,38);cout<<"Next  [1]";
            gotoxy(16,47);
            do
            {
                if(getch()=='1')
                    break;
            }while(true);

}
void timeUp()
{
     gotoxy(13,15);cout<<"Your time is up, You gave answer in more than 20 sec";
            gotoxy(16,38);cout<<"Next  [1]";
            gotoxy(16,47);
            do
            {
                if(getch()=='1')
                    break;
            }while(true);

}
void anotherGameStart()
{
    char newinput;
     inputagain:
            newinput=getch();
            if(newinput=='1')
            {
                system("cls");
                //goto NewGame;
                return;
            }
            else if(newinput=='2')
            {
                system("cls");
                exit(0);
            }
            else
            {
                goto inputagain;
            }
}
void lifelineUsed(int current,int SR)
{
    gotoxy(14,15);cout<<"Lifeline used already!!!   ";
                cout<<"Enter again  [1]";
                Pressagain:
                counter(current,SR);
                if(getch()=='1')
                {
                    gotoxy(14,15);symbolPrinter(' ',50);
                    return;
                }
                else
                {
                    goto Pressagain;
                }
}
int removeOption1(int validOption,int correctAnswer)
{
    int a;
    int B[] = {1,2,3,4};
    for (int i=0;i<4;i++)
                {
                    if (B[i] != validOption && B[i] != correctAnswer)
                    {
                        a = B[i];
                        break;
                    }
                }
                return a;

}
int removeOption2(int validOption,int correctAnswer,int A)
{
    int c;
    int B[] = {1,2,3,4};
    for (int i=0;i<4;i++)
                {
                    if ((B[i] != validOption && B[i] != correctAnswer) && B[i] != A)
                    {
                        c = B[i];
                        break;
                    }
                }
                return c;

}

char guessAfterLifeline(int Current,int SR)
{

        char guessAnswer;
        do{
                againInsidedouble:
                gotoxy(12,20);symbolPrinter(' ',50);
                gotoxy(12,15);symbolPrinter(' ',11);
                gotoxy(19,35);cout<<"Special Note!!";
                gotoxy(21,17);symbolPrinter(' ',54);
                gotoxy(22,30);symbolPrinter(' ',11);
                gotoxy(21,23);cout<<"You cannot use another Lifeline after";
                gotoxy(22,25);cout<<"using X2 or 50:50 in same qustion";

                gotoxy(24,37);cout<<"LEAVE: [8]";
                gotoxy(12,15);cout<<"INPUT: ";
                counter(Current,SR);
                guessAnswer=getch();
                gotoxy(12,22);cout<<guessAnswer;
                counter(Current,SR);
                gotoxy(12,23);char temp=getch();


                if(temp=='\r' && ((guessAnswer>48 && guessAnswer<53)||guessAnswer==56))
                {
                    break;
                }
                else
                    goto againInsidedouble;


            }while(true);
            return guessAnswer;


}
int randomNumber(int A,int B)
{
    srand(time(0));
    int random = int(rand()%(B-A+1))+ A;
    return random;
}

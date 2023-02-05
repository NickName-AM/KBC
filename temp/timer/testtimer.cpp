#include <iostream>
#include <string>
#include <windows.h>
#include <atomic>
#include<vector>
using namespace std;
void gotoxy(short y,short x)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

   vector <int> input;
atomic<bool> stop_timer(false);
   DWORD WINAPI Timer(LPVOID lpParameter)
{
    int a;
     cout<<endl;
    Sleep(2000);
    int seconds, time,i;
    seconds=12;
    time=seconds;

    for(i=time;i>=0;i--)
    {

        gotoxy(4,20);cout<<"\b\b\b";

        if(seconds>9)
        {
        cout<<seconds<<"s";
        gotoxy(5,50);cout<<" ";
        }
        else
        {
        cout<<"0";
        cout<<seconds;
         gotoxy(5,50);cout<<" ";
        }
        seconds=(seconds==0)?0:--seconds;
        input.push_back(seconds);
        Sleep(1000);


    }

gotoxy(5,50);cout<<" ";
        return  0;
}


int main()
{

int i=0;

    int name;
    int question_duration = 30; // duration of the timer in seconds

    cout << "A question has been asked. You have " << question_duration << " seconds to answer." << endl;

    HANDLE timer_handle = CreateThread(NULL, 0, Timer, &question_duration, 0, NULL);


    stop_timer=true;
    int stop_timer=WaitForSingleObject(timer_handle, INFINITE);
    while(stop_timer==true)
    {
        if(input[i]==0)
        {
            break;
        }

        gotoxy(5,30); cout << "What is your name:";
        gotoxy(5,50);cin >> name;
        gotoxy(6,50);cout<<name;

            i++;
    }

    gotoxy(5,30); cout << "What is:";
    CloseHandle(timer_handle);



    /*WaitForSingleObject(timer_handle, INFINITE);
    CloseHandle(timer_handle);*/

    // Add your code here to check the user's answer and continue the game

    return 0;
}



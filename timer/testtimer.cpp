#include <iostream>
#include <string>
#include <windows.h>
#include <atomic>
using namespace std;
void gotoxy(short y,short x)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

atomic<bool> stop_timer(false);
   DWORD WINAPI Timer(LPVOID lpParameter)
{
    int a;
     cout<<endl;
    Sleep(2000);
    int seconds, time,i;
    seconds=30;
    time=seconds;

    for(i=time;i>0;i--)
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
        Sleep(1000);

    }
    return 0;

gotoxy(5,50);cout<<" ";
}


int main()
{


    int name;
    int question_duration = 30; // duration of the timer in seconds

    cout << "A question has been asked. You have " << question_duration << " seconds to answer." << endl;

    HANDLE timer_handle = CreateThread(NULL, 0, Timer, &question_duration, 0, NULL);

    gotoxy(5,30); cout << "What is your name:";
    gotoxy(5,50);cin >> name;
    gotoxy(6,50);cout<<name;


    stop_timer = true;

    WaitForSingleObject(timer_handle, INFINITE);
    CloseHandle(timer_handle);

    // Add your code here to check the user's answer and continue the game

    return 0;
}



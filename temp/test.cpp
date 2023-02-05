#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

#include <cstring>
#include<windows.h>

using namespace std;


char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return buf;
}


/*  THE CODE BELOW THIS IS THE IMPORTTANT  */

bool interrupt_timer = false;

void timer() {
    int elapsed_seconds = 0;
    while (elapsed_seconds < 30 && !interrupt_timer) {
        this_thread::sleep_for(chrono::seconds(1));
        ++elapsed_seconds;
    }
    if (interrupt_timer) {
        cout << "Timer interrupted." << endl;
    } else {
        cout << "Time's up! Press 'n' for next question" << endl;
    }
}

void interrupt() {
    char c;
    while (true) {
        c = getch();
        if (c != '\n') {
            interrupt_timer = true;
            break;
        }
    }
}

int main() {
    cout << "Starting timer for 30 seconds. Press any key to interrupt." << endl;
    thread t1(timer);
    thread t2(interrupt);
    t1.join();
    t2.join();
    return 0;
}

#include<iostream>
#include<fstream>
#include<iomanip>
#include<tuple>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include <Windows.h>
#include <conio.h>
#include "./header/console.h"
#include "./header/start_page.h"

using namespace std;

class Question{
protected:
    int questionNumber;     // The Question Number
    string q;               // The Question
    string option[4];       // Options for the Question
    string filename;        // File where the questions/options are at
    string answerFile;      // File containing answers
    string a;               // The Answer

    // Get a random number in the given range
    template<class A, class B>A getRandomNum(A min, B max){
        srand(time(0));

        // A random integer betn 1 and 50
        A randNum = int(rand())%(max - min + 1) + min;
        return randNum;
    }
public:
    virtual string getRandomQuestion() = 0;
    virtual string getPureQuestion() = 0;
    virtual void displayOptions() = 0;
    virtual int getQuestionNumber() = 0;
    virtual int getAnswer() = 0;
    virtual void gameOver(int)=0;


    //~Question(){}
};

class GameManager: public Question{
protected:
    int level;
    int grabQuestionNumber(){
        // Get the Question number located at the beginning of the line
        int num = 0;
        num = int(this->q[0]) - 48;
        if (this->q[1] != ' ')
            num = num * 10 + (int(this->q[1]) - 48);
        return num;
    }
public:
    GameManager();                                       // Constructor

    string getRandomQuestion();                             // Returns a random question USE THE ONE BELOW THIS
    string getPureQuestion();                                   // Get Question without the initial question number USE THIS
    void displayOptions();     // return 4 options as 4-tuple
    int getQuestionNumber();                                // Get the question number of the chosen question
    int getAnswer();                                        // Get the answ er of the chosed question
    void increaseLevel();
    void gameOver(int correctposition);

    ~GameManager(){}
};


// QuestionLevel1 Function Definitions
// =====================================================
GameManager::GameManager(){
    this->filename = "./question/level1.txt";
    this->answerFile = "./answer/answer1.txt";
}

string GameManager::getRandomQuestion(){
        this->questionNumber = getRandomNum(1, 5);
        ifstream file(this->filename);
        while(getline (file, this->q)){
            int num = grabQuestionNumber();

            if (this->questionNumber == num){
                file.close();

                return this->q;
            }
        }
        return "Error";
    }

string GameManager::getPureQuestion(){
    string q = this->getRandomQuestion();
    string pureQuestion;
    int c;
    for (c = 0; c<q.length(); c++){
        if(c<2) continue;
        pureQuestion += q[c];
    }
    return pureQuestion;

}

void GameManager::displayOptions(){
    ifstream file(this->filename);
    while(getline (file, this->q)){
        int num = grabQuestionNumber();
        if (this->questionNumber == num){
            for(int i = 0; i<4; i++)
                getline(file, this->option[i]);
            file.close();
        }
    }
    gotoxy(7,13);cout << "A) " << this->option[0];gotoxy(7,65);cout<<"[1]";
    gotoxy(8,13);cout << "B) " << this->option[1];gotoxy(8,65);cout<<"[2]";
    gotoxy(9,13);cout << "C) " << this->option[2];gotoxy(9,65);cout<<"[3]";
    gotoxy(10,13);cout << "D) " << this->option[3];gotoxy(10,65);cout<<"[4]";


}

int GameManager::getQuestionNumber(){
    return this->questionNumber;
}

int GameManager::getAnswer(){
    ifstream file(this->answerFile);
    while (getline (file, this->a)){
        int num = 0;
        num = int(this->a[0]) - 48;

        if (this->a[1] != ' ')
            num = num * 10 + (int(this->a[1]) - 48);

        if(num == this->questionNumber)
            return int(this->a[this->a.length() - 1]) - 48;     // The last character as integer which is our option
    }
    // Error
    return -1;
}

void GameManager::increaseLevel(){
    this->level++;
    if (this->level == 2){
        this->filename = "./question/level2.txt";
        this->answerFile = "./answer/answer2.txt";
    } else if(this->level == 3){
        this->filename = "./question/level3.txt";
        this->answerFile = "./answer/answer3.txt";
    } else {
        this->filename = "./question/level4.txt";
        this->answerFile = "./answer/answer4.txt";
    }
}
void GameManager::gameOver(int correctposition){
    draw_boundary();
    Cheque(correctposition);
}



// ==================================================
// End of QuestionLevel1 Function Definition


class Structure{
private:
    int p;
    int checkpoints[4];
public:
    // Constructor
    Structure(){
        this->p = 1;
        this->checkpoints[0] = 0;
        this->checkpoints[1] = 4;
        this->checkpoints[2] = 8;
        this->checkpoints[3] = 15;

    }

    // Display the structure
    void display(int a,int s,int d,int f){
        this->p=a+1;
        gotoxy(2,92);cout<<"BREAKTHROUHH";
        gotoxy(4,95);cout << "Lifeline"<< endl;
        gotoxy(6,77);cout<<">>"<<" "<<"("<<s<<")\t\t"<<"X2"<<" "<<"("<<d<<")\t\t" <<"50:50"<<" "<<"("<<f<<")\t\t"<< endl;
        gotoxy(7,78);cout<<"[5]";
        gotoxy(7,97);cout<<"[6]";
        gotoxy(7,116);cout<<"[7]";


        string money[] = {"5K", "10K", "20K", "40K", "80K", "1.6Lakh", "3.2Lakh", "6.4Lakh", "12.5Lakh", "25Lakh", "50Lakh", "1 Crore", "3 Crore", "5 Crore", "7 Crore"};
        int i,j=0;
        for(i = 15; i>0; i--,j++){
            int c = i - 1;
            int w = 30;
            string position = to_string(i);

            if (i < 10)
                w = 31;

            if (i == 15 || i == 8 || i == 4){
                w = 29;
                if (i == 8 || i == 4) w = 30;
                position = "(" + position + ")";
            }else{
                position = " " + position;
            }


            gotoxy(9+j,78);cout << position;
            if (i == p){
                w-=2;
                cout << setw(w-10) << ">>" << setw(20) << money[c] << endl;
            }
            else cout << setw(w+8) << money[c] << endl;
        }

        draw_boundary();
        breakthrough_box();


    }

    // Return the current position
    int getCurrentPosition(){
        return this->p - 1;
    }

    // Return the last checkpoint
    int getCheckpoint(){
        int cp = 0;
        for (int i=0; i<3; ++i){
            if(this->p >= this->checkpoints[i]){
                cp = this->checkpoints[i];

            }
        }
        return cp;
    }
};

// void startOptions(){
//     cout << "1 Start Game" << endl;
//     cout << "2 Exit" << endl;
// }

void clrscr(){
    system("cls");
}

string startgame()
{
string username;
    start_page();

    gotoxy(18,60);cout<<"Start a New Game[1]";
    gotoxy(18,18);cout << "Help[2]";
    gotoxy(18,110);cout << "Quit[3]" << endl;
    char starting_user_input='0';
    while(starting_user_input != '1' ||'3'||'2')
    {
        gotoxy(19,67);starting_user_input= getch();
        if(starting_user_input=='1')
        {
            username=request_Name();
            clrscr();
            break;
        }
        else if(starting_user_input=='3')
        {
            system("cls");
            exit(0);
        }
        else if(starting_user_input=='2')
        {
            clrscr();
            help();
            gotoxy(18,28);cout<<"Start a New Game[1]";
            gotoxy(18,95);cout << "Quit[2]" << endl;
            starting_user_input='0';
            while(starting_user_input != '1'||'2')
            {
             gotoxy(19,68);starting_user_input= getch();
             if(starting_user_input=='1')
             {
                username=request_Name();
                clrscr();
                break;
             }
            else if(starting_user_input=='2')
             {
                system("cls");
                exit(0);
             }
            }
            break;
        }
    }
    return username;
}

/*void gameOver(int correctposition)
{
    draw_boundary();
    Cheque(correctposition);
}*/





int main(){
    SetConsoleOutputCP(CP_UTF8);


    // To resize the console

    int horizontal;
    int vertical;
    GetDesktopResolution(horizontal, vertical);

    HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,0,0,horizontal,vertical,TRUE);

   // GameManager gm;
   // Structure s;
    string question;
    int correctAnswer;
    char guessAnswer;
    int lockedAnswer;
    int questionCounter;
    string username;
    char newinput;
    int Skip,Double,Fifty;



    Sleep(1);

    // Start the game and take the username

    NewGame:
    Skip=1;
    Double=1;
    Fifty=1;
    GameManager gm;
    Structure s;
    username=startgame();
    string filename = username + ".txt";

    ofstream fd;
    fd.open(filename, ios::out);

    // Game Start
    questionCounter = 0;
    for (int position=1; position <=15; ++position){
        clrscr();


        skipUsed:             // label for Branching after Skip Lifeline


        s.display(questionCounter,Skip,Double,Fifty);
        cout << endl << endl;


        // Question
        string question1 = "";
        string question2 = "";
        question = gm.getPureQuestion();

        if(question.length()<55)
        {
             for (int i=0;i<question.length();i++)
             {
                question1 += question[i];
             }
        }
        else
        {
             for (int i=0;i<55;i++)
            question1 += question[i];
            for (int i=55;i<question.length();i++)
            question2 += question[i];
        }

        gotoxy(4,12);cout <<"[*]"<<question1 << endl;
        gotoxy(5,16);cout <<question2<< endl;

        gm.displayOptions();
        correctAnswer = gm.getAnswer();




        lifelineUsed: // Label if lifeline is already used

        gotoxy(14,15);symbolPrinter(' ',43);

         //Label if double lifeline is used

        do{

        again:
            gotoxy(12,20);symbolPrinter(' ',50);
            gotoxy(12,15);symbolPrinter(' ',11);

            gotoxy(19,35);cout<<"Special Note!!";
            gotoxy(21,18);cout<<"Press enter only while Choosing Option and Lifeline";
            gotoxy(22,32);cout<<"else no need to press Enter";

            gotoxy(24,37);cout<<"LEAVE: [8]";
            gotoxy(12,15);cout<<"INPUT: ";
            guessAnswer=getch();
            gotoxy(12,22);cout<<guessAnswer;
            gotoxy(12,23);char temp=getch();
            if(temp=='\r' && guessAnswer>48 && guessAnswer<57)
            {
                break;
            }
            else
                goto again;


        }while(true);
        lockedAnswer=guessAnswer - 48;



        fd << question << endl;
      //  fd << guessAnswer << endl << endl;


      // label for Branching after using Lifeline
        fiftyUsed:
        doubleUsed:

        //If user wants to exit
        if(lockedAnswer==8)
        {
            system("cls");
            gm.gameOver(questionCounter);
            anotherGameStart(); // Our Header File
            goto NewGame;    // Go to Beginning page

        }

        //If user guess correct answer
        else if(lockedAnswer==correctAnswer)
        {
            rightAnswer(); //Our Header File
        }

          //Skip lifeline
        else if(lockedAnswer==5)
        {
            if(Skip==1)
            {
                system("cls");
                --Skip;
                goto skipUsed;
            }
            else
            {
                lifelineUsed(); //Our header File
                goto lifelineUsed;
            }

        }

        //Double Lifeline
        else if(lockedAnswer==6)
        {
             if(Double==1)
             {
                --Double;
                s.display(questionCounter,Skip,Double,Fifty);
                int wrong=1;
                errorDouble:
                lockedAnswer=guessAfterLifeline() - 48; // Our Header File

                if(lockedAnswer<5 && lockedAnswer!=correctAnswer)
                {

                    if(wrong==2)
                    {
                        system("cls");
                        gm.gameOver(questionCounter);
                        anotherGameStart();
                        wrong=1;
                        goto NewGame;
                    }
                    else
                    {
                        ++wrong;
                        goto errorDouble;
                    }
                }
                else
                    goto doubleUsed;
             }
             else
             {
                    lifelineUsed(); //Our header File
                    goto lifelineUsed;
             }
        }

        // End of Double Lifeline



        //50:50 Lifeline

        else if(lockedAnswer==7)
        {
        int A[2];
            if(Fifty == 1)
            {
                --Fifty;
                int validOption = randomNumber(1,4);
                A[0]=removeOption1(validOption,correctAnswer);
                A[1]=removeOption2(validOption,correctAnswer,A[0]);
                gotoxy(A[0]+6,13);symbolPrinter(' ',55);
                gotoxy(A[1]+6,13);symbolPrinter(' ',55);

                s.display(questionCounter,Skip,Double,Fifty);

                lockedAnswer=guessAfterLifeline() - 48;   //Our Header File
                goto fiftyUsed;

            }
            else
            {
                    lifelineUsed(); //Our header File
                    goto lifelineUsed;
            }
        }
        //End of 50:50


        // If wrong Answer
        else
        {
            int checkpoint=s.getCheckpoint();
            wrongAnswer();
            system("cls");
            gm.gameOver(checkpoint);
            anotherGameStart(); // Our Header File
            goto NewGame;   // Go to Beginning Page
        }


        // If correct Answer, increase question counter
             questionCounter++;
             if (questionCounter == 4 || questionCounter == 8 || questionCounter == 11 )
             gm.increaseLevel();
    }
    //After 15th question
            system("cls");
            gm.gameOver(questionCounter);
            anotherGameStart();  //Our Header file
            goto NewGame;


    fd.close();

    return 0;
}

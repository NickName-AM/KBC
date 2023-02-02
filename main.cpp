#include<iostream>
#include<fstream>
#include<iomanip>
#include<tuple>
#include<string>
#include<stdlib.h>
#include<unistd.h>

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
};


// QuestionLevel1 Function Definitions
// =====================================================
GameManager::GameManager(){
    this->filename = "level1.txt";
    this->answerFile = "answer1.txt";
}

string GameManager::getRandomQuestion(){
        this->questionNumber = getRandomNum(1, 2);
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
    cout << "1 " << this->option[0] << "\t\t" << "2 " << this->option[1] << endl;
    cout << "3 " << this->option[2] << "\t\t" << "4 " << this->option[3] << endl;

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
        this->filename = "level2.txt";
        this->answerFile = "answer2.txt";
    } else if(this->level == 3){
        this->filename = "level3.txt";
        this->answerFile = "answer3.txt";
    } else {
        this->filename = "level4.txt";
        this->answerFile = "answer4.txt";
    }
}



// ==================================================
// End of QuestionLevel1 Function Definition



void symbolPrinter(char symbol, int no){
    int i;
    for (i=0; i<no; ++i)
        cout << symbol;
    cout << endl;
}



class Structure{
private:
    int p;
    int checkpoints[3];
public:
    // Constructor
    Structure(){
        this->p = 1;
        this->checkpoints[0] = 4;
        this->checkpoints[1] = 8;
        this->checkpoints[2] = 15;
    }

    // Display the structure
    void display(){
        symbolPrinter('|', 70);
        symbolPrinter('.', 70);
        cout << "Lifeline" << setw(42) << "X2(Double 5)\t>>(Next 6)" << endl;
        symbolPrinter('.', 70);

        string money[] = {"5K", "10K", "20K", "40K", "80K", "1.6Lakh", "3.2Lakh", "6.4Lakh", "12.5Lakh", "25Lakh", "50Lakh", "1 Crore", "3 Crore", "5 Crore", "7 Crore"};
        int i;
        for(i = 15; i>0; i--){
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


            cout << position;
            if (i == p){
                w-=2;
                cout << setw(w-10) << ">>" << setw(12) << money[c] << endl;
            }
            else cout << setw(w) << money[c] << endl;
        }
        symbolPrinter('.', 70);
        this->p++;
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

void startOptions(){
    cout << "1 Start Game" << endl;
    cout << "2 Exit" << endl;
}

void clrscr(){
    system("clear");
}

void startgame()
{
    int i;
    for(i=0;i<70;i++)
    {
        cout<<"|";
    }
    cout<<endl<<endl<<endl<<endl<<endl<<endl;

    cout<<setw(50)<<"Welcome to Ko Bancha Crorepati";
    cout<<endl<<endl;
    cout<<setw(42)<<"Start New game (1)";

    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    for(i=0;i<70;i++)
    {
        cout<<"|";
    }


    if(cin.get()=='1')
    {
        clrscr();
    }

}


int main(){
    GameManager gm;
    Structure s;
    string question;
    int correctAnswer;
    int guessAnswer;
    int questionCounter = 0;
    string username;


    // Start the game
    startgame();
    sleep(1);

    cout << "Your name: " << endl;
    cin >> username;
    string filename = username + ".txt";

    ofstream fd;
    fd.open(filename, ios::out);
    
    // Game Start
    for (int position=1; position <=15; ++position){
        clrscr();
        s.display();
        cout << endl << endl;
        
        // Question
        question = gm.getPureQuestion();
        cout << question << endl;
        gm.displayOptions();
        correctAnswer = gm.getAnswer();
        cout << endl << "> ";
        cin >> guessAnswer;

        fd << question << endl;
        fd << guessAnswer << endl << endl;
        

        // If correct Answer, increase question counter
        questionCounter++;
        if (questionCounter == 4 || questionCounter == 8 || questionCounter == 11 )
            gm.increaseLevel();
    }

    fd.close();

    return 0;
}
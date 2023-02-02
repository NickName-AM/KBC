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
    virtual tuple<string, string, string, string> getOptions() = 0;
    virtual int getQuestionNumber() = 0;
    virtual int getAnswer() = 0;
};

class QuestionLevel1: public Question{
protected:
    int grabQuestionNumber(){
        // Get the Question number located at the beginning of the line
        int num = 0;
        num = int(this->q[0]) - 48;
        if (this->q[1] != ' ')
            num = num * 10 + (int(this->q[1]) - 48);
        return num;
    }
public:
    QuestionLevel1();                                       // Constructor

    string getRandomQuestion();                             // Returns a random question
    tuple<string, string, string, string> getOptions();     // return 4 options as 4-tuple
    int getQuestionNumber();                                // Get the question number of the chosen question
    int getAnswer();                                        // Get the answ er of the chosed question
};

class QuestionLevel2: public QuestionLevel1{
    public:
    QuestionLevel2(){
        this->filename = "level2.txt";
        this->answerFile = "answer2.txt";
    }
};

class QuestionLevel3: public QuestionLevel1{
    public:
    QuestionLevel3(){
        this->filename = "level3.txt";
        this->answerFile = "answer3.txt";
    }
};

class QuestionLevel4: public QuestionLevel1{
    public:
    QuestionLevel4(){
        this->filename = "level4.txt";
        this->answerFile = "answer4.txt";
    }
};



// QuestionLevel1 Function Definitions
// =====================================================
string QuestionLevel1::getRandomQuestion(){
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

tuple<string, string, string, string> QuestionLevel1::getOptions(){
    ifstream file(this->filename);
    while(getline (file, this->q)){
        int num = grabQuestionNumber();
        if (this-> questionNumber == num){
            for(int i = 0; i<4; i++)
                getline(file, this->option[i]);
            file.close();
        }
    }
    return make_tuple(this->option[0], this->option[1], this->option[2], this->option[3]);
}

int QuestionLevel1::getQuestionNumber(){
    return this->questionNumber;
}

int QuestionLevel1::getAnswer(){
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

QuestionLevel1::QuestionLevel1(){
    this->filename = "level1.txt";
    this->answerFile = "answer1.txt";
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
        this->p = 15;
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
                position = "(" + position + ")";
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



int main(){
    QuestionLevel1 q1;
    Structure s;

    // Display the structure ( Use a loop, the position of '>>' will automatically change in each iteration)
    s.display();

    // Get a random question
    string question = q1.getRandomQuestion();
    
    // Display that question
    cout << question << endl;

    // Get the options
    tuple<string, string, string, string> options = q1.getOptions();
    
    // Display the options
    cout << get<0>(options) << "\t\t\t\t" << get<1>(options) << endl;
    cout << get<2>(options) << "\t\t\t\t" << get<3>(options) << endl;
    

    // Get Current Position in the structure (1 to 15)
    cout << s.getCurrentPosition() << endl;

    // Get Last Checkpoint in the structure (4 or 8 or 15)
    cout << s.getCheckpoint() << endl;

    return 0;
}
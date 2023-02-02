#include<iostream>
#include<fstream>

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
    virtual void displayOptions() = 0;
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
    // Constructor
    QuestionLevel1(){
        this->filename = "level1.txt";
        this->answerFile = "answer1.txt";
    }

    // Returns a random question
    string getRandomQuestion(){
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

    // Displays the options
    void displayOptions(){
        ifstream file(this->filename);
        while(getline (file, this->q)){
            int num = grabQuestionNumber();

            if (this-> questionNumber == num){
                for(int i = 0; i<4; i++)
                    getline(file, this->option[i]);
                file.close();
            }
        }
        cout << "1 " << option[0] << "\t\t" << "2 " << option[1] << endl; 
        cout << "3 " << option[2] << "\t\t" << "4 " << option[3] << endl; 
    }

    // Get the question number of the chosen question
    int getQuestionNumber(){
        return this->questionNumber;
    }

    // Get the answer of the chosed question
    int getAnswer(){
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

int main(){
    QuestionLevel2 q1;

    cout<<q1.getRandomQuestion()<< endl;
    q1.displayOptions();
    cout << q1.getQuestionNumber() << endl;
    cout << q1.getAnswer() << endl;

    
    return 0;
}
#include<iostream>
#include<fstream>
#include<tuple>

using namespace std;

class Question{
protected:
    int questionNumber;     // The Question Number
    string q;               // The Question
    string option[4];       // Options for the Question
    string filename;        // File where the questions/options are at

    // Get a random number between 1 and 50
    int getRandomNum(){
        srand(time(0));     // Seed for random number
        int randNum = int(rand())%(2 - 1 + 1) + 1;     // A random integer betn 1 and 50
        return randNum;
    }
public:
    virtual tuple<string, string, string, string, string, int> getQuestionAndOptions() = 0;
};

class QuestionLevel1: public Question{
public:
    // Constructor
    QuestionLevel1(){
        this->filename = "level1.txt";
    }

    // Return 1 Question and 4 options
    // Question, option1, option2, option3, option4
    // To Access: get<0>(object.getQuestion())    This will catch 
    tuple<string, string, string, string, string, int> getQuestionAndOptions(){
        int randNum = getRandomNum();
        ifstream file(filename);
        while (getline (file, this->q)){

            // Get the Question number located at the begining of the line
            int num = 0;
            num = int(this->q[0]) - 48;
            if (this->q[1] != ' ')
                num = num * 10 + (int(this->q[1]) - 48);
            // Got the Integer

            // If the number at the beginning of the line is equal to random number, return the question and options
            if (randNum == num){
                for(int i = 0; i<4; i++)
                    getline(file, this->option[i]);
                file.close();

                // Return the random question and 4 options
                return make_tuple(this->q, this->option[0], this->option[1], this->option[2], this->option[3], randNum);
            }
        }
        // Error will occur if the random number is not generated between 1 and 50
        return make_tuple("Error", "Error", "Error", "Error", "Error");


    }
};

class QuestionLevel2: public QuestionLevel1{
    public:
    QuestionLevel2(){
        this->filename = "level2.txt";
    }

};


int main(){

    QuestionLevel2 q1;
    cout << get<1>(q1.getQuestionAndOptions()) << endl;

    return 0;
}
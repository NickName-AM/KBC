#include <iostream>
#include <ctime>
using namespace std;


int randomNumber(int A,int B)
{
    srand(time(0));
    int random = int(rand()%(B-A+1))+A;
    return random;
}

int main()
{
	int validOption =  randomNumber(1,4);
    cout << validOption;
}
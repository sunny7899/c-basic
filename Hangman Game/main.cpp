#include <iostream>
#include <vector>
#include "hangman_function.h"
using namespace std;
int main()
{
    greet();

    string codeword = "chotapackethai";
    string answer= "___________";
    int misses = 0;
    vector<char> incorrect;
    bool guess = false;
    char letter;


    while (answer!= codeword && misses <7)
    {
        display_misses(misses);
        display_status(incorrect, answer);

        cout<< "\n\n Please enter your guess: ";
        cin>>letter;

        for(int i = 0; i < codeword.length(); i++)
        {
            if (letter == codeword[i])
            {
                answer[i]=letter;
                guess=true;
            }
        }
        if (guess)
        {
            cout<< "\n Correct !\n";
        }
        else
        {
            cout<< "\n Incorrect, falling more :( \n";
            incorrect.push_back(letter);
            misses++;
        }
        guess = false;
    }

    end_game(answer, codeword);
    return 0;
}

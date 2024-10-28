#include<iostream>
#include<vector>
#include "hangman_function.h"
using namespace std;


//define func
void greet()
{
    std::cout<< " ======================\n";
    std::cout<< " Hangman: The Game \n";
    std::cout<< " =======================\n";
    std::cout<< "Ins. Save him from being hanged by guessing the letters in the codeword. \n";

}

void display_misses(int misses)
{
    if ( misses == 0)
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========== \n";

    }
    else if ( misses == 1)
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  o   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========== \n";

    }
    else if ( misses == 2)
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  o   | \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========== \n";

    }
    else if ( misses == 3)
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  o   | \n";
        cout<<" /|   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========== \n";

    }
    else if ( misses == 4)
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  o   | \n";
        cout<<" /|\\  | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========== \n";

    }
    else if ( misses == 5)
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  o   | \n";
        cout<<" /|\\  | \n";
        cout<<" /    | \n";
        cout<<"      | \n";
        cout<<" ========== \n";

    }
    else if (misses == 6)
    {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  o   | \n";
        cout<<" /|\\  | \n";
        cout<<" / \\  | \n";
        cout<<"      | \n";
        cout<<" ========== \n";
    }
}

void display_status(vector<char> incorrect, string answer)
{
    cout<< " Your guess is incorrect: \n";

    for(int i =0; i <incorrect.size();i++)
    {
        cout<< incorrect[i]<<" ";
    }
    cout<< " \n Codeword: \n";

    for(int i =0; i <answer.length(); i++)
    {
        cout<<answer[i]<< " ";
    }
}

void end_game(string answer, string codeword)
{
    if(answer==codeword)
    {
        cout<< " woohoooo! you save me :) \n";
        cout<< "congoo!\n";

    }
    else
    {
        cout<< " ========================"
        cout<< "oh noo!, I'm dead now  :C";


    }
}
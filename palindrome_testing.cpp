// Author: Matthew Peach
// Program Status: Complete
// Description:
//   This program uses a class that accepts user input as a string in the constructor 
// and checks to see if the user input a palindrome. The user is prompted to try again
// if entering all whitespace, only one character, or entering nothing. Numbers and other
// characters are acceptable input.

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Palindrome{
private:
    string word {"Unset"};
    bool isPalindrome {true};

public:
    Palindrome();
    void checkWord();
};

int main(){
    bool goAgain {false};
    string userInput {"Unset"};
    
    do{
        Palindrome *ptr_palindrome = new Palindrome();
        ptr_palindrome->checkWord();
        delete ptr_palindrome;
        
        // Ask if user wants to make another palindrome
        do{
            cout << "\n\nTry another palindrome? (y/n): ";
            getline(cin, userInput);
            cin.clear();
        }while(userInput != "Y" && userInput != "y" && userInput != "N" && userInput != "n");
        
        // Set goAgain
        if(userInput == "Y" || userInput == "y"){
            goAgain = true;
        }
        else{
            goAgain = false;
        }
        
        cout << "===========================================================" << endl;
        
    }while(goAgain);
        
    return 0;
}

Palindrome::Palindrome(){
    string userInput {"Unset"};
    int spaceCount {0};
    
    do{
        spaceCount = 0; //Needs to be reset after each loop
        cout << "Please enter a palindrome: ";
        getline(cin, userInput);
        cin.clear();
        
        // Checking to see if it's all blank space
        for(int i {0}; i < userInput.size(); ++i){
            if( std::isspace(userInput[i]) ){
                ++spaceCount;
            }
        }
   //while( nothing entered   ||  1 character entered  ||       it's all whitespace      )
    }while( userInput.empty() || userInput.size() <= 1 || spaceCount == userInput.size() );
    
    this->word = userInput;
    
    //==============================================================
    //                  Checking for palindrome
    //==============================================================
    for(int i {0}; i < (userInput.size() / 2); ++i){
        if(userInput[i] != userInput[userInput.size() - 1 - i]){
            this->isPalindrome = false;
            break;
        }
    }
}

void Palindrome::checkWord(){
    if(isPalindrome){
        cout << "\nYes, " << word << " is a palindrome!" << endl;
    }
    else{
        cout << "\nNo, " << word << " is not a palindrome..." << endl
             << "\nYour word forwards: " << word << endl
             << "Your word backwards: ";
        for(int i {word.size() - 1}; i >= 0; --i){
            cout << word[i];
        }
    }
}
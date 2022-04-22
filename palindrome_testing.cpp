#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

class Palindrome{
private:
    string word {"Unset"};
    bool isPalindrome {false};

public:
    Palindrome();
    void checkWord();
    

};

int main(){
    
    Palindrome *ptr_palindrome = new Palindrome();
    
    string test = "four";
    
    cout << "Size of four: " << test.size() << endl;
    
    return 0;
}

Palindrome::Palindrome(){
    string userInput {"Unset"};
    
    do{
        cout << "Please enter a palindrome: ";
        getline(cin, userInput);
        cin.clear();
    }while( userInput.empty() || userInput.size() <= 1 );
    
    this->word = userInput;
}

void Palindrome::checkWord(){
    int numCharacters = word.size();
}
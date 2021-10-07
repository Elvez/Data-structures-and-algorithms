#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

class StringStack {
    public: 
    //String
    std::string _str = "";

    /**
     * Pop from stack
     */
    void pop(void) {
        //Pop first element
        _str.erase(0, 1);
    }

    /**
     * Push to stack
     */
    void push(char chr) {
        std::string str(1, chr);
        _str.insert(0, str);
    }
};

/**
 * Check if string is valid or not, if it contains a character other than
 * a bracket, then it is not valid to check.
 */
bool isValid(std::string str) {
    for(int iter = 0; iter < str.length() ; iter ++) {
        if(str.at(iter) == '(' or str.at(iter) == ')' or
            str.at(iter) == '[' or str.at(iter) == ']' or
            str.at(iter) == '{' or str.at(iter) == '}') {
                return true;
            } else {
                return false;
            }
    }
    
    return true;
} 


int main () {
    //Keep running?
    bool keepRunning = true;
    
    //Valid sequence
    bool validString = false;
    
    //Stack pointer
    int stackPtr;

    //Bracket string
    std::string input = "";
    StringStack bracketString;

    while(keepRunning) {
        //Ask for input
        std::cout << "Enter bracket sequence, or send '!' to cancel : " << std::endl;
        
        //Store input 
        std::cin >> input;

        //Cancel if entered
        if(input.at(0) == '!') {
            keepRunning = false;
            break;
        }

        //Check if string is valid
        if(isValid(input)) {
            //String is valid
            validString = true;
            
            //Stack pointer
            stackPtr = bracketString._str.length();

            //Push elements one by one
            for(int iter = 0; iter < input.length(); iter ++) {
                bracketString.push(input.at(iter));
                
                //Pop brackets if they match
                if(iter != 0 and stackPtr != 0) {
                    if(bracketString._str.at(stackPtr - 1) == ')' and bracketString._str.at(stackPtr) == '(') {
                        stackPtr -= 2;
                    } else if(bracketString._str.at(stackPtr - 1) == ']' and bracketString._str.at(stackPtr) == '[') {
                        stackPtr -= 2;
                    } else if(bracketString._str.at(stackPtr - 1) == '}' and bracketString._str.at(stackPtr) == '{') {
                        stackPtr -= 2;
                    }
                }
            }
        } else {
            //Invalid string, string contains other character than brackets.
            std::cout << "Invalid string!" << std::endl;
            validString = false;
        }

        //Check if string is empty
        if(validString) {
            if(stackPtr == 0) {
                //Stack is empty
                std::cout << std::endl << "Correct!" << std::endl;
            } else {
                //Stack is not empty
                std::cout << std::endl << "Incorrect!" << std::endl;
            }
            
            //Reset stack
            bracketString._str = "";
            stackPtr = 0;
        }
    }
    
    return 0;
}


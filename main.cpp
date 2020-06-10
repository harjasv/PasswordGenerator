/*
    Harjas Virk
    3373921
    Assignment 2: Project 1
    Password Generator
*/

#include <iostream>
#include <ctime>
#include <string>
#include <math.h>

using namespace std;

// This is a custom random number generator
// It will generate a number between 0 and 1
// It prompts the user to enter a random number of characters
// It will then calculate the ascii value of those characters and multiply them
// It will also caluclate the time it takes the user to enter those characters, and multiply that time value too
// Lastly it will use the built in rand() function as a multiplier
float makeRand() {
    string random;
    clock_t start;
    float duration;
    char letter;
    int i;
    float r = 1;
    cout << "Please enter any number of any kind of characters for randomization.\n";
    start = clock();
    cin >> random;
    duration = (clock() - start) / (float) CLOCKS_PER_SEC;
    for(i = 0; i < random.length(); i++) {
        letter = random.at(i);
        r = r * int(letter);
    }
    
    r = r * duration * rand();
    
    while(r > 1) {
        r = r/10;
    }
    return r;
}

// This password generator is based off of a password generator example on wikipedia, however this version is noticeably stronger since the randomization is based entirely on user input and is very difficult to replicate. The criteria for my password generator can be found in my assignment document.
int main(int argc, const char * argv[]) {
    int length = 0;
    int i;
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string numbers = "0123456789";
    string special = "!@#$%^&*()~`-=_+[]{}|;':,./<>?";
    string all = uppercase + lowercase + numbers + special;
    
    cout << "Please enter the length of your password ";
    while (length < 8) {
        cout << "(minimum 8 characters): ";
        cin >> length;
    }
    
    string password = "";
    
    for(i = 0; i < length; i++) {
        float r = makeRand();
        int character = floor((r) * all.length());
        password = password + all.at(character);
    }
    
    cout << "Your password is:\n" << password << "\n";
    
    return 0;
}

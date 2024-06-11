/*Ethan Tarnarider
2365982
tarnarider@chapman.edu 
CPSC 350-03
PA1
This is the header file for the model class which initializes and declares all necessary variables and methods*/
//Guard so the header file is only used once
#ifndef Model_H
#define Model_H
//Including iostream, string and namespace since they are all needed
#include <iostream>
#include <string>
using namespace std;

class Model{
public:
//Model class constructor and destructor
    Model();
    ~Model();
//Methods that translate a single letter (vowels and consonants) into their appropriate robber language counterparts initialization
    std::string translateSingleConsonant(char n);
    std::string translateSingleVowel(char e);
};


#endif

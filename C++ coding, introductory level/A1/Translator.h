/*Ethan Tarnarider
2365982
tarnarider@chapman.edu 
CPSC 350-03
PA1
Header file for the Translator class which initializes and declares necessary variables and methods*/
//Beginning of the guard, iostream, string, the Model header file and namespace as well
#ifndef Translator_H
#define Translator_H
#include <iostream>
#include <string>
#include "Model.h"
using namespace std;

class Translator{
    public:
//Various variables needed for the Translator class that essentially become a wrapper around model
//first is the letter counting for single words for loop purpose, then the string that is the robber translation and the same 
//for the sentence versions as well    
    int singlelettercount;
    string singleletterrobber;
    int sentencecount;
    string sentencerobber;
//Class constructor and destructors    
    Translator();
    ~Translator();
//Declaring the two functions that work for full words/sentences    
    string translateEnglishWord(string word);
    string translateEnglishSentence(string sentence);
    private:
        Model m;
};

#endif
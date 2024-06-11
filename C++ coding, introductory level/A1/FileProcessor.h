/*Ethan Tarnarider
2365982
tarnarider@chapman.edu 
CPSC 350-03
PA1
The header file for the FileProcessor class declares and initializes all the necessary variables and methods*/
//Guard
#ifndef FileProcessor_H
#define FileProcessor_H
//Necessary inclusion of past header files and libraries
#include "Model.h"
#include "Translator.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FileProcessor{
public:
//Constructor and destructor
    FileProcessor();
    ~FileProcessor();
//Method declaration of the method that takes an input and output file name and translates the file into robber language    
    void processFile(string inputFileName, string outputFileName);
//Variable that stores the text of the in file as a string for translation purposes only
    string lineContents;
//Variable that stores the robber translation
    string robberVer;
//Variable that stores the original text file as a string for HTML purposes
    string originalVer;
};
#endif
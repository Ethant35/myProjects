/*Ethan Tarnarider
2365982
tarnarider@chapman.edu 
CPSC 350-03
PA1
The header file for the FileProcessor class declares and initializes all the necessary variables and methods*/
//Guard
#ifndef Speakerview_H
#define Speakerview_H
//Necessary inclusion of past header files and libraries

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Speakerview{
public:
//Constructor and destructor
    Speakerview();
    ~Speakerview();
    void getRowsasArray(string rowcont, double** seatingChart, int index);
    int getNumColumns(string wordsParsed);
    string processthefile(string toParse);
    void mainFunction(string inputFileName);
    string lineContents;

};
#endif
/*Ethan Tarnarider
2365982
tarnarider@chapman.edu 
CPSC 350-03
PA1
The Main file creates all the necessary objects and then uses the processFile method with the command line arguments to 
get the input file and what file to output to*/
//Necessary inclusions of the header files of the previous files
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
//Main formatted so command line arguments are used
int main(int argc, char** argv)
{
//Three instantiations of the Model, Translator and FileProessor class
    Model m;
    Translator t;
    FileProcessor f;
//Calling the processFile method and indexing into argv for the names of the input and output file
    f.processFile(argv[1],argv[2]);
    return 0;
}

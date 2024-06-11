/*Ethan Tarnarider
2365982
tarnarider@chapman.edu 
CPSC 350-03
PA1
The FileProcessor class uses ifstream to read into a given file and uses a Translator object to translate the contents
of the file into robber language and then uses an ofstream to write it to a HTML file*/
#include "FileProcessor.h"

//Translator object and the class' constructor and destructor
Translator t;
FileProcessor::FileProcessor(){

}

FileProcessor::~FileProcessor(){

}
//Method that takes the input and output file names' and uses ifstream to read it and translate it into robber language, and 
//handles all the HTML work as well
void FileProcessor::processFile(string inputFileName, string outputFileName){
    lineContents="";
//Assigns ifstream    
    ifstream reader;
//Opens file
    reader.open(inputFileName);
//Uses the getline method to transcribe the file into a string that is used for HTML and translates into robber language as well
    while (getline(reader, lineContents)) {
        originalVer+=lineContents + "<br>";
//Uses the translator class object to translate line by line and store it in the robberVer variable
        robberVer+= t.translateEnglishSentence(lineContents) + "<br>"; 
  }
//Closing reader once loop is broken out of 
    reader.close();
//Assigning the ofstream to the word HTML
    ofstream HTML;
//Creating a new file that is called whatever you want it to be but must end in .html
    HTML.open(outputFileName);
//HTML stuff
    HTML<<"<!DOCTYPE html><html><head>Here is a test of robber language in C++<title></title>";
    HTML<<"</head><body><p><b></b><br></p>";
//Including the original English version in the HTML file
    HTML<<"<p><b>"+originalVer+"</b><br></p>"<<endl;
//Including the robber alnguage translation in the HTML
    HTML<<"<p><i>"+robberVer+"<i><br></p>";
    HTML<<"</body></html>";  
//Closing the ofstream
    HTML.close();
}

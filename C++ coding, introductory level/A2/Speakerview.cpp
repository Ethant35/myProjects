#include "Speakerview.h"
#include "ATStack.h"
#include <string>
#include <sstream>

    
//Class destructor and constructor
Speakerview::Speakerview(){

}

Speakerview::~Speakerview(){

}

void Speakerview::mainFunction(string inputFileName){
//Declaring/assigning necessary variables
    lineContents="";
    string contents="";
    int lineReadCounter=0;
    int rows=0;
    int columns=0;


//Assigns ifstream    
    ifstream reader;
//Opens file
    reader.open(inputFileName);
    //Doing a first pass of getLine to get the size of the input file
    while (getline(reader, lineContents)) {
        columns=getNumColumns(lineContents);
        rows++;

    }
    //Creating array of monotonic stacks with the parameters from before
    ATStack<double>** arrayOfStacks=new ATStack<double>*[columns];
    //Initialize 2d array that represents the given seating chart
    double** seatingChart = new double*[rows];
 
    for (int i = 0; i < rows; i++) {
        seatingChart[i] = new double[columns];
    }
    //Clearing reader to use it again for another pass where I assign values
    reader.clear();
    //Using seekg function to start reader back at beginning of file
    reader.seekg (0, ios::beg);
    //Using getLine in a loop to assign contents and then to use in the function that assigns that row into the
    //2d array
    for (int i=0;i<rows;++i) {
        getline(reader,lineContents);
        contents=lineContents;
        getRowsasArray(contents,seatingChart,i);
  }
  for (int i=0;i<rows;++i){
      for (int j=0;j<columns;++j){
      }
  }
  reader.close();
    for (int i=0;i<columns;i++){
        //Populating array of stacks
        arrayOfStacks[i] = new ATStack<double>(rows, 'd');
    }
    for (int i=rows-1;i>=0;--i){
        //Pushing into stack going in reverse row order to keep monotonicness
        for (int j=0;j<columns;++j){
            arrayOfStacks[j]->push(seatingChart[i][j]);
        }
    }

    for (int i=0;i<columns;++i){
        //Print outs with some if statements to see if a comma should be placed or inches
        cout<<"In column "<<i<<" there are "<<arrayOfStacks[i]->size()<<" that can see. Their heights are: ";
        while (!arrayOfStacks[i]->isEmpty()){
            cout<<arrayOfStacks[i]->pop();
            if(arrayOfStacks[i]->isEmpty()){
                cout<<" Inches."<<endl;
            }
            else{
                cout<<", ";
            }

        }
    }
    //Destroying dynamically allocated stuff
    for (int i=0;i<columns;++i){
        arrayOfStacks[i]->~ATStack();
    }
    delete[] arrayOfStacks;
    for (int i=0;i<rows;++i){
        delete[] seatingChart[i];
    }
    delete[] seatingChart;

    return;
    
//Closing reader once loop is broken out of 
    
}
//Function that adds a single line of the input file into the array
void Speakerview::getRowsasArray(string rowcont,double** seatingChart,int index){
    istringstream iss(rowcont);
    int counter = 0;
    double value;
    while(iss >> value){
        seatingChart[index][counter]=value;
        ++counter;
  }
  return;
  


}

string Speakerview::processthefile(string toParse){
    istringstream stream(toParse);
    string newWord;
    int wordsParsedCounter;
    while (stream>>newWord){
    }
    return newWord;

}
//Function that returns the number of columns in the input file
int Speakerview::getNumColumns(string wordsParsed){
    istringstream stream(wordsParsed);
    string newWord;
    int wordsParsedCounter=0;
    while (stream>>newWord){
        wordsParsedCounter++;
    }
    return wordsParsedCounter;
}

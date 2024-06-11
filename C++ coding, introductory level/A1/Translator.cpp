/*Ethan Tarnarider
2365982
tarnarider@chapman.edu 
CPSC 350-03
PA1
The translator class is effectively a wrapper class around Model which makes it possible to translate entire words or sentences*/
//Necessary files that must be included
#include "Translator.h"
#include "Model.h"

//Constructor and destructor
Translator::Translator(){

}

Translator::~Translator(){

}
//Method that takes in a word as a string and uses a for loop with a nested if, else to translate the word letter by letter
//into robber language
string Translator::translateEnglishWord(string word){
    singlelettercount=word.length();
    for (int i=0;i<singlelettercount;i++){
        if(word[i]=='a'||word[i]=='A'||word[i]=='e'||word[i]=='E'||word[i]=='i'||word[i]=='I'||word[i]=='o'||word[i]=='O'||word[i]=='u'||word[i]=='U'){
            singleletterrobber+=m.translateSingleVowel(word[i]);
        }
        else{
            singleletterrobber+=m.translateSingleConsonant(word[i]);
        }
    }
    return singleletterrobber;
}

//A method that takes in a full sentence and iterates letter by letter and spaces appropriately and returns the whole sentence
//in robber language
string Translator::translateEnglishSentence(string sentence){
    sentencecount=sentence.length();
    sentencerobber="";
    for (int i=0;i<sentencecount;i++){
        if(sentence[i]=='a'||sentence[i]=='A'||sentence[i]=='e'||sentence[i]=='E'||sentence[i]=='i'||sentence[i]=='I'||sentence[i]=='o'||sentence[i]=='O'||sentence[i]=='u'||sentence[i]=='U'){
            sentencerobber+=m.translateSingleVowel(sentence[i]);
        }
        else{
            sentencerobber+=m.translateSingleConsonant(sentence[i]);
        }
    }
    return sentencerobber;
}
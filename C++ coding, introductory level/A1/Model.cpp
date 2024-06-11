/*Ethan Tarnarider
2365982
tarnarider@chapman.edu 
CPSC 350-03
PA1
This is the Model class which is responsible for translating consonants and vowels into robber language, has two
methods that both return strings*/
#include "Model.h"

//Constructor and destructor
Model::Model(){

}

Model::~Model(){

}

//Function that takes in a single char, checks if it is a consonant, then translates it over to robber language, accounts
//for punctuation and spaces as well takes in a char and outputs a string, accounts for capitals as well
string Model::translateSingleConsonant(char n){
    string consonant="";
    if (n=='b' || n=='B'|| n=='c' || n=='C' || n=='d' ||n=='D'|| n=='f'|| n=='F' ||n=='g' ||n=='G'||n=='h'||n=='H'||n=='j'||n=='J'
   || n=='k'||n=='K'||n=='l'||n=='L'||n=='m'||n=='M' ||n=='n'||n=='N'||n=='o'||n=='O'||n=='p'||n=='P'||n=='q'||n=='Q'||n=='r'
   ||n=='R'||n=='s'||n=='S'||n=='t'||n=='T'||n=='u'||n=='U'||n=='v'||n=='V'||n=='w'||n=='W'||n=='x'||n=='X'||n=='y'||n=='Y'||
   n=='z'||n=='Z'){
       consonant=n;
       consonant+="o";
       consonant +=n;
       }
    else if(n==' '){
        consonant=' ';
    }
    else if(n=='.'){
        consonant=". ";
    }
    else if (n=='?'){
        consonant="? ";
    }
    else if (n=='!'){
        consonant="! ";
    }
    else if (n==','){
        consonant=", ";
    }
    else if (n=='\''){
        consonant="\' ";
    }
    return consonant;
}

//Function that takes in a char and returns a string but first checks if it is a vowel and then turns it into robber language
//accounts for capitals as well
string Model::translateSingleVowel(char e){
    string vowel="";
    if(e=='a'||e=='A'||e=='e'||e=='E'||e=='i'||e=='I'||e=='o'||e=='O'||e=='u'||e=='U'){
        vowel=e;
    }
    else if(e==' '){
        vowel=' ';
    } 
    else if(e=='.'){
        vowel=". ";
    }
    else if (e=='?'){
        vowel="! ";
    }
    else if (e=='!'){
        vowel="! ";
    }
    else if (e==','){
        vowel=", ";
    }
    else if (e=='\''){
        vowel="\' ";
    }
    return vowel;

    
}
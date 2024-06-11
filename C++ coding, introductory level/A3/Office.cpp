#include "Office.h"

Office::~Office(){

}
Office::Office(int numWindows){
    window=new Window*[numWindows];
    for (int i=0;i<numWindows;++i){
        window[i]= new Window();
    }
    numwindows=numWindows;
    line=new ListQueue<Customer*>();
}
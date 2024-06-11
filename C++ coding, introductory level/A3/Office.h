#include <iostream>
#include "Window.h"
using namespace std;
#ifndef OFFICE_H
#define OFFICE_H

class Office{
public:
    virtual ~Office();
    Office(int numWindows);
    Window** window;
    ListQueue<Customer*>* line;
    int numwindows;

    
};

#endif
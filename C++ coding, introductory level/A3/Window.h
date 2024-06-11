#include <iostream>
#include "DblList.h"
#include "Listnode.h"
#include "ListQueue.h"
#include "Customer.h"
using namespace std;
#ifndef WINDOW_H
#define WINDOW_H

class Window{
public:
    Window();
    virtual ~Window();
    Customer* c;
    int endTime; 
    int idleTime;
       
};

#endif
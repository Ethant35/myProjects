#include <iostream>
#include "Office.h"
using namespace std;
#ifndef SERVICECENTER_H
#define SERVICECENTER_H

class serviceCenter{
public:
    serviceCenter(int numr,int numc,int numf);
    virtual~ serviceCenter();
    Office* regis;
    Office* cash;
    Office* faid;

    

};

#endif
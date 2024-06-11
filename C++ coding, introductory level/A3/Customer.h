#include <string>
#include "DblList.h"
#include "Listnode.h"
#include "ListQueue.h"
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
public:
    Customer();
    ~Customer();
    Customer(int arrived,char first,char second,char third,int timeFirst, int timeSecond, int timeThird);
    ListQueue<char> orderToAdd;
    ListQueue<int> orderToWait;
    int timeArrived;
    int timeWaitingCash;
    int timeWaitingFaid;
    int timeWaitingRegis; 
    int totalWait;
private:

};


#endif
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Customer.h"
#include "DblList.h"
#include "Listnode.h"
#include "ListQueue.h"
#include "Office.h"
#include "Window.h"
#include "serviceCenter.h"
#include <sstream>
#include<fstream>

class Simulation{
public:
    Simulation();
    virtual ~Simulation();
    void runTheSimulation(string fileName);
    void checkWindows(int time);
    Customer* createCustomer(int time ,string customerData);
    void addCurrentStudent(Customer* customer,int currentTime);
    bool checkIfDone();
    void addToWindow(serviceCenter* m_center, int currentTime);
    ListQueue<double>* getMeanandMaxIdle(ListQueue<double>* queue);
    void RegisWindowMath();
    int waitOver10(ListQueue<Customer*>* queue);
    void FaidWindowMath();
    void CashWindowMath();
    ListQueue<double>* getMeanandMax(ListQueue<double>* queue,int numWindows);
    /*ListQueue<int>* cashWaitTimeQueue;
    ListQueue<int>* faidWaitTimeQueue;
    ListQueue<int>* regisWaitTimeQueue; 
    ListQueue<int>* cashIdleTimeQueue;
    ListQueue<int>* faidIdleTimeQueue;
    ListQueue<int>* regisIdleTimeQueue; 
    ListQueue<Customer*>* totalCustWait;*/
    ListQueue<double>* cashWaitTimeQueue=new ListQueue<double>;
    ListQueue<double>* faidWaitTimeQueue=new ListQueue<double>;
    ListQueue<double>* regisWaitTimeQueue=new ListQueue<double>; 
    ListQueue<double>* cashIdleTimeQueue=new ListQueue<double>;
    ListQueue<double>* faidIdleTimeQueue=new ListQueue<double>;
    ListQueue<double>* regisIdleTimeQueue=new ListQueue<double>; 
    ListQueue<Customer*>* totalCustWait=new ListQueue<Customer*>;
private:
    serviceCenter* m_center;
    
    


    
};

#endif
#include "Customer.h"

Customer::Customer(){

}
Customer::~Customer(){

}
Customer::Customer(int arrived,char first,char second,char third,int timeFirst, int timeSecond, int timeThird){
    int timeWaitingCash=0;
    int timeWaitingFaid=0;
    int timeWaitingRegis=0;
    int timeArrived=arrived;
    orderToAdd.add(first);
    orderToAdd.add(second);
    orderToAdd.add(third);
    orderToWait.add(timeFirst);
    orderToWait.add(timeSecond);
    orderToWait.add(timeThird);
    totalWait=0;
}
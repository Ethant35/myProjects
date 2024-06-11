#include "Simulation.h"
using namespace std;


Simulation::Simulation(){
    m_center=NULL;
}
Simulation::~Simulation(){

}

//Need to track metrics as well



void Simulation::runTheSimulation(string filename){
    //initialize t=0, do the loop until "done"
    //incrementing t by 1 every iteration

    ifstream reader;
    string linecontents="";
    //string* arr = new string[counter];
    reader.open(filename);
    //Creating service center
    getline(reader, linecontents);
    int registrarwindows=stoi(linecontents);
    getline(reader, linecontents);
    int cashierwindows=stoi(linecontents);
    getline(reader, linecontents);
    int faidwindows=stoi(linecontents);
    m_center=new serviceCenter(registrarwindows,cashierwindows,faidwindows);
    bool endOfFile=false;
    getline(reader,linecontents);
    int customerTime=stoi(linecontents);
    getline(reader,linecontents);
    int numCustomers=stoi(linecontents);
        //linecontents="";
    bool isDone=false;
    int time=1;
    while(!isDone){
        //cout<<"Time is: "<<time<<endl;
        if(checkIfDone() && endOfFile){
            isDone=true;
            break;
        }
        checkWindows(time);
        if(time==customerTime){
            string* customerData=new string[numCustomers];
            for (int i=0;i<numCustomers;++i){
                getline(reader,linecontents);
                customerData[i]=linecontents;
                //cout<<customerData[i]<<" "<<customerTime<<endl;
                Customer* customer=createCustomer(time,customerData[i]);
                totalCustWait->add(customer);
                //cout<<customer->orderToAdd.peek()<<endl;
                //cout<<"Time is: "<<time<<endl;
                addCurrentStudent(customer,time);
            }
            delete[] customerData;
            getline(reader,linecontents);
            //cout<<linecontents<<endl;
            if(!endOfFile){
                if (!reader){
                    if (reader.eof()){
                        endOfFile=true;
                        reader.close();
                    }
                }
                else{
                customerTime=stoi(linecontents);
                getline(reader,linecontents);
                numCustomers=stoi(linecontents);
                }
        }
        
 
        }
    time=time+1;
    CashWindowMath();
    RegisWindowMath();
    FaidWindowMath();

    }
    ListQueue<double>* cashMath=getMeanandMax(cashWaitTimeQueue,cashierwindows);
    ListQueue<double>* faidMath=getMeanandMax(faidWaitTimeQueue,faidwindows);
    ListQueue<double>* regisMath=getMeanandMax(regisWaitTimeQueue,registrarwindows);
    ListQueue<double>* cashIdleMath=getMeanandMaxIdle(cashIdleTimeQueue);
    ListQueue<double>* faidIdleMath=getMeanandMaxIdle(faidIdleTimeQueue);
    ListQueue<double>* regisIdleMath=getMeanandMaxIdle(regisIdleTimeQueue);
    double cashAvg=cashMath->remove();
    double faidAvg=faidMath->remove();
    double regisAvg=regisMath->remove();
    cout<<"The average wait times for the the cashier's, financial aid's and registrar's office, respectively are: "<<cashAvg<<", "<<faidAvg<<", "<<regisAvg<<endl;
    double cashLong=cashMath->remove();
    double faidLong=faidMath->remove();
    double regisLong=regisMath->remove();
    cout<<"The longest wait times for the the cashier's, financial aid's and registrar's office, respectively are: "<<cashLong<<", " <<faidLong<< ", " <<regisLong<<endl;
    double totalOverTen=waitOver10(totalCustWait);
    cout<<"The number of students waiting over 10 minutes total across all offices is: "<<totalOverTen<<endl;
    double cashMeanIdle=cashIdleMath->remove();
    double faidMeanIdle=faidIdleMath->remove();
    double regisMeanIdle=regisIdleMath->remove();
    cout<<"The mean idle wait time for the cashier's, financial aid's and registrar's office respectively are: "<<cashMeanIdle<<", "<<faidMeanIdle<<", "<<regisMeanIdle<<endl;
    double cashLongestIdle=cashIdleMath->remove();
    double faidLongestIdle=faidIdleMath->remove();
    double regisLongestIdle=regisIdleMath->remove();
    cout<<"The longest idle time for the cashier's, financial aid's and registrar's office, respectively are: "<<cashLongestIdle<<", "<<faidLongestIdle<<", "<<regisLongestIdle<<endl;
    double cashOverFive=cashMath->remove();
    double faidOverFive=faidMath->remove();
    double regisOverFive=regisMath->remove();
    double totalOverFive=cashOverFive+faidOverFive+regisOverFive;
    cout<<"The total number of windows across all offices with a wait time longer than five minutes is: "<<totalOverFive<<endl;
    

}

void Simulation::checkWindows(int time){
    for (int i=0;i<m_center->cash->numwindows;++i){
        if(m_center->cash->window[i]->c==NULL){
            continue;
        }
        if(m_center->cash->window[i]->endTime==time){
            if (!m_center->cash->window[i]->c->orderToAdd.isEmpty()){
                addCurrentStudent(m_center->cash->window[i]->c,time);
                m_center->cash->window[i]->c=NULL;
                m_center->cash->window[i]->endTime=-1;
                addToWindow(m_center,time);

            }
            else{
                m_center->cash->window[i]->c=NULL;
                m_center->cash->window[i]->endTime=-1;
            }
        }
    }
    for (int i=0;i<m_center->faid->numwindows;++i){
        if(m_center->faid->window[i]->c==NULL){
            continue;
        }
        if(m_center->faid->window[i]->endTime==time){
            if (!m_center->faid->window[i]->c->orderToAdd.isEmpty()){
                addCurrentStudent(m_center->faid->window[i]->c,time);
                m_center->faid->window[i]->c=NULL;
                m_center->faid->window[i]->endTime=-1;
                addToWindow(m_center,time);

            }
            else{
                m_center->faid->window[i]->c=NULL;
                m_center->faid->window[i]->endTime=-1;
            }
        }
    }
    for (int i=0;i<m_center->regis->numwindows;++i){
        if(m_center->regis->window[i]->c==NULL){
            continue;
        }
        if(m_center->regis->window[i]->endTime==time){
            if (!m_center->regis->window[i]->c->orderToAdd.isEmpty()){
                addCurrentStudent(m_center->regis->window[i]->c,time);
                m_center->regis->window[i]->c=NULL;
                m_center->regis->window[i]->endTime=-1;
                addToWindow(m_center,time);

            }
            else{
                m_center->regis->window[i]->c=NULL;
                m_center->regis->window[i]->endTime=-1;
            }
        }
    }
}

Customer* Simulation::createCustomer(int time ,string customerData){
    Customer* c;
    istringstream stream(customerData);
    int firstOfficeTime,secondOfficeTime,thirdOfficeTime;
    char firstOffice,secondOffice,thirdOffice;
    stream>>firstOfficeTime>>secondOfficeTime>>thirdOfficeTime>>firstOffice>>secondOffice>>thirdOffice;
    c=new Customer(time,firstOffice,secondOffice,thirdOffice,firstOfficeTime,secondOfficeTime,thirdOfficeTime);
    return c;
}

void Simulation::addCurrentStudent(Customer* customer,int currentTime){
    char next=customer->orderToAdd.remove();
    if (customer->orderToWait.isEmpty()){
        return;
    }
    int nextTime=customer->orderToWait.peek();
    if (nextTime==0){
        customer->orderToWait.remove();
        if (customer->orderToAdd.isEmpty()){
            
            return;
        }
        addCurrentStudent(customer,currentTime);
        return;
    }
    if(customer->orderToAdd.isEmpty()){
        return;
    }
    bool enteredWindow=false;
     if (next=='C'){
        for (int i=0;i<m_center->cash->numwindows;++i){
            if (m_center->cash->window[i]->endTime==-1&&!enteredWindow){
                m_center->cash->window[i]->c=customer;
                int timeAtNextWindow=customer->orderToWait.remove();
                m_center->cash->window[i]->endTime=timeAtNextWindow+currentTime;
                enteredWindow=true;
                int timeWaitingCash;
                if(customer->timeWaitingCash==0){
                    timeWaitingCash=0;

                }
                else{
                    timeWaitingCash=currentTime-customer->timeWaitingCash;
                }
                cashWaitTimeQueue->add(timeWaitingCash);
                customer->totalWait+=timeWaitingCash;

            }
                 
        }
        if (!enteredWindow){
            customer->timeArrived=currentTime;
            customer->timeWaitingCash=currentTime;
            m_center->cash->line->add(customer);
        }
    }
    if (next=='F'){
        for (int i=0;i<m_center->faid->numwindows;++i){
            if (m_center->faid->window[i]->endTime==-1&&!enteredWindow){
                m_center->faid->window[i]->c=customer;
                int timeAtNextWindow=customer->orderToWait.remove();
                m_center->faid->window[i]->endTime=timeAtNextWindow+currentTime;
                enteredWindow=true;
                int timeWaitingFaid;
                if(customer->timeWaitingFaid==0){
                    timeWaitingFaid=0;

                }
                else{
                    timeWaitingFaid=currentTime-customer->timeWaitingFaid;
                }
                faidWaitTimeQueue->add(timeWaitingFaid);
                customer->totalWait+=timeWaitingFaid;

            }
           
        }
        if (!enteredWindow){
            customer->timeArrived=currentTime;
            customer->timeWaitingFaid=currentTime;
            m_center->faid->line->add(customer);
        }
    }
    if (next=='R'){
        for (int i=0;i<m_center->regis->numwindows;++i){
            if (m_center->regis->window[i]->endTime==-1&&!enteredWindow){
                m_center->regis->window[i]->c=customer;
                int timeAtNextWindow=customer->orderToWait.remove();
                m_center->regis->window[i]->endTime=timeAtNextWindow+currentTime;
                enteredWindow=true;
                int timeWaitingRegis;
                if(customer->timeWaitingRegis==0){
                    timeWaitingRegis=0;

                }
                else{
                    timeWaitingRegis=currentTime-customer->timeWaitingRegis;
                }
                regisWaitTimeQueue->add(timeWaitingRegis);
                customer->totalWait+=timeWaitingRegis;
            }
 
        }
        if (!enteredWindow){
            customer->timeArrived=currentTime;
            customer->timeWaitingRegis=currentTime;
            m_center->regis->line->add(customer);
        }
    }

   
}

void Simulation::addToWindow(serviceCenter* m_center,int currentTime){
    for (int i=0;i<m_center->cash->numwindows;++i){
        if (m_center->cash->window[i]->endTime==-1){
            if(m_center->cash->line->isEmpty()){
                break;
            }
            Customer* c=m_center->cash->line->remove();
            m_center->cash->window[i]->c=c;
            if (c->orderToWait.isEmpty()){
                break;
            }
            int timeAtNextWindow=c->orderToWait.remove();
            m_center->cash->window[i]->endTime=timeAtNextWindow+currentTime;
            int timeWaitingCash=currentTime-c->timeWaitingCash;
            cashWaitTimeQueue->add(timeWaitingCash);
            c->totalWait+=timeWaitingCash;
        }
        
    }
    for (int i=0;i<m_center->faid->numwindows;++i){
        if (m_center->faid->window[i]->endTime==-1){
            if(m_center->faid->line->isEmpty()){
                break;
            }
            Customer* c=m_center->faid->line->remove();
            m_center->faid->window[i]->c=c;
            if (c->orderToWait.isEmpty()){
                break;
            }
            int timeAtNextWindow=c->orderToWait.remove();
            m_center->faid->window[i]->endTime=timeAtNextWindow+currentTime;
            int timeWaitingFaid=currentTime-c->timeWaitingFaid;
            faidWaitTimeQueue->add(timeWaitingFaid);
            c->totalWait+=timeWaitingFaid;
        }
    }
    for (int i=0;i<m_center->regis->numwindows;++i){
        if (m_center->regis->window[i]->endTime==-1){
            if(m_center->regis->line->isEmpty()){
                break;
            }
            Customer* c=m_center->regis->line->remove();
            m_center->regis->window[i]->c=c;
            
            if (c->orderToWait.isEmpty()){
                break;
            }
            int timeAtNextWindow=c->orderToWait.remove();
            m_center->regis->window[i]->endTime=timeAtNextWindow+currentTime;
            int timeWaitingRegis=currentTime-c->timeWaitingRegis;
            regisWaitTimeQueue->add(timeWaitingRegis);
            c->totalWait+=timeWaitingRegis;
        }
    }
}


bool Simulation::checkIfDone(){
    //cout<<"Cashier number of windows: "<<m_center->cash->numwindows<<endl;
    for(int i=0;i<m_center->cash->numwindows;++i){
        //cout<<m_center->cash->window[i]->endTime<<endl;
        if(m_center->cash->window[i]->endTime!=-1){
            //cout<<"Cashier not empty"<<endl;
            //cout<<"Cashier end time"<<m_center->cash->window[i]->endTime<<endl;
            return false;
        }

    }
    for(int j=0;j<m_center->regis->numwindows;++j){
        if(m_center->regis->window[j]->endTime!=-1){
            //cout<<"Registrar end time"<<m_center->cash->window[j]->endTime<<endl;
            return false;
        }
    } 
    for(int k=0;k<m_center->faid->numwindows;++k){
        if(m_center->faid->window[k]->endTime!=-1){
            //cout<<"Financial aid end time"<<m_center->cash->window[k]->endTime<<endl;
            return false;
        }
    }
    return true;
}

ListQueue<double>* Simulation::getMeanandMax(ListQueue<double>* queue,int numWindows){
    double length=queue->size();
    double sum=0;
    double max=0;
    double waitCounter=0;
    while(!queue->isEmpty()){ 
        double n=queue->remove();
        sum+=n;
        if (max<n){
            max=n;
        }
        if(n>5){
            waitCounter+=numWindows;
        }
    }
    double avg=sum/length;
    ListQueue<double>* toReturn=new ListQueue<double>;
    toReturn->add(avg);
    toReturn->add(max);
    toReturn->add(waitCounter);
    return toReturn;

}

void Simulation::CashWindowMath(){
    for (int i=0;i<m_center->cash->numwindows;++i){
        if (m_center->cash->window[i]->endTime==-1 && (m_center->cash->line->isEmpty())){
            m_center->cash->window[i]->idleTime++;
        }
        if(m_center->cash->window[i]->endTime!=-1 && m_center->cash->window[i]->idleTime!=0){
            cashIdleTimeQueue->add(m_center->cash->window[i]->idleTime);
            m_center->cash->window[i]->idleTime=0;
        }
    }
    

}

void Simulation::FaidWindowMath(){
    for (int i=0;i<m_center->faid->numwindows;++i){
        if (m_center->faid->window[i]->endTime==-1 && (m_center->faid->line->isEmpty())){
            m_center->faid->window[i]->idleTime++;
        }
        if(m_center->faid->window[i]->endTime!=-1 && m_center->faid->window[i]->idleTime!=0){
            faidIdleTimeQueue->add(m_center->faid->window[i]->idleTime);
            m_center->faid->window[i]->idleTime=0;
        }
    }

}

int Simulation::waitOver10(ListQueue<Customer*>* queue){
    int counter=0;
    while(!queue->isEmpty()){
        Customer* c=queue->remove();
        int n=c->totalWait;
        if (n>=10){
            counter++;
        }
    }
    return counter;
}

void Simulation::RegisWindowMath(){
    for (int i=0;i<m_center->regis->numwindows;++i){
        if (m_center->regis->window[i]->endTime==-1 && (m_center->regis->line->isEmpty())){
            m_center->regis->window[i]->idleTime++;
        }
        if(m_center->regis->window[i]->endTime!=-1 && m_center->regis->window[i]->idleTime!=0){
            regisIdleTimeQueue->add(m_center->regis->window[i]->idleTime);
            m_center->regis->window[i]->idleTime=0;
        }
    }

}

ListQueue<double>* Simulation::getMeanandMaxIdle(ListQueue<double>* queue){
    double length=queue->size();
    double sum=0;
    double max=0;
    double counter=0;
    while(!queue->isEmpty()){ 
        double n=queue->remove();
        if (n>=5){
            counter++;
        }
        sum+=n;
        if (max<n){
            max=n;
        }
    }
    double avg=sum/length;
    ListQueue<double>* toReturn=new ListQueue<double>;
    toReturn->add(avg);
    toReturn->add(max);
    toReturn->add(counter);
    return toReturn;

}
#ifndef ATSTACK_H
#define ATSTACK_H
#include <cstdlib>
using namespace std;
template <typename T>
class ATStack{
public:
  ATStack();
  ATStack(int iSize, char stackType);
  ~ATStack();
  int size();
  bool isEmpty();
  void push(T c);
  T pop();
  T peek();
  char type;
private:
  T* stackArr;
  int count; //number of things in stack
  int max; //most things we can hold
  int top;
  bool isFull();
};

template <typename T>
ATStack<T>::ATStack(){ //O(1)
  top = -1;
  count = 0;
  max = 0;
  stackArr = NULL;
}
template <typename T>
ATStack<T>::ATStack(int iSize, char stackType){ //O(1)
  top = -1;
  count = 0;
  max = iSize;
  type=stackType;
  stackArr = new T[max];
}
template <typename T>
ATStack<T>::~ATStack(){ //O(1)
  if(stackArr!=NULL){
    //delete[] stackArr;
    delete[] stackArr;
  }
}
template <typename T>
int ATStack<T>::size(){ //O(1)
  return count;
}
template <typename T>
bool ATStack<T>::isEmpty(){ //O(1)
  return (count==0);
}
template <typename T>
bool ATStack<T>::isFull(){ //O(1)
  return (count==max);
}
template <typename T>
void ATStack<T>::push(T c){ //O(max) linear
  if(isFull()){
    T* temp = new T[2*max];
    for(int i = 0; i < max; ++i){
      temp[i] = stackArr[i];
    }
  }
  max *= 2;
  if(!isEmpty()){
    if (type=='i'){
      while(!isEmpty()&& peek()>c){
        pop();
      }
    }
    else{
      while(!isEmpty()&&peek()<c){
        pop();
      }
    }
  }
  stackArr[++top]=c;
  ++count;
}
  
  

template <typename T>
T ATStack<T>::pop(){ //O(1) better tell user to check if empty first
  --count;
  return stackArr[top--];
}
template <typename T>
T ATStack<T>::peek(){ //O(1) what about if empty?
  return stackArr[top];
}
#endif
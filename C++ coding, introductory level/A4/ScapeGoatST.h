#ifndef ScapeGoatST_H
#define ScapeGoatST_H

#include<cmath>
#include "TreeNode.h"
#include <iostream>
using namespace std;
template <typename T>
class ScapeGoatST{
public:
  ScapeGoatST();
  virtual ~ScapeGoatST();
  void insert(T d);
  void remove(T d);
  TreeNode<T>* contains(T d);
  //void printInOrder();
  void printPostOrder();
  int getSize(TreeNode <T>* node);
  int getSize();
  T getMedian();
  T getMin();
  T getMax();
  TreeNode<T>* rebuildTree(TreeNode<T>* node);
  TreeNode<T>** bubbleSort(TreeNode<T>** arr, int n);
  TreeNode<T>* m_root;
private:
  int m_size;
  int insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode,int depth, TreeNode<T>* parentNode);
  TreeNode<T>* containsHelper(TreeNode<T>* subTreeRoot, T d);
  void printInOrderHelper(TreeNode<T>* subTreeRoot);
  void printPostOrderHelper(TreeNode<T>* subTreeRoot);
  T getMinHelper(TreeNode<T>* subTreeRoot);
  T getMaxHelper(TreeNode<T>* subTreeRoot);
  void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
  T getSuccessor(TreeNode<T>* node);
  int m;
  TreeNode<T>* buildSubTreeFromArray(TreeNode<T>** arr,int size);
  int storeInArray(TreeNode<T>* node, TreeNode<T>** arr, int i);
};
template <typename T>
ScapeGoatST<T>::ScapeGoatST(){
  m_root = NULL;
  m_size = 0;
  m=0;
}
template <typename T>
ScapeGoatST<T>::~ScapeGoatST(){
  if(m_root != NULL){
    delete m_root;
  }
}

template <typename T>
void ScapeGoatST<T>::insert(T d){
    TreeNode<T>* newNode=new TreeNode<T>(d);
    int leftheight=0;
    int rightheight=0;
    int depth=insertHelper(m_root,newNode,0,NULL);
    ++m_size;
    ++m;
    /*float log3over2=log(m)/log(1.5);
    if (depth>log3over2){
      TreeNode<T>* ScapeGoat=newNode->m_parent;
      float ScapeGoatSize=getSize(ScapeGoat);
      float parentSize=getSize(ScapeGoat->m_parent);
      //cout<<ScapeGoat->m_data<<endl;
      float num=ScapeGoatSize/parentSize;
      while(num<=.667){
        //change ScapeGoat to parent of ScapeGoat depending on some math
        ScapeGoat = ScapeGoat->m_parent;
        ScapeGoatSize=getSize(ScapeGoat);
        parentSize=getSize(ScapeGoat->m_parent);
        //cout<<ScapeGoat->m_data<<endl;
        num=ScapeGoatSize/parentSize;
      }
      rebuildTree(ScapeGoat);*/

  }   

/*int ScapeGoatST<T>::insertHelper(TreeNode<T>*& subTreeRoot,TreeNode<T>* newNode){
    TreeNode<T>* currentRoot=subTreeRoot;
    if(currentRoot==NULL){
        currentRoot=newNode;
        return 0;    
    }
    bool isDone=false;
    int depth=0;
    while(!isDone){
      if(newNode->m_data<currentRoot->m_data){
        if(currentRoot->m_left==NULL){
          currentRoot->m_left=newNode;
          newNode->m_parent=currentRoot;
          isDone=true;

        }
        else{
          currentRoot=currentRoot->m_left;
        }
      
        //insertHelper(subTreeRoot->m_left,newNode);
        } 
      
    else
    {
        if (currentRoot->m_right==NULL){
          currentRoot->m_right=newNode;
          newNode->m_parent=currentRoot;
          isDone=true;
        }
        else{
          currentRoot=currentRoot->m_right;
        }
        //insertHelper(subTreeRoot->m_right,newNode);
    }
    depth++;
    }
    return depth;
}*/
template <typename T>
int ScapeGoatST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode,int depth, TreeNode<T>* parentNode){
  if(subTreeRoot == NULL){
    subTreeRoot = newNode;
    subTreeRoot->m_parent=parentNode;
    return depth;
  } else if(newNode->m_data.m_id < subTreeRoot->m_data.m_id){
    return insertHelper(subTreeRoot->m_left,newNode,depth+1,subTreeRoot);
  } else{
    return insertHelper(subTreeRoot->m_right,newNode,depth+1,subTreeRoot);
  }
}
template <typename T>
int ScapeGoatST<T>::getSize(){
  return m_size;
}
template <typename T>
int ScapeGoatST<T>::getSize(TreeNode <T>* node){
  if (node==NULL){
    return 0;
  }
  else{
    return 1+getSize(node->m_left)+getSize(node->m_right);
  }
}
template <typename T>
TreeNode<T>* ScapeGoatST<T>::contains(T d){
  return containsHelper(m_root,d);
}
template <typename T>
TreeNode<T>* ScapeGoatST<T>::containsHelper(TreeNode<T>* subTreeRoot, T d){
  if(subTreeRoot == NULL){
    return NULL;
  } else if (subTreeRoot->m_data->m_id == d){
    return subTreeRoot;
  } else if(d < subTreeRoot->m_data->m_id){
    return containsHelper(subTreeRoot->m_left,d);
  } else{
    return containsHelper(subTreeRoot->m_right,d);
  }
}
/*
template <typename T>
bool ScapeGoatST<T>::iterativeContains(T d){
  if(m_root == NULL){
    return false;
  }
  if(m_root->m_data ==  d){
    return true;
  }
  bool found = false;
  TreeNode<T>* current = m_root;
  while(!found){
    if(d < current->m_data){
      current = current->m_left;
    } else{
      current = current->m_right;
    }
    if(current == NULL){
      found = false;
      break;
    }
    if(current->m_data ==  d){
      found = true;
      break;
    }
  }
  return found;
}
*/

template <typename T>
void ScapeGoatST<T>::printPostOrder(){
  printPostOrderHelper(m_root);
}
template <typename T>
TreeNode<T>** ScapeGoatST<T>::bubbleSort(TreeNode<T>** arr, int n){
    for(int i=0;i<n-1;++i){
        for (int j=0;j<n-i;++j){
            if(arr[j]>arr[j+1]){
                TreeNode<T>* temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;
}

/*template <typename T>
void ScapeGoatST<T>::printInOrder(){
  printInOrderHelper(m_root);
}
template <typename T>
void ScapeGoatST<T>::printInOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printInOrderHelper(subTreeRoot->m_left);
    cout << subTreeRoot->m_data->m_id << endl;
    printInOrderHelper(subTreeRoot->m_right);
  }
  else{
    cout<<"The tree is empty"<<endl;
  }
}*/

template <typename T>
void ScapeGoatST<T>::printPostOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printPostOrderHelper(subTreeRoot->m_left);
    printPostOrderHelper(subTreeRoot->m_right);
    cout << subTreeRoot->m_data->m_id << endl;
  }
}
template <typename T>
T ScapeGoatST<T>::getMedian(){
  return m_root->m_data;
}
template <typename T>
T ScapeGoatST<T>::getMin(){
  return getMinHelper(m_root);
}
template <typename T>
T ScapeGoatST<T>::getMax(){
  return getMaxHelper(m_root);
}
template <typename T>
T ScapeGoatST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left == NULL){
    return subTreeRoot->m_data;
  } else{
    return getMinHelper(subTreeRoot->m_left);
  }
}
template <typename T>
T ScapeGoatST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_right == NULL){
    return subTreeRoot->m_data;
  } else{
    return getMaxHelper(subTreeRoot->m_right);
  }
}
template <typename T>
void ScapeGoatST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
  while(target != NULL && !(target->m_data==key)){
    parent = target;
    if(key < target->m_data){
      target = target->m_left;
    } else{
      target = target->m_right;
    }
  }
}
template <typename T>
T ScapeGoatST<T>::getSuccessor(TreeNode<T>* node){ //assume node starts at right child
  while(node->m_left != NULL){
    node = node->m_left;
  }
  return node->m_data;
}
template <typename T>
void ScapeGoatST<T>::remove(T d){
  //make sure to free memory
  //check for follishness
  TreeNode<T>* parent = NULL; //keep track of what needs to be deleted and patched
  TreeNode<T>* target = NULL;
  //do the remove
  target = m_root;
  findTarget(d,target,parent);
  if(target == NULL){ //not in tree
    return;
  }
  //do some real work
  if(target->m_left == NULL && target->m_right == NULL ){ //it's a leaf
    if(target == m_root){
      m_root = NULL;
    } else{
      if(target == parent->m_left){
        parent->m_left = NULL;
      } else{
        parent->m_right = NULL;
      }
    }
  } else if(target->m_left != NULL && target->m_right != NULL){ //2 children
    T succValue = getSuccessor(target->m_right);
    remove(succValue);
    target->m_data = succValue;
  } else{ // 1 child
    TreeNode<T>* child;
    if(target->m_left != NULL){
      child = target->m_left;
    } else{
      child = target->m_right;
    }
    if(target == m_root){
      m_root = child;
    } else{
      if(target == parent->m_left){
        parent->m_left = child;
      } else{
        parent->m_right = child;
      }
    }
    m_size--;
  }
}






#endif
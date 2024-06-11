#ifndef BST_H
#define BST_H
#include "TreeNode.h"
#include <iostream>
using namespace std;
template <typename T>
class BST{
public:
  BST();
  virtual ~BST();
  void insert(T d);
  void remove(T d);
  bool contains(T d);
  void printInOrder();
  void printPostOrder();
  int getSize();
  T getMedian();
  T getMin();
  T getMax();
private:
  TreeNode<T>* m_root;
  int m_size;
  void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
  bool containsHelper(TreeNode<T>* subTreeRoot, T d);
  void printInOrderHelper(TreeNode<T>* subTreeRoot);
  void printPostOrderHelper(TreeNode<T>* subTreeRoot);
  T getMinHelper(TreeNode<T>* subTreeRoot);
  T getMaxHelper(TreeNode<T>* subTreeRoot);
  void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
  T getSuccessor(TreeNode<T>* node);
};
template <typename T>
BST<T>::BST(){
  m_root = NULL;
  m_size = 0;
}
template <typename T>
BST<T>::~BST(){
  if(m_root != NULL){
    delete m_root;
  }
}
template <typename T>
int BST<T>::getSize(){
  return m_size;
}
template <typename T>
void BST<T>::insert(T d){
  TreeNode<T>* newNode = new TreeNode<T>(d);
  insertHelper(m_root,newNode);
  ++m_size;
}
template <typename T>
void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    subTreeRoot = newNode;
  } else if(newNode->m_data.m_id < subTreeRoot->m_data.m_id){
    insertHelper(subTreeRoot->m_left,newNode);
  } else{
    insertHelper(subTreeRoot->m_right,newNode);
  }
}
template <typename T>
bool BST<T>::contains(T d){
  return containsHelper(m_root,d);
}
template <typename T>
bool BST<T>::containsHelper(TreeNode<T>* subTreeRoot, T d){
  if(subTreeRoot == NULL){
    return false;
  } else if (subTreeRoot->m_data.m_id == d){
    return true;
  } else if(d < subTreeRoot->m_data.m_id){
    return containsHelper(subTreeRoot->m_left,d);
  } else{
    return containsHelper(subTreeRoot->m_right,d);
  }
}
/*
template <typename T>
bool BST<T>::iterativeContains(T d){
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
void BST<T>::printInOrder(){
  printInOrderHelper(m_root);
}
template <typename T>
void BST<T>::printInOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printInOrderHelper(subTreeRoot->m_left);
    cout << subTreeRoot->m_data.m_id << endl;
    printInOrderHelper(subTreeRoot->m_right);
  }
}
template <typename T>
void BST<T>::printPostOrder(){
  printPostOrderHelper(m_root);
}
template <typename T>
void BST<T>::printPostOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printPostOrderHelper(subTreeRoot->m_left);
    printPostOrderHelper(subTreeRoot->m_right);
    cout << subTreeRoot->m_data.m_id << endl;
  }
}
template <typename T>
T BST<T>::getMedian(){
  return m_root->m_data.m_id;
}
template <typename T>
T BST<T>::getMin(){
  return getMinHelper(m_root);
}
template <typename T>
T BST<T>::getMax(){
  return getMaxHelper(m_root);
}
template <typename T>
T BST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left == NULL){
    return subTreeRoot->m_data.m_id;
  } else{
    return getMinHelper(subTreeRoot->m_left);
  }
}
template <typename T>
T BST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_right == NULL){
    return subTreeRoot->m_data.m_id;
  } else{
    return getMaxHelper(subTreeRoot->m_right);
  }
}
template <typename T>
void BST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
  while(target != NULL && target->m_data.m_id != key){
    parent = target;
    if(key < target->m_data.m_id){
      target = target->m_left;
    } else{
      target = target->m_right;
    }
  }
}
template <typename T>
T BST<T>::getSuccessor(TreeNode<T>* node){ //assume node starts at right child
  while(node->m_left != NULL){
    node = node->m_left;
  }
  return node->m_data;
}
template <typename T>
void BST<T>::remove(T d){
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
  }
}
#endif
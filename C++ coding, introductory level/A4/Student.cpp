#include "Student.h"

Student::Student(){

}

Student::~Student(){
  
}
Student::Student(int id,string name,string level,string major,double gpa,int advisor){
    m_id=id;
    m_name=name;
    m_level=level;
    m_major=major;
    m_gpa=gpa;
    m_advisor=advisor;
}

bool Student::containsStudent(int id, TreeNode<Student>* node){
    return containsHelper(node,id);
}



bool Student::containsHelper(TreeNode<Student>* subTreeRoot, int d){
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

TreeNode<Student>* Student::findHelper(TreeNode<Student>* subTreeRoot, int d){
  if(subTreeRoot == NULL){
    return NULL;
  } else if (subTreeRoot->m_data.m_id == d){
    return subTreeRoot;
  } else if(d < subTreeRoot->m_data.m_id){
    return findHelper(subTreeRoot->m_left,d);
  } else if(d > subTreeRoot->m_data.m_id){
    return findHelper(subTreeRoot->m_right,d);
  }
}

TreeNode<Student>* Student::findStudent(int id, TreeNode<Student>* node){
  return findHelper(node,id);
}

string Student::studenttoString(){
    string n="";
    n+=this->m_name+" ";
    n+=this->m_level+" ";
    n+=this->m_major+" ";
    n+=to_string(this->m_gpa)+" ";
    n+=to_string(this->m_advisor)+" ";
    return n;
}

bool Student::operator==(const Student &s2){
  return(this->m_id==s2.m_id);
}

bool Student::operator>(const Student &s2){
  return(this->m_id>s2.m_id);
}

bool Student::operator<(const Student &s2){
  return(this->m_id<s2.m_id);
}








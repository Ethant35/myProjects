#include "Faculty.h"

Faculty::Faculty(){

}

Faculty::~Faculty(){
  
}
Faculty::Faculty(int id,string name,string level,string department,DblList<int> advisor){
    m_id=id;
    m_name=name;
    m_level=level;
    m_dept=department;
    m_advisee=advisor;

}

string Faculty::factoString(){
    string n="";
    n+=this->m_name+" ";
    n+=this->m_level+" ";
    n+=this->m_dept;
    for (int i=0;i<this->m_advisee.getSize();++i){
      n+=" ";
      int k=this->m_advisee.remove(i);
      n+=to_string(k);
    }
    return n;
}

bool Faculty::containsFaculty(int id, TreeNode<Faculty>* node){
    if(node == NULL){
      return false;
  } else if (node->m_data.m_id == id){
    return true;
  } else if(id < node->m_data.m_id){
    return containsHelper(node->m_left,id);
  } else{
    return containsHelper(node->m_right,id);
  }
}



bool Faculty::containsHelper(TreeNode<Faculty>* subTreeRoot, int d){
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

TreeNode<Faculty>* Faculty::findHelper(TreeNode<Faculty>* subTreeRoot, int d){
  if(subTreeRoot == NULL){
    return NULL;
  } else if (subTreeRoot->m_data.m_id == d){
    return subTreeRoot;
  } else if(d < subTreeRoot->m_data.m_id){
    return findHelper(subTreeRoot->m_left,d);
  } else{
    return findHelper(subTreeRoot->m_right,d);
  }
}

TreeNode<Faculty>* Faculty::findFaculty(int id, TreeNode<Faculty>* node){
    if(node == NULL){
      return NULL;
  } else if (node->m_data.m_id == id){
    return node;
  } else if(id < node->m_data.m_id){
    return findHelper(node->m_left,id);
  } else{
    return findHelper(node->m_right,id);
  }
}

bool Faculty::operator==(const Faculty &f2){
  return(this->m_id==f2.m_id);
}

bool Faculty::operator>(const Faculty &f2){
  return(this->m_id>f2.m_id);
}

bool Faculty::operator<(const Faculty &f2){
  return(this->m_id<f2.m_id);
}
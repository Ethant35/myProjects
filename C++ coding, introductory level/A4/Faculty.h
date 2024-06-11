#ifndef FACULTY_H   
#define FACULTY_H
#include<iostream>
#include "Listnode.h"
#include "DblList.h"
#include "TreeNode.h"
#include "ScapeGoatST.h"
using namespace std;
class Faculty{

public:
    Faculty();
    virtual ~Faculty();
    Faculty(int id,string name,string level,string department,DblList<int> advisor);
    int m_id;
    string m_name;
    string m_level;
    string m_dept;
    DblList<int> m_advisee;
    string factoString();
    bool containsFaculty(int id, TreeNode<Faculty>* node);
    bool containsHelper(TreeNode<Faculty>* subTreeRoot, int d);
    TreeNode<Faculty>* findHelper(TreeNode<Faculty>* subTreeRoot, int d);
    TreeNode<Faculty>* findFaculty(int id, TreeNode<Faculty>* node);
    bool operator==(const Faculty &f2);
    bool operator>(const Faculty &f2);
    bool operator<(const Faculty &f2);





    

};
    



#endif
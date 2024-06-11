#ifndef STUDENT_H   
#define STUDENT_H
//#include<iostream>
#include "ScapeGoatST.h"
using namespace std;
class Student{

public:
    Student();
    virtual ~Student();
    Student(int id,string name,string level,string major,double gpa,int advisor);
    int m_id;
    string m_name;
    string m_level;
    string m_major;
    double m_gpa;
    int m_advisor;
    bool containsStudent(int id, TreeNode<Student>* node);
    string studenttoString();
    bool containsHelper(TreeNode<Student>* subTreeRoot, int d);
    TreeNode<Student>* findStudent(int id, TreeNode<Student>* node);
    TreeNode<Student>* findHelper(TreeNode<Student>* subTreeRoot, int d);
    bool operator==(const Student &s2);
    bool operator>(const Student &s2);
    bool operator<(const Student &s2);



};



#endif
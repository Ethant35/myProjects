#ifndef DATABASE_H
#define DATABASE_H
#include "Student.h"
#include "Faculty.h"
#include "ScapeGoatST.h"

class Database{
public:
    Database();
    virtual ~Database();
    void driverCode();
    void printInOrderStu();
    void printInOrderHelperStu(TreeNode<Student>* subTreeRoot);
    ScapeGoatST<Student>* student=new ScapeGoatST<Student>;
    ScapeGoatST<Faculty>* faculty=new ScapeGoatST<Faculty>;
    void printInOrderHelperFac(TreeNode<Faculty>* subTreeRoot);
    void printInOrderFac();
    void printInOrderToFile();
    void printInOrderHelperToFile(TreeNode<Student>* studentRoot, TreeNode<Faculty>* facultyRoot);

};

#endif
#include "Database.h"
#include "Student.h"
#include "Faculty.h"
#include<iostream>
#include <sstream>
#include <fstream>
using namespace std;

Database::Database(){
    ScapeGoatST<Student>* student=new ScapeGoatST<Student>;
    ScapeGoatST<Faculty>* faculty=new ScapeGoatST<Faculty>;
}
Database::~Database(){
}
void Database::driverCode(){
    int n;
    bool done=false;
    cout<<"Pick an number choice from the following please"<<endl;
    cout<<"1. Print all students and their information"<<endl;
    cout<<"2. Print all faculty and their information"<<endl;
    cout<<"3. Find and display student information given the student's id"<<endl;
    cout<<"4. Find and display faculty information given the faculty id"<<endl;
    cout<<"5. Add a new student"<<endl;
    cout<<"6. Delete a student given the id"<<endl;
    cout<<"7. Add a new faculty member"<<endl;
    cout<<"8. Delete a faculty member given the id."<<endl;
    cout<<"9. Change a student’s advisor given the student id and the new faculty id."<<endl;
    cout<<"10. Remove an advisee from a faculty member given the ids"<<endl;
    cout<<"11. Exit"<<endl;
    cin>>n;
    if(n==1){
        printInOrderStu();
    }
    if(n==2){
        printInOrderFac();
    }
    if(n==3){
        int k=0;
        cout<<"Please enter the ID number of a student you would like to find"<<endl;
        cin>>k;
        bool found=Student().containsStudent(k, student->m_root);
        if(found==true){
          TreeNode<Student>* foundStu=Student().findStudent(k, student->m_root);
          Student s=foundStu->m_data;
          cout<<"The information of that student is: "<<s.studenttoString()<<endl;
        }
        else{
          cout<<"A student with an ID number of "<<k<<" is not present in the database"<<endl;
        }
    }

    if(n==4){
        int k=0;
        cout<<"Please enter the ID number of a faculty member you would like to find"<<endl;
        cin>>k;
        bool found=Faculty().containsFaculty(k, faculty->m_root);
        if(found==true){
          TreeNode<Faculty>* foundFac=Faculty().findFaculty(k, faculty->m_root);
          Faculty f=foundFac->m_data;
          cout<<"The information of that student is: "<<f.factoString()<<endl;
        }
        else{
          cout<<"A faculty member with an ID number of "<<k<<" is not present in the database"<<endl;
        }
    }
    if (n==5){
      cout<<"Please enter the full information of a student, as presented in the next line:"<<endl;
      cout<<"ID name level major gpa advisor"<<endl;
      //string info="";
      int id;
      string name;
      string level;
      string major;
      double gpa;
      int advisor;
      cin >> id >> name >> level >> major >> gpa >> advisor;
      //bool advisorFound=Faculty().containsFaculty(advisor,faculty->m_root);
      Student stu (id,name,level,major,gpa,advisor);
      student->insert(stu);
    }
    if(n==6){
      cout<<"Please enter the ID of a student that you would like to delete"<<endl;
      int toDelete;
      cin>>toDelete;
      bool found=Student().containsStudent(toDelete,student->m_root);
      if (found==true){
        TreeNode<Student>* foundstu=Student().findStudent(toDelete,student->m_root);
        Student stu=foundstu->m_data;
        int studentAdvisor=stu.m_advisor;
        int studID=stu.m_id;
        TreeNode<Faculty>* advisor=Faculty().findFaculty(studentAdvisor,faculty->m_root);
        Faculty found=advisor->m_data;
        DblList<int> advisorList=found.m_advisee;
        advisorList.removeByValue(studID);
        student->remove(stu);
        cout<<"Student with ID"<<toDelete<<" was deleted"<<endl;
      }
      else{
        cout<<"The student ID you provided is not present in the database"<<endl;
      }
    }
    if (n==7){
      cout<<"Please enter the specifications for a faculty member in the order below"<<endl;
      cout<<"ID name level department"<<endl;
      cout<<"Additionally, please enter the IDs of the students that this faculty member is an advisor for"<<endl;
      int id;
      string name;
      string level;
      string department;
      string advisees;
      string arraySizeHelp;
      int counter=0;
      DblList<int> advisee;
      cin>>id>>name>>level>>department>>advisees;
      istringstream stream(advisees);
      while(stream>>arraySizeHelp){
        counter++;
      }
      string arr[counter];
      int array[counter];
      for (int i=0;i<counter;++i){
        stream>>arr[i];
      }
      for (int i=0;i<counter;++i){
        arr[i]=array[i];
      }
      bool validList = true;
      for (int i=0;i<counter;++i){
        bool studentFound=Student().containsStudent(array[i],student->m_root);
        validList=studentFound;
        if(validList==false){
          {
            cout<<"The list of advisees entered was invalid, please try again"<<endl;
          }
        advisee.add(i,array[i]);
        }
      }
      if(validList==true){
        Faculty fac (id,name,level,department,advisee);
        faculty->insert(fac);
      }

    }
    if(n==8){
      cout<<"Please enter the ID number of the faculty member to delete"<<endl;
      int toDelete;
      cin>>toDelete;
      cout<<"Please input a Faculty member ID that all the students who belonged to the advisor you would like to delete will now belong to"<<endl;
      int o;
      cin>>o;
      bool facToDelete=Faculty().containsFaculty(toDelete,faculty->m_root);
      bool facToAdd=Faculty().containsFaculty(o,faculty->m_root);
      if (facToDelete&&facToAdd){
        TreeNode<Faculty>* foundFacMember=Faculty().findFaculty(toDelete,faculty->m_root);
        Faculty foundFaculty=foundFacMember->m_data;
        DblList<int> adviseeReassign=foundFaculty.m_advisee;
        TreeNode<Faculty>* newFacMember=Faculty().findFaculty(toDelete,faculty->m_root);
        Faculty newFaculty=newFacMember->m_data;
        DblList<int> newAdvisee=newFaculty.m_advisee;
        int arr[adviseeReassign.getSize()];
        for(int i=0;i<adviseeReassign.getSize();++i){
          int ID=adviseeReassign.removeBack();
          arr[i]=ID;
        }
        TreeNode<Student>* array[adviseeReassign.getSize()];
        for(int i=0;i<adviseeReassign.getSize();++i){
          TreeNode<Student>* node=Student().findStudent(arr[i],student->m_root);
          array[i]=node;
        }
        
        for (int i=0;i<adviseeReassign.getSize();++i){
          array[i]->m_data.m_advisor=o;
        }
        for(int i=0;i<adviseeReassign.getSize();++i){
          newFaculty.m_advisee.addFront(array[i]->m_data.m_id);
        }
        faculty->remove(foundFaculty);
      }
      else{
        cout<<"The faculty ID for the exisitng faculty member or the faculty member to add after the deletion was invalid and this process will be aborted"<<endl;
      }

    }
    if(n==9){
      cout<<"Please input the ID of an advisor and the ID of a student, separated by a space to change the student's faculty advisor to the one that was inputted"<<endl;
      int studentID;
      int facultyID;
      cin>>facultyID>>studentID;
      bool findFaculty=Faculty().containsFaculty(facultyID,faculty->m_root);
      bool findStudent=Student().containsStudent(studentID,student->m_root);
      if(findFaculty&&findStudent){
        TreeNode<Faculty>* foundFaculty=Faculty().findFaculty(facultyID,faculty->m_root);
        TreeNode<Student>* foundStudent=Student().findStudent(studentID,student->m_root);
        Faculty fac=foundFaculty->m_data;
        Student stu=foundStudent->m_data;
        stu.m_advisor=facultyID;
        fac.m_advisee.addBack(studentID);

      }
      else{
        cout<<"Either the Student ID or Faculty member ID was invalid and the operation will be aborted"<<endl;
      }
    }
    if(n==10){
      cout<<"Please enter the ID of a faculty member and the ID of a student whom you would like to remove from that faculty member's list of advisees"<<endl;
      int studentID;
      int facultyID;
      cin>>facultyID>>studentID;
      bool findFaculty=Faculty().containsFaculty(facultyID,faculty->m_root);
      bool findStudent=Student().containsStudent(studentID,student->m_root);
      if(findFaculty&&findStudent){
        TreeNode<Faculty>* foundFaculty=Faculty().findFaculty(facultyID,faculty->m_root);
        TreeNode<Student>* foundStudent=Student().findStudent(studentID,student->m_root);
        Faculty fac=foundFaculty->m_data;
        Student stu=foundStudent->m_data;
        stu.m_advisor=0;
        fac.m_advisee.removeByValue(studentID);
      }
      else{
        cout<<"Either the student ID or faculty ID that was entered was not present in the database and this process will be aborted"<<endl;
      }
    }
    if(n==11){
      printInOrderToFile();
      done=true;
    }
      if (!done){
        driverCode();
      }
      else{
        return;
        }

    
    
}

void Database::printInOrderStu(){
  printInOrderHelperStu(student->m_root);
}

void Database::printInOrderHelperStu(TreeNode<Student>* subTreeRoot){
  if(subTreeRoot != NULL){
    printInOrderHelperStu(subTreeRoot->m_left);
    Student s=subTreeRoot->m_data;
    cout << s.studenttoString()<< endl;
    printInOrderHelperStu(subTreeRoot->m_right);
  }
}

void Database::printInOrderToFile(){
  printInOrderHelperToFile(student->m_root,faculty->m_root);
}

void Database::printInOrderHelperToFile(TreeNode<Student>* studentRoot, TreeNode<Faculty>* facultyRoot){
  if(studentRoot != NULL && facultyRoot !=NULL){
    printInOrderHelperToFile(studentRoot->m_left,facultyRoot->m_left);
    ofstream writer;
    writer.open("runLog.txt");
    Student s=studentRoot->m_data;
    writer << s.studenttoString()<< endl;
    Faculty f=facultyRoot->m_data;
    writer<<f.factoString()<<endl;
    printInOrderHelperToFile(studentRoot->m_right,facultyRoot->m_right);
  }
}

void Database::printInOrderFac(){
  printInOrderHelperFac(faculty->m_root);
}

void Database::printInOrderHelperFac(TreeNode<Faculty>* subTreeRoot){
  if(subTreeRoot != NULL){
    printInOrderHelperFac(subTreeRoot->m_left);
    Faculty f=subTreeRoot->m_data;
    cout << f.factoString()<< endl;
    printInOrderHelperFac(subTreeRoot->m_right);
  }
}


    



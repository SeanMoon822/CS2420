/*
    Author: Seonghyun Moon
    Date: Apr.9th.2023
    Program: Doubly Linked-List
    filename: Assignment4.cpp
*/
//Time Complexity: O(n)
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;
class Student 
{
    private:
    string uID;
    string name;
    string major;
    public:
    //Create a constructor.
        Student()
        {
            uID = " ";
            name = " ";
            major = " ";
        }
    //Create a constructor and set them equal in order to use the private variables.
        Student(string uid,string Name,string Major)
        {
            uID = uid;
            name = Name;
            major = Major;
        }
    //Make setters to access the private class variables.
        void setuID(string uid)
        {
            uID = uid;    
        }
        void setname(string Name)
        {
            name = Name;
        }
        void setmajor(string Major)
        {
            major = Major;
        }
    //Make getters to access the private class variables.
        string getuID()
        {
            return uID;    
        }
        string getname()
        {
            return name;
        }
        string getmajor()
        {
            return major;
        }
    //Print the students id, name, and major.
        void print() const
        {
            cout << "ID: " << uID << ", Name: " << name << ", Major: " << major << endl;
        }
    
};
int main() 
{
    // Create a list of students.
    list<Student> students;

    // Open the input file.
    ifstream inputFile("studentsList.txt");

    // Read students informations from file and add to the list.
    string uID, name, major;
    while (inputFile >> uID >> name >> major) 
    {
        Student student = { uID, name, major };
        students.push_back(student);
    }

    // Print all students informations in the list.
    cout <<"All students: "<<endl;
    for (const auto& student : students) 
    {
        student.print();
    }

    // Insert new student at the front of the list.
    Student newStudent1 = { "u2000", "Solomon", "Physics" };
    students.push_front(newStudent1);

    // Insert new student at the back of the list.
    Student newStudent2 = { "u3000", "Rebecca", "Biology" };
    students.push_back(newStudent2);

    // Delete student, Jess from the list.
    auto i = students.begin();
    while (i != students.end()) 
    {
        if (i->getname() == "Jess") 
        {
            i = students.erase(i);
        } else 
        {
            ++i;
        }
    }

    // Insert another new student to the list before Rebecca.
    Student newStudent3 = { "u3001", "Tina", "Chemistry" };
    i = students.begin();
    while (i != students.end()) 
    {
        if (i->getuID() == "u3000") 
        {
            students.insert(i, newStudent3);
            break;
        } 
        else 
        {
            ++i;
        }
    }
    // Delete the first student from the list.
    students.pop_front();
    // Print all students in the list after the operations 3-7.
    cout << "\nAfter operations: \n";
    for (const auto& student : students) 
    {
        student.print();
    }
    return 0;
}

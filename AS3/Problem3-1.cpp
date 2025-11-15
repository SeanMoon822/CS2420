/*
    Author: Seonghyun Moon
    Date: Mar.29th.2023
    Program: Linked-List
    filename: Assignment3.cpp
*/
#include<iostream>
#include<list>
#include<vector>
#include<fstream>
using namespace std;
class Student
{
    private:
        string uID;
        string name;
        string major;
    public:
    //Create a empty constructor.
        Student()
        {
            uID = " ";
            name = " ";
            major = " ";
        }
    //Create a constructor and set them equal in order to use the private variables.
        Student(string id,string Name,string Major)
        {
            uID = id;
            name = Name;
            major = Major;
        }
    //Make setters so that user can access private variables.
        void setuID(string id)
        {
            uID = id;    
        }
        void setname(string Name)
        {
            name = Name;
        }
        void setmajor(string Major)
        {
            major = Major;
        }
    //Make getters in order to get the value of the students id, name, and major.
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
        void display()
        {
            cout<<uID<<"  "<<name<<"  "<<major<<"  ";
        }
};
int main ()
{
    //Create vector class in order to access the studentsList.txt information.
    vector<Student> studentsList;
    ifstream File("studentsList.txt");
    string id,name,major;
    if(File.is_open())
    {
        while(File>>id>>name>>major)
        {
            //create a new object, so that able to recieve information and put on studentsList vector.
            Student student(id,name,major);
            studentsList.push_back(student);
        }
        //Print the information that user received from the text file.
        cout<<"All students in the list: ";
        for(Student student: studentsList)
        {
            cout<<endl;
            student.display();
        }
        cout<<endl;
        //Create a new object in order to add in the front of the list.
        Student newStudent("u2000","Solomon","Physics");
        studentsList.insert(studentsList.begin(),newStudent);
        //Create another object to add in the end of the list.
        Student newStudent2("u3000","Rebecca","Biology");
        studentsList.push_back(newStudent2);
        //erase Solomon's information.
        studentsList.erase(studentsList.begin());
        cout<<endl;
        cout<<"All students in the list: ";
        for(Student student: studentsList)
        {
            cout<<endl;
            student.display();
        }
    }
    else
    {
        File.close();
    }
    return 0;
}

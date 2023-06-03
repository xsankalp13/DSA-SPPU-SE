#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include <cstdio>
using namespace std;

class Student{
    public:
    int rollNumber;
    string name;
    string div;
    string address;
    Student(){
        rollNumber = -1;
        name = "";
        div = "";
        address = "";
    }
};

void handleCreate(Student &s,queue<string> &q){
    cout<<"Enter your roll number: ";
    cin>>s.rollNumber;
    cout<<"Enter Your Full Name: ";
    cin.ignore();
    getline(cin,s.name);
    cout<<"Enter Your Division: ";
    cin>>s.div;
    cout<<"Enter you Address: ";
    cin.ignore();
    getline(cin,s.address);

    string nameOfFile = s.div + "_" + to_string(s.rollNumber) + ".txt";

    ofstream out;
    out.open(nameOfFile);
    out<<to_string(s.rollNumber) + '\n';
    out<<s.name + '\n';
    out<<s.div + '\n';
    out<<s.address + '\n';
    out.close();
    q.push(nameOfFile);
}

void handleDisplay(Student &s, queue<string> &q,int count){
    cout<<"Enter the Roll Number: ";
    cin>>s.rollNumber;
    cout<<"Enter the Divison: ";
    cin>>s.div;
    string fileName = s.div + "_" + to_string(s.rollNumber) + ".txt";
    cout<<"FileName: "<<fileName<<endl;
    bool flag = 0;
    for(int i=0;i<count;i++){
        string temp = q.front();
        cout<<temp<<endl;
        q.pop();
        if(temp == fileName){
            cout<<"Record Found!!"<<endl;
            ifstream in;
            in.open(fileName);
            in>>s.rollNumber;
            in.ignore();
            getline(in,s.name);
            in>>s.div;
            in.ignore();
            getline(in,s.address);
            in.close();
            cout<<"Name of the Students is: "<<s.name<<endl;
            cout<<"Address of the student is: "<<s.address<<endl;
            // cout<<"roll number is :" << s.rollNumber<<endl;
            // cout<<"div: "<<s.div<<endl;
            flag=1;
        }
        q.push(temp);
    }
    if(!flag)
        cout<<"Record not found!"<<endl;
}

void handleDelete(Student &s, queue<string> &q,int count){
    cout<<"Enter the Roll Number: ";
    cin>>s.rollNumber;
    cout<<"Enter the Divison: ";
    cin>>s.div;
    string fileName = s.div + "_" + to_string(s.rollNumber) + ".txt";
    bool flag1 = 0;
    bool flag2 = 0;
    for(int i=0;i<count;i++){
        string temp = q.front();
        cout<<temp<<endl;
        q.pop();
        if(temp == fileName){
            cout<<"Record Found!!"<<endl;
            ifstream in;
            in.open(fileName);
            in>>s.rollNumber;
            in.ignore();
            getline(in,s.name);
            in>>s.div;
            in.ignore();
            getline(in,s.address);
            in.close();
            cout<<"-----------------The Student---------------"<<endl;
            cout<<"Name of the Students is: "<<s.name<<endl;
            cout<<"Address of the student is: "<<s.address<<endl;
            cout<<"roll number is :" << s.rollNumber<<endl;
            cout<<"div: "<<s.div<<endl;
            // int n  = fileName.length();
            // char *file = new char[n+1];
            // strcpy(file,fileName.c_str());
            remove(fileName.c_str());
            cout<<"-------Record Removed---------------"<<endl;
            flag1=1;
            flag2=1;

        }
        if(!flag2){
            q.push(temp);
            flag2 = 0;
        }
    }
    if(!flag1)
        cout<<"Record not found!"<<endl;
}



int main(){

    Student s;
    queue<string> q;
    int ch;
    int countOfStudents = 0;
    int count;
    start:
    cout<<"Enter Your Choice: ";
    cin>>ch;
    switch (ch)
    {
    case 1:
        countOfStudents++;
        handleCreate(s,q);
        goto start;
        break;
    case 2:
        handleDisplay(s,q,countOfStudents);
        goto start;
    case 3:
        handleDelete(s,q,countOfStudents);
        countOfStudents--;
        goto start;
    default:
        break;
    }




    return 0;
}
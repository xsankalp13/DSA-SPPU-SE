#include<iostream>
#include<fstream>
#include<string>
#include<queue>

using namespace std;


class Student{
    public:
        string rollNumber;
        string name;
        string address;
        string div;

        Student(){
            rollNumber="";
            name="";
            address="";
            div="";
        }
};


void addStudent(Student &s, queue<string> &q){
    cout<<"----------------Enter the Student Information---------------"<<endl;
    cout<<"Enter the name of the student: ";
    cin.ignore();
    getline(cin,s.name);
    cout<<"Enter the Roll Number: ";
    cin>>s.rollNumber;
    cout<<"Enter the Division: ";
    cin>>s.div;
    cout<<"Enter the Address: ";
    cin.ignore();
    getline(cin,s.address);

    string fileName = s.div + "_" + s.rollNumber + ".txt";
    ofstream out;
    out.open(fileName);
    out<<s.name + "\n";
    out<<s.address + '\n';
    out<<s.rollNumber + '\n';
    out<<s.div + '\n';
    out.close();
    q.push(fileName);
    cout<<"-------------Record Added SuccessFully-------------------------"<<endl;
}


void display(Student &s , queue<string> &q, int count){
    cout<<"--------------------Student Information DashBoard--------------------"<<endl;
    cout<<"Enter the Roll Number of the Student: ";
    cin>>s.rollNumber;
    cout<<"Enter the Division of the Student: ";
    cin>>s.div;
    string fileName = s.div + "_" + s.rollNumber + ".txt";
    bool flag1 = 0;
    for(int i=0; i<count;i++){
        string front = q.front();
        q.pop();
        cout<<front<<endl;
        if(fileName == front){
            cout<<"Record Found!!"<<endl;
            flag1 = 1;
            ifstream in;
            in.open(fileName);
            in.ignore();
            getline(in,s.name);
            in.ignore();
            getline(in,s.address);
            in.close();
            cout<<endl;
            cout<<"The name of Student is: "<<s.name<<endl;
            cout<<"The address of the Student is: "<<s.address<<endl;
        }
        q.push(front);
    }
    if(!flag1){
        cout<<"Record Not Found!!";
    }
}


void deleteStudent(Student &s, queue<string> &q, int count){
    cout<<"--------------------Student Deletion DashBoard--------------------"<<endl;
    cout<<"Enter the Roll Number of the Student: ";
    cin>>s.rollNumber;
    cout<<"Enter the Division of the Student: ";
    cin>>s.div;
    string fileName = s.div + "_" + s.rollNumber + ".txt";
    bool flag1 = 0;
    bool flag2 = 0;
    for(int i=0; i<count;i++){
        string front = q.front();
        q.pop();
        cout<<front<<endl;
        if(fileName == front){
            cout<<"Record Found!!"<<endl;
            flag1 = 1;
            flag2 = 1;
            ifstream in;
            in.open(fileName);
            in.ignore();
            getline(in,s.name);
            in.ignore();
            getline(in,s.address);
            in.close();
            cout<<endl;
            cout<<"The Roll Number of Student is: "<<s.rollNumber<<endl;
            cout<<"The name of Student is: "<<s.name<<endl;
            cout<<"The division of the Student is: "<<s.div<<endl;
            cout<<"The address of the Student is: "<<s.address<<endl;
            
            remove(fileName.c_str());
            cout<<"--------------------------File Deletion Success-----------------------"<<endl;
        }
        if(!flag2){
            q.push(front);
            flag2 = 0;
        }
    }
    if(!flag1){
        cout<<"Record Not Found!!"<<endl;
    }
}



int main(){
    Student s;
    queue<string> q;
    int countOfStudents = 0;
    loop:
    cout<<"Enter Your Choice: ";
    int ch;
    cin>>ch;
    switch (ch)
    {
    case 1:
        countOfStudents++;
        addStudent(s,q);
        goto loop;
        break;
    case 2:
        display(s,q,countOfStudents);
        goto loop;
        break;
    case 3:
        deleteStudent(s,q,countOfStudents);
        countOfStudents--;
        goto loop;
    default:
        break;
    }
    return 0;
}
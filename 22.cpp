//let's make the hands dirty

#include<iostream>
#include<fstream>
#include<string>
using namespace std;



void addStudent(){
    string name;
    int rollNumber;
    string division;
    string address;

    cout<<"Enter the name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter the roll number: ";
    cin>>rollNumber;
    cout<<"Enter the Division: ";
    cin>>division;
    cout<<"Enter the address: ";
    cin.ignore();
    getline(cin,address);

    ofstream out;
    out.open("Student_DataBase.txt",ios::app);
    if(!out){
        cout<<"There is some issue cannot proceede futher"<<endl;
        return;
    }
    out<<to_string(rollNumber) + "\n";
    out<<name + "\n";
    out<<division + "\n";
    out<<address + '\n';
    out.close();
}

void displayStudent(int rollNumber){
    string name;
    string address;
    char division;

    ifstream in;
    in.open("Student_DataBase.txt");
    if(!in){
        cout<<"File does not exist!!";
        return;
    }
    int flag = 0;
    while(!in.eof()){
        string line;
        getline(in,line);
        if(line == to_string(rollNumber)){
            flag =1;
            cout<<"Roll Number: "<< line << endl;
            getline(in,line);
            cout<<"Name: "<<line<<endl;
            getline(in,line);
            cout<<"Division: "<<line<<endl;
            getline(in,line);
            cout<<"Address: "<<line<<endl;
            break;
        }
    }
    if(!flag){
        cout<<"The Student who's roll number is " <<rollNumber << " does not exist in the database!!"<<endl; 
    }




}

int main(){
    cout<<"This program create the Database of the students"<<endl;
    int ch = 0;
    while(ch<4){
        cout<<"Enter the choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            addStudent();
            break;
        case 2:
            int roll;
            cout<<"Enter the roll number of the student: ";
            cin>>roll;
            displayStudent(roll);
            break;
        // case 3:
        //     deleteStudent();
        default:
            break;
        }
    }




}
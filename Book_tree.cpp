// A book consists of chapters, chapters consist of sections and sections consist of
// subsections. Construct a tree and print the nodes. Find the time and space requirements of
// your method.
#include<iostream>
using namespace std;

class Node{
    public:
        string name;
        Node* next;
        Node* down;
        int flag;
};

class Gll{
    string ch;
    int n, i;
    Node *head=NULL, *temp=NULL, *t1=NULL,*t2=NULL;
    public:
        Node *create();
        void insertBook();
        void insertChapter();
        void insertSection();
       // void insertSubSection();
        void displayBook();
};

Node* Gll::create(){

    Node *p = new Node;
    p->next = NULL;
    p->down=NULL;
    p->flag=0;
    cout<<"Enter the Name: ";
    cin>>p->name;
    return p;
}

void Gll::insertBook(){
    if(head == NULL){
        t1 = create();
        head = t1;
    }else{
        cout<<"Book already exists"<<endl;
    }
}

void Gll::insertChapter(){
    if(head == NULL)
        cout<<"Book did not exist please create it first!";
    else{
        cout<<"How many chapters do you want to include: ";
        cin>>n;
        for(i = 0;i<n;i++){
            t1=create();
            if(head->flag == 0){
                head->down=t1;
                head->flag = 1;
            }else{
                temp = head;
                temp = temp->down;
                while(temp->next !=NULL)
                    temp = temp->next;
                temp->next = t1;
            }
                
        }

    }
}

void Gll::insertSection(){
    int chapters = n;
    if(head == NULL)
        cout<<"Book did not exist please create it first!";
    else if(head->down == NULL)
        cout<<"Book exists but the Chapters are not there";
    else{
        temp = head;
        temp=temp->down;
        for(i = 0; i< chapters;i++){
            cout<<"Enter the number of section in "  << temp->name << " : ";
            cin>>n;
            for(int j=0;j<n;j++){
                t1=create();
                Node* temp1 = temp;
                if(temp1->flag == 0){
                    temp1->down = t1;
                    temp1->flag = 1;
                }else{
                    temp1 = temp1->down;
                    while(temp1->next != NULL)
                        temp1= temp1->next;
                    temp1->next = t1;
                }
            } 
            temp = temp->next;
        }
    }
}


void Gll::displayBook(){
    cout<<"Printing the index of the book: "<<endl;
    cout<<head->name<<endl;
    temp = head;
    if(head->flag == 0)
        cout<<endl;
    else{
        temp = temp->down;
        while(temp != NULL){
            Node *newTemp = temp;
            cout<<"\t"<<temp->name<<endl;
            if(temp->flag == 1){
                newTemp = newTemp->down;
                while(newTemp!=NULL){
                    cout<<"\t\t"<<newTemp->name<<endl;
                    newTemp = newTemp->next;
                }
            }
            temp = temp->next;
        }
    }
    cout<<"\n The End"<<endl;
}

int main(){
    Gll g;   int x;
    int t = 10;
       while(t--)
      {    cout<<"\n\n enter your choice";
            cout<<"\n 1.insert book";
            cout<<"\n 2.insert chapter";
            cout<<"\n 3.insert section";
            cout<<"\n 4.display book";
            cout<<"\n 5.exit\t: ";
            cin>>x;
           switch(x)
           {   case 1:          g.insertBook();
                                         break;             
                case 2:          g.insertChapter();
                                         break;      
                case 3:          g.insertSection();
                                         break;
                case 4:          g.displayBook();
                                         break;      
                default:  exit(0);
           }
       }
       return 0;
}
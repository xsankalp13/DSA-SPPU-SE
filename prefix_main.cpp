// Construct an expression tree from the given prefix expression eg. +--a*bc/def and
// traverse it using post order traversal (non recursive) and then delete the entire tree. 
#include<iostream>
#include<string.h>

using namespace std;

struct node{
    char data;
    node* left;
    node * right;
};
class Tree{
    char prefix[20];
    public:
    node* top;
    void expression(char[]);
    void display(node*);
    void non_rec_postorder(node *);
    void del(node *);
};


class stack{
    node * data[30];
    int top;
    public:
        stack(){
            top=-1;
        }
        int empty(){
            if(top==-1)
                return 1;
            return 0;
        }
        void push(node* p){
            data[++top]=p;

        }
        node *pop(){
            return(data[top--]);
        }
};

void Tree::expression(char prefix[]){
    char c;
    stack s;
    node *t1, *t2;
    int len,i;
    len=strlen(prefix);

    for(i = len-1; i>=0;i--){
        top=new node;
        top->left=NULL;
        top->right=NULL;
        if(isalpha(prefix[i])){
            top->data=prefix[i];
            s.push(top);
        }
        else if(prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i]=='/'){
            t2=s.pop();
            t1=s.pop();
            top->data=prefix[i];
            top->left = t2;
            top->right=t1;
            s.push(top);
        }
    }
    top=s.pop();
    
}

void Tree::display(node *root){
    if(root!=NULL){
        display(root->left);
        cout<<root->data;
        display(root->right);
    }
}
void Tree::non_rec_postorder(node* top){
    stack s1, s2;
    node *T= top;
    cout<<endl;
    s1.push(T);
    while(!s1.empty()){
        T=s1.pop();
        s2.push(T);
        if(T->left!=NULL)
            s1.push(T->left);
        if(T->right!=NULL)
            s1.push(T->right);
    }
    cout<<"The Prefix Expression is: ";
    while(!s2.empty()){
        top=s2.pop();
        cout<<top->data;
    }
}



void Tree::del(node* node){
    if(node == NULL) return;
    del(node->left);
    del(node->right);

    cout<<"Deleting node: "<<node->data<<endl;
    free(node);
}


int main(){
    char expr[20];
    Tree t;
    cout<<"Enter the Expression: ";
    cin>>expr;
    cout<<"\n\n\n";
    cout<<"Printing Expression as it is: ";
    cout<<expr<<endl;

    t.expression(expr);
    cout<<"Displaying the tree: ";
    t.display(t.top);
    t.non_rec_postorder(t.top);
    cout<<endl;
    t.del(t.top);
    //t.display(t.top);

}

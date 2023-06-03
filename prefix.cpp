#include<iostream>
#include<stack>
using namespace std;


class Node{
    public:
        char data;
        Node *left;
        Node  *right;
        Node(char data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


Node* convertToTree(string exp,int &index){
    if(index > exp.length())
        return NULL;
    Node *root = new Node(exp[index]);
    cout<<"Im created "<<exp[index]<<endl;

    if(exp[index] == '+' || exp[index] == '-' || exp[index] == '*' || exp[index] == '/'){
        cout<<"Im calling left " << exp[index++] <<endl;
        root->left = convertToTree(exp,index);
        cout<<"Im calling right " << exp[index++] <<endl;
        root->right = convertToTree(exp,index);
    }
    cout<<"Im returing "<<exp[index] <<endl;
    return root;
}


void postOrder(Node *root){
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty()){
        Node *top = s1.top();
        s1.pop();
        s2.push(top);
        if(top->left != NULL)
            s1.push(top->left);
        if(top->right != NULL)
            s1.push(top->right);
    }
    while(!s2.empty()){
        Node* top = s2.top();
        s2.pop();
        cout<<top->data<<" ";
    }
}


void deleteTree(Node *root){
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty()){
        Node *top = s1.top();
        s1.pop();
        s2.push(top);
        if(top->left != NULL)
            s1.push(top->left);
        if(top->right != NULL)
            s1.push(top->right);
    }
    while(!s2.empty()){
        Node* top = s2.top();
        s2.pop();
        cout<<endl;
        cout<<top->data<<" Has been Deleted"<<endl;
        delete top;
    }
}

void preOrder(Node *root){
    if(root->left == NULL || root->right == NULL)
        return;
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}



int main(){
    cout<<"Enter the Expression: ";
    string exp;
    cin>>exp;
    int index = 0;
    Node* root = convertToTree(exp,index);
    postOrder(root);
    cout<<endl;
    preOrder(root);
    deleteTree(root);
    return 0;
}
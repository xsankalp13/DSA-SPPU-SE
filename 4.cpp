
#include<iostream>
using namespace std;
struct node
{
struct node *left;
struct node *right;
int data;
};
struct node* createnode(int value)
{
struct node *nn=new node;
nn->data=value;
nn->left=NULL;
nn->right=NULL;
return nn;
}
struct node* insertnode(struct node* root,int val)
{
if(root==NULL){
return createnode(val);
}
if(val<root->data)
{
root->left=insertnode(root->left,val);
}
else if(val>root->data)
{
root->right=insertnode(root->right,val);
}
return root;
}
void min(struct node*root)
{
struct node*temp=root;
while(temp->left!=NULL)
{
temp=temp->left;
}
cout<<"Minimum data value is :"<<temp->data<<endl;
}
void mirror(struct node*root)
{
if(root==NULL)
{
return;
}
else{
struct node*temp;
temp=root->left;
root->left=root->right;
root->right=temp;
}
mirror(root->left);
mirror(root->right);
}
void inorder(struct node*root)
{
if(root!=NULL){
inorder(root->left);
cout<<root->data<<" | ";
inorder(root->right);
}
}
void search(node* root, int value) {
if (root->data == value) {
cout<<"Search is successful for value :"<<value;
}
else if (value < root->data) {
search(root->left, value);
}
else if(value > root->data){
search(root->right, value);
}
else{
cout<<"Search is not successful for value :"<<value;
}
}
int findLongestPath(struct node* root) {
if (root == NULL) {
return 0;
}
int leftDepth = findLongestPath(root->left);
int rightDepth = findLongestPath(root->right);
return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
int main()
{
int ch,val,dd,rootv;
struct node*root=NULL;
cout<<"Insert root node of the tree :";
cin>>rootv;
root=insertnode(root,rootv);
cout<<"1)Insert nodes into the tree :";
while(true)
{
cout<<"\nEnter the data to insert :(-1 to exit) :";
cin>>val;
if(val==-1){
break;
}
else{
insertnode(root,val);
cout<<val<<" is inserted";
}
}
cout<<"\n2)Find number of nodes in longest path from root\n3)Minimum data value found in the tree\n4)Change a tree so that the roles of the left and right pointers are swapped at every nodcout"<<"Enter your choice : "<<endl;
cin>>ch;
switch(ch){
case 2:
cout<<"Number of Nodes is longest path are :";
cout<<findLongestPath(root);
break;
case 3:
min(root);
break;
case 4:
cout<<"\nInorder tree is :";
inorder(root);
cout<<"\nMirror tree is :";
mirror(root);
inorder(root);
cout<<"\nThe roles of the left and right pointers are swapped at every node(mirror)\n";
break;
case 5:
cout<<"\nEnter the data to search :";
cin>>dd;
search(root,dd);
break;
}
}
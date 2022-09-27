#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;
    node(int d) {
        this-> data= d;
        this-> left =NULL;
        this-> right= NULL;
    }
};
node* buildTree(node* root) {
    cout <<"Enter the data: "<< endl;
    int data;
    cin>>data;
    root= new node(data);
    if (data==-1){
        return NULL;
    }
    cout<<"enter data for left"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data for right"<<data<<endl;
    root->right=buildTree(root->right);
    return root;

}
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        cout << temp-> data << "";
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp ->left) {
                q.push(temp ->left);
            }
            if(temp ->right)
                q.push(temp ->right);
        } 
    }
}
int main(){
    node* root = NULL;
    // creating a Tree
    root = buildTree(root);
    cout<<"Printing the traversal order"<<endl;
    levelOrderTraversal(root);
    return 0;
}

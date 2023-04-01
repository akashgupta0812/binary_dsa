#include<bits/stdc++.h>
using namespace std;
class node{
    public:
int data;
node*left;
node*right;
node(int d)
{
data=d;
this->left=NULL;
this->right=NULL;
}
};

int max_element(node*root)
{
    if(root==NULL)
    {
        cout<<"tree is empty ";
        return 0;
    }
    else{
        node*temp=root;
        int minleft,minright,mine=temp->data;
        if(temp->left!=NULL)
        {
            minleft=max_element(temp->left);
            // maxe=maxe>maxleft?maxe:maxleft;
            mine=mine<minleft?mine:minleft;
        }
        if(temp->right!=NULL)
        {
            minright=max_element(temp->right);
            // maxe=maxe>maxright?maxe:maxright;
            mine=mine<minright?mine:minright;
        }
        return mine;
    }
}
node* Buildtree(node*root)
{
    int d;
    cout<<"enter the data "<<endl;
    cin>>d;
    if(d==-1)
    return NULL;
    root=new node(d);
    cout<<"enter the data left of "<<root->data<<endl;
    root->left=Buildtree(root->left);
    cout<<"enter the data right "<<root->data<<endl;
    root->right=Buildtree(root->right);
    return root;
}
int main()
{
    node*root=NULL;
    root=Buildtree(root);
    cout<<"max elemt is  "<<max_element(root);
}

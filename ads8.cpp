#include<iostream>
using namespace std;
class node
{
 public:
 node *right,*left;
 int data;
 node()
 {
  right=left=NULL;
  data=0;
 }
};
class avl
{
 public:
 node *root;
 avl()
 {
  root=NULL;
 }
 node * insert(node * rt,int val)
 {
  if(rt==NULL)
  {
    node *temp;
    temp=new node();
    temp->data=val;
    rt=temp;
    return rt;
  }
  else
  {
   if(rt->data>val)
     {
       rt->left=insert(rt->left,val);
       if(balance(rt)>1)
         {
           if(balance(rt->left)>0)
              rt=RR(rt);
           else
              rt=LR(rt);
         }
     }
     else
     {
       rt->right=insert(rt->right,val);
       if(balance(rt)<-1)
         {
           if(balance(rt->left)<0)
              rt=LL(rt);
           else
              rt=RL(rt);
         }
     }
    return rt;
  }
 }
 int balance(node *rt)
 {
  int l,r;
  l=height(rt->left);
  r=height(rt->right);
  return l-r;
 }
 int height(node *rt)
 {
  int h1,h2;
  if(rt==NULL)
   return 0;
  if(rt->right==NULL&&rt->left==NULL)
    return 1;
  h1=height(rt->right);
  h2=height(rt->left);
  if(h1>h2)
   return h1+1;
  else
   return h2+1;
 }
 node *RR(node *rt)
 {
   node *temp=rt->left;
   rt->left=temp->right;
   temp->right=rt;
   return temp;
 }
 node *LR(node *rt)
 {
   node *temp1=rt->left;
   node *temp2=temp1->right;
   temp1->right=temp2->left;
   rt->left=temp2->right;
   temp2->left=temp1;
   temp2->right=rt;
   return temp2;
 }
 node *LL(node *rt)
 {
   node *temp=rt->right;
   rt->right=temp->left;
   temp->left=rt;
   return temp;
 }
 node *RL(node *rt)
 {
   node *temp1=rt->right;
   node *temp2=temp1->left;
   temp1->left=temp2->right;
   rt->right=temp2->left;
   temp2->right=temp1;
   temp2->left=rt;
   return temp2;
 }
 void inorder(node *root)
 {
  if(root!=NULL)
   {
   inorder(root->left);
   cout<<" "<<root->data;
   inorder(root->right);
   }
 }
 void postorder(node *root)
 {
   if(root!=NULL)
   {
   postorder(root->left);
   postorder(root->right);
   cout<<" "<<root->data;
   }
 }
};
int main()
{
 avl object;
 for(int i=0;i<5;i++)
 {
  cout<<"enter data";
  int data; 
  cin>>data;
  object.root=object.insert(object.root,data);
 }
 object.inorder(object.root);
 object.postorder(object.root);
}

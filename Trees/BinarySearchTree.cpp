#include <bits/stdc++.h>
using namespace std ;

struct BstNode
{
  int key ;
  BstNode* left ;
  BstNode* right ;
}

class LinkedList
{
  public:
  Node* head ;
  Node* tail ;
};

BstNode* Delete(BstNode* root , int key)
{
  if(root==NULL) return root ;
  else if(key<root->key) root->left=Delete(root->left , key);
  else if(key>root->key) root->right=Delete(root->right,key);
  else
  {
    if(root->left==NULL && root->right==NULL) //No Child
    {
      delete root ;
      root=NULL ;
    }
    else if (root->left==NULL)
    {
      Node* temp=root ;
      root=root->right ;
      delete temp ;
    }
    else 
    {
      BstNode* temp=FindMin(root->right);
      root->key=temp->key ;
      root->right=Delete(root->right,temp->key);
    }
    return root ;
  }
}

bool isleftlesser(BstNode* root ,int key)
{
  if(root==NULL)  return true ;
  if(root->key<=key && isleftlesser(root->left,root->key) && isleftlesser(root->right,root->key))
    return true ;
  return false ;
}

bool isrightgreater(BstNode* root ,int key)
{
  if(root==NULL) return true ;
   if(root->key>key && isrightgreater(root->right,root->key) && isrightgreater(root->right,root->key))
     return true ;
  return false ;
}

bool isitBST(BstNode* root)
{
  if(isleftlesser(root->left,root->key))
  {
     if(isrightgreater(root->right,root->key))
     {
       if(isitBST(root->left) && isitBST(root->right))
        return true ;
     }
  }
  return false ;
}

BstNode* insert(BstNode* root , int key)
{
  if(root==NULL)
  {
    root->key=key ;
    root->left=root->right=NULL ;
  }
  else if(key>root->key)
  {
    root->right=insert(root->right , key);
  }
  else if(key<=root->key)
  {
    root->left=insert(root->left,key);
  }
  return root ;
}

BstNode* search(BstNode* root , int key)
{
  if(root==NULL)
    return NULL ;
  else if(root->key==key) return root ;
  else if(key>root->key) return search(root->right,key);
  else return search(root->left,key);
}

int FindMax(BstNode* root)
{
  BstNode* current=root ;
  while(current->right!=NULL)
  {
    current=current->right ;
  }
  return current->key ;
}

int FindMin(BstNode* root)
{
  BstNode* current=root ;
  while(current->left!=NULL)
  {
    current=current->left ;
  }
  return current->key ;
}

int FindHeight(BstNode* root)
{
  if(root==NULL) return -1 ;
  else return(max(FindHeight(root->left),FindHeight(root->right))+1 ;
}

void LevelOrder(BstNode* root)
{
  queue<BstNode*> q ;
  q.push(root);
  while(!q.empty())
  {
    BstNode* current=q.front(); 
    cout<<current->key<<" " ;
    if(current->left!=NULL) q.push(current->left);
    if(current->right!=NULL) q.push(current->right);
    q.pop();
  }
}

void PreOrder(BstNode* root)
{
  if(root==NULL) return ;
  cout<<root->key<<" " ;
  PreOrder(root->left);
  PreOrder(root->right);
}

void InOrder(BstNode* root)
{
  if(root==NULL) return ;
  Inorder(root->left);
  cout<<root->data<<" " ;
  Inortder(root->right);
}
              
void PostOrder(BstNode* root)
{
  if(root==NULL) return ;
  PostOrder(root->left);
  PostOrder(root->right);
  cout<<root->data<<" " ;
}
              
BstNode* InorderSuccessor(BstNode* root , int key)
{
  BstNode* current=search(root,key);
  if(current==NULL) return NULL ;
  else if(current->right!=NULL)
  {
    BstNode* temp=current->right ;
    return FindMin(current->right);
  }
  else
  {
    BstNode* successor=NULL ;
    BstNode* ancestor=root ;
    while(ancestor!=current)
    {
      if(current->key<ancestor->key)
      {
        successor=ancestor ;
        ancestor=ancestor->left ;
      }
      else
      {
        ancestor=ancestor->right ;
      }
    }
    return successor ;
  }
}

LinkedList Flatten(BstNode* root)
{
  LinkedList l ;
  if(root==NULL)
  {
    l.head=l.tail=NULL ;
    return l ;
  }
  else if(root->right==NULL && root->left==NULL)
  {
    l.head=l.tail=root ;
    return l
  }
  else if(root->left!=NULL && root->right==NULL)
  {
    LinkedList lefll=flatten(root->left);
    leftll.tail=root->right ;
    l.head=leftll.head ;
    l.tail=root ;
    return l ;
  }
  else if(root->right!=NULL && root->left=NULL)
  {
    LinkedList rightll=flatten(root->right);
    root->right=rightll.head ;
    l.head=root ;
    l.tail=rightll.tail ;
    return l ;
  }
  LinkedList leftll=flatten(root->left);
  LinkedList rightll=flatten(root->right);
  l.head=leftll.head ;
  l.tail=rightll.tail ;
  return l;
}
              
int main()
{
  BstNode* root=NULL ;
  /* calling necessary push traverse operations*/ 
  return 0;
}
   

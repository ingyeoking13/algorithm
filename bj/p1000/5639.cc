#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int key;
  struct Node* left,* right,* parent;
}Node;

Node* newNode(int key)
{
  Node* nNode = (Node*)malloc(sizeof(Node));
  nNode->key = key;
  nNode->left = nNode->right = nNode->parent  =0;
  return nNode;
}

void postTraverse(Node* now)
{
  if (now ==0) return;
  postTraverse(now->left);
  postTraverse(now->right);
  printf("%d\n", now->key);
}

Node* min(Node* now)
{
  while(now->left) now = now->left;
  return now;
}

Node* successor(Node* now)
{
  if (now->right) return min(now->right);

  Node* p = now->parent;
  while( p && p->right == now) 
  {
    now=p;
    p=p->parent;
  }
  return p;
}

int main()
{
  int tmp;
  Node* treeRoot=0;
  Node* cur=0;
  while(~scanf("%d",&tmp))
  {
    if ( treeRoot == 0)  {
      treeRoot = newNode(tmp); 
      cur = treeRoot;
      continue;
    }

    if ( tmp < cur->key )
    {

      cur->left = newNode(tmp);
      cur->left->parent = cur;

      cur = cur->left;
    }
    else 
    {
      Node* success = successor(cur);

      while(success && success->key < tmp)
      {
        cur = success;
        success = successor(success);
      }

      cur->right = newNode(tmp); 
      cur->right->parent = cur;
      cur = cur->right;

    }
  }
  postTraverse(treeRoot);

}

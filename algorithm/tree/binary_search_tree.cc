#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int key;
  struct Node* left,* right,* parent;
}Node;

void traverse(Node* now)
{
  if (now==0) return;
  traverse(now->left);
  printf("%d\n", now->key);
  traverse(now->right);
};

Node* search(Node* now, Node* find)
{
  if (now == 0) return 0;
  if (now->key == find->key) return now;

  if (find->key > now->key) return search(now->right, find);
  else return search(now->left, find);
}

Node* searchWithVal(Node* now, int key)
{
  if (now == 0) return 0;
  if (now->key == key) return now;

  if (now->key > key) return searchWithVal(now->right, key);
  else return searchWithVal(now->left, key);
}

Node* search_iter(Node* now, Node* find)
{
  Node* ret=0;
  while(now)
  {
    if ( now->key == find->key) 
    {
      ret = now;
    }
    if (find->key > now->key) now=now->right;
    else now=now->left;
  }
  return ret;
}
 
Node* newNode(int key)
{
  Node* node =  (Node*)malloc(sizeof(Node));
  node->left = node->right = node->parent = 0;
  node->key = key;
  return node;
}

Node* min(Node* now)
{
  while(now->left) now=now->left;
  return now;
}

Node* successor(Node* now)
{
  if (now->right) return min(now->right);
  Node* y = now->parent;
  while(y != 0 &&  y->right == now)
  {
    now= y;
    y= y->parent;
  }
  return y;
}

void insert(Node** root, Node* add)
{
  Node* bef = 0;
  Node* now = *root;

  while(now)
  {
    bef = now;
    if ( now->key > add->key) now = now->left;
    else now= now->right;
  }
  add->parent = bef;
  if (bef == 0 ) *root= add;
  else if ( bef->key > add->key ) bef->left = add;
  else bef->right = add;
}

void transParent(Node** root, Node* u, Node* v)
{  // Trans parent, parent of u now get v as a child. and u are going to move somewhere.
   // This function works good when we delete some node in tree T.  
  if ( u->parent == 0) *root = v;
  else if ( u == u->parent->left) u->parent->left = v;
  else  u->parent->right = v;

  if ( v != 0 ) v->parent = u->parent; 
}

void delF(Node** root, Node* del)
{
  if (del->left == 0) transParent(root, del, del->right);
  else if ( del->right == 0) transParent(root, del, del->left);
  else 
  {
    Node* y =  min(del->right); // remember min function works with complexity of O(h). 
    if ( y->parent != del) 
    {  // if parent of y is not del one, then depth between y and del is more than two.
       /* example.
            del
               --- 
                   x
                  - - 
                y     z 
                 -S
       */
      // Then y are going to position of del. and subtree S will be at position of y.
      transParent(root, y, y->right);
      y->right = del->right;
      y->right->parent = y;
    }
    transParent(root, del, y);
    y->left = del->left;
    y->left->parent = y;
  }
  free(del);
}

int main()
{
  Node* treeRoot=0;
  insert(&treeRoot, newNode(5) );
  insert(&treeRoot, newNode(10) );
  insert(&treeRoot, newNode(20) );
  insert(&treeRoot, newNode(30) );
  printf("===== traverse START =====\n");
  traverse(treeRoot);
  printf("===== traverse END =====\n");
  delF(&treeRoot, searchWithVal(treeRoot,5) );
  printf("===== traverse START =====\n");
  traverse(treeRoot);
  printf("===== traverse END =====\n");
}

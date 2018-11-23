#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
struct Node
{
  Node* left; Node* right;
  int num, height;
  char name[23];

  Node(int n, char* str)
  {
    left = right = 0;
    num = n;
    height = 0;
    strcpy(name, str);
  };
};

struct Tree
{
  Node* root;
  Tree() { root = 0; }
  Node* insert(Node* now, Node* in)
  {
    if ( now == 0) return in;

    if ( strcmp ( now->name, in->name ) > 0)
    {
      now->left = insert(now->left, in);
    }
    else now->right = insert(now->right, in);

    int lh=-1, rh=-1;
    if (now->left)  lh = now->left->height;
    if (now->right) rh = now->right->height;
    now->height = 1 + max( lh, rh );

    int bal = lh - rh;
    if (bal > 1 &&  strcmp(now->left->name, in->name) > 0)
    {
      now = rightRotate(now);
    }
    else if (bal > 1 &&  strcmp(now->left->name, in->name) < 0)
    {
      now->left = leftRotate(now->left);
      now= rightRotate(now);
    }
    else if (bal < -1 &&  strcmp(now->right->name, in->name) < 0)
    {
      now = leftRotate(now);
    }
    else if (bal < -1 &&  strcmp(now->right->name, in->name) > 0)
    {
      now->right = rightRotate(now->right);
      now = leftRotate(now);
    }

    return now;
  }

  Node* rightRotate(Node* now)
  {
    Node* ret= now->left;

    now->left = ret->right;
    ret->right = now;

    int lh=-1, rh=-1;
    if (now->left)  lh = now->left->height;
    if (now->right) rh = now->right->height;
    now->height =  max(lh, rh) +1;

    lh=-1, rh=-1;
    if (ret->left)  lh = ret->left->height;
    if (ret->right) rh = ret->right->height;
    ret->height =  max(lh, rh) +1;

    return ret;
  }

  Node* leftRotate(Node* now)
  {
    Node* ret= now->right;

    now->right = ret->left;
    ret->left = now;

    int lh=-1, rh=-1;
    if (now->left)  lh = now->left->height;
    if (now->right) rh = now->right->height;
    now->height =  max(lh, rh) +1;

    lh=-1, rh=-1;
    if (ret->left)  lh = ret->left->height;
    if (ret->right) rh = ret->right->height;
    ret->height =  max(lh, rh) +1;

    return ret;
  }

  int Search(char* str)
  {
    Node* now = root;
    while(now)
    {
      int val = strcmp ( now->name, str );
      if (val ==0) return now->num;
      else if ( val>0 ) now = now->left;
      else now = now->right;
    }
    return -1;
  }
};

int main()
{
  int n, m;
  char a[(int)1e5+1][23];
  scanf("%d%d", &n,&m);

  Tree* tree = new Tree();
   
  for (int i=1; i<=n; i++)
  {
    scanf("%s", a[i]);
    Node* newNode = new Node(i, a[i]);
    tree->root = tree->insert(tree->root, newNode);
  }

  while(m--)
  {
    char in[23];
    scanf("%s", in);
    if ('0'<= in[0] && in[0] <= '9')
    {
      int num=0;
      for (int i=0; in[i]; i++)
      {
        num *= 10;
        num += (in[i]-'0');
      }
      printf("%s\n", a[num]);
    }
    else printf("%d\n", tree->Search(in));
  }

}

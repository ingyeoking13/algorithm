#include <stdio.h>

class AVLTree
{
  private:
    AVLNode* root;
  public:
    AVLTree() 
    {
      root = 0;
    }
    ~AVLTree();
    bool Insert(int key)
    {
      if (root == 0) 
      {
        root=new AVLNode(key);
        return true;
      }



    }
    bool PrintAll();
    bool Search(int key);
    bool Rank();
};

class AVLNode
{
  private:
    AVLNode* right,* left;
    int key;
    int bf;
  public:
    AVLNode(int key) : key(key)
    {
      right=left=0;
      bf=0;
    }

    void setRight(AVLNode* p) { right = p;}
    void setLeft(AVLNode* p) { left = p;}

    AVLNode* getRight() { return right; }
    AVLNode* getLeft() {return left;}
    int getKey() {return key;}
    int getBf() { return bf; }
}

int main()
{
  AVLTree tree = new AVLTree();
  tree.Insert(10);
  tree.Insert(12);
  tree.Insert(13);
  tree.Insert(14);
}

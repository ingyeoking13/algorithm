/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

  void dfs(int nowi, int nowj)
  {



  }

  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int i=0, j=post.size()-1;
    dfs(i, j);
  }
};

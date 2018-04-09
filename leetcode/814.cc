/*struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
 
int dfs(TreeNode* now){
	int chk=0;
	if (now->left) {
		if(dfs(now->left)) chk=1;
		else{
			if ( now->left->val ==0) now->left=0;
		}
	}
	if (now->right){
	 	if(dfs(now->right)) chk=1;
		else{
			if ( dfs->left->val ==0) now->right=0;
		}
	}

	if (now->val ==1) chk=1;

	return chk; 
};

class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
		dfs(root);
		return root;
  }
};

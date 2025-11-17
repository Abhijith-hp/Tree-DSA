class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]] = i;
        TreeNode* root = buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>&inorder,int inorderStart,int inorderEnd,vector<int>&postorder,int postorderStart,int postorderEnd,map<int,int>&inMap){
        if(inorderStart>inorderEnd || postorderStart > postorderEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postorderEnd]);
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inorderStart;

        root->left = buildTree(inorder,inorderStart,inRoot-1,postorder,postorderStart,postorderStart+numLeft-1,inMap);
        root->right = buildTree(inorder,inRoot+1,inorderEnd,postorder,postorderStart+numLeft,postorderEnd-1,inMap);
        return root;
    }
};
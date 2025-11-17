class Solution {
public:
    TreeNode* buildTree(vector<int>&preorder,int preorderStart,int preorderEnd,int inorderStart,int inorderEnd,map<int,int>&inMap){
        if(preorderStart > preorderEnd || inorderStart > inorderEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preorderStart]);
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inorderStart;
        root->left = buildTree(preorder,preorderStart+1,preorderStart+numLeft,inorderStart,inRoot-1,inMap);
        root->right = buildTree(preorder,preorderStart+numLeft+1,preorderEnd,inRoot+1,inorderEnd,inMap);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int>inMap;
        for(int i=0;i<inorder.size();i++)
               inMap[inorder[i]] = i;
        
        TreeNode* root  = buildTree(preorder,0,preorder.size()-1,0,inorder.size()-1,inMap);
        return root;
    }
};
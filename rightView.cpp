class Solution {
public:
    void traverse(TreeNode* node,int level,vector<int>&ds){
        
        if(node==NULL)
            return;
        if(level==ds.size())
            ds.push_back(node->val);
        traverse(node->right,level+1,ds);
        traverse(node->left,level+1,ds);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ds;
        traverse(root,0,ds);
        return ds;
    }
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        vector<vector<int>> result;

        if(root==NULL)
          return result;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();
                int index = leftToRight ? i : size - i - 1;
                row[index] = currentNode->val;

                if(currentNode->left)
                    nodesQueue.push(currentNode->left);
                if(currentNode->right)
                    nodesQueue.push(currentNode->right);
            }
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};
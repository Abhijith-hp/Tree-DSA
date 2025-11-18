class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s;
        queue<TreeNode*> tempQueues;
        tempQueues.push(root);
        while(!tempQueues.empty()){
            TreeNode* node = tempQueues.front();
            tempQueues.pop();
            if(node==NULL) s.append("#,");
            else{
               s.append(to_string(node->val )+ ",");
               tempQueues.push(node->left);
               tempQueues.push(node->right); 
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        queue<TreeNode*> tempQueues;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        tempQueues.push(root);
        while(!tempQueues.empty()){
            TreeNode* node = tempQueues.front();
            tempQueues.pop();
            getline(s,str,',');
            if(str=="#") node->left = NULL;
            else{
                node -> left = new TreeNode(stoi(str));
                tempQueues.push(node->left);
            }

            getline(s,str,',');
             if(str=="#") node->right = NULL;
            else{
                node -> right = new TreeNode(stoi(str));
                tempQueues.push(node->right);
            }
        }
    return root;
    }
};
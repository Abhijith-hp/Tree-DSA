class Solution {
  public:
    vector<int> bottomView(Node *root) {
       vector<int>ans;
       if(root==NULL) return ans;
       map<int,int>mpp;
       queue<pair<int,Node*>> tempNodes;
       tempNodes.push({0,root});
       
       while(!tempNodes.empty()){
           Node* node = tempNodes.front().second;
           int level = tempNodes.front().first;
           tempNodes.pop();
           mpp[level] = node->data;
           if(node->left) tempNodes.push({level-1,node->left});
           if(node->right) tempNodes.push({level+1,node->right});
       }
       
       for(auto values: mpp)
           ans.push_back(values.second);
       
    
       return ans;
       
    }
};
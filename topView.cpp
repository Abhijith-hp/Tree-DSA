class Solution {
  public:
    vector<int> topView(Node *root) {
       vector<int>ans;
       queue<pair<Node*,int>> tempNodes;
       map<int,int>mpp;
       tempNodes.push({root,0});
       while(!tempNodes.empty()){
           Node* node = tempNodes.front().first;
           int level = tempNodes.front().second;
           tempNodes.pop();
           if(node->left) tempNodes.push({node->left,level-1});
           if(node ->right) tempNodes.push({node->right,level+1});
           if(mpp.find(level)==mpp.end()) mpp[level] = node->data;
           
       }
       for(auto element:mpp){
           ans.push_back(element.second);
       }
    return ans;
    }
};
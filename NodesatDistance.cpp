class Solution {

  public:
   void markParent(Node* root,unordered_map<Node*,Node*> &parents){
            queue<Node*> tempQueues;
            tempQueues.push(root);
            while(!tempQueues.empty()){
                int size = tempQueues.size();
                for(int i=0;i<size;i++){
                Node* node = tempQueues.front();
                tempQueues.pop();
                if(node->left){
                    parents[node->left] = node;
                    tempQueues.push(node->left);
                }
                if(node->right){
                    parents[node->right] = node;
                    tempQueues.push(node->right);
                }
               
                }
            }
    }
    Node* gettargetNode(Node* root,int target){
       if(root==NULL) return root;
       if(root->data == target) return root;
       Node* left = gettargetNode(root->left,target);
       Node* right = gettargetNode(root->right,target);
       if(left!=NULL) return left;
       return right;
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        vector<int>ans;
        if(root==NULL) return ans;
        unordered_map<Node*,Node*> parents;
        unordered_map<Node*,bool> visited;
        markParent(root,parents);
        queue<Node*> tempQueues;
        Node* targetNode = gettargetNode(root,target);
        tempQueues.push(targetNode);
        int currentLevel = 0;
        while(!tempQueues.empty()){
            int size = tempQueues.size();
            if(currentLevel++ == k) break;
            for(int i=0;i<size;i++){
              Node* node = tempQueues.front();
              tempQueues.pop();
              visited[node]=true;
              if(node->left && !visited[node->left]){
                tempQueues.push(node->left);
                visited[node->left] = true;
              }
              if(node->right && !visited[node->right]){
                tempQueues.push(node->right);
                visited[node->right] = true;
              }
              if(parents[node] && !visited[parents[node]]){
                tempQueues.push(parents[node]);
                visited[parents[node]]=true;
              }
            }
        }  
        while(!tempQueues.empty()){
            ans.push_back(tempQueues.front()->data);
            tempQueues.pop();
        } 
    std::sort(ans.begin(),ans.end());
    return ans;
    }
    
};
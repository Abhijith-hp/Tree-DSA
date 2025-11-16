class Solution {
  public:
  
     Node* markParents(Node* root,unordered_map<Node* ,Node*>&parents,int target){
        queue<Node*> tempQueues;
        tempQueues.push(root);
        Node* targetNode = NULL;
        while(!tempQueues.empty()){
            int size = tempQueues.size();
            for(int i=0;i<size;i++){
                Node* node = tempQueues.front();
                tempQueues.pop();
                if(node->data==target) targetNode = node;
                if(node->left){
                    tempQueues.push(node->left);
                    parents[node->left] = node;
                }
                if(node->right){
                    tempQueues.push(node->right);
                    parents[node->right] = node;
                }
            }
        }
        return targetNode;
    }
    int minTime(Node* root, int target) {
        unordered_map<Node* ,Node*> parents;
        unordered_map<Node*,bool> visited;
        Node* targetNode = markParents(root,parents,target);
        queue<Node*> tempQueues;
        int time = 0;
        tempQueues.push(targetNode);
        while(!tempQueues.empty()){
            int size = tempQueues.size();
            int flag = 0;
            for(int i=0;i<size;i++){
                Node* node = tempQueues.front();
                tempQueues.pop();
                visited[node] = true;
                if(node->left && !visited[node->left]){
                    flag = 1;
                    visited[node->left] = true;
                    tempQueues.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    flag =1;
                    visited[node->right] = true;
                    tempQueues.push(node->right);
                }
                if(parents[node] && !visited[parents[node]]){
                    flag =1;
                    visited[parents[node]] = true;
                    tempQueues.push(parents[node]);
                }
            }
            if(flag) time++;
        }
        return time;
    }
};
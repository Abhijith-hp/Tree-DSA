class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        // code here
         int answer = -1;
        int count = 0;
        if(root==NULL) return -1;
        Node* current = root;
        while(current!=NULL){
          if(current->left==NULL){
              count++;
              if(count==k) answer =  current->data;
              current = current->right;
          }else{
            Node* prev = current->left;
            while(prev->right && prev->right!=current){
                   prev = prev->right;
            }
             if(prev->right==NULL){
                    prev->right = current;
                    current = current->left;
                }
             else{
                prev->right = NULL;
                count++;
                if(count==k) answer = current->data;
                current = current->right;
             }
          }
        }
    return answer;
    }
};
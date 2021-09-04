class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    { if(!root) return;
      queue<Node*>q;
      q.push(root);
      
      while(!q.empty()){
          int size = q.size();
          Node* prev = NULL;
          while(size--){
            Node* curr = q.front();
            q.pop();
            curr->nextRight = prev;
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
            prev = curr;
          }
 
      }
       
    }    
      
};
//time and space :O(N)
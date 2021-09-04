//time : O(N) and space : O(N)
class Solution{
  public:
     map<int,int>mp;
     void findSum(Node* root){
         queue<pair<Node*,int>>q;
         q.push({root,0});
         while(!q.empty()){
             int size = q.size();
             while(size--){
                 Node* node = q.front().first;
                 int h = q.front().second;
                 q.pop();
                 mp[h]+=(node->data);
                 if(node->left) q.push({node->left,h-1});
                 if(node->right) q.push({node->right,h+1});
         }
         
     }
         
     }
    vector <int> verticalSum(Node *root) {
        vector<int>res;
    
        findSum(root);
        
        for(auto &it:mp){
           res.push_back(it.second);
        }
        return res;
    }
};



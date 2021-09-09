vector<int> findSpiral(Node *root)
{

    vector<int>res;
    if(!root) return res;
    queue<Node*>q;
    q.push(root);
    int level = 1;
    while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            while(size--){
                auto curr = q.front();
                q.pop();
                temp.push_back(curr->data);
                 if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            if(level%2){
                reverse(temp.begin(),temp.end());
                for(int i=0;i<temp.size();++i){
                    res.push_back(temp[i]);
                }
            }
            else{
                for(int i=0;i<temp.size();++i){
                    res.push_back(temp[i]);
                }
            }
            level++;
    }
    return res;
}

//O(N) and O(N)
//using two stack
vector<int> findSpiral(Node *root)
{
    
    vector<int>res;
    if(!root) return res;
    stack<Node*>s1 //right to left traversal
    stack<Node*>s2 //left to right
    s1.push(root)
  
    while(!s1.empty() || !s2.empty()){
         while(!s1.empty()){
             auto curr = s1.top();
             s1.pop();
             res.push_back(curr->data);
             if(curr->right){
                 s2.push(curr->right);
             }
             if(curr->left){
                 s2.push(curr->left);
             }
         }
         
          while(!s2.empty()){
             auto curr = s2.top();
             s2.pop();
             res.push_back(curr->data);
             if(curr->left){
                 s1.push(curr->left);
             }
             if(curr->right){
                 s2.push(curr->right);
             }
         }  
            
    }
    return res;
}

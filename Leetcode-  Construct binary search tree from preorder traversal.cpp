class Solution {
public:
    TreeNode* buildTree(TreeNode* &root ,int x){
        if(root==NULL){
            return root = new TreeNode(x);
        }
        if(x<root->val){
            root->left = buildTree(root->left ,x);
        }
        else{
            root->right = buildTree(root->right ,x);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root = NULL;
        for(auto x: preorder){
            buildTree(root,x);
        }
        return root;
    }
};
//time O(N^2) and space : O(N)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder ,int &pos, int min,int max){
        if(pos>=preorder.size()) return NULL;
        int curr = preorder[pos];
        if(curr>max || curr<min) return NULL;
         ++pos;
        TreeNode * root = new TreeNode(curr);
        root->left = buildTree(preorder,pos,min,curr);
        root->right = buildTree(preorder,pos,curr,max);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pos = 0;
        return buildTree(preorder,pos,INT_MIN,INT_MAX);
        
    }
};
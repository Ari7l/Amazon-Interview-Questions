void modifyBSTUtil(Node *root, int *sum){
    //used reverse in order
    if(!root) return;
    modifyBSTUtil(root->right ,sum);
    *sum = *sum + root->data;
    root->data = *sum;
    modifyBSTUtil(root->left,sum);
}

//we are passing sum by reference so that is value keeps updating
Node* modify(Node *root)
{
    int sum = 0;
    modifyBSTUtil(root, &sum);
    return root;
    // Your code here
}
//time O(N) O(1)
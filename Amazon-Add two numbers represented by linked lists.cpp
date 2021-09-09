//itrative solution 
//O(N+M) and O(max(N,M))
class Solution
{
    public:
    Node* reverse(Node * node){
        Node* curr = node;
        Node* nxt;
        Node* prev =NULL;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       Node* curr =NULL;
       Node* res =NULL;
       first = reverse(first);
       second = reverse(second);
       int sum = 0;
       int c = 0;
       while(first!=NULL || second!=NULL){
           sum = (first?first->data:0 )+ (second?second->data:0) +c;
           c= (sum>=10)?sum/10:0;
           Node * temp = new Node(sum%10);
           if(!res){
               res = temp;
           }
           else{
               curr->next = temp;
           }
           curr = temp;
           if(first) first = first->next;
           if(second)second = second->next;
       }
       if(c>0){
           Node *temp = new Node(c);
            curr->next = temp;
            curr = temp;
       }
       res = reverse(res);
       return res;
        
    }
};
//recursivec soln

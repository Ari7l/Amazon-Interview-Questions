class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	   vector<int>res;
	   int n = a.size();
	   int m = b.size();
	   int carry =0;
	   int i=n-1, j=m-1;
	   int sum;
	   while(i>=0 and j>=0){
	       sum = a[i]+b[j] + carry;
	       res.push_back(sum%10);
	       carry = sum/10;
	        i--;j--;
	        }
	   
	   while(i>=0){
	       int s = a[i]+carry;
	        res.push_back(s%10);
	        carry = s/10;
	        i--;
	   }
	   while(j>=0){
	       int s = b[j]+carry;
	        res.push_back(s%10);
	        carry = s/10;
	        j--;
	   } 
	   if(carry>0) res.push_back(carry);
	   reverse(res.begin(),res.end());
	   return res;
	    
	}
 //Time Complexity: O(n + m)

//Auxiliary Space: O(max(n, m))
};

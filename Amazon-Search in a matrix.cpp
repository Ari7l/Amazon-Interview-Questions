class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	      if(X<mat[0][0] || X>mat[N-1][M-1]) return 0;
	      int i =0 , j = M-1;
	      int flag = 0;
	      //we will be starting from top - right most element
	     while(i<N and j>=0){
	         //if X greater than curr number then we know all element 
	         //in curr row will also be less than X hence skip this row
	          if(mat[i][j]<X){
	              i++;
	          }
	          //if X les than curr number then we know all element 
	         //in curr col will also be greater than X hence skip this col
	          else if(mat[i][j]>X){
	              j--;
	          }
	          else{
	              flag =1;
	              break;
	          }
	      }
	      return flag;
	      
	}
};
//O(N+M) and O(1)
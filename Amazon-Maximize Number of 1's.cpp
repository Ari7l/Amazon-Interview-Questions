 int findZeroes(int arr[], int n, int m) {
            int i = 0, j;
        for (j = 0; j < n; ++j) {
            if (arr[j] == 0) m--;
            if (m < 0 && arr[i++] == 0) m++;
        }
        return j - i;
    }
// j will keep incrementing to right, if we encounter a 0 we decrement 'm' if m==0 it means it is a feasiable solutions
//when m<0 then if arr[i]==0 we increment the left pointer 'i' till we make m>=0 again so that we can get  a valid soln
//in the end we are returning j-i as we know that j-i dist will remain same after it reaches the max width
///why?Well as we keep iterate j we will find out that j and i keep adding 1 in every iteration, which makes the distance between j and i the same(and is the currently best).
//The distance between j and i would change again if there is a longer subarray exist.  
//alternate
    //
    int findZeroes(int arr[], int n, int m) {
            int i = -1, j;
            int cntZ = 0;
            int ans =0 ;
        for (j = 0; j < n; ++j) {
            if (arr[j] == 0)cntZ++;
            while(cntZ>m){
                 i++;
                if(arr[i]==0){
                    cntZ--;
                }
               
            }
            ans = max(ans,j-i);
        }
        return ans;
    }  
};
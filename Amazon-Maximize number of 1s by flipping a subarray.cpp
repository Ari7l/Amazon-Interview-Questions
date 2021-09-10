//brute force approach 
//O(N^2)

class Solution{
    public:
    //for a subarray to have max count of 1, it must have maximum no. of 0's
    //and minimum number of 1's  i.e. cntZ - cntO must be maximum
    //in final ans we need the original number of 1's + diff
    //original no. of 1's the 1's that are not flipped so they will be counted
    //the 1's which are part of subarray will be flipped and automaticallu reduced from
    //the original count due to diff.
    int maxOnes(int a[], int n) 
    {
        int diff = 0;
         int original_cntO = 0;
        for(int i=0;i<n;++i){
            if(a[i]==1) original_cntO++;
            int cntZ = 0 ,cntO = 0;
            for(int j=i;j<n;++j){
               a[j]==1?cntO++:cntZ++;
               diff=max(diff , cntZ - cntO);
        }
    }
        
    return original_cntO + diff;    
    }


//O(N) approach
 //this is a variation of kadane's algo basically we will calulate largest subarray 
    //sum...here we want max no. of 1's after flipping the subarray ..it is same to same t
    // we want max subarray sum bcoz if there are more 1's then sum will be max
    //so if we encounter a 0 will add it as 1 and if encounter a 1 we will subtract it 
    //as -1 so that we can get subarray with max zeroes we can flip to get max 1's
    int maxOnes(int a[], int n) 
    {
        int maxH = 0;
         int max_so_far= 0;
          int  original_cntO = 0;
        for(int i=0;i<n;++i){
            if(a[i]==1) original_cntO++;
            if(a[i]==1) maxH-=1;
            else maxH+=1;
            if(maxH<0) maxH = 0;
            max_so_far = max(max_so_far ,maxH);
        }
         return original_cntO + max_so_far;    
    }
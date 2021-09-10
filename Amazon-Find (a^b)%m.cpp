class Solution {
  public:
   long long MOD(string a , long long m){
         long long num = 0;
         for(long long i=0;i<a.size();++i){
              num = ((num*10) + (a[i] - '0') ); //converts string to int 
              num  = num%m; //we are taking mod every time to ensure that it wont 
              //overflow
         }
         return num;
   }
   long long power(long long ans ,long long b, long long m){
       long long temp = 1;
       ans = ans%m;
       while(b>0){
           if(b&1){
               temp = (ans * temp)%m;
           }
            b=b/2;
            ans = (ans*ans)%m;
            
       }
       return temp;
   }
   //since ‘a’ is very large so read ‘a’ as string.
    long long powerMod(string a, long long b, long long m) {
        long long ans = MOD(a,m);
        if(b==0) return ans;
        long long res = power(ans,b,m);
        return res;
    }
};
//Expected Time Complexity: O(Number of digits in a)
//Expected Space: O(1)
//O(N) and O(N)
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.

    long long steps( int n ,vector<long long>&ways){
        if(n<=0){
           return 1; 
        }
        if(ways[n]!=-1) return ways[n];
        long long  one = 0;
        long  long two = 0;
        if(n>=1){
            one = steps(n-1, ways);
        }
        if(n>=2){
            two = steps(n-2, ways);
        }
        ways[n] = one+two;
        return ways[n];
    }
    int countWays(int n)
    {   int mod = 1000000007;
        vector<long long>ways(n+1 ,-1);
        steps(n,ways);
        return ways[n]%mod;
        
    }
};
// 2nd Approach
//O(N) and O(1)
//to reach
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.

    
    int countWays(int n)
    {    int mod = 1000000007;   
        if(n<=1) return 1;
        long long one =1;
        long long two = 1;
        long long ways = 0;
        for(int i=2;i<=n;++i){
            ways = (one + two)%mod;
            one = two ;
            two = ways;
        }
        return two;
    }
};

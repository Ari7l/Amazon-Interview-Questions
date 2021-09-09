//(n&~(n-1)) always return the binary number containing rightmost set bit as 1.

//if N = 12 (1100) then it will return 4 (100)
//Here log2 will return you, number of times we can express that number in power of two.
//For all binary number containing only rightmost set bit as 1 like 2 , 4, 8, 16, 32….
//We will find that position of right most set bit is always equals to log2(Number)+1

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
         unsigned int set_bit = n & ~(n&(n-1)); //try for 010010
         return log2(set_bit)+1;
    }
};

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
         unsigned int set_bit = n ^ (n&(n-1)); //try for 010010
         return log2(set_bit)+1;
    }
};

//tle
class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
       int i=1;
       int pos=1;
       while(!(n&i)){ //if we find set bit break the loop
           i = i<<1;//until we find left most setbit..left shift 1
           ++pos;
       }
       return  pos;
    }
};

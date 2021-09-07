//generating all possible combinations 
//gives TLE error
//Time Complexity: O((n^2)^k). 
//For every recursive call n^2 recursive calls is generated until the value of k is 0.
 //So total recursive calls are O((n^2)^k).

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void findMax(string str,string &res, int k){
        if(k==0) return;
        
        for(int i= 0 ;i<str.size()-1;++i){
            for(int j=i+1;j<str.size();++j){
                if(str[j]>str[i]){
                swap(str[j] ,str[i]);
                if(str.compare(res)>0){
                    res = str;
                }
                findMax(str,res,k-1);
                swap(str[j] ,str[i]);//bactracking

            }

            }
        }
        
    }
    string findMaximumNum(string str, int k)
    {
        string res = "";
        res = str ;
        findMax(str,res,k);
        return res;
    }
};

//optimized approach
//O(n^k)
   void findMax(string str,string &res, int k,int idx){
        if(k==0) return;
        int n= str.size();
        char max = str[idx];
        //pre-computing the largest digit on right to 
        //avoid unnecessary swaps
        for(int i=idx+1;i<n;++i){
            if(str[i]>max){
                max = str[i];
            }
        }
        //if we find larger digit then swap is possible
        //hence k--
        if(str[idx]!=max){
            k--;
        }
        
        for(int i= idx ;i<n;++i){
             if(str[i]==max){
                swap(str[idx] ,str[i]);
                if(str.compare(res)>0){
                    res = str;
                }
                findMax(str,res,k,idx+1);
                swap(str[i] ,str[idx]);//bactracking

            }
        }
        
    }
    string findMaximumNum(string str, int k)
    {
        string res = "";
        res = str ;
        findMax(str,res,k,0);
        return res;
    }
};
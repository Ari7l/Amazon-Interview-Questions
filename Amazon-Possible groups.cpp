
/*1. Hash all elements in a count array based on remainder, i.e, 
   for all elements a[i], do c[a[i]%3]++;
2. Now c[0] contains the number of elements which when divided
   by 3 leave remainder 0 and similarly c[1] for remainder 1 
   and c[2] for 2.
3. Now for group of 2, we have 2 possibilities
   a. 2 elements of remainder 0 group. Such possibilities are 
      c[0]*(c[0]-1)/2
   b. 1 element of remainder 1 and 1 from remainder 2 group
      Such groups are c[1]*c[2].
4. Now for group of 3,we have 4 possibilities
   a. 3 elements from remainder group 0.
      No. of such groups are c[0]C3
   b. 3 elements from remainder group 1.
      No. of such groups are c[1]C3
   c. 3 elements from remainder group 2.
      No. of such groups are c[2]C3
   d. 1 element from each of 3 groups. 
      No. of such groups are c[0]*c[1]*c[2].
5. Add all the groups in steps 3 and 4 to obtain the result.*/

class Solution{   
public:
    long long findgroups(int arr[], int n) {
       long long rem[3] = {0};
       for(int i=0;i<n;++i){
           rem[arr[i]%3]++;
       }
       //for group of two 
       long long res = (rem[0] *(rem[0]-1)/2) + (rem[1]* rem[2]);
       res += rem[0]*(rem[0]-1)*(rem[0]-2)/6;
       res += rem[1]*(rem[1]-1)*(rem[1]-2)/6;
       res += rem[2]*(rem[2]-1)*(rem[2]-2)/6;
       res += rem[0]*rem[1]*rem[2];
       return res;
    }
};
//O(N) and O(1)
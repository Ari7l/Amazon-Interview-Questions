class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int total = 0;
       for(int i=0;i<n;++i) total+=p[i].petrol - p[i].distance;
       //if total is <0 for one pass then we will never be able to come back again
       if(total<0) return -1;
       long long t = 0;
       long long ans = 0;
       for(int i=0;i<n;++i){
           t +=p[i].petrol - p[i].distance;
           //if we see that the total is -ve then we will start over from next station
           //once we update ans if total t never goes negative it means we can circle again
           if(t<0){
               t=0;
               ans = i+1;
           }
       }
       return ans;
        
    }
};

class Solution {
public:

 
 bool isPossible(vector<int>&weights,int capacity,int days)
 {
     int cap = 0;
    int n = weights.size();
    int i =0;
    while(i<n && days)
    {
        if(weights[i] > capacity)
        return false;
        if(cap + weights[i] > capacity)
        {
            cap = weights[i]; 
            days--;
        }
        else
        {
            cap += weights[i];
        }
        i++;
    }
    if(days)
    return true;
    return false;
 }


    int shipWithinDays(vector<int>& weights, int days) {
       int sum = 0,ans;
       for(int i = 0; i<weights.size();i++)
       sum += weights[i];
       int high = sum;
       int low = 0;
       int mid = 0;
       while(low<=high)
       {
           mid = low+(high-low)/2;
           if(isPossible(weights,mid,days))
           {
               ans = mid;
               high = mid-1;
           }
           else
           {
               low = mid+1;
           }
       } 
       return ans;
    }
};
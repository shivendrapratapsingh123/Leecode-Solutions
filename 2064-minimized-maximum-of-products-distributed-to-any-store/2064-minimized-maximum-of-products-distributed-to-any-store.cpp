class Solution {
public:

bool isPossible(vector<int>&quantities,int n , int limit)
{
    int cnt = 0;
    for(int i = 0; i<quantities.size();i++)
    {
        if(quantities[i] <= limit)
        {
            cnt ++;
        }
        else
        {
           int temp = quantities[i];
           while(temp>0)
           { 
                 temp -= limit;
                 cnt++;
           }
             
           }
            if(cnt > n)
              return false;
        }
    
    return true;
}

  
    int minimizedMaximum(int n, vector<int>& quantities) {

       int low =  1,high = *max_element(quantities.begin(),quantities.end());
       int mid = 0;
       int ans = 0;
       while(low <= high)
       {
           mid = low + (high-low)/2;
           if(isPossible(quantities,n,mid))
           {
               ans = mid;
               high = mid-1;
           }
           else
           {
               low = mid + 1;
           }
       }
       return ans;
    }
};
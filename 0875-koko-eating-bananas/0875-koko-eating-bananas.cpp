// koko will eat some banana (let as max as possible) that can be eating within given hours 
 //then try to minimise these bananas  till low <= high and answer is obvious 

class Solution {
public:
 
 bool isPossible(vector<int>&piles, int banana,long long  hour)
 {
     long long  h = 0;

     for(int i = 0;i<piles.size();i++)
     {
         if(piles[i]%banana == 0)
         {
             h += piles[i]/banana;
         }
         else{
             h += piles[i]/banana;
             h += 1;
         }
     }
     if(h <= hour)
     return true;
     return false;
 }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans = 0;
           int maxi = INT_MIN;
           for( auto it : piles)
           {
               maxi = max(it,maxi);
           }
        int low = 1;
        int high = maxi;

        int mid = 0;
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(isPossible(piles,mid,h))
            {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
      return ans;
    }
};
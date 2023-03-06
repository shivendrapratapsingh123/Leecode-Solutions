class Solution {
public:

  unordered_map<int,int>findFactor(int num){
      int f = 2;
      unordered_map<int,int>fac;
      while(num>1 && f*f <= num){
          while(num%f == 0)
          {
            fac[f]++;
            num /=f;
          }
          f++;
      }
      if(num != 1) fac[num] = 1;
      return fac;
  }



    int findValidSplit(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto it : nums)
        {
            auto fac  = findFactor(it);
            for(auto &[f, c] : fac){
                freq[f] +=c;
            }
        }

        auto org = freq; // copy of map 

        int dirty = 0;  // factors that are neighter equal to original nor have power zero

        for(int i = 0;i<nums.size()-1;i++)
        {
            auto fac = findFactor(nums[i]);
            for(auto &[f,c] : fac){
                if(org[f] == freq[f] && c!=freq[f]) dirty++;
                if(org[f] != freq[f] && c == freq[f] ) dirty--;
                freq[f] -= c;
            }
            if(dirty == 0) return i;
        }
        return -1; 
    }
};
// index at which no factor is dirty that means either factors are zero or equal to 
// original array at that point we can separate two arrays 
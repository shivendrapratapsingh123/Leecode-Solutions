class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int>mp;

        int max_picked = 0;
        
        int left = 0;
        for(int right = 0; right < fruits.size();right++)
        {
            mp[fruits[right]]++;

            while(mp.size()>2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            max_picked = max(max_picked,right-left+1);
        }
        return max_picked;
    }
};
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<int>remainingCapacity;
        for(int i = 0; i< capacity.size();i++)
        {
            remainingCapacity.push_back(capacity[i]-rocks[i]);
        }
        sort(remainingCapacity.begin(),remainingCapacity.end());

        int cnt=0;

        for(int i = 0; i<remainingCapacity.size();i++)
        {
            if(additionalRocks >= remainingCapacity[i])
            {
                cnt++;
                additionalRocks -= remainingCapacity[i];
            }
        }
        return cnt++;
    }
};
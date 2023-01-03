class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
      int cnt = 0;
        int i = 0;
        int j = 0;
        while(j<strs[0].size())
        {
            i = 1;
            while(i<strs.size())
            {
                if(strs[i][j] < strs[i-1][j])
                {
                    cnt++;
                    break;
                }
                i++;
            }
           j++;
        }
        return cnt;
    }
};
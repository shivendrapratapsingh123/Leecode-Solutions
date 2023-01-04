class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int i = 0; i<tasks.size();i++)
        {
            mp[tasks[i]]++;
        }

        int flag = 0;
        int cnt =0;
        for(auto it : mp)
        {
            if(it.second == 1)
            {
                flag = 1;
                break;
            }
            int temp = it.second;
          if(temp %3 == 0)
          {
              cnt += temp/3;
              temp = temp%3;
          }
          else if(temp%3 == 2)
          {
              cnt++;
              temp -=2;
              cnt += temp/3;
              temp = temp%3;
          }
          else if(temp%3 == 1)
          {
              cnt += 2;
              temp -= 4;
              cnt += temp/3;
              temp = temp%3;
          }
        }
        if(flag == 1)
        return -1;
        return cnt;
    }
};
class Solution {
public:
    bool detectCapitalUse(string word) {
       int flag = 0;
        int cnt = 0;
        for(int i = 0; i< word.size();i++)
        {
            if(word[i] <= 90 && word[i] >=65)
            {
               if(i == 0)
               {
                   cnt++;
                   flag = 1;
               }
                else
                {
                    cnt++;
                }
            }
        }
        if(cnt == word.size())
            return true;
        if(cnt == 1 && flag == 1)
            return true;
        if(cnt == 0)
            return true;
        return false;
    }
};
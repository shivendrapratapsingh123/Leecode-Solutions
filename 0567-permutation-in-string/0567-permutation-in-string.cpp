class Solution {
public:

  bool match(vector<int>&s1mp, vector<int>&s2mp)
  {
      for(int i = 0; i<26;i++)
      {
       if(s1mp[i] != s2mp[i])
       return false;
      }
      return true;
  }

    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
        return false;
      vector<int>s1mp(26,0);
      vector<int>s2mp(26,0);
      for(int i = 0; i < s1.size(); i++)
      {
          s1mp[s1[i]-'a']++;
          s2mp[s2[i]-'a']++;
      }

      // sliding window 
      int n = s1.size();
      for(int i = 0;i<(s2.size() - s1.size()); i++)
      {
          if(match (s1mp,s2mp))
          return true;
         s2mp[s2[i+n]-'a']++;
         s2mp[s2[i]-'a']--;
      }
      return match(s1mp,s2mp);
    }
};
class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char,string>p2s;
        unordered_map<string,char>s2p;
        int idx = 0; 
        string temp = "";
        for(int i = 0; i <= s.size();i++)
        {
          if(s[i] == ' ' || i == s.size())
          {
            if(idx < p.size() && (p2s.find(p[idx]) != p2s.end() || s2p.find(temp) != s2p.end()))
            {
                if(p2s[p[idx]] != temp || s2p[temp] != p[idx]) return false;
            }
            else
            {
                p2s[p[idx]] = temp;
                s2p[temp] = p[idx];
            }
            temp = "";
            idx++;
          } 
           else
        {
            temp += s[i];
        }
        }

       return idx == p.size();
    }
};
class Solution {
public:

bool dfs(int idx, string str, unordered_set<string>&st)
{
    for(int i = idx;i<str.size();i++)
    {
       string prefix = str.substr(idx,i-idx+1);
       string suffix = str.substr(i+1);
       if(st.find(prefix) != st.end() && st.find(suffix) != st.end())
       return true;
       if(st.find(prefix) != st.end() && dfs(i+1,str,st))
       return true;
    }
    return false;
}
   

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>st;
        vector<string>ans;
        for(int i = 0; i<words.size();i++)
        {
            st.insert(words[i]);
        }

        for(int i = 0; i< words.size();i++)
        {
            if(dfs(0,words[i],st))
            {
                ans.push_back(words[i]);
            }
        }
        return ans; 
    }
};
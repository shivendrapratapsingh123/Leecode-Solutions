//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:


  static bool cmp(string&a, string& b)
  {
      if(a.size() != b.size())
      return a.size() < b.size();
      
      return a > b;
  }


    string longestString(vector<string> &words)
    {
        unordered_map<string,int>mp;
        
        int n  = words.size();
         
        
        bool flag = true;
        
        for(int i = 0; i< n;i++)
        {
            mp[words[i]]++;
        }
        
        sort(words.begin(),words.end(),cmp);
         
         for(int i = n-1; i>=0; i--)
         {
             string temp = "";
             flag = true;
             for(int j = 0; j < words[i].size();j++)
             {
                 temp += words[i][j];
                 if(mp[temp] == 0)
                 {
                     flag = false;
                     break;
                 }
             }
             if(flag)
             return words[i];
         }
         return {};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends
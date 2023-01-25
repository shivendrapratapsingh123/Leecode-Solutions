//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        
        string str ="";
        int maxi = 0;
        for(int i = 0; i<s.size();i++)
        {
            int cnt = 0;
            str+=s[i];
            int j = i+1;
            int k =  0;
            while(k<str.size() && j <s.size()){
              if(str[k] == s[j])
              {
                  cnt++;
                  k++;
                  j++;
              }
              else
              break;
            }
            if(cnt == str.size())
            {
                maxi = max(maxi,cnt);
            }
            
        }
        if(maxi ==0)
        return s.size();
        return maxi+1+s.size()-2*maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
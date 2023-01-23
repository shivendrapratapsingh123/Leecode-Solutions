//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<int>st;
        for(int i = 0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else if(s[st.top()] == s[i])
            {
                st.pop();
            }
            else
            st.push(i);
        }
        string str="";
        while(!st.empty())
        {
            str.push_back(s[st.top()]);
            st.pop();
        }
        reverse(str.begin(),str.end());
        if(str.size()==0)
        return "-1";
        return str;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
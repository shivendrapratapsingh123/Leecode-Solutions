//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        vector<int>ans;
        ans.clear();
        stack<int>st;
        while(!st.empty())
        st.pop();
        int i =0;
        while(i<N)
        {
            while(!st.empty() && i<N && (asteroids[i] <0 && st.top()>=0))
            {
                if(abs(st.top()) < abs(asteroids[i]))
                st.pop();
                else if(abs(st.top()) == abs(asteroids[i]))
                {
                    i++;
                    st.pop();
                }
                else if(abs(asteroids[i]) < abs(st.top()))
                i++;
                else
                break;
            }
            if(i<N)
            st.push(asteroids[i]);
        i++;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
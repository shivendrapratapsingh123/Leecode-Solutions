//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{
       vector<vector<int>>graph;
       graph.push_back({0,8});
      graph.push_back({1,2,4});
      graph.push_back({1,2,3,5});
      graph.push_back({2,3,6});
      graph.push_back({1,4,5,7});
      graph.push_back({2,4,5,6,8});
      graph.push_back({3,5,6,9});
      graph.push_back({4,7,8});
      graph.push_back({5,7,8,9,0});
      graph.push_back({6,8,9});
       
       vector<vector<long long int >>dp(N+1,vector<long long int>(10,0));
       for(int i = 1;i<=N;i++)
       {
            for(int j = 0;j<=9;j++)
            {
                if(i == 1)
                {
                    dp[i][j] = 1;
                }
                else{
                    for(int prev : graph[j])
                    dp[i][j] += dp[i-1][prev];
                }
            }
       }
       long long int  sum = 0;
       for(int i = 0;i<=9;i++)
       sum += dp[N][i];
      return sum;
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
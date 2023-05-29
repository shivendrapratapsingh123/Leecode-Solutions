//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
 // replacing zeros with  1 and ones with -1 and applying kadan's algorithm
  int max_diff = -1;
  int curr = 0;
  int sum = 0;
	int maxSubstring(string S)
	{
	    
	    for(int i = 0;i<S.size();i++)
	    {
	        if(S[i] == '0')
	        {
	            sum = max(1,sum + 1);
	        }
	        else{
	            sum = max(-1,sum-1);
	        }
	        max_diff = max(max_diff,sum);
	    }
	    return max_diff;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	// space optimisation 
		int AlternatingaMaxLength(vector<int>&nums){
		    int n = nums.size();
		   vector<vector<int>>dp(n,vector<int>(2,0));
		   vector<int>curr(2,0);
		  curr[0] = curr[1] = 1;
		  for(int i = n-1;i > 0 ;i--)
		  {
		          if(nums[i] > nums[i-1])
		          {
		                  curr[0] = 1 + curr[1]; 
		          }
		         else if(nums[i] < nums[i-1])
		         {
		            curr[1] =  1 + curr[0];  
		         }
		  }
		  return max(curr[0],curr[1]);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
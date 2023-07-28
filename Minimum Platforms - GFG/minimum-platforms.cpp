//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int,int>>vp;
    	for(int  i = 0;i<n;i++){
    	    vp.push_back({arr[i],0});
    	    vp.push_back({dep[i],1});
    	}
    	sort(vp.begin(),vp.end());
    	int cnt = 0;
    	int ans = 0;
    	for(int i = 0;i<vp.size();i++){
    	    if(vp[i].second == 0) cnt++;
    	    else
    	    cnt--;
    	    ans = max(ans,cnt);
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int mod = 1e9+7;
	ll countStrings(int n) {
	    
	    int a[n+1]; // a[] represents strings that end with zero
	    int b[n+1]; // b[] represents strings that end with one 
	    a[0] = b[0]  = 0;
	    a[1] = b[1]  = 1; // one length only one one string ending at 0 and 1
	    for(int i = 2;i <= n;i++)
	    {
	        a[i] = (a[i-1] + b[i-1])%mod;
	        b[i] = a[i-1];
	    }
	    return (a[n] + b[n])%mod;
	}
};
// string that ends with zero we can apppend 0 or 1 at the end of it 
// string that ends at one we can append 1 at the end of it 
//so reccurence relation is a[i] = a[i-1] + b[i-1]
// b[i]  = a[i-1]; stiing ending at one in next steps are steps ending at zero at previous step

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
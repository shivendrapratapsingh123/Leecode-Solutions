//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	long long int mod = 1e9+7;
	
	long long int findHash(string pat){
	    long long int p = 255;
	    long long int pow = p;
	    long long int desiredhash = pat[0]-'a'+1;
	    for(int i = 1;i<pat.size();i++){
	        desiredhash = (desiredhash + (pat[i]-'a' + 1)*pow)%mod;
	        pow = (pow*p)%mod;
	    }
	    return desiredhash;
	}
	
	int search(string text, string pat)
	{
	    long long int patHash = findHash(pat);
	    int n = text.size();
	    long long int dp[n];
	    long long int power[n];
	    long long int p = 255;
	    power[0] = 1;
	    dp[0] = text[0]-'a'+1;
	    long long int pow = p;
	    for(int i = 1;i<text.size();i++){
	        dp[i]  = (dp[i-1] + (text[i]-'a'+1)*pow)%mod;
	        power[i] = pow;
	        pow = (pow*p)%mod;
	    }
	    int sp = 0;
	    int ep = pat.size()-1;
	    while(ep < text.size()){
	        long long int window = dp[ep];
	        if(sp > 0) 
	        window = (window - dp[sp-1] + mod)%mod;
	        if(window == (patHash*power[sp])%mod)
	        return 1;
	        sp++;
	        ep++;
	    }
	    return 0;
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
   		string x, y;
   		cin >> x >> y;



        Solution ob;
   		cout << ob.search(x, y) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
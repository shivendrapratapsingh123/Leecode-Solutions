//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    unordered_map<int,int>mp;
    for(auto it : S){
        mp[it]++;
    }
    int cnt = 0;
    for(auto it : mp){
        if(it.second%2 == 1)
        cnt++;
    }
    if((S.size() %2 == 1 && cnt == 1) || (S.size() %2 == 0 && cnt == 0))
    return true;
    return false;
    
}
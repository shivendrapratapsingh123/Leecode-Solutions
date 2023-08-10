//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int>permutation;
        int fact = 1;
        k = k-1; // taking zero based indexing and taking permutation on scale from 0 to k-1
        for(int i = 1;i<n;i++){
            fact = fact*i;
            permutation.push_back(i);
        }
        permutation.push_back(n);
        string str = "";
        while(true){
            str.push_back(permutation[k/fact] + '0');
            permutation.erase(permutation.begin() + k/fact);
            if(permutation.size() == 0)
            break;
            k  = k%fact;
            fact = fact/permutation.size();
        }
        return str;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
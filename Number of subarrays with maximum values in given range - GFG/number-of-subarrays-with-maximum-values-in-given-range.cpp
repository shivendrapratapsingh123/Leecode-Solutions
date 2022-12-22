//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        long long int inc =0;
        long long int exc = 0;
        long long sum = 0;
        for(int i = 0; i<n; i++)
        {
          if(a[i] > R)
          {
             sum += (inc*(inc+1))/2 - (exc*(exc+1))/2;
              inc = 0;
              exc = 0;  
          }
          else if(a[i] < L)
              {
                  exc++;
                  inc++;
              }
              else
              {
                 sum -= (exc*(exc+1))/2;
                 exc =0;
                 inc++;
              }
         
        }
        sum += (inc*(inc+1))/2 - (exc*(exc+1))/2;
        return sum;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
       
       int start = 0;
       int end = 0;
       int fardest = 0;
       int prev = 0;
       
       while(end < N-1)
       {
           fardest = 0;
           prev = end;
           for(int i = start; i<= end; i++)
           {
               fardest = max(fardest, i+A[i]);
           }
           start = end+1;
           end = fardest;
           if(end >=N-1)
           return true;
           if(end == prev)
           return false;
       }
       return true;
    }
};

//thinking greedy solution 
//we think fardest index to which we can reach from curr index 
//  and we take range for every index that is minimum and maximum reach 
// from that index and for this range we find next fardest index to which we can 
// reach if we are able to reach at end index then we will return true else false




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
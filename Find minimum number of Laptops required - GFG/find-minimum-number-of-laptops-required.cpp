//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 // it is the modified language of minimum plateform problem 
 // here we are only interested in end of any meeting and start of any meeting 

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
       
       int laptopRequired = 1;
       int result = 1;
       int i =0; // i points to end of any meeting 
       int j = 1; // j points to start of any meeting 
       sort(start, start+N);
       sort(end, end+N);
       while(i<N && j<N)
       {
           if(start[j] < end[i])
           {
               laptopRequired++;
               j++;
           }
           else
           {
               laptopRequired--;
               i++;
           }
           if(laptopRequired > result)
           {
               result = laptopRequired;
           }
       }
       return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends
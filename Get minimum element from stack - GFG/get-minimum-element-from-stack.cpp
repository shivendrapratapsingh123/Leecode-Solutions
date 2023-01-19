//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    stack<pair<int,int>>minSt;
    stack<int> st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(minSt.empty())
           return -1;
           return minSt.top().first;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(st.empty())
           return -1;
           if(minSt.top().first == st.top())
           {
               minSt.top().second--;
           }
           if(minSt.top().second == 0)
           minSt.pop();
           int pop = st.top();
           st.pop();
           return pop;
           }
       
       /*push element x into the stack*/
       void push(int x){
           
           st.push(x);
           if(minSt.empty() || x < minSt.top().first)
           {
               minSt.push({x,1});
           }
           else if( minSt.top().first == x)
           {
               minSt.top().second++;
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string strL="";
        string strU="";
        for(int i = 0; i<str.size();i++)
        {
            if(str[i] >= 97 && str[i] <= 122)
            {
                strL += str[i];
            }
            else{
                strU += str[i];
            }
        }
        sort(strL.begin(),strL.end());
        sort(strU.begin(),strU.end());
        string ans = "";
        int i = 0;
        int j = 0;
        for(int idx = 0; idx < n; idx++)
        {
            if(str[idx] >= 97 && str[idx] <= 122){
                ans += strL[i];
                i++;
            }
            else{
                ans += strU[j];
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
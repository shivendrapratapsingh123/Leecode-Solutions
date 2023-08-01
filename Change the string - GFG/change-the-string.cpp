//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    string modify (string s)
    {
        if(s[0] >= 65 && s[0] <= 90){
            for(int i = 0;i<s.size();i++){
                if(s[i] >= 97 && s[i] <= 122){
                    s[i] = toupper(s[i]);
                }
            }
        }
        else{
            for(int i = 0;i<s.size();i++){
                if(s[i] >= 65 && s[i] <= 90){
                    s[i] = tolower(s[i]);
                }
            } 
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.modify (s) << endl;
	}
}
// } Driver Code Ends
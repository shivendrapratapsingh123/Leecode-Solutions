// naive string matching algorithm 

class Solution {
public:
    int strStr(string haystack, string needle) {
       if(needle.size()==0)
           return 0;
        int n= haystack.size();
        int m= needle.size();
        for(int i=0;i<=n-m;i++)
        {
            int j;
            for(j=0;j<m;j++)
                if(haystack[i+j]!=needle[j])
                    break;
                if(j==m)
                    return i;
        }
        return -1;
    }
};
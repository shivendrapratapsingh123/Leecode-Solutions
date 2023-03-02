class Solution {
public:
    int compress(vector<char>& chars) {
        
        int cnt  = 0;
           int idx = 0;
        int n = chars.size();
        int i = 0;
        while(i<n){
            int j = i;
            while(j<n && chars[j] == chars[i])
            j++;
            chars[idx++]  = chars[i];
            if(j-i>1)
            {
                int count = j-i;
               string str = to_string(count);
                for(int i = 0;i<str.size();i++)
                chars[idx++] = str[i];
            }   
            i = j;
        }
        return idx;
    }
};
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       int carry=0;
        int n=num.size()-1;
        for(int i=n;i>=0&&k>0;i--)
        {
            num[i]+=k;
            k=num[i]/10;
            num[i]=num[i]%10;
        }
        while(k>0)
        {
            num.insert(num.begin(),k%10);
            k=k/10;
        }
        return num;
        
    }
};
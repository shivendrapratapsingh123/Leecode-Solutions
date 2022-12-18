//concept of largest rectangle in histogram

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        // see notes  for concept;
        int mod = 1e9+7;
        long long int sum = 0;
        
        stack<int>st;
        int n = arr.size();
        vector<int>left(n),right(n);     
        for(int i =0;i<n;i++)
        {
            if(st.empty())
            {
                left[i] =0;
                st.push(i);
            }
            else {
                while(!st.empty() &&  arr[st.top()] > arr[i])
                    st.pop();
                left[i] = st.empty() ? 0 : st.top()+1;
                st.push(i);
            }
        }
        while(!st.empty())
            st.pop();
        for(int i = n-1 ; i >=0 ;i--)
        {
            if(st.empty())
            {
                right[i] = n-1;
                st.push(i);
            }
            else 
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                right[i] = st.empty() ? n-1 : st.top()-1;
                st.push(i);
            }
        }
        for(int i = 0;i<n;i++)
        {
            long long subarray = ((i - left[i] + 1) * (right[i] - i + 1))%mod;
            sum = (sum + (arr[i] * subarray)%mod)%mod;
        }
        return sum;
    }
};
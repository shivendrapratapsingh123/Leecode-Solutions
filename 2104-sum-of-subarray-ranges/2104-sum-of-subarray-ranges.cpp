//extended version of sum of subarray minimum
// we will first minimum in all the ranges and their contribution and then find maximum in
// in all the range their contribution and then find the answer 
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long  int mini =0,maxi=0;
        vector<long long >left(n),right(n); 
        stack<long long >st;
        for(int i =0; i<n;i++)
        {
            if(st.size() == 0)
            {
                left[i] = 0;
                st.push(i);
            }
            else
            {
                while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
                left[i] = st.empty() == true ? 0 : st.top()+1;
                st.push(i);
            }
        }
        while(!st.empty())
        st.pop();

         for(int i =n-1; i>=0;i--)
        {
            if(st.size() == 0)
            {
                right[i] = n-1;
                st.push(i);
            }
            else
            {
                while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
                right[i] = st.empty() == true ? n-1 : st.top()-1;
                st.push(i);
            }  
        }
        for(int i = 0; i<n; i++)
        {
            mini += (i-left[i]+1)*(right[i]-i+1)*nums[i];
        }
         
          while(!st.empty())
        st.pop();
        // same for calculating max element 

         for(int i =0; i<n;i++)
        {
            if(st.size() == 0)
            {
                left[i] = 0;
                st.push(i);
            }
            else
            {
                while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
                left[i] = st.empty() == true ? 0 : st.top()+1;
                st.push(i);
            }
        }
        while(!st.empty())
        st.pop();

         for(int i =n-1; i>=0;i--)
        {
            if(st.size() == 0)
            {
                right[i] = n-1;
                st.push(i);
            }
            else
            {
                while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
                right[i] = st.empty() == true ? n-1 : st.top()-1;
                st.push(i);
            }  
        }

        for(int i = 0; i<n; i++)
        {
            maxi += (i-left[i]+1)*(right[i]-i+1)*nums[i];
        }
        // cout<<maxi-mini;
      return maxi-mini;
    }
};
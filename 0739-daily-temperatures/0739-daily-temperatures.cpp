
// t.c bigoh(n) and s.c bigoh(n)
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int>ans(temperatures.size(),0);
//         stack<int>st;
//         for(int currDay=0;currDay<temperatures.size();currDay++)
//         {
//            int ele = temperatures[currDay];
//             while(!st.empty() && temperatures[st.top()]<ele )
//             {
//                 int prevDay = st.top();
//                 ans[prevDay]=currDay-prevDay;
//                 st.pop();
//             }
//             st.push(currDay);
//         }
//         return ans;
        
//     }
// };



// 000000000000000000000000000000 solution in Bigohh(1) space //complexity

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(),0);
        int n = temperatures.size();
    
        int hottest = 0;
        
        for(int currDay=n-1;currDay>=0;currDay--)
        {
            if(temperatures[currDay]>=hottest)
            {
                hottest = temperatures[currDay];
                continue;
            }
            int days=1;
            while(temperatures[currDay+days]<=temperatures[currDay])
            {
                days+=ans[currDay+days];
            }
            ans[currDay] = days;
        }
        return ans;
        
    }
};

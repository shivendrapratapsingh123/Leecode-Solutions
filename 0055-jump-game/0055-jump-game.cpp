// peak valley approach 

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//       int reachable =0;
//         for(int i =0;i<nums.size();i++)
//         {
//             if(reachable <i)
//                 return false;
//             reachable = max(reachable, i+nums[i]);
//         }
//         return true;
//     }
// };


// from backbard neetcode 


class Solution {
public:
    bool canJump(vector<int>& nums) {
      int goal =nums.size()-1;
        for(int i =nums.size()-2;i>=0;i--)
        {
            if(i+nums[i]>=goal)
                goal = i;
        }
        return goal ==0?true:false;
    }
};
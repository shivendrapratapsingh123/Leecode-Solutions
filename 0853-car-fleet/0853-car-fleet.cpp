class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int,int>>res;
       stack<double>st;
       for(int i = 0; i<position.size();i++)
       {
           res.push_back({position[i],speed[i]});
       } 
       sort(res.begin(),res.end());

       double t  = 0,dis=0;
       for(int i = res.size()-1; i>=0; i--){
           dis = target - res[i].first;
           t = dis/res[i].second;
           if(st.empty() || st.top() < t)
           {
               st.push(t);
           }
       }
       return st.size();
    }
};
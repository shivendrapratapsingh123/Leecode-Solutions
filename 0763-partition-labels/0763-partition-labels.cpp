class Solution {
public:

   vector<vector<int>>mergeIntervals(vector<vector<int>>&interval)
   {
       vector<vector<int>>merge;
       merge.push_back(interval[0]);
       for(int i = 1; i< interval.size();i++){
           if(merge.back()[1] < interval[i][0])
           {
               merge.push_back(interval[i]);
           }
           else
           {
               merge[merge.size()-1][1] = max(merge.back()[1],interval[i][1]);
           }
       }
       return merge;
   }

    vector<int> partitionLabels(string s) {
       vector<pair<char,int>>chr;
       vector<vector<int>>interval;
       for(int i = 0; i<s.size(); i++)
       {
           chr.push_back({s[i],i});
       }
       sort(chr.begin(),chr.end());
         
       interval.push_back({chr[0].second,chr[0].second});
       for(int i = 1; i < chr.size();i++)
       {
           int end = interval[interval.size()-1][1];
           if(chr[i].first == s[end])
           {
               interval[interval.size()-1][1] = chr[i].second;
           }
           else
           {
               interval.push_back({chr[i].second,chr[i].second});
           }
       }
       
       sort(interval.begin(),interval.end());

      vector<vector<int>>res =  mergeIntervals(interval);
      // for( auto it : interval)
      // cout<<it[0] <<" "<<it[1]<<" ";
       vector<int>ans;
      for(int i  = 0; i < res.size();i++)
      {
          int start = res[i][0];
          int end = res[i][1];
          ans.push_back(end - start + 1);
      }
        return ans;
    }
};
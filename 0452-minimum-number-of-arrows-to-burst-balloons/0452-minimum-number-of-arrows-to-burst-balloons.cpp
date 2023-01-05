class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0] == b[0])
        return a[1]<b[1];
        return a[0]<b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        
        int cnt = 0;
        
        int i =0; 
        int j  = 1;
        while(j<points.size())
        {
            if(points[j][0] > points[i][1] )
            {
                i = j;
            }
            else if(points[j][1] < points[i][1])
            {
                cnt++;
                i = j;
            }
            else if(points[j][1] >= points[i][1])
            {
                cnt++;
            }
            j++;
        }
        return n-cnt;
    }
};
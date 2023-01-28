class SummaryRanges {
public:
set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>stream;
        int start = -1;
        int end = -1;
        for(auto &ele : st)
        {
            if(start == -1)
            {
                start = ele;
                end = ele;
            }
            else if(ele == end+1)
            {
                end = ele;
            }
            else{
                stream.push_back({start,end});
                start = ele;
                end  = ele;
            }
        }
        if(start != -1)
        {
            stream.push_back({start,end});
        }
        return stream;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
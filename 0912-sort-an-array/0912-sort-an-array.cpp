class Solution {
public:

  void merge(vector<int>&nums,int low , int mid , int high)
  {
      int ln = mid - low +1;
      int rn = high - mid;
      vector<int>left(ln);
      vector<int>right(rn);
      int s = 0;
      for(int  i = low;i<=mid;i++)
      left[s++] = nums[i];
      s = 0;
      for(int i = mid+1;i<=high;i++)
      right[s++] = nums[i];

      int l = 0;
      int  r = 0;
      int midx = low;
      while( l < ln && r < rn )
      {
        if(left[l] < right[r])  
        {
           nums[midx++] = left[l];
           l++;
        }
        else
        {
           nums[midx++] = right[r];
           r++;
        }
      }
      while(l < ln )
      {
          nums[midx++] = left[l++];
      }
      while(r<rn)
      {
          nums[midx++] = right[r++];
      }
  }

  void mergeSort(vector<int>&nums,int low , int high)
  {

    if(low<high)
    {
        int mid =  (high + low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low, mid, high);
    }
  }

   vector<int> sortArray(vector<int>& nums) {
     int low = 0;
     int high = nums.size()-1;
      mergeSort(nums,low,high);
       return nums;
    }
   
};  








// recursive function to sort an aray 

// class Solution {
// public:
    
    
    
//     void insert(vector<int>&v, int temp)
//     {
//         if(v.size()==0 || v[v.size()-1]<=temp)
//         {
//           v.push_back(temp);  
//             return ;
//         }
           
//         int val = v[v.size()-1];
//             v.pop_back();
//         insert(v, temp);
//         v.push_back(val);
//     }
    
    
//     void Sort(vector<int>&v)
//     {
//         if(v.size()==0)
//             return ;
//         int temp = v[v.size()-1];
//         v.pop_back();
//         Sort(v);
//         insert(v, temp);
//     }
    
    
//     vector<int> sortArray(vector<int>& nums) {
//         vector<int>v;
//         v = nums;
//         Sort(v);
//         return v;
//     }
// };
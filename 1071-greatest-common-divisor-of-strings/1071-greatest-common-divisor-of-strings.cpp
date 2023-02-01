class Solution {
public:

string joinword(string base, int n){
    string  str = "";
    for(int i = 0; i<n;i++)
    {
        str += base;
    }
    return str;
}



 bool isValid(string&str1, string&str2,int k)
 {
     if(str1.size()%k > 0 || str2.size()%k > 0)
     return false;
     else{
         int n1 = str1.size()/k;
         int n2 = str2.size()/k;

         string base = str2.substr(0,k);
         
         return str1 == joinword(base,n1) && str2 == joinword(base,n2);
     }
 }



    string gcdOfStrings(string str1, string str2) {
      
        int len1 = str1.size();
        int len2 = str2.size();
        for(int i = min(len1,len2); i>=1;i--)
        {
            if(isValid(str1,str2,i)){
                return str1.substr(0,i);
            }
        }
        return "";
    }
};
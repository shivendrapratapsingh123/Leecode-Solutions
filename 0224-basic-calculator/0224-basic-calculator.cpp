


class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int sum =0;
        int sign = 1;
        stack<int>st;
        for(int i =0;i<n;i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;
                while(i<n && s[i] >= '0' && s[i] <= '9')
                {
                    num = num *10 + (s[i]-'0');
                    i++;
                }
                sum+= num * sign;
                i--;
            }
            else if(s[i] == '+')
            {
                sign =1;
            }
            else if (s[i] == '-')
            {
                sign  = -1;
            }
            else if(s[i] =='(')
            {
                st.push(sum);
                st.push(sign);
                sum =0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                sum = st.top()*sum;
                st.pop();
                sum += st.top();
                st.pop();
            }
        }
           return sum;    
    }
};









// failed method

// class Solution {
// public:
//     int calculate(string s) {
//         int n = s.size();
//         if(n==1)
//             return stoi(s);
//         stack<char>st;
//         vector<string>v;
        
//         for(int i = 0;i<n;i++)
//         {
//             if(s[i]=='(')
//             {
//                 st.push('(');
//             }
//             else if(s[i] == '+' || s[i] == '-')
//             {
//                 while(!st.empty() && (st.top() == '+' || st.top() == '-'))
//                 {
//                     string temp = "";
//                       temp+=st.top();
//                     st.pop();
//                     v.push_back(temp);
//                 }
//                 st.push(s[i]);
//             }
//             else if(s[i] != ' ' &&  s[i] != '+' && s[i] != '-' && s[i] != ')' && s[i] != ')')
//             { 
//                 string temp="";
//                 temp+=s[i];
//                 v.push_back(temp);
//             }
//             else if(s[i] == ')')
//             {
//                 while(st.top() != '(')
//                 {
//                     string temp ="";
//                     temp += st.top();
//                     v.push_back(temp);
//                     st.pop();
//                 }
//                 st.pop();
//             }
//         }
//         while(!st.empty())
//         {
//             string temp ="";
//             temp += st.top();
//             v.push_back(temp);
//             st.pop();
//         }
        
//         stack<long long>myst;
//         for(int i =0; i<v.size();i++)
//         {
//             // cout<<v[i];
//             if(v[i] != "+" && v[i] != "-")
//             {
//                 myst.push(stoi(v[i]));
//                 cout<<myst.top();
//             }
//             else if(v[i] == "+")
//             {
//                 long long t1 = myst.top();
//                 myst.pop();
//                 long long t2 = myst.top();
//                 myst.pop();
//                 long long temp = t2 + t1;
//                 myst.push(temp);
//             }
//             else if(v[i] == "-")
//             {
               
//                 long long  t1 = myst.top();
//                 myst.pop();
//                 long long t2 = myst.top();
//                 myst.pop();
//                 long long temp = t2 - t1;
//                 myst.push(temp); 
//             }
//         }
//         // cout<<myst.top();
//       return myst.top();
//     }
// };
#include <string>
#include <stack>

using namespace std; 

class Solution {
public:
    char processStr(string s, long long k) { 
        stack<long long> st;
        st.push(0LL);
        long long curr = 0;
        for (char x : s){
            if (x == '*'){
                curr = max(curr - 1, 0LL);
                st.push(curr);
            }
            else if (x == '#'){
                curr *= 2;
                st.push(curr);
            }
            else if (x == '%'){
                st.push(curr);
            }
            else{
                curr++;
                st.push(curr);
            }
        }
        if (k >= st.top()) return '.';

        int pos = s.size() - 1;
        while (pos >= 0){
            if (s[pos] == '#'){
                st.pop();
                if (k >= st.top()) k -= st.top();
            }
            else if (s[pos] == '*'){
                st.pop();
            }
            else if (s[pos] == '%'){
                k = st.top() - 1 - k;
                st.pop();
            }
            else{
                if (k == st.top() - 1) return s[pos];
                st.pop();
            }
            pos--;
        }
        return '.';
    }
};

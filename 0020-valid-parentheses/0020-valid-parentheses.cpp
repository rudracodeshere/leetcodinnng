class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty())
                    return false;
                else if (ch == ')') {
                    if (st.top() == '(')
                        st.pop();
                    else
                        break;
                } else if (ch == '}') {
                    if (st.top() == '{')
                        st.pop();
                    else
                        break;
                } else if (ch == ']') {
                    if (st.top() == '[')
                        st.pop();
                    else
                        break;
                }
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
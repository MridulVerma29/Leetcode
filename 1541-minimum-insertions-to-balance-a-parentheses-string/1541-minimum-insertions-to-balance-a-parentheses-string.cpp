class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // Need a pair of closing parentheses
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;  // Consume the second ')'
                } else {
                    res++; // Insert the missing ')'
                }

                if (open > 0) {
                    open--;
                } else {
                    res++; // Insert a missing '('
                }
            }
        }

        return res + 2 * open;
    }
};
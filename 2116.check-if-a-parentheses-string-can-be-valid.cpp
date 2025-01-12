/*
 * @lc app=leetcode id=2116 lang=cpp
 *
 * [2116] Check if a Parentheses String Can Be Valid
 */

// @lc code=start
class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) return false;

    int openBalance = 0, closeBalance = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (locked[i] == '1' && s[i] == ')') {
            if (openBalance == 0) return false;
            --openBalance;
        } else {
            ++openBalance;
        }
    }

    for (int i = s.size() - 1; i >= 0; --i) {
        if (locked[i] == '1' && s[i] == '(') {
            if (closeBalance == 0) return false;
            --closeBalance;
        } else {
            ++closeBalance;
        }
    }

    return true; 
    }
};
// @lc code=end


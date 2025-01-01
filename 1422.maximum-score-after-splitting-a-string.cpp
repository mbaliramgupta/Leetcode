/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
         int n=s.size();
       int count_one=0,count_zero=0;
       int result=INT_MIN;
       for(int i=0;i<n-1;i++){
        if(s[i]=='1')count_one++;
        if(s[i]=='0')count_zero++;
        result=max(result,count_zero-count_one);
       }
       if(s[n-1]=='1'){
        count_one++;
       }
       return result+count_one;
    }
};
// @lc code=end


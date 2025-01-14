/*
 * @lc app=leetcode id=2657 lang=cpp
 *
 * [2657] Find the Prefix Common Array of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
         vector<int>ans;
        unordered_set<int>st;
        int count=0;
        for(int i=0;i<A.size();i++){
                if(st.count(A[i]))count++;
                st.insert(A[i]);

                if(st.count(B[i]))count++;
                st.insert(B[i]);

                ans.push_back(count);
        }
        return ans;
    }
};
// @lc code=end


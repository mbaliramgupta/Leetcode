/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 */

// @lc code=start
class Solution {
public:
int find(int num){
    int res=0;
    while(num){
        res+=num%10;
        num/=10;
    }
    return res;
}
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp;
           int maxsum=-1;
           for(auto& num:nums){
            int sum=find(num);

            if(mp.count(sum)){
                maxsum=max(maxsum,mp[sum]+num);
            }

            mp[sum]=max(mp[sum],num);
           }
         return maxsum;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=3160 lang=cpp
 *
 * [3160] Find the Number of Distinct Colors Among the Balls
 */

// @lc code=start
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ballcolor;
        unordered_map<int,int>color_count;
        vector<int>res;
        for(auto& it:queries){
            int x=it[0];
            int y=it[1];

            if(ballcolor.count(x)){
                int oldcolor=ballcolor[x];
                color_count[oldcolor]--;
                if(color_count[oldcolor]==0){
                    color_count.erase(oldcolor);
                }
            }
            ballcolor[x]=y;
            color_count[y]++;
            res.push_back(color_count.size());
        }
        return res;
    }
};
// @lc code=end


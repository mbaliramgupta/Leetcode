/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{-1,0},{1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         int m=isWater.size();
        int n=isWater[0].size();
        
        vector<vector<int>>heights(m,vector<int>(n,-1));
        queue<pair<int,int>>que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty()){
            int size=que.size();
            while(size--){
                auto temp=que.front();
                que.pop();
                int i=temp.first;
                int j=temp.second;

                for(auto &dir:directions){
                    int i_=i+dir[0];
                    int j_=j+dir[1];

                    if(i_>=0 && i_<m && j_>=0 && j_<n && heights[i_][j_]==-1){
                        heights[i_][j_]=heights[i][j]+1;
                        que.push({i_,j_});
                    }
                }
            }
        }
        return heights;
    }
};
// @lc code=end


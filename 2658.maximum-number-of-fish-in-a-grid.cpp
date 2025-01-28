/*
 * @lc app=leetcode id=2658 lang=cpp
 *
 * [2658] Maximum Number of Fish in a Grid
 */

// @lc code=start
class Solution {
public:
int n,m,res;
void dfs(int i,int j,vector<vector<int>>&grid,int &cnt,vector<vector<bool>>&vis){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0|| vis[i][j]){
                     return;
        }
        cnt+=grid[i][j];
        vis[i][j]=true;
        dfs(i+1,j,grid,cnt,vis);
        dfs(i-1,j,grid,cnt,vis);
        dfs(i,j+1,grid,cnt,vis);
        dfs(i,j-1,grid,cnt,vis);
    int findMaxFish(vector<vector<int>>& grid) {
         n=grid.size();
               m=grid[0].size();
               res=0;
               vector<vector<bool>>vis(n,vector<bool>(m,false));
              for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]>0){
                         int cnt=0;
                        dfs(i,j,grid,cnt,vis);
                        res=max(res,cnt);
                    }
                }
              }

     return res;
    }
};
// @lc code=end


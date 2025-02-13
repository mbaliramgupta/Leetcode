class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
            int operations=0;
    
            while(pq.size()>1 && pq.top()<k){
                   long long x=pq.top();pq.pop();
                   long long y=pq.top();pq.pop();
    
                   long long ans=(min(x,y)*2)+max(x,y);
                   pq.push(ans);
                   operations++;
            }
            return pq.top()>=k?operations:-1;
        }
    };
// 746. Min Cost Climbing Stairs

// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.
// Example 1:
// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:
// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.

// recursion
//tc O(2^N)
//space O(N)->stack call
class Solution {
public:

    int solve(int i,vector<int>& cost)
    {
        int n = cost.size();

        if(i>=n)
        return 0;

        int step_1 = solve(i+1,cost) + cost[i];
        int step_2 = solve(i+2,cost) + cost[i];

        return min(step_1,step_2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int start_0 = solve(0,cost);
        int start_1 = solve(1,cost);
        return min(start_0,start_1);
        
    }
};



//top-down
//time o(2*N)
//space o(n+1+n) ->stack call + size of do
class Solution {
public:

    int solve(int i,vector<int>& cost,vector<int>& dp)
    {
        int n = cost.size();

        if(i>=n)
        return 0;
        
        if(dp[i] !=-1)
        return dp[i];
        
        int step_1 = solve(i+1,cost,dp) + cost[i];
        int step_2 = solve(i+2,cost,dp) + cost[i];

        return dp[i] = min(step_1,step_2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        int start_0 = solve(0,cost,dp);
        int start_1 = solve(1,cost,dp);
        return min(start_0,start_1);
        
    }
};


//bottom-up - with vector dp
//time o(2n)
//space o(n+1)
class Solution {
public:

    int solve(vector<int>& cost, int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i-1] + cost[i-1],
                        dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        return solve(cost, n);
    }
};


//bottom up without vector dp
//time o(2n)
//space o(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
       int n =  cost.size();
       if(n==2)
       {
        return min(cost[0],cost[1]);
       }
       for(int i = 2;i<n;i++)
       {
        cost[i] = cost[i] + min(cost[i-1],cost[i-2]);
       }
       return  min(cost[n-1],cost[n-2]);
    }
};
// 198. House Robber
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Example 1:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

//recursion
//time o(2^n)
//space o(n)
class Solution {
public:
    int solve(vector<int>& nums,int i)
    {
        int n = nums.size();
        if(i>=n)
        return 0;

        int steal_current = nums[i] + solve(nums,i+2);
        int steal_next = solve(nums,i+1);
        return max(steal_current,steal_next);
    }
    int rob(vector<int>& nums) {
        int i=0;
        return  solve(nums,i);
    }
};


//top down
//time o(2*n)
//o(n+1+n)
class Solution {
public:
   int solve(int i,vector<int>& nums,vector<int>& dp)
   {
    int n = nums.size();
    if(i>=n)
    return 0;
 
    if(dp[i]!=-1)
    return dp[i];

    int steal_current = nums[i] + solve(i+2,nums,dp);
    int steal_next = solve(i+1,nums,dp);
    return dp[i] = max(steal_current,steal_next);
   }
    int rob(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(i,nums,dp);   
    }
};

// bottom up
//time o(n)
//o(n) => dp array space
class Solution {
public:
    int solve(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++)
        {
            int steal_current = nums[i - 1] + dp[i - 2];
            int skip_current = dp[i - 1];

            dp[i] = max(steal_current, skip_current);
        }

        return dp[n];
    }

    int rob(vector<int>& nums) {
        return solve(nums);
    }
};



// bottom up optimized
//time o(n)
//o(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;              
        if(n == 1) return nums[0];        
        if(n == 2) return max(nums[0], nums[1]);

        int prev = nums[0];
        int prev1 = max(nums[0], nums[1]);  

        for(int i = 2; i < n; i++) {
            int curr = max(prev1, nums[i] + prev);
            prev = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

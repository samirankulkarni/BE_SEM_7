#include <bits/stdc++.h>
using namespace std;

// 0/1 knapsack

int knapsack(int i,int n,vector<int> &weights,vector<int> &values,int capacity,vector<vector<int>> &dp){
    if(i == n || capacity == 0) return 0;
    if(dp[i][capacity] != -1) return dp[i][capacity];
    // if we could take we take
    int ans1 = INT_MIN;
    if(weights[i] <= capacity) ans1 = values[i] + knapsack(i+1,n,weights,values,capacity-weights[i],dp);
    int ans2 = knapsack(i+1,n,weights,values,capacity,dp);
    return dp[i][capacity] = max(ans1,ans2);
}

int main(){
    vector<int> weights = {95, 4, 60, 32, 23, 72, 80, 62, 65, 46};
    vector<int> values = {55, 10, 47, 5, 4, 50, 8, 61, 85, 87};
    int n = 10;
    int capacity = 269;

    vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));
    cout<<knapsack(0,n,weights,values,capacity,dp)<<'\n';

    return 0;
}
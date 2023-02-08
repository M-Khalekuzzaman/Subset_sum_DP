#include<bits/stdc++.h>
using namespace std;

const int N = 101;
const int M = 1e5 + 5;
int nums[N];
int dp[N][M];

int subSet_sum(int n,int target)
{
    // 1. Base case
    if(n == 0)
    {
        if(target == 0) return 1;
        return 0;
    }
    // 2. check dp state calculation
    if(dp[n][target] != -1)
    {
        return dp[n][target];
    }

    int ans1 = subSet_sum(n-1,target);
    if(target < nums[n])
    {
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = subSet_sum(n-1,target-nums[n]);
    int ans = ans1 || ans2;
    dp[n][target] = ans;

    return ans;

}
int main()
{
    int n,target;
    cin>>n>>target;

    for(int i = 1; i<=n; i++)
    {
        cin>>nums[i];
    }

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=target; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<subSet_sum(n,target)<<endl;

    return 0;
}

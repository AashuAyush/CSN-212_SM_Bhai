#include<bits/stdc++.h>
using namespace std;

int Compute(vector<int> &num, int n)
{
	vector<vector<int> > dp(n, vector<int>(2,0));
	dp[0][0] = dp[0][1] = 1;
	
	for(int i = 1;i < n;i++)
	{
		for(int j = 0;j < i;j++)
		{
			if(num[j] < num[i])
			{
				dp[i][0] = max(dp[i][0], dp[j][1]);
			}
			else if(num[j] > num[i])
			{
				dp[i][1] = max(dp[i][1], dp[j][0]);
			}
		}
		dp[i][0]++, dp[i][1]++;
	}
	
	for(int i = 0;i < n;i++)
	{
		dp[0][0] = max(dp[0][0], max(dp[i][0], dp[i][1]));
	}
	return dp[0][0];
}

int main()
{
	int n, answer = 0;
	scanf("%d", &n);
	vector<int> sequence(n);
	
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &sequence[i]);
	}
	answer = Compute(sequence, n);
	printf("%d\n", answer);
	return 0;
}

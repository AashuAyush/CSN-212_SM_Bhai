    #include<bits/stdc++.h>
    using namespace std;
     
    int lis(int *tmp, int id, int n){
    	vector<int> dp(n, 0);
    	int res = 0;
    	dp[0] = 1;
    	for(int i = id+1;i < id+n; i++){
    		for(int j = id;j < i;j++){
    			if(tmp[j] < tmp[i] && dp[i-id] < dp[j-id]){
    				dp[i-id] = dp[j-id];
    			}
    		}
    		dp[i-id]++;
    		if(res < dp[i-id])
    		    res = dp[i-id];
    	}
    	
    	return res;
    }
     
    int main(){
    	std::ios::sync_with_stdio(false);
    	int t,n,ans,d;
    	scanf("%d",&t);
    	while(t--){
    		ans = 0;
    		scanf("%d",&n);
    		int tmp[2*n];
    		vector<pair<int,int> > num(n);
    		
    		for(int i = 0;i < n;i++){
    			scanf("%d", &tmp[i]);
    			num[i].first = tmp[i];
    			num[i].second = i;
    			tmp[i+n] = tmp[i];
    		}
    		sort(num.begin(),num.end());
    		for(int i = 0;i < min(n, 37);i++)
    			ans = max(ans, lis(tmp,num[i].second,n));
    		printf("%d\n", ans);
    	}
    }  
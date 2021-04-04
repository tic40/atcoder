#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,k; string s;
  cin >> n >> k >> s;

  vector<int> nums;
  int cnt = 1;
  REP(i,n-1) {
    if (s[i+1] == s[i]) cnt++;
    else { nums.push_back(cnt); cnt=1; }
  }
  nums.push_back(cnt);

  vector<int> sum(nums.size()+1);
  REP(i,sum.size()-1) sum[i+1] = nums[i]+sum[i];

  int ans = 0;
  int st0 = s[0]=='0';
  REP(i,sum.size()) {
    int add = 2*k;
    if (st0) add += i%2;
    else add += i%2==0;

    int right = min(i+add, (int)sum.size()-1);
    ans = max(ans, sum[right]-sum[i]);
  }

  cout << ans << endl;
  return 0;
}
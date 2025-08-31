#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  vector<ll> dp(10);
  cin >> dp[0] >> dp[1];
  for(int i = 2; i < 10; i++) {
    string s = to_string(dp[i-1]+dp[i-2]);
    reverse(s.begin(),s.end());
    dp[i] = stoll(s);
  }
  cout << dp[9] << endl;
  return 0;
}
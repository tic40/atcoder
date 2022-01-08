#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n, ans = 0;

bool ok (ll x) {
  vector<int> cnt(10);
  while(0 < x) {
    cnt[x%10]++;
    x/=10;
  }
  return cnt[3] && cnt[5] && cnt[7];
}

void dfs(ll x) {
  if (n < x) return;
  if (ok(x)) ans++;
  for(int v: {3,5,7}) dfs(x*10+v);
}

int main() {
  cin >> n;
  for(int v: {3,5,7}) dfs(v);

  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll k; cin >> k;

  const int n = 50; // n を50に固定して考える
  vector<ll> ans(n,n);
  ll d = k % n;
  REP(i, n-d) ans[i] = 49 - d;

  ll add = k / n;
  REP(i,n) ans[i] += add; // 全ての要素に1回ずつ操作をすると全て均等に-1されるため

  cout << ans.size() << endl;
  for(ll v: ans) cout << v << " ";

  return 0;
}
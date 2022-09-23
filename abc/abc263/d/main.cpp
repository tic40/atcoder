#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,l,r;
  cin >> n >> l >> r;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[i][j] := i項までで、x,xでもyでもない,y の状態それぞれの総和最小値
  vector<ll> dp = {l,a[0],r};

  for(int i = 1; i < n; i++) {
    vector<ll> p(3);
    swap(dp,p);
    // xへの遷移
    dp[0] = p[0] + l;
    // xでもyでもない遷移
    dp[1] = min(p[0]+a[i], p[1]+a[i]);
    // yへの遷移
    dp[2] = min(p[1]+r, p[2]+r);
  }

  cout << *min_element(dp.begin(),dp.end()) << endl;
  return 0;
}
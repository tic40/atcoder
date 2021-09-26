#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll n,x;
vector<ll> a;

void solve() {
  ll sum = 0; // 一周の合計
  REP(i,n) sum += a[i];

  ll ans += n * (x/sum);
  ll cur = sum * (x/sum);
  REP(i,n) {
    if (x < cur) break;
    cur += a[i];
    ans++;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];
  cin >> x;

  solve();
  return 0;
}
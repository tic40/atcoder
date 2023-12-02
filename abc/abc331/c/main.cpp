#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  auto b = a;
  sort(b.begin(),b.end());
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+b[i];

  REP(i,n) {
    int idx = upper_bound(b.begin(),b.end(),a[i]) - b.begin();
    ll ans = s[n] - s[idx];
    cout << ans << " ";
  }
  return 0;
}
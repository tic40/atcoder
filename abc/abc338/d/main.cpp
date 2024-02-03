#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> x(m);
  REP(i,m) { cin >> x[i]; x[i]--; }

  vector<ll> d(n+1);

  auto add = [&](int l, int r, int x) {
    d[l] += x;
    d[r] -= x;
  };

  REP(i,m-1) {
    int s = x[i], t = x[i+1];
    if (s > t) swap(s,t);
    int a = t-s;
    int b = n-a;
    add(0,s,a);
    add(s,t,b);
    add(t,n,a);
  }
  REP(i,n) d[i+1] += d[i];
  ll ans = *min_element(d.begin(),d.begin()+n);
  cout << ans << endl;
  return 0;
}
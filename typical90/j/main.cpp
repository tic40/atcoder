#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n,q;
vector<int> c,p,l,r;

void solve() {
  // s1: クラス1, s2: クラス2 それぞれの累積和
  vector<ll> s1(n+1),s2(n+1);
  REP(i,n) {
    s1[i+1] = s1[i];
    s2[i+1] = s2[i];

    if (c[i]==1) s1[i+1]+=p[i];
    else s2[i+1]+=p[i];

  }

  REP(i,q) {
    cout << (s1[r[i]+1] - s1[l[i]]);
    cout << " ";
    cout << (s2[r[i]+1] - s2[l[i]]);
    cout << endl;
  }

  return;
}

int main() {
  cin >> n;
  c.resize(n);
  p.resize(n);
  REP(i,n) cin >> c[i] >> p[i];
  cin >> q;
  l.resize(q);
  r.resize(q);
  REP(i,q) {
    cin >> l[i] >> r[i];
    l[i]--; r[i]--;
  }

  solve();
  return 0;
}
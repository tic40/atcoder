#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  auto b = a;
  sort(b.begin(),b.end());
  map<int,int> mp;
  REP(i,n) mp[b[i]] = i;

  fenwick_tree<int> fw1(n);
  fenwick_tree<ll> fw2(n);

  ll ans = 0;
  REP(i,n) {
    int idx = mp[a[i]];
    int fw1sum = fw1.sum(0,idx);
    ll fw2sum = fw2.sum(0,idx);
    ans += (ll)a[i] * fw1sum - fw2sum;
    fw1.add(idx,1);
    fw2.add(idx,a[i]);
  }
  cout << ans << endl;
  return 0;
}
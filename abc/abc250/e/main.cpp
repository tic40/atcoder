#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  int q; cin >> q;

  vector<pair<ll,int>> ma(n+1), mb(n+1); // ma[i] = { i番目の集合の和, i番目の集合のサイズ }
  map<int,int> mp; // [i] = 最初にiが出た位置
  unordered_set<int> sa,sb;

  REP(i,n) {
    ma[i+1] = ma[i];
    mb[i+1] = mb[i];
    if (!sa.count(a[i])) {
      sa.insert(a[i]);
      ma[i+1].first += a[i];
      ma[i+1].second++;
      mp[a[i]] = i+1;
    }
    if (!sb.count(b[i])) {
      sb.insert(b[i]);
      mb[i+1].first += b[i];
      mb[i+1].second++;
    }
  }

  REP(i,q) {
    int x,y; cin >> x >> y;
    int pos = mp[b[0]];
    bool ok = ma[x] == mb[y] && 0 < pos && pos <= x;

    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}
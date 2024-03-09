#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct E {
  int from, to;
  E(int from=0, int to=0): from(from), to(to) {}
};

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  unordered_map<int,E> mp;
  mp[a[0]] = E{-1,a[1]};
  mp[a[n-1]] = E{a[n-2],-1};
  for(int i = 1; i < n-1; i++) mp[a[i]] = E{a[i-1],a[i+1]};

  int first = a[0];
  int q; cin >> q;
  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int x,y; cin >> x >> y;
      auto now = mp[x];
      mp[x].to = y;
      mp[y] = E{x,now.to};
      mp[now.to].from = y;
    } else {
      int x; cin >> x;
      auto now = mp[x];
      if (now.to != -1) { mp[now.to].from = now.from; }
      if (now.from != -1) {
        mp[now.from].to = now.to;
      } else {
        first = now.to;
      }
    }
  }

  int v = first;
  while(v != -1) { cout << v << " "; v = mp[v].to; }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n,h,m; cin >> n >> h >> m;
  vector<P> c;
  REP(i,n) {
    int a,b; cin >> a >> b;
    c.emplace_back(a,b);
  }

  map<int,int> mp;
  mp[h] = m;
  int ans = 0;
  for(auto [a,b]: c) {
    map<int,int> old;
    swap(mp,old);
    for(auto[k,v]: old) {
      if (k >= a) chmax(mp[k-a],v);
      if (v >= b) chmax(mp[k],v-b);
    }
    if (mp.size() == 0) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
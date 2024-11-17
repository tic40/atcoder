#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,q; cin >> n >> q;
  vector<int> cnt(n,1);
  map<int,P> mp; // <左端の位置, <右端の位置, 色>>
  REP(i,n) mp[i] = P(i,i);

  REP(_,q) {
    int t; cin >> t;
    if (t == 2) {
      int c; cin >> c; c--;
      cout << cnt[c] << endl;
      continue;
    }

    int x,c; cin >> x >> c; x--; c--;
    auto it = mp.upper_bound(x);
    it--;
    int l = it->first;
    auto [r,pc] = it->second;
    it = mp.erase(it);
    while(it != mp.begin()) {
      it--;
      if (it->second.second != pc) { it++; break; }
      l = it->first;
      it = mp.erase(it);
    }
    while(it != mp.end()) {
      if (it->second.second != pc) break;
      r = it->second.first;
      it = mp.erase(it);
    }
    mp[l] = P(r,c);
    cnt[pc] -= r-l+1;
    cnt[c] += r-l+1;
  }
  return 0;
}
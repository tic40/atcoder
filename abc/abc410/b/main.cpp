#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> cnt(n+1);
  cnt[0] = 1e9;
  REP(i,q) {
    int x; cin >> x;
    if (x == 0) {
      int idx = min_element(cnt.begin(),cnt.end()) - cnt.begin();
      cout << idx << " ";
      cnt[idx]++;
    } else {
      cout << x << " ";
      cnt[x]++;
    }
  }
  return 0;
}
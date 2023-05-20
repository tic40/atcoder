#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  map<int,int> mp;
  int r = 0, ans = 0;
  REP(l,n) {
    while(r < n) {
      if (!mp.count(a[r]) && (int)mp.size() == k) break;
      mp[a[r]]++;
      r++;
    }
    ans = max(ans,r-l);
    mp[a[l]]--;
    if (mp[a[l]] == 0) mp.erase(a[l]);
    if (r == l) r++;
  }

  cout << ans << endl;
  return 0;
}
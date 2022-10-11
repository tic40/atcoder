#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  map<int,int> mp;
  // sum: 種類の合計数
  int r = 0, sum = 0, ans = 0;
  REP(l,n) {
    while(r < n) {
      if (mp[a[r]] == 0) {
        if (sum == k) break;
        sum++;
      }
      mp[a[r]]++;
      r++;
    }
    ans = max(ans,r-l);
    mp[a[l]]--;
    if (mp[a[l]] == 0) sum--;
  }

  cout << ans << endl;
  return 0;
}
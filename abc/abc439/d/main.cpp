#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  map<int,vector<int>> mp;
  REP(i,n) mp[a[i]].push_back(i);

  ll ans = 0;
  REP(j,n) {
    if (a[j] % 5 != 0) continue;

    int ai = a[j] / 5 * 7, ak = a[j] / 5 * 3;
    if (mp.count(ai) == 0 || mp.count(ak) == 0) continue;

    auto itai = lower_bound(mp[ai].begin(), mp[ai].end(), j);
    auto itak = lower_bound(mp[ak].begin(), mp[ak].end(), j);
    // aj が min
    int rai = mp[ai].end() - itai;
    int rak = mp[ak].end() - itak;
    ans += (ll)rai * rak;
    // aj が max
    int lai = itai - mp[ai].begin();
    int lak = itak - mp[ak].begin();
    ans += (ll)lai * lak;
  }
  cout << ans << endl;
  return 0;
}

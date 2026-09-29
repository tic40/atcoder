#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> pa;
  REP(i,n) {
    int a,b; cin >> a >> b;
    pa.emplace_back(a,b);
  }
  sort(pa.begin(),pa.end(),[](P x, P y) {
    return x.first != y.first ? x.first < y.first : y.second < x.second;
  });

  vector<int> dp;
  REP(i,n) {
    auto it = lower_bound(dp.begin(),dp.end(),pa[i].second);
    if (it == dp.end()) dp.push_back(pa[i].second);
    else *it = pa[i].second;
  }
  cout << dp.size() << endl;
  return 0;
}

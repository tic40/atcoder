#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  vector<P> pb;
  REP(i,m) pb.emplace_back(b[i],i);
  sort(pb.rbegin(),pb.rend());

  vector<int> ans(m,-1);
  int cur = 0;
  REP(i,m) {
    while(cur < n) {
      if (a[cur] <= pb[i].first) {
        ans[pb[i].second] = cur+1;
        break;
      }
      cur++;
    }
  }
  for(auto v: ans) cout << v << endl;
  return 0;
}
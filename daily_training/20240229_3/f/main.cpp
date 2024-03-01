#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector<P> v;
  set<int> sa,sb;
  REP(i,n) {
    int a,b; cin >> a >> b; a--; b--;
    v.emplace_back(a,b);
    sa.insert(a); sb.insert(b);
  }
  auto f = [&](set<int>& st) {
    vector<int> res;
    for(auto v: st) res.push_back(v);
    return res;
  };
  auto va = f(sa);
  auto vb = f(sb);
  for(auto [a,b]: v) {
    auto na = lower_bound(va.begin(),va.end(),a) - va.begin() + 1;
    auto nb = lower_bound(vb.begin(),vb.end(),b) - vb.begin() + 1;
    cout << na << " " << nb << endl;
  }
  return 0;
}
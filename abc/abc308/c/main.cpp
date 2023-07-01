#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<pair<long double,int>> vp;
  REP(i,n) {
    long double a,b; cin >> a >> b;
    long double r = a / (a+b);
    vp.emplace_back(r,-i);
  }
  sort(vp.rbegin(),vp.rend());
  for(auto [_,v]: vp) cout << (-v+1) << " ";
  return 0;
}
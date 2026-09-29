#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> pa;
  REP(i,n) {
    int t; cin >> t;
    pa.emplace_back(t,i);
  }
  sort(pa.begin(),pa.end());
  REP(i,3) cout << pa[i].second + 1 << " ";
  return 0;
}

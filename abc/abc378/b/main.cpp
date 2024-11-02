#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> pa(n);
  REP(i,n) cin >> pa[i].first >> pa[i].second;
  int Q; cin >> Q;
  REP(i,Q) {
    int t,d; cin >> t >> d; t--;
    auto [q,r] = pa[t];
    cout << d + ((r-d) % q + q) % q << endl;
  }
  return 0;
}
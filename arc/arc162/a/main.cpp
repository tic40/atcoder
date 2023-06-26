#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int t; cin >> t;
  REP(_,t) {
    int n; cin >> n;
    vector<int> p(n);
    REP(i,n) cin >> p[i];
    int mn = INF, ans = 0;
    reverse(p.begin(),p.end());
    REP(i,n) {
      if (p[i] <= mn) { ans++; mn = p[i]; }
    }
    cout << ans << endl;
  }
  return 0;
}
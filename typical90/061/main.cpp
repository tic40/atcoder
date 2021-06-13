#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int q; cin >> q;
  int t,x;
  deque<int> d;

  REP(i,q) {
    cin >> t >> x;
    if (t == 1) {
      d.push_front(x);
    } else if (t == 2) {
      d.push_back(x);
    } else {
      cout << d[x-1] << endl;
    }
  }

  return 0;
}
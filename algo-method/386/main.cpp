#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m;
  cin >> n >> m;
  queue<int> a,b;
  REP(i,n) {
    int _; cin >> _;
    a.push(_);
  }
  REP(i,m) {
    int _; cin >> _;
    b.push(_);
  }
  a.push(INF); b.push(INF);

  REP(i,n+m) {
    if (a.front() < b.front()) {
      cout << a.front() << endl;
      a.pop();
    } else {
      cout << b.front() << endl;
      b.pop();
    }
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> x(n);
  REP(i,m) {
    int a; cin >> a;
    a--;
    x[a]++;
  }

  REP(i,n) cout << m - x[i] << endl;
  return 0;
}
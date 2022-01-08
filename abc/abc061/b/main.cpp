#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  int a,b;
  vector<int> G(n,0);
  REP(i,m) {
    cin >> a >> b;
    G[a-1]++; G[b-1]++;
  }
  REP(i,n) { cout << G[i] << endl; }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  vector<int> g(n);
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a]++; g[b]++;
  }

  int ok = false;
  REP(i,n) if (g[i] == n-1) ok = true;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
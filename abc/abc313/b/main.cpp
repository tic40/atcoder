#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> deg(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    deg[b]++;
  }

  vector<int> t;
  REP(i,n) if (deg[i] == 0) t.push_back(i+1);
  cout << (t.size() >= 2 ? -1 : t[0]) << endl;
  return 0;
}
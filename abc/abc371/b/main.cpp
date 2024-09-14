#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<bool> t(n);
  REP(i,m) {
    int a; char b; cin >> a >> b;
    a--;
    if (t[a] || b == 'F') cout << "No" << endl;
    else {
      cout << "Yes" << endl;
      t[a] = true;
    }
  }
  return 0;
}
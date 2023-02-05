#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,x;
  cin >> n >> x;
  bool ok = false;
  REP(i,n) {
    int a; cin >> a;
    if (a == x) ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
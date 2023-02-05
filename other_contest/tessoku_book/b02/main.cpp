#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b; cin >> a >> b;
  bool ok = false;
  for(int i = a; i <= b; i++) {
    if (100 % i == 0) ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
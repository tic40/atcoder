#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b; cin >> a >> b;
  if (a > b) swap(a,b);
  bool ok = b == 2*a || b == 2*a+1;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
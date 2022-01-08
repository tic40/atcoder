#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()

int main() {
  int n; cin >> n;
  if (n == 0 || n % 100) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
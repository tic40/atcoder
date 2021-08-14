#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; cin >> n;
  if (n <= 125) cout << 4;
  else if (n <= 211) cout << 6;
  else cout << 8;

  cout << endl;
  return 0;
}
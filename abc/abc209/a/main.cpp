#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int a,b; cin >> a >> b;
  cout << max(0, b - a + 1) << endl;
  return 0;
}
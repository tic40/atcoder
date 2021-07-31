#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int a,b; cin >> a >> b;

  if (0 < a && b == 0) cout << "Gold";
  else if (a == 0 && 0 < b) cout << "Silver";
  else cout << "Alloy";

  cout << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  cout << n << endl;
  REP(i,n) cout << i+1 << " " << (i+1)%n+1 << endl;
  return 0;
}
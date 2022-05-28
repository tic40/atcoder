#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  vector<int> a(3);
  REP(i,3) cin >> a[i];
  int b = a[1];
  sort(a.begin(),a.end());
  if(a[1] == b) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

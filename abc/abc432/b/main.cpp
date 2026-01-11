#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int x; cin >> x;
  vector<int> a;
  int zero = 0;
  while(x) {
    int v = x%10;
    if (v == 0) zero++;
    else a.push_back(v);
    x/=10;
  }
  sort(a.begin(),a.end());
  cout << a[0];
  REP(i,zero) cout << 0;
  for(int i = 1; i < (int)a.size(); i++) cout << a[i];

  return 0;
}
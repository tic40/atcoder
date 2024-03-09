#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> a;
  while(1) {
    int x; cin >> x;
    a.push_back(x);
    if (x == 0) break;
  }
  reverse(a.begin(),a.end());
  for(auto v: a) cout << v << endl;
  return 0;
}
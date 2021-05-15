#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

vector<int> convert_base(int n, int base=10) {
  vector<int> a;
  while(n) {
    // baseが負のときを考慮してabsを取る
    int m = abs(n%base);
    a.push_back(m);
    // baseが負のとき
    if (base < 0 && m) n--;
    n /= base;
  }
  reverse(a.begin(), a.end());
  return a;
}

int main() {
  int n; cin >> n;
  auto ans = convert_base(n, -2);

  if (ans.size()) for(int v: ans) cout << v;
  else cout << 0;

  cout << endl;

  return 0;
}
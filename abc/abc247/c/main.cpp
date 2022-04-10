#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int n;
vector<int> f(int x, vector<int> s) {
  if (n < x) return s;
  vector<int> ns = s;
  ns.push_back(x);
  for(int v: s) ns.push_back(v);
  return f(x+1, ns);
}

int main() {
  cin >> n;
  auto ans = f(2, {1});
  for(auto v: ans) cout << v << " ";
  return 0;
}
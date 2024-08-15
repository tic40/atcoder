#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  map<int,vector<int>> memo;
  memo[1] = { 1 };

  auto f = [&](auto self, int i) {
    if (memo.find(i) != memo.end()) return memo[i];
    vector<int> res;
    for(auto v: self(self,i-1)) res.push_back(v);
    res.push_back(i);
    for(auto v: self(self,i-1)) res.push_back(v);
    return memo[i] = res;
  };

  for(auto v: f(f,n)) cout << v << " ";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  string s; cin >> s;
  vector<P> vs;
  for(auto c: s) {
    if (vs.size() && vs.back().first == c) vs.back().second++;
    else vs.emplace_back(c,1);
  }
  for(auto [k,v]: vs) if (k == '-') cout << v << " ";
  return 0;
}
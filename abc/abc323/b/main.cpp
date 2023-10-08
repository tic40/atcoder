#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> cnt(n);
  REP(i,n) {
    string s; cin >> s;
    REP(j,n) if (s[j] == 'o') cnt[i]++;
  }

  vector<P> p(n);
  REP(i,n) p[i] = { cnt[i], -(i+1) };
  sort(p.rbegin(),p.rend());

  for(auto [_,v]: p) cout << -v << " ";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; string s; int q;
  cin >> n >> s >> q;
  vector<int> t(q),x(q);
  vector<char> c(q);
  P last = {0,0};
  REP(i,q) {
    cin >> t[i] >> x[i] >> c[i];
    x[i]--;
    if (t[i] != 1) last = {t[i],i};
  }

  auto f = [&](char c, int i) -> char {
    auto [t,li] = last;
    if (i <= li) {
      if (t == 2) return tolower(c);
      if (t == 3) return toupper(c);
    }
    return c;
  };

  REP(i,n) s[i] = f(s[i],0);
  REP(i,q) if (t[i] == 1) s[x[i]] = f(c[i],i);
  cout << s << endl;
  return 0;
}
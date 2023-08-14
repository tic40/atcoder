#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int q; cin >> q;
  vector<int> t(q),x(q);
  vector<char> c(q);
  int tl = -1;
  REP(i,q) {
    cin >> t[i] >> x[i] >> c[i];
    x[i]--;
    if (t[i] != 1) tl = i;
  }

  auto f = [&](char c, int i) {
    if (i < tl) {
      if (t[tl] == 2) c = tolower(c);
      if (t[tl] == 3) c = toupper(c);
    }
    return c;
  };

  REP(i,n) s[i] = f(s[i],0);
  REP(i,q) if (t[i] == 1) s[x[i]] = f(c[i],i);
  cout << s << endl;
  return 0;
}
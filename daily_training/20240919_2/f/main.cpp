#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  auto f = [&](string& s) {
    auto t = s;
    reverse(t.begin(),t.end());
    return t == s;
  };

  int top = 0,bottom = 0;
  REP(i,n) {
    if (s[i] == 'a') top++;
    else break;
  }
  reverse(s.begin(),s.end());
  REP(i,n) {
    if (s[i] == 'a') bottom++;
    else break;
  }
  reverse(s.begin(),s.end());

  string add = string(max(0,bottom-top),'a');
  s = add + s;
  cout << (f(s) ? "Yes" : "No") << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

ll base8_to_ll(string s) {
  ll res = 0;
  for(auto c: s) res = res * 8 + (c-'0');
  return res;
}

string ll_to_base9(ll x) {
  if (x == 0) return "0";
  string res = "";
  while(x > 0) {
    res = char(x % 9 + '0') + res;
    x /= 9;
  }
  return res;
}

int main() {
  string s; int k;
  cin >> s >> k;

  REP(_,k) {
    s = ll_to_base9(base8_to_ll(s));
    for(char& v: s) if (v == '8') v = '5';
  }
  cout << s << endl;
  return 0;
}
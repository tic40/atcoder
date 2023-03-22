#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

ll base_to_ll(int base, string s) {
  ll res = 0;
  for(auto c: s) res = res * base + (c-'0');
  return res;
}

string ll_to_base(int base, ll x) {
  if (x == 0) return "0";
  string res = "";
  while(x > 0) {
    res = char(x % base + '0') + res;
    x /= base;
  }
  return res;
}

int main() {
  string s; int k;
  cin >> s >> k;

  REP(_,k) {
    s = ll_to_base(9, base_to_ll(8,s));
    for(char& v: s) if (v == '8') v = '5';
  }
  cout << s << endl;
  return 0;
}
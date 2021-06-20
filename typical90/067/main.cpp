#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

// 8進数(string) to 10進数(ll)
ll base8_to_long(string s) {
  ll res = 0;
  REP(i,s.size()) {
    res = res * 8 + (s[i]-'0');
  }
  return res;
}

// 10進数(ll) to 9進数(string)
string long_to_base9(ll n) {
  if (n == 0) return "0";
  string res;
  while(n > 0) {
    res = char(n % 9 + '0') + res;
    n /= 9;
  }
  return res;
}

int main() {
  string s;
  int k;
  cin >> s >> k;

  REP(i,k) {
    s = long_to_base9(base8_to_long(s));
    REP(j,s.size()) if (s[j] == '8') s[j] = '5';
  }
  cout << s << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int k;

ll f(string s) {
  ll res = 0;
  for(char c: s) {
    res *= k;
    res += c - '0';
  }
  return res;
}

int main() {
  cin >> k;
  string a,b;
  cin >> a >> b;

  cout << f(a)*f(b) << endl;
  return 0;
}
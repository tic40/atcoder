#include <bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<(x)<<"\n"
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n; string t;
  cin >> n >> t;
  ll x = 1e10;

  if (t == "1") { COUT(2*x); return 0; }
  if (t == "11") { COUT(x); return 0; }

  string s;
  REP(i,100000) s+="110";
  int ok = 0;
  REP(i,3) if (s.substr(i,n) == t) ok = 1;
  if (!ok) { COUT(0); return 0; }

  int cntZero = 0;
  REP(i,n) if (t[i]=='0') cntZero++;

  if (t[n-1] == '0') {
    COUT(x - cntZero + 1);
  } else {
    COUT(x - cntZero);
  }

  return 0;
}
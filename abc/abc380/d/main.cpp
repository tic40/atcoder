#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  string s; int q; cin >> s >> q;
  int n = s.size();
  REP(_,q) {
    ll k; cin >> k; k--;
    char c = s[k%n];
    k/=n;
    int pcnt = 0;
    while(k) { pcnt+=k%2; k /= 2; }
    cout << char(pcnt%2 ? c^32 : c) << " ";
  }
  return 0;
}
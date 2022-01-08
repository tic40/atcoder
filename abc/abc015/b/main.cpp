#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n,a,s=0,bugs=0,ans=0;
  cin >> n;
  REP(i, n) {
    cin >> a;
    if (a == 0) continue;
    bugs+=a;
    s++;
  }
  cout << ceil((double)bugs/s) << endl;
}
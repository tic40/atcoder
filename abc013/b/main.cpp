#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;
  int cur = a, ansR = 0, ansB = 0;
  while(cur != b) {
    cur++;
    if (cur == 10) cur = 0;
    ansR++;
  }
  cur = a;
  while(cur != b) {
    cur--;
    if (cur == -1) cur = 9;
    ansB++;
  }
  cout << min(ansR, ansB) << endl;
}

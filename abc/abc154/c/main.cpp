#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n,x;
  cin >> n;
  map<int, int> m;
  REP(i,n) {
    cin >> x;
    m[x]++;
    if (m[x] >= 2) { cout << "NO" << endl; return 0; }
  }
  cout << "YES" << endl;
}
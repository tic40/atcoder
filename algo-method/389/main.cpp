#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> mem(101);
  REP(i,n) {
    int a; cin >> a;
    mem[a]++;
  }
  sort(mem.rbegin(),mem.rend());
  cout << mem[0] << endl;
  return 0;
}
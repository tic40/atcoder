#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

bool s(int n) {
  int d = n % 10;
  n /= 10;
  while(n > 0) {
    int nd = n % 10;
    if (d != nd) return false;
    n/=10;
    d = nd;
  }
  return true;
}

int main() {
  int n; cin >> n;
  for (int i = n; i <= 999; i++) {
    if (s(i) == true) { COUT(i); break; }
  }
  return 0;
}
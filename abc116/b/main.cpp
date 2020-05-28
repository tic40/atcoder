#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
#define YES(x) cout<<(x?"YES":"NO")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int f(int n) {
  return n%2 ? 3*n+1 : n/2;
}

int main() {
  int a[1000000];
  cin >> a[0];

  M m; m[a[0]] = 1;
  for(int i = 1; i <= 1000000; i++) {
    a[i] = f(a[i-1]);
    if (m[a[i]] == 1) { COUT(i+1); break; }
    m[a[i]]++;
  }
  return 0;
}

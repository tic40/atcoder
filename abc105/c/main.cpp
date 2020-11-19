#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;

  if (n == 0) { COUT(0); return 0; }

  vector<int> a;
  while(n != 0) {
    int tmp = n % 2;
    if (tmp < 0) tmp+=2;

    a.push_back(tmp);
    n = (n-tmp) / -2;
  }

  reverse(a.begin(), a.end());
  for(auto v: a) cout << v;
  cout << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  IOS;
  double N; cin >> N;
  for (double h = 1; h <= 3500; h++) {
    for (double n = 1; n <= 3500; n++) {
      // 4/N = 1/h + 1/n + 1/w
      // 4hnw = Nnw + Nhw + Nhn
      // w(4hn - Nn - Nh) = Nhn
      // w = Nhn / (4hn - Nn - Nh)
      double w = N*h*n / (4*h*n - N*n - N*h);
      if (0 < w && w <= 3500 && w == floor(w)) {
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }

  return 0;
}
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
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  double maxc = 0.0;
  int ansSuger=0,ansWater=0;
  for(int i=0; 100*a*i<=f; i++){
    for(int j=0; 100*a*i+100*b*j<=f; j++){
      int water=100*a*i+100*b*j;
      if (water == 0) continue;

      for(int k=0; water+c*k<=f; k++){
        for(int l=0; water+c*k+d*l<=f; l++){
          int suger = c*k+d*l;
          int weight = water+suger;
          if (water/100*e < suger) break; // 溶け残る
          double con = 100.0 * suger / weight;
          if (maxc <= con) {
            maxc = con;
            ansWater = water;
            ansSuger = suger;
          }
        }
      }
    }
  }
  cout << ansWater+ansSuger << " " << ansSuger << endl;
  return 0;
}
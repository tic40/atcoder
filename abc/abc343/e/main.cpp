#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const int L = 7;
// 3つの直方体が重なっている部分の面積を返す
int calcV3(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) {
  int minX = max({x1, x2, x3});
  int maxX = min({x1 + L, x2 + L, x3 + L});
  int minY = max({y1, y2, y3});
  int maxY = min({y1 + L, y2 + L, y3 + L});
  int minZ = max({z1, z2, z3});
  int maxZ = min({z1 + L, z2 + L, z3 + L});
  if (maxX - minX < 0 || maxY - minY < 0 || maxZ - minZ < 0) return 0;
  int v = (maxX - minX) * (maxY - minY) * (maxZ - minZ);
  return max(0,v);
}

// 2つの直方体が重なっている部分の面積を返す
int calcV2(int x1, int y1, int z1, int x2, int y2, int z2) {
  int minX = max(x1, x2);
  int maxX = min(x1 + L, x2 + L);
  int minY = max(y1, y2);
  int maxY = min(y1 + L, y2 + L);
  int minZ = max(z1, z2);
  int maxZ = min(z1 + L, z2 + L);
  if (maxX - minX < 0 || maxY - minY < 0 || maxZ - minZ < 0) return 0;
  int v = (maxX - minX) * (maxY - minY) * (maxZ - minZ);
  return max(0,v);
}

int main() {
  vector<int> v(3);
  REP(i,3) cin >> v[i];

  auto f = [&](int x2, int y2, int z2, int x3, int y3, int z3) {
    int x1 = 0, y1 = 0, z1 = 0;
    vector<int> nv(3);
    nv[2] = calcV3(x1,y1,z1, x2,y2,z2, x3,y3,z3);
    // 1-2, 1-3, 2-3 それぞれの組み合わせで重なっている部分の面積の合計 - 3つ重なっている部分の面積
    nv[1] = calcV2(x1,y1,z1, x2,y2,z2) + calcV2(x1,y1,z1, x3,y3,z3) + calcV2(x2,y2,z2, x3,y3,z3) - nv[2]*3;
    // 3つの合計面積 - 重なっている部分の面積
    nv[0] = (7*7*7*3) - (nv[1]*2 + nv[2]*3);
    return v == nv;
  };

  for(int i1 = -7; i1 <= 7; i1++) {
    for(int j1 = -7; j1 <= 7; j1++) {
      for(int k1 = -7; k1 <= 7; k1++) {
        for(int i2 = -7; i2 <= 7; i2++) {
          for(int j2 = -7; j2 <= 7; j2++) {
            for(int k2 = -7; k2 <= 7; k2++) {
              if (f(i1,j1,k1,i2,j2,k2)) {
                printf("Yes\n0 0 0 %d %d %d %d %d %d\n",i1,j1,k1,i2,j2,k2);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
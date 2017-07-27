#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<bitset>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<utility>
#include<iterator>
using namespace std;
int c, n, t, m, tmp;
int d[800][100][100];
int s[800];
int main(void) {
    cin>>c;
    while (c--) {
        cin>>n>>t>>m;
        int p=0;
        scanf("%d", s+p++);
        for (int i=1; i<n; i++) {
            scanf(", %d", s+p++);
        }
        memset(d, 0, sizeof(d));
        for (int i=0; i<n; i++) {
            for (int j=0; j<=m; j++) {
                for (int k=0; k<=t; k++) {
                    if (k<s[i]) {
                        d[i+1][j][k]=d[i][j][k];
                    } else {
                        d[i+1][j][k]=max(d[i][j][k], d[i][j][k-s[i]]+1);
                    }
                    if (j>0) {
                        d[i+1][j][k]=max(d[i+1][j][k], d[i][j-1][t-s[i]]+1);
                    }
                }
            }
            cout<<d[i+1][m][t]<<endl;
        }
        int r=0;
        for (int i=0; i<=n; i++) {
            r=max(r, d[i][m][0]);
        }
        cout<<r<<endl;
        if (c) {
            cout<<endl;
        }
    }
    return 0;
}
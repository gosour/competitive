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
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define SQR(n)                ( (n) * (n) )
const int INF = 1<<29;


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back

typedef vector<int> vi;
const int MOD = 1000000007;

int arr[100005];

const int UPPERBOUND = 1000005;
int factarr[UPPERBOUND];

void init(){
	factarr[1] = factarr[2] = 1;
	REP2(i,3,UPPERBOUND-1){
		factarr[i] = ((long long)factarr[i-1] + factarr[i-2])%MOD;
	}
}

int calcFact(int n){
	if(n<UPPERBOUND) return factarr[n];
	else return (calcFact(n-1)+(long long)calcFact(n-2))%MOD;
}

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int n,q;

int fact(int n){
	if(n==1 || n == 2) return 1;
	else return fact(n-1) + fact(n-2);
}

int findGCD(int l, int r){
	int mn;
	REP2(i,l,r) {
		if(i==l) mn = arr[l];
		else mn = min(arr[i],mn);
	}
	int mult = 1;
	if(mn == 1 || mn == 2 || l == r) return 1;
	int fmn = calcFact(mn);
	// DEBUG(mn);
	// DEBUG(fmn);
	REP2(i,l,r){
		// DEBUG(i);
		if(arr[i] == mn) continue;
		int diff = (arr[i] - mn);
		// DEBUG(diff-1);
		if(diff == 1) {
			mult = 1;
			break;
		}
		else{
			diff = diff - 1;
			// DEBUG(fmn%diff);
			if(fmn%diff == 0 || diff%fmn == 0){
				mult = ((long long)mult*(diff) )%MOD;
			}
			else{
				mult = 1; break;
			}
		}
	}
	if(mult == 1) return 1;
	// DEBUG(mult);
	int div = get_fibonacci_huge(fmn+1,mult);
	// DEBUG(div);
	if(div == 0 || div == fmn) return min(fmn,mult);
	else return 1;

}

int main(){
	cin>>n>>q;
	init();
	REP2(i,1,n) cin>>arr[i];
	REP(i,q){
		int l,r; cin>>l>>r;
		cout<<findGCD(l,r)<<endl;
	}
}
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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)

int INT(char a){
	return (int)a - (int)'0';
}
char CHAR(int a){
	return (char)a + '0';
}
string TOSTRING(int a){
	string ans = "";
	while(a){
		ans = CHAR(a%10) + ans;
		a /= 10;
	}
	return ans;

}

int modulo(int a, string b){
	int ans = 0;
	REP(i,b.length()){
		ans = (ans*10 + INT(b[i])) % a;
	}
	return ans;
}

string gcd(int a, string b){
	if(a == 0)  return b;
	else{
		return gcd(modulo(a,b),TOSTRING(a));
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		int a; string b;
		cin>>a; cin>>b;
		cout<< gcd(a,b) <<endl;
	}
}
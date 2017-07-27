#include<bitset>
#include<vector>
#include<cstdio>
using namespace std;

int circle[20];
bool used[20];

bool is_prime(int p){
	for(int i=2;i<=sqrt(p);i++) if(p%i == 0) return false;
	return true;
}

void search(int m){
	if(m == n-1 && is_prime(circle[n-1] + circle[n])){
		 for(int i = 0; i < n; i++)
            printf(i == n - 1? "%d" : "%d ", circle[i]);
        printf("\n");
        return;
	}
	for(int i=2;i<=n; i++){
		if(!used[i] && is_prime(circle[m] + i)){
			used[i] = true;
			circle[m+1] = i;
			search(m+1);
			used[i] = false;
		}
	}
}

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		circle[0] = circle[n] = 1;
		search(0);
	}
}
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

void decode_huff(node * root,string s)
{
    int index = 0;
    int len = s.length();
    node *temp = root;
    while(index < len){
        if(temp->left == NULL && temp->right == NULL){ //if child node
            cout<<temp->data;
            index++;  
            temp = root;
            continue;
        }
        if(s[index] == '0'){ //move left
            temp = temp->left;
            index++;
        }
        if(s[index] == '1'){ //move right
            temp = temp->right;
            index++;
        }
    }
    
}

int main(){
	
}
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
#include<sstream>
using namespace std;
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define SQR(n)                ( n * n )
const int INF = 1<<29;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back
typedef vector<int> vi;
map<string,int> wordDict;
map<int, string> oppDict;
vector< vector<string> > lengthDict;
vector< vector<int> > adjacencyList;
int visited[10005];

bool dist(string a, string b){
	// cout<<"Calculating diff between : "<<a<<" "<<b<<endl;
	int diffCount = 0;
	for(int i=0;i<a.length();i++)
		if(a[i]!=b[i]) diffCount++;
	if(diffCount == 1) return true;
	else return false;
}

void createGraph(string s){
	int len = s.length();
	vector<string> currentNodes = lengthDict[len];
	for(int i=0;i<currentNodes.size();i++){
		for(int j=0;j<currentNodes.size();j++){
			if(i==j) continue;
			if(dist(currentNodes[i],currentNodes[j])){
				int u = wordDict[currentNodes[i]];
				int v = wordDict[currentNodes[j]];
				adjacencyList[u].pb(v);
				// cout<<currentNodes[i]<<" & "<<currentNodes[j]<<endl;
			}
		}
	}
}

int bfs(string source, string dest){
	if(source == dest) return 0;
	queue<int> q;
	q.push(wordDict[source]);
	visited[wordDict[source]] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i=0;i<adjacencyList[u].size();i++){
			int v = adjacencyList[u][i];
			if(visited[v]<0){
				visited[v] = visited[u]  + 1;
				string s = oppDict[v];
				if(dest == s){
					return visited[v];
				}
				q.push(v);
			}
		}
	}
	return -1;
}

int main(){
	int tests; scanf("%d",&tests);
	string empty; getline(cin,empty);

	getchar();
	REP(t,tests){
		string word;
		int count = 0;
		lengthDict.clear(); lengthDict.resize(12);
		while(cin>>word && word!="*"){
			wordDict[word] = count;
			oppDict[count++] = word;
			lengthDict[word.length()].pb(word);
		}
		string line;
		adjacencyList.clear(); adjacencyList.resize(count+1);
		if(t > 0) cout<<endl;
		getline(cin,line);
		while(getline(cin,line) && line.size() > 0){
			string source, dest;
			istringstream ss(line);
			ss>>source>>dest;
			createGraph(source);
			memset(visited,0xff,sizeof(visited));
			int ans = 0;
			ans = bfs(source,dest);
			cout<<source<<" "<<dest<<" "<<ans<<endl;
		}
	}	
}
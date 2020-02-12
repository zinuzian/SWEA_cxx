#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int way[2][100];
int visited[100]= {0};
int dfs(int node){
    int ret = 0;
    if(node == 99){
        return 1;
    }
    if(visited[node]){
        return 0;
    }
    visited[node] = 1;
    for(int i=0;i<2;i++){
        if(way[i][node] != -1){
            ret |= dfs(way[i][node]);
        }
    }
    return ret;
}


int main(int argc, char** argv)
{
	int test_case;
	int T=10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	// cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer=0;
        int t, n;
        cin >> t >> n;
        memset(visited,0,100*sizeof(int));
        memset(way[0],-1,100*sizeof(int));
        memset(way[1],-1,100*sizeof(int));
        int s,e;

        for(int i=0;i<2*n;i+=2){
            cin >> s >> e;
            if(way[0][s] >=0)
                way[1][s] = e;
            else{
                way[0][s] = e;
            }
        }

        answer = dfs(0);    

        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}
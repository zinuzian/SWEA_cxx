#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
int answer;
int n, m;
int adjMat[10][10];
bool visited[10];

void init()
{
    memset(adjMat, 0, sizeof(int) * 10 * 10);
    memset(visited, 0, sizeof(bool) * 10);
    answer = 0;
}

void dfs(int v, int cnt)
{
    if(cnt > answer){
        answer = cnt;
    }
    for(int i=0;i<n;i++){
        if(v != i && adjMat[v][i] == 1 && !visited[i]){
            visited[i] = true;
            dfs(i, cnt+1);
            visited[i] = false;
        } 
    }
}

int main(int argc, char const *argv[])
{
    int T = 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        init();
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int t1, t2;
            cin >> t1 >> t2;
            adjMat[t1-1][t2-1] = 1;
            adjMat[t2-1][t1-1] = 1;
        }
        for(int i=0;i<n;i++){
            visited[i] = true;
            dfs(i,1);
            visited[i] = false;
        }
        
        cout << "#" << test_case << " " << answer << endl;
    }
}
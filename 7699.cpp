#include <iostream>
#include <cstring>
using namespace std;
int answer;
int r,c;
int visited[26];
char map[20][20];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void init()
{
    memset(visited, 0, sizeof(int) * 26);
    memset(map, 0, sizeof(char) * 20 * 20);
    answer = 0;
}

void dfs(int y, int x, int cnt){
    visited[map[y][x] - 'A'] = 1;
    if(cnt > answer){
        answer = cnt;
    }
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if( ny >= 0 && ny < r && 
            nx >= 0 && nx < c && 
            !visited[map[ny][nx]-'A']){
            dfs(ny, nx, cnt+1);
        }
        
    }
    visited[map[y][x] - 'A'] = 0;
    
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
        cin >> r >> c;

        for(int y=0;y<r;y++){
            for(int x=0;x<c;x++){
                cin >> map[y][x];
            }
        }
        dfs(0,0,1);
        
        cout << "#" << test_case << " " << answer << endl;
    }
}
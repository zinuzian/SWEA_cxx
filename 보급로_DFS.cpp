#include <iostream>
#include <cstring>
 
using namespace std;
int answer;
int n;
int map[100][100];
int dp[100][100];
bool visited[100][100];
char line[101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
 
void greedy(int y, int x, int temp){
    if(y == n-1 && x == n-1){
        answer = temp;
        return;
    }
    int min = -1;
    int nx, ny;
    for(int i=1;i<3;i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx >= 0 && nx < n 
        && ny >= 0 && ny < n){
            if(min == -1){
                min = i;
            }
            else if(map[y+dy[min]][x+dx[min]] > map[ny][nx]){
                min = i;
            }
        }
    }
    nx = x + dx[min];
    ny = y + dy[min];
    visited[ny][nx] = true;
    greedy(ny,nx,temp+map[ny][nx]);
    visited[ny][nx] = false;
    return;
}
 
void backtrack(int y, int x, int temp){
    if(dp[y][x] == -1){
        dp[y][x] = temp;
    }else{
        if(dp[y][x] > temp){
            dp[y][x] = temp;
        }else{
            return;
        }
    }
     
    if(y == n-1 && x == n-1){
        if(answer > temp){
            answer = temp;
        }
        return;
    }
     
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n 
        && ny >= 0 && ny < n 
        && !visited[ny][nx] 
        && temp + map[ny][nx] < answer){
           visited[ny][nx] = true;
            backtrack(ny, nx, temp + map[ny][nx]);
            visited[ny][nx] = false;
        }
    }
 
    return;
}
void init(){
    memset(visited, 0, sizeof(bool)*100*100);
    memset(line, 0, sizeof(char)*101);
    memset(dp, -1, sizeof(int)*100*100);
}
 
 
int main(int argc, char const *argv[])
{
    int T= 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        init();
        cin >> n;
        for(int i=0;i<n;i++){
 
            cin >> line;
            int t=0;
            while(line[t]){
                map[i][t] = (int)(line[t]-'0');
                t += 1;
            }
        }
        greedy(0,0,0);
        backtrack(0,0,0);
        cout << "#" << test_case << " " << answer << endl;
    }
}
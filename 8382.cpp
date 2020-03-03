#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define HOR 0
#define VER 1
using namespace std;
typedef struct pos{
    int y;
    int x;
    int dir;
    int cnt;
} POS;
int answer;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<POS> que;
bool visited[201][201][2];

int sy, sx, ey, ex;


void init()
{
    while(que.size() != 0){
        que.pop();
    }
    answer = 2147483647;
    memset(visited, 0, sizeof(bool)*201*201*2);
}

void bfs(){
    while(que.size() != 0){
        POS curr = que.front();
        que.pop();
        visited[curr.y][curr.x][curr.dir] = true;
        if(curr.y == ey && curr.x == ex){
            if(curr.cnt < answer){
                answer = curr.cnt;
            }
            return;
        }
        if(curr.dir == VER){
            for(int i=1;i<4;i+=2){
                int ny = curr.y + dy[i];
                int nx = curr.x + dx[i];    
                if(!visited[ny][nx][HOR]){
                    POS next = {ny, nx, HOR, curr.cnt+1};
                    que.push(next);
                }
            }
        }else{
            for(int i=0;i<4;i+=2){
                int ny = curr.y + dy[i];
                int nx = curr.x + dx[i];    
                if(!visited[ny][nx][VER]){
                    POS next = {ny, nx, VER, curr.cnt+1};
                    que.push(next);
                }
            }
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
        
        cin >> sx >> sy >> ex >> ey;
        init();
        sx += 100; sy += 100; ex += 100; ey += 100; 
        POS temp1 = {sy, sx, HOR, 0};
        que.push(temp1);
        bfs();

        init();
        POS temp2 = {sy, sx, VER, 0};
        que.push(temp2);
        bfs();

        cout << "#" << test_case << " " << answer << endl;
    }
}
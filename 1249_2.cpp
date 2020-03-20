#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

#define INF 0x7fffffff

using namespace std;
int answer;
int n;
int map[100][100];
int dist[100][100];
bool visited[100][100];
char line[101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void init(){
    memset(line, 0, sizeof(char)*101);
    memset(visited, 0, sizeof(bool)*100*100);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = INF;
        }
    }
}

int dijkstra() {
    // min heap
    priority_queue<pair<int, pair<int, int>>> pq;
    dist[0][0] = 0;

    pq.push({ 0,{0,0} });
    while (!pq.empty()) {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
 
        if (y == n - 1 && x == n- 1) {
            break;
        }
        if (visited[y][x]) {
            continue;
        }

        visited[y][x] = true;
 
        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i], nx = x + dx[i];

            if (ny >= 0 && nx >= 0 && ny < n && nx < n
                && dist[ny][nx] > dist[y][x] + map[ny][nx]){
                
                dist[ny][nx] = dist[y][x] + map[ny][nx];
                pq.push({ -dist[ny][nx],{ny,nx} });

            }
        }
    }
    return dist[n-1][n-1];
}


int main(int argc, char const *argv[])
{
    int T= 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin >> n;
        init();
        for(int i=0;i<n;i++){

            cin >> line;
            int t=0;
            while(line[t]){
                map[i][t] = (int)(line[t]-'0');
                t += 1;
            }
        }
        answer = dijkstra();
        cout << "#" << test_case << " " << answer << endl;
    }
}




#include <iostream>
#include <cstring>
#define INF 0x7fffffffffffffff
using namespace std;
long long answer;
int n;
double e;
long long px[1000], py[1000];
double adj[1000][1000];

///////////////////////////////// Prim /////////////////////////////////
long long g[1000];
bool visited[1000];

int extract_min(){
    long long min = INF;
    int min_idx = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && min > g[i]){
            min = g[i];
            min_idx = i;
        }
    }
    return min_idx;
}

double MST_Prim(int r){
    for(int u=0;u<n;u++){
        g[u] = INF;
    }
    g[r] = 0;
    int next;
    while((next = extract_min()) != -1){
        for(int i=0;i<n;i++){
            if(!visited[i] && adj[next][i] != 0 && adj[next][i] < g[i]){
                g[i] = adj[next][i];
            }
        }
        visited[next] = true;
    }

    double s = 0;
    for(int i=0;i<n;i++){
        s += e * g[i];
    }
    return s;

}
///////////////////////////////// Prim /////////////////////////////////

void calcDist(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            adj[i][j] = ((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]));
            adj[j][i] = adj[i][j];
        }
    }
}

void init(){
    memset(adj, 0, sizeof(long long)*1000*1000);
    memset(visited, 0, sizeof(bool)*1000);
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
        init(); 
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> px[i];
        }
        for(int i=0;i<n;i++){
            cin >> py[i];
        }
        cin >> e;
        calcDist();
        answer = (long long)(MST_Prim(0)+0.5);
        cout << "#" << test_case << " " << answer << endl;
    }
}
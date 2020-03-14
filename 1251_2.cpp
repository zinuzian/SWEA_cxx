#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 0x7fffffffffffffff

using namespace std;

long long answer;
int n;
double e;
long long px[1000], py[1000];
double adj[1000][1000];

///////////////////////////////// Kruskal /////////////////////////////////
class Edge{
    public:
    int node[2];
    long long dist; 
    Edge(int  x, int y, long long distance){
        this->node[0] = x;
        this->node[1] = y;
        this->dist = distance;
    }
    bool operator<(const Edge &e) const{
        return this->dist < e.dist;
    }
};


int parent[1000], Rank[1000];
vector<Edge> v;

void make_set(int x){
    parent[x] = x;
    Rank[x] = 0;
}

int find_set(int x){
    if(x != parent[x]) parent[x] = find_set(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    int px = find_set(x);
    int py = find_set(y);

    if(Rank[px] > Rank[py]){
        parent[py] = x;
    }else{
        parent[px] = y;
        if(Rank[px] == Rank[py]){
            Rank[py]++;
        }
    }

}

void calcDist(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            adj[i][j] = ((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]));
            adj[j][i] = adj[i][j];
            v.push_back(Edge(i,j,adj[i][j]));
        }
    }
}

double MST_Kruskal(){
    calcDist();
    sort(v.begin(), v.end());
    // qsort(&v[0], v.size(), sizeof(Edge), comparer);

    double s=0;
    for(int i=0;i<v.size();i++){
        if(find_set(v[i].node[0]) != find_set(v[i].node[1])){
            s += e * v[i].dist;
            Union(v[i].node[0], v[i].node[1]);
        }
    }
    return s;
}

///////////////////////////////// Kruskal /////////////////////////////////



void init(){
    memset(adj, 0, sizeof(long long)*1000*1000);
    for(int i=0;i<1000;i++){
        parent[i] = i;
    }
    memset(Rank, 0, sizeof(int) * 1000);
    v.clear();
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
        answer = (long long)(MST_Kruskal()+0.5);
        cout << "#" << test_case << " " << answer << endl;
    }
}
#include <iostream>
#define INF 0x7fffffff
#define MAX_SIZE 8

using namespace std;
int g[MAX_SIZE];
bool isIncluded[MAX_SIZE] = {0};
int adj[MAX_SIZE][MAX_SIZE] = {
    {0, 32, 31, 0, 0, 54, 30, 0},
    {32, 0, 21, 0, 0, 0, 0, 0},
    {31, 21, 0, 0, 46, 0, 25, 0},
    {0, 0, 0, 0, 34, 28, 0, 0},
    {0, 0, 0, 34, 0, 40, 51, 29},
    {54, 0, 0, 28, 40, 0, 0, 0},
    {30, 0, 25, 0, 51, 0, 0, 20},
    {0, 0, 0, 0, 29, 0, 20, 0}
};
int extract_min(){
    int min = INF;
    int min_idx = -1;
    for(int i=0;i<MAX_SIZE;i++){
        if(!isIncluded[i] && min > g[i]){
            min = g[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int sum(){
    int s = 0;
    for(int i=0;i<MAX_SIZE;i++){
        s += g[i];
    }
    return s;
}
void MST_Prim(int r){
    for(int u=0;u<MAX_SIZE;u++){
        g[u] = INF;
    }
    g[r] = 0;
    int next;
    while((next = extract_min()) != -1){
        for(int i=0;i<MAX_SIZE;i++){
            if(!isIncluded[i] && adj[next][i] != 0 && adj[next][i] < g[i]){
                g[i] = adj[next][i];
            }
        }
        isIncluded[next] = true;
    }
}


int main(int argc, char const *argv[])
{
    MST_Prim(0);
    cout << sum() << endl;
    return 0;
}

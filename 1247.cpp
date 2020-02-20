#include <iostream>
#include <iomanip>
#include <cstring>
#define ABS(x) (x>=0)? x:-x;
using namespace std;
int n;
int answer=0;
int xpos[12];
int ypos[12];
int dist[12][12];
int perm[10];

void init(){
    for(int i=0;i<10;i++){
        perm[i] = i;
    }
    answer = 0;
}
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calcDist(){
    for(int i=0;i<n+1;i++){
        for(int j=i+1;j<n+2;j++){
        
            dist[i][j] = ABS(xpos[i]-xpos[j]) + ABS(ypos[i]-ypos[j]);
            dist[j][i] = dist[i][j];
            
        }
    }
}

void calculate(){
    int ret=0;
    for(int i=0;i<n-1;i++){
        ret += dist[perm[i]][perm[i+1]];
    }
    ret += dist[perm[0]][n+1];
    ret += dist[perm[n-1]][n];
    if(ret > answer){
        answer = ret;
    }
}

void permutation(int nth){
    if(nth == 1){
        // for(int i=0;i<n;i++){
        //     cout << perm[i] << " ";
        // }
        // cout << endl;
        calculate();
    }else{
        for(int i=0;i<nth-1;i++){
            swap(&perm[i], &perm[nth-1]);
            permutation(nth-1);
            swap(&perm[i], &perm[nth-1]);
        }
    }
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
        for(int i=n+1;i>=0;i--){ cin >> xpos[i] >> ypos[i]; }
        calcDist();
        permutation(n);
        cout << "#" << test_case << " " << answer << endl;
    }
}
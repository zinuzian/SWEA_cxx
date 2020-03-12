#include <iostream>
#include <cstring>

using namespace std;
double answer;
int n;
long long px[1000], py[1000];
long long map[1000][1000];
void prim_algo(){

}
void calcDist(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            map[i][j] = (px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]);
            map[j][i] = map[i][j];
        }
    }
}

void init(){
    memset(map, 0, sizeof(long long)*1000*1000);
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
        calcDist();

        cout << "#" << test_case << " " << answer << endl;
    }
}
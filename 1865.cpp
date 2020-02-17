#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

int arr[16][16];
double answer = 0.0;
int perm[16];
bool used[16];
void init(int n){
    memset(perm, 0, sizeof(int)*16);
    memset(used, 0, sizeof(bool)*16);
    memset(arr, 0, sizeof(int)*16*16);
    answer = 0.0;
}

void genPerm(int n, int remain, double now){
    double ret = 1.0;
    if(remain == 0){
        if(now > answer){
            answer = now;
        } 
    }else{
        for(int i=0;i<n;i++){
            if(!used[i] && arr[n-remain][i] != 0){
                double temp = now*arr[n-remain][i]/100.0;
                if(temp >= answer){
                    used[i] = true;
                    genPerm(n, remain-1, temp);
                    used[i] = false;
                }
                
            }
        }
    }

}

int main(int argc, char const *argv[])
{
    int T = 10;
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    cin >> T;
    for(int test_case = 1;test_case <=T;test_case++){
        
        int n;
        cin >> n;   
        init(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
            }
        }
        genPerm(n, n, 1.0); 
        answer = round(answer * 100000000)/1000000.0;
        cout.precision(6);
        cout.fill(0);
        cout << "#" << test_case << " " << fixed << setprecision(6);
        cout << answer << endl;
    }
    return 0;
}

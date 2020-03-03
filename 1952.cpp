#include <iostream>
#include <cstring>
#define MIN(x,y) (x<y)? x:y

using namespace std;
int answer[13];
int fare[4];
int plan[13];
void dp(){
    for(int i=1;i<13;i++){
        if(i>=3){
            answer[i] = MIN(answer[i-1] + fare[0]*plan[i], 
                            answer[i-1] + fare[1]);
            answer[i] = MIN(answer[i], 
                            answer[i-3] + fare[2] );
        }else{
            answer[i] = MIN(answer[i-1] + fare[0]*plan[i], 
                            answer[i-1] + fare[1] );
        }
    }
}

int main(int argc, char const *argv[])
{
    int T= 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        memset(answer, 0, sizeof(int)*13);
        for(int i=0;i<4;i++){ 
            cin >> fare[i];
        }
        for(int i=1;i<13;i++){ 
            cin >> plan[i];
        }
        dp();
        if(answer[12] > fare[3])
            answer[12] = fare[3];

        cout << "#" << test_case << " " << answer[12] << endl;
    }
    return 0;
}
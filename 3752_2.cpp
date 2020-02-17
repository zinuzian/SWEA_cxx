#include <iostream>
#include <cstring>
using namespace std;
bool possibleScoreAsc[10001]={true,};
void init(){
    memset(possibleScoreAsc+sizeof(char), false, sizeof(char)*10000);
}

int main(int argc, char const *argv[])
{
    int T = 10;
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case =1;test_case <= T;test_case++){
        init();
        int N;
        cin >> N;
        int last =0;
        for(int i=0;i<N;i++){
            int temp;
            cin >> temp;
            bool temp_possible[10001];
            memcpy(temp_possible,possibleScoreAsc, sizeof(char)*(last+1));
            for(int j=0;j<=last;j++){
                if(temp_possible[j]){
                    possibleScoreAsc[temp+j] = true;
                }
            }
            last += temp;
        }
        int answer = 0;
        for(int j=0;j<=last;j++){
            if(possibleScoreAsc[j]) answer++;
        }
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}

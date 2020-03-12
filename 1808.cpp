#include <iostream>
#include <cstring>


using namespace std;
int answer, target;
int availNums[10];
int dp[1000001];
void init(){
    for(int i=0;i<1000001;i++){
        dp[i] = 2147483647;
    }
}
int min(int x, int y){
    return (x<y)? x:y;
}
int genNum(int n, int cnt){
    if(n == 0){
        return cnt;
    }
    int ret=2147483647;
    for(int i=0;i<10;i++){
        if(availNums[i]==1 && n%10 == i){
            ret = genNum(n/10, cnt+1);
            if(ret != 2147483647) break;
        }
    }
    return ret;
}
int findFactor(int n){
    if(dp[n] != 2147483647){
        return dp[n];
    }
    int ret = 0;
    for(int i=n-1;i>1;i--){
        if(n % i == 0 && dp[i] != 2147483647){
            ret = dp[i] + findFactor(n/i);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 10;

    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int tc=0;tc<T;tc++){
        init();
        for(int i=0;i<10;i++){
            cin >> availNums[i];
            if(availNums[i] == 1){
                dp[i] = 1;
            }
        }
        cin >> target;
        answer = 2147483647;
        
        for(int i=10;i<=target;i++){
            if(target%i==0){
                dp[i] = min(genNum(i,0), findFactor(i));
            }
            
        }

        if (dp[target] == 2147483647){
            answer = -1;
        }else{
            answer = dp[target];
        }

        cout << "#" << tc << " " << answer << endl;
    }



    return 0;
}

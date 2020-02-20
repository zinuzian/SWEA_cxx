#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
char arr[2000][2000];
int w,h;
bool hasCode[2000];

void init(){
    memset(arr, '0', sizeof(char)*2000*2000);
    memset(hasCode, false, sizeof(bool)*2000);
}

int toBinary(char* str, int i){
    for(int j=w-1;j>=0;j--){
        switch(str[j])
        {
            case '0': break;
            case '1': memcpy(&arr[i][j*4], "0001", sizeof(char)*4);hasCode[i]=true;break;
            case '2': memcpy(&arr[i][j*4], "0010", sizeof(char)*4);hasCode[i]=true;break;
            case '3': memcpy(&arr[i][j*4], "0011", sizeof(char)*4);hasCode[i]=true;break;
            case '4': memcpy(&arr[i][j*4], "0100", sizeof(char)*4);hasCode[i]=true;break;
            case '5': memcpy(&arr[i][j*4], "0101", sizeof(char)*4);hasCode[i]=true;break;
            case '6': memcpy(&arr[i][j*4], "0110", sizeof(char)*4);hasCode[i]=true;break;
            case '7': memcpy(&arr[i][j*4], "0111", sizeof(char)*4);hasCode[i]=true;break;
            case '8': memcpy(&arr[i][j*4], "1000", sizeof(char)*4);hasCode[i]=true;break;
            case '9': memcpy(&arr[i][j*4], "1001", sizeof(char)*4);hasCode[i]=true;break;
            case 'A': memcpy(&arr[i][j*4], "1010", sizeof(char)*4);hasCode[i]=true;break;
            case 'B': memcpy(&arr[i][j*4], "1011", sizeof(char)*4);hasCode[i]=true;break;
            case 'C': memcpy(&arr[i][j*4], "1100", sizeof(char)*4);hasCode[i]=true;break;
            case 'D': memcpy(&arr[i][j*4], "1101", sizeof(char)*4);hasCode[i]=true;break;
            case 'E': memcpy(&arr[i][j*4], "1110", sizeof(char)*4);hasCode[i]=true;break;
            case 'F': memcpy(&arr[i][j*4], "1111", sizeof(char)*4);hasCode[i]=true;break;
        }
    }
}

void setZero(int i, int end, int mul){
    int cnt=0;
    while(arr[i+cnt][end] == '1'){
        cnt++;
    }
    for(int k=0;k<cnt;k++){
        memset(&arr[i+k][end-7*mul+1], '0', sizeof(char)*56*mul);
    }
}
int search(int i){
    int code[8];
    int ret = 0;
    int j=w*4-1;
    int end=0;
    
    int min=100;
    for(int num=7;num>=0;num--){
        int ratio[3]= {0,};
        while(arr[i][j] == '0'){
            j--;
            if(j == 0){
                return 0;
            }
        }

        end=j;
        // 1 발견
        while(arr[i][j] == '1'){
            ratio[2] ++;
            j--;
        }
        // 0 발견
        while(arr[i][j] == '0'){
            ratio[1] ++;
            j--;
        }
        // 1 발견
        while(arr[i][j] == '1'){
            ratio[0] ++;
            j--;
        }

        // 최소값 (비율 찾기)
        for(int idx=0;idx<3;idx++){
            if(min > ratio[idx]) min = ratio[idx];
        }

        for(int idx=0;idx<3;idx++){
            ratio[idx] /= min;
        }

        if(ratio[0] == 1){
            if(ratio[1] == 1){
                if(ratio[2] == 2){
                    code[num] = 9; // 1 1 2
                } else if(ratio[2] == 4){
                    code[num] = 6; // 1 1 4
                }
            }else if(ratio[1] == 2){
                code[num] = 2; // 1 2 2
            }else if(ratio[1] == 3){
                code[num] = 4; // 1 3 2
            }
        }else if(ratio[0] == 2){
            if(ratio[1] == 1){
                if(ratio[2] == 1){
                    code[num] = 0; // 2 1 1 
                }else if(ratio[2] == 3){
                    code[num] = 8; // 2 1 3
                }
            }else if(ratio[1] == 2){
                code[num] = 1; // 2 2 1
            }else if(ratio[1] == 3){
                code[num] = 5; // 2 3 1
            }
        }else if(ratio[0] == 3){
            code[num] = 7; // 3 1 2
        }else if(ratio[0] == 4){
            code[num] = 3; // 4 1 1
        }else{
            cout << "unidentified number" << endl;
        }
    }
    
    // code 계산
    int verification=0;
    for(int num=0;num<7;num++){
        if(num % 2 == 0){ // 홀수
            verification += code[num] * 3;
        }else{
            verification += code[num];
        }
    }
    verification += code[7];
    if(verification%10 == 0){
        for(int j=0;j<8;j++){
            ret += code[j];
        }
        
    }
    
    // 후처리
    setZero(i,end,min);
    return ret;
}
int main(int argc, char const *argv[])
{
    int T = 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("sample_input.txt","r",stdin);
    cin >> T;
    for(int test_case = 1;test_case <=T;test_case++){
        init();
        int answer = 0;
        cin >> h >> w;
        for(int i=0;i<h;i++){
            char temp_str[501];
            cin >> temp_str;
            toBinary(temp_str, i);
        }
        
        for(int i=0;i<h;i++){
            if(hasCode[i]){
                answer += search(i);
            }
        }
        
        cout << "#" << test_case << " " << answer << endl;
    }
}
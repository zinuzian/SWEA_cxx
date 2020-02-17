#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

int arr[50][100];
void init(){
    memset(arr, 0, sizeof(int)*5000);
}

int main(int argc, char const *argv[])
{
    int T = 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    cin >> T;
    for(int test_case = 1;test_case <=T;test_case++){
        int h,w;
        init();
        cin >> h >> w;
        string input_str, temp_str;
        int end = -1;
        for(int i=0;i<h;i++){
            cin >> temp_str;
            if(end == -1){
                end = temp_str.rfind('1');
                
            }
            if( end != -1 && input_str.length() == 0){
                input_str = temp_str;
            }
            
        }
        int num_arr[8];
        int i=0;
        bool clean=true;
        for(int x=end-55;x<end+1;x+=7){
            bitset<7> bit_string(input_str.substr(x,7));
            if((bit_string ^ bitset<7>("0001101")).none()){
                num_arr[i++] = 0;
            }else if((bit_string ^ bitset<7>("0011001")).none()){
                num_arr[i++] = 1;
            }else if((bit_string ^ bitset<7>("0010011")).none()){
                num_arr[i++] = 2;
            }
            else if((bit_string ^ bitset<7>("0111101")).none()){
                num_arr[i++] = 3;
            }
            else if((bit_string ^ bitset<7>("0100011")).none()){
                num_arr[i++] = 4;
            }
            else if((bit_string ^ bitset<7>("0110001")).none()){
                num_arr[i++] = 5;
            }
            else if((bit_string ^ bitset<7>("0101111")).none()){
                num_arr[i++] = 6;
            }
            else if((bit_string ^ bitset<7>("0111011")).none()){
                num_arr[i++] = 7;
            }
            else if((bit_string ^ bitset<7>("0110111")).none()){
                num_arr[i++] = 8;
            }
            else if((bit_string ^ bitset<7>("0001011")).none()){
                num_arr[i++] = 9;
            }else{
                clean = false;
                break;
            }
        }
        if(!clean){
            cout << "#" << test_case << " " << 0 << endl;
            continue;
        }
        int odd=0, even = 0;
        for(int j=0;j<7;j++){
            if(j%2==0){
                even += num_arr[j];
            }
            else{
                odd += num_arr[j];
            }
        }
        if((even * 3 + odd + num_arr[7])%10 == 0){
            int sum = 0;
            for(int j=0;j<8;j++){ sum += num_arr[j]; }
            cout << "#" << test_case << " " << sum << endl;
        }else{
            cout << "#" << test_case << " " << 0 << endl;
        }


    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

string numbers[10] = {
    "0001101",
    "0011001",
    "0010011",
    "0111101",
    "0100011",
    "0110001",
    "0101111",
    "0111011",
    "0110111",
    "0001011"
};
int nZr_rfind(string str, string& output){
    int len = str.length();
    char *temp = new char[len*4+1];
    bool found = false;
    temp[len*4] = '\0';
    memset(temp, '0', sizeof(char)*len*4);
    for(int i=0;i<len;i++){
        switch(str[i])
        {
            case '1': memcpy(temp+i*4, "0001", sizeof(char)*4);found = true;break;
            case '2': memcpy(temp+i*4, "0010", sizeof(char)*4);found = true;break;
            case '3': memcpy(temp+i*4, "0011", sizeof(char)*4);found = true;break;
            case '4': memcpy(temp+i*4, "0100", sizeof(char)*4);found = true;break;
            case '5': memcpy(temp+i*4, "0101", sizeof(char)*4);found = true;break;
            case '6': memcpy(temp+i*4, "0110", sizeof(char)*4);found = true;break;
            case '7': memcpy(temp+i*4, "0111", sizeof(char)*4);found = true;break;
            case '8': memcpy(temp+i*4, "1000", sizeof(char)*4);found = true;break;
            case '9': memcpy(temp+i*4, "1001", sizeof(char)*4);found = true;break;
            case 'A': memcpy(temp+i*4, "1010", sizeof(char)*4);found = true;break;
            case 'B': memcpy(temp+i*4, "1011", sizeof(char)*4);found = true;break;
            case 'C': memcpy(temp+i*4, "1100", sizeof(char)*4);found = true;break;
            case 'D': memcpy(temp+i*4, "1101", sizeof(char)*4);found = true;break;
            case 'E': memcpy(temp+i*4, "1110", sizeof(char)*4);found = true;break;
            case 'F': memcpy(temp+i*4, "1111", sizeof(char)*4);found = true;break;
        }
    }
    output.assign(temp);
    if(found){
        cout << temp << endl;
        return output.rfind('1');
    }
    return -1;
}
string zip_text(string str, int end){
    int start = str.find('1');
    int mul = (end-start)/56 + 1;
    int len = str.length();
    char *ret = new char[len/mul+1];
    for(int i=0;i<len;i+=mul){
        ret[i/mul] = str[i];
    }
    ret[len/mul]='\0';
    string rr;
    rr.assign(ret);
    return rr;
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
        int h,w;
        cin >> h >> w;
        string input_str, temp_str;
        int end = -1;
        for(int i=0;i<h;i++){
            cin >> temp_str;
            if(end == -1)
                end = nZr_rfind(temp_str, input_str);
        }
        input_str = zip_text(input_str, end);
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
}
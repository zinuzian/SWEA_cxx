#include <iostream>
#include <cstring>

using namespace std;
int answer;
int n;

void init(){

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

        cout << "#" << test_case << " " << answer << endl;
    }
}
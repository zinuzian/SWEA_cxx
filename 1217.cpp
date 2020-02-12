#include<iostream>

using namespace std;
int mul(int , int);
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	// freopen("input.txt", "r", stdin);
	// cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer=0;
        int t, n, m;
        cin >> t;
        cin >> n >> m;

        answer = mul(n,m);

        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}

int mul(int base, int n){
    if (n==1){
        return base;
    }else{
        return mul(base , n-1)* base;
    }

}
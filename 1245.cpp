#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int n;
double xpos[10];
double answer[9];
int mass[10];

double calcBalance(double pos){
    double rG=0.0, lG=0.0;
    for(int i=0;i<n;i++){
        if(pos < xpos[i]){
            rG += mass[i]/((xpos[i]-pos)*(xpos[i]-pos));
        }else{
            lG += mass[i]/((xpos[i]-pos)*(xpos[i]-pos));
        }
    }
    return lG - rG;
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
        int max=0, min=2147483647; 
        cin >> n;

        for(int i=0;i<n;i++){
            cin >> xpos[i];
        }
        for(int i=0;i<n;i++){
            cin >> mass[i];
        }

        for(int i=0;i<n-1;i++){
            double left = xpos[i], right=xpos[i+1];
            double mid = (left + right)/2.0;
            while(1){
                double diff = calcBalance(mid);
                if(right - left < 1e-12) break;
                if(diff < 0){
                    right = mid;
                    mid = (left + mid) / 2.0;
                }else{
                    left = mid;
                    mid = (right + mid) / 2.0;
                }
            }
            answer[i] = mid;
        }

        cout << "#" << test_case << " " << fixed << setprecision(10);
        for(int i=0;i<n-1;i++){ cout << answer[i] << " "; }
        cout << endl;
    }
}
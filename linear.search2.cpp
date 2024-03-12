#include <iostream>
#define MAXN 10000
using namespace std;

void Nhap(int a[], int &n){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

}

int main()
{
    int a[MAXN];
    int n, target;
    int count=0, index=0;
    Nhap(a, n);
    cin >> target;
    for (int i=0; i<n; i++){
        if (a[i]==target){
            count++;
        }
    }
    if (count==0) cout << 0 << endl;
    else cout << count << endl;
    int t=0;
    while(count>0){
       // index=0;
        for (int j=t; j<n; j++){
            if (a[j]==target) {
                cout << index << "\t" << index+1 << endl;
                t=j+1;
                break;
            }
            else{
                index++;
            }
        }
       // if (index==n) cout << 0 << endl;
        index++;
        count--;
    }

    // int count1 = 1;
    // for (int i=n-1; i>0; i--){
    //     if (a[i]==target){
    //         cout << count1-1 << endl << count1 << endl;
    //         break;
    //     }
    //     count1++;
    // }
   // if (count1==n) cout << -1 << endl;
}

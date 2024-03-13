#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solution(int &s, int&big)
{
    vector<int> a;
    for (int i=0; i<s; i++){
        int input;
        cin >> input;
        a.push_back(input);
    }

    vector<int> b;
    
    int max1 = *max_element(a.begin(),a.end());
    int min1 = *min_element(a.begin(),a.end());

    for (int i=0; i<a.size(); i++){
        if (a[i]!=max1 && a[i]!=min1) b.push_back(a[i]);
    }

    int max2 = *max_element(b.begin(),b.end());
    int min2 = *min_element(b.begin(),b.end());

    big = (max1-min1)+(max2-min2);
}

void MaxDifferent(int &n, vector<int>&cases)
{
    cin >> n;
    for (int i=0; i<n; i++){
        bool done=false;
        int big=0;
        int input;
        cin >> input;
        if (input==2){
            vector<int> temp;
            for (int j=0; j<input; j++){
                int input2;
                cin >> input2;
                temp.push_back(input2);
            }
            big = temp[0] > temp[1] ? (temp[0]- temp[1]) : (temp[1] - temp[0]) ;
            cases.push_back(big);
            done = true;
        }
        if (!done){
        Solution(input, big);
        cases.push_back(big);
        }
    }
    
    for (int i=0; i<cases.size(); i++) cout << cases[i] << endl;
}

int main()
{
    vector<int>cases;
    int n;
    MaxDifferent(n, cases);
}

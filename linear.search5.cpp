#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int &s, int&big)
{
    vector<int> a;
    for (int i=0; i<s; i++){
        int input;
        cin >> input;
        a.push_back(input);
    }

    int mid=0;
    vector<int> result;
    while(mid<s-1){
        mid++;
        vector<int> left(a.begin(), a.begin()+mid);
        vector<int> right(a.begin()+mid, a.end());

        int max_left=*max_element(left.begin(), left.end());
        int min_left=*min_element(left.begin(), left.end());
        int max_right=*max_element(right.begin(), right.end());
        int min_right=*min_element(right.begin(), right.end());
        result.push_back((max_left-min_left)+(max_right-min_right));
    }
    result.push_back(*max_element(a.begin(), a.end())-*min_element(a.begin(),a.end()));
    big = *max_element(result.begin(), result.end());
}

void Nhap(int &n, vector<int>&cases)
{
    cin >> n;
    for (int i=0; i<n; i++){
        int big=0;
        int input;
        cin >> input;
        solution(input, big);
        cases.push_back(big);
    }
    for (int i=0; i<cases.size(); i++) cout << cases[i] << endl;
}

int main()
{
    int big=0;
    vector<int>cases;
    vector<int>vt;
    int n;
    Nhap(n, cases);
}

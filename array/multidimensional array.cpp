#include <iostream>
#include <array>
#include <algorithm>
#include <climits>

using namespace std;


#int x[3][2] 3 rows two coloums

int main(){
    array< array<int, 10>, 30 > boxes = {};
    int k,d;

    while(cin >> k >> d) {

        for(int i = 0; i < k; ++i) {
            fill(boxes[i].begin(), boxes[i].end(), INT_MAX);
            for(int j = 0; j < d; ++j)
                cin >> boxes[i][j];
            sort(boxes[i].begin(), boxes[i].begin() + d); // sort the first d elemenents
        }
        sort(boxes.begin(), boxes.begin() + k); // sort the first k  rows

        for(auto& row : boxes) { // output
            for(auto& n : row)
                cout << n << ' ';
            cout << '\n';
        }
    }
}




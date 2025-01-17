#include <bits/stdc++.h>

using namespace std;

int det(vector<vector<int>> matrix){

    vector<vector<int>> nested;
    int a = 0, b = 0;
    cout << "HUHE" << endl;
    if(matrix.size() == 2){
        return 1;
    }
    for(int i = ; i < matrix.size(); i++){
        cout << "UHUH" << endl;
        cout << matrix[i].size() << endl;
        for(int j = 0; j < matrix[i].size(); j++){
            if(j == -1)
                continue;
            cout << "frfr" << endl;
            nested[i].push_back(matrix[i][j]);
            cout << nested[i][j];
        }
        cout << endl;
    }
    for(a = 0; a < matrix.size(); a++){
        for(b = 0; b < matrix[a].size(); b++){
            return matrix[a][b]*det(nested);
        }
    }
    return 1;
}

int main(){
    vector<vector<int>> mat = {
        {1, 2, 3, 7},
        {4, 5, 6, 7},
        {7, 8, 9, 7},
        {1, 2, 4, 5}
    };
    cout << det(mat) << endl;
}
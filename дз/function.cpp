#include "function.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillMatrixRandom(vector<vector<int>>& matrix, int& rows, int& cols) {
    srand(time(0));
    cout << "\n¬вед≥ть к≥льк≥сть р€дк≥в ≥ стовпц≥в: ";
    cin >> rows >> cols;
    matrix.assign(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = rand() % 10;
}

void fillMatrixUser(vector<vector<int>>& matrix, int& rows, int& cols) {
    cout << "\n¬вед≥ть к≥льк≥сть р€дк≥в ≥ стовпц≥в: ";
    cin >> rows >> cols;
    matrix.assign(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            cout << "≈лемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
}

void displayMatrix(const vector<vector<int>>& matrix) {
    cout << "\nћатриц€:" << endl;
    for (const auto& row : matrix) {
        for (int val : row)
            cout << setw(4) << val;
        cout << endl;
    }
}

void convertToCSR(const vector<vector<int>>& matrix, vector<int>& vval, vector<int>& vpos, vector<int>& vptz) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vval.clear(); vpos.clear(); vptz = { 0 };
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                vval.push_back(matrix[i][j]);
                vpos.push_back(j);
            }
        }
        vptz.push_back(vval.size());
    }
}

void subtractScalarFromDiagonal(vector<int>& vval, vector<int>& vpos, vector<int>& vptz, int scalar, int rows) {
    for (int i = 0; i < rows; ++i) {
        bool diagFound = false;
        int start = vptz[i];
        int end = vptz[i + 1];
        for (int j = start; j < end; ++j) {
            if (vpos[j] == i) {
                vval[j] -= scalar;
                diagFound = true;
                break;
            }
        }
        if (!diagFound) {
            vval.insert(vval.begin() + end, -scalar);
            vpos.insert(vpos.begin() + end, i);
            for (int k = i + 1; k < vptz.size(); ++k)
                vptz[k]++;
        }
    }
}

void restoreMatrixFromCSR(vector<vector<int>>& matrix, const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptz) {
    int rows = vptz.size() - 1;
    int cols = rows;
    matrix.assign(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        int start = vptz[i];
        int end = vptz[i + 1];
        for (int j = start; j < end; ++j)
            matrix[i][vpos[j]] = vval[j];
    }
}

void displayCSR(const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptz) {
    cout << "\nvval: ";
    for (int val : vval) cout << val << " ";
    cout << "\nvpos: ";
    for (int pos : vpos) cout << pos << " ";
    cout << "\nvptz: ";
    for (int ptz : vptz) cout << ptz << " ";
    cout << endl;
}

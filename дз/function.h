#pragma once

#include <vector>

void fillMatrixRandom(std::vector<std::vector<int>>& matrix, int& rows, int& cols);
void fillMatrixUser(std::vector<std::vector<int>>& matrix, int& rows, int& cols);
void displayMatrix(const std::vector<std::vector<int>>& matrix);
void convertToCSR(const std::vector<std::vector<int>>& matrix, std::vector<int>& vval, std::vector<int>& vpos, std::vector<int>& vptz);
void subtractScalarFromDiagonal(std::vector<int>& vval, std::vector<int>& vpos, std::vector<int>& vptz, int scalar, int rows);
void restoreMatrixFromCSR(std::vector<std::vector<int>>& matrix, const std::vector<int>& vval, const std::vector<int>& vpos, const std::vector<int>& vptz);
void displayCSR(const std::vector<int>& vval, const std::vector<int>& vpos, const std::vector<int>& vptz);

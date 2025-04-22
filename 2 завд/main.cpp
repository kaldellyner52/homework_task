#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("text.txt");
    if (!file) return cerr << "Файл не відкрито!\n", 1;

    map<string, int> wordCount;
    string word;
    while (file >> word) wordCount[word]++;

    for (auto it = wordCount.begin(); it != wordCount.end(); ++it)
        cout << it->first << ": " << it->second << '\n';

    return 0;
}

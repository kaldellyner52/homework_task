#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

bool isValidBrackets(const string& s) {
    vector<char> stack;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') stack.push_back(ch);
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty()) return false;
            char open = stack.back();
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) return false;
            stack.pop_back();
        }
    }
    return stack.empty();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    cout << "������ ����� � �������: ";
    cin >> input;
    cout << (isValidBrackets(input) ? "����� ���������� ���������:)" : "����� ���������� �����������:(") << endl;
    return 0;
}

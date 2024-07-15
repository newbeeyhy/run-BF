#include <iostream>

using namespace std;

char arr[1000];
char *p;

void run(char c) {
    switch (c) {
        case '>': p++; break;
        case '<': p--; break;
        case '+': *p = *p + 1; break;
        case '-': *p = *p - 1; break;
        case '.': cout << char(*p); break;
        case ',': *p = getchar(); break;
        default: break;
    }
}

int main() {
    while (1) {
        memset (arr, 0, sizeof(arr));
        p = arr + 500;
        cout << "\n> ";
        string s;
        cin >> s;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                if (*p == 0) {
                    int cnt = 1;
                    while (cnt != 0) {
                        i++;
                        if (s[i] == '[') cnt++;
                        if (s[i] == ']') cnt--;
                    }
                    i--;
                }
            }
            else if (s[i] == ']') {
                if (*p != 0) {
                    int cnt = 1;
                    while (cnt != 0) {
                        i--;
                        if (s[i] == ']') cnt++;
                        if (s[i] == '[') cnt--;
                    }
                    i--;
                }
            }
            else run(s[i]);
        }
    }
    return 0;
}
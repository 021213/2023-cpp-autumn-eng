#include <iostream>
#include <string>

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void permute(std::string str, int l, int r) {
    if (l == r) {
        std::cout << str << " ";
    }
    else {
        for (int i = l; i <= r; ++i) {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]);
        }
    }
}

int main() {
    std::string str;
    std::cin >> str;

    permute(str, 0, str.length() - 1);

    return 0;
}
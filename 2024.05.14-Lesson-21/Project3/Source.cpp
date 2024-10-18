#include <iostream>

class SimpleArray {
private:
    int* arr;
    int size = 0;

public:
    SimpleArray(int n) : size(n) {
        arr = new int[n];
    }

    ~SimpleArray() {
        delete[] arr;
    }

    int& get(int i) {
        return arr[i - 1];
    }

    void update(int l, int r, int x) {
        for (int i = l; i < r; ++i) {
            arr[i] = x;
        }
    }

    void add(int l, int r, int x) {
        for (int i = l; i < r; ++i) {
            arr[i] += x;
        }
    }

    int rsq(int l, int r) {
        int sum = 0;
        for (int i = 0; i < r; ++i) {
            sum += arr[i];
        }
        return sum;
    }

    int rmq(int l, int r) {
        int minVal = arr[0];
        for (int i = 1; i < r; ++i) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        return minVal;
    }
};

int main() {
    int n = 0;
    std::cin >> n;

    if (n < 1 || n > 1000) {
        std::cout << "Error: n should be between 1 and 1000." << std::endl;
        return 1;
    }
    SimpleArray arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr.get(i + 1);
    }

    int m = 0;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "get") {
            int idx = 0;
            std::cin >> idx;
            std::cout << arr.get(idx) << std::endl;
        }
        else if (op == "update") {
            int l = 0;
            int r = 0;
            int x = 0;
            std::cin >> l >> r >> x;
            arr.update(l, r, x);
        }
        else if (op == "add") {
            int l = 0;
            int r = 0;
            int x = 0;
            std::cin >> l >> r >> x;
            arr.add(l, r, x);
        }
        else if (op == "rsq") {
            int l = 0;
            int r = 0;
            std::cin >> l >> r;
            std::cout << arr.rsq(l, r) << std::endl;
        }
        else if (op == "rmq") {
            int l = 0;
            int r = 0;
            std::cin >> l >> r;
            std::cout << arr.rmq(l, r) << std::endl;
        }
    }

    return EXIT_SUCCESS;
}

#include <iostream>

typedef long long lint;

int main() {

    lint n = 0;
    lint m = 0;
    lint k = 0;
    std::cin >> n >> m >> k;

    int** a = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        a[i] = new int[m + 1]{ 0 };
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
        }
    }

    int** prefixSum = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        prefixSum[i] = new int[m + 1]{ 0 };
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefixSum[i][j] = a[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < k; ++i) {
        int y1 = 0;
        int x1 = 0;
        int y2 = 0;
        int x2 = 0;
        std::cin >> y1 >> x1 >> y2 >> x2;
        int sum = prefixSum[y2][x2] - prefixSum[y1 - 1][x2] - prefixSum[y2][x1 - 1] + prefixSum[y1 - 1][x1 - 1];
        std::cout << sum << " ";
    }

    for (int i = 0; i < n + 1; ++i)
    {
        delete[] a[i];
        delete[] prefixSum[i];
    }
    delete[] a;
    delete[] prefixSum;

    return EXIT_SUCCESS;
}

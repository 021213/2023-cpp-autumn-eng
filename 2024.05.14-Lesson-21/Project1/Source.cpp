#include<iostream>

typedef long long uint;
int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    uint* arr = new uint[n] { 0 };
    uint* rsq = new uint[n + 1] { 0 };
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    rsq[0] = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        rsq[i] = rsq[i - 1] + arr[i - 1];
    }
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int l = 0;
        int r = 0;
        std::cin >> l >> r;
        if (l > r)
        {
            l ^= r ^= l ^= r;
        }
        std::cout << rsq[r] - rsq[l - 1] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    delete[] rsq;
    return EXIT_SUCCESS;
}
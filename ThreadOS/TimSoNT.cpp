#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <algorithm>
std::vector<int> primes;
std::mutex primes_mutex;
bool is_Prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void find_Primes(int start, int end) {
    std::vector<int> local_Primes;
    for (int i = start; i <= end; i++) {
        if (is_Prime(i))
            local_Primes.push_back(i);
    }
    std::lock_guard<std::mutex> gruad(primes_mutex);
    primes.insert(primes.end(), local_Primes.begin(), local_Primes.end());
}


int main() {
    int left, right;
    std::cout << "Nhap khoang [left-right]: "; std::cin >> left >> right;
    const size_t num_Threads = std::thread::hardware_concurrency();
    std::vector<std::thread>threads;
    int range = (right - left + 1) / num_Threads;
    for (int i = 0; i < num_Threads; i++) {
        int start = left + i * range;
        int end = (i == num_Threads - 1) ? right : start + range - 1;
        threads.emplace_back(find_Primes, start, end);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::sort(primes.begin(), primes.end());

    std::cout << "Các số nguyên tố trong khoảng [" << left << ", " << right << "] là:\n";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
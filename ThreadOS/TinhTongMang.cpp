#include <iostream>
#include <vector>
#include <thread> // Thư viện luồng
#include <atomic> //Thư viện biến nguyên tử
#include <chrono> //Thư viện thời gian

// Hàm tính tổng một phần của mảng
void partialSum(const std::vector<int>& arr, size_t start, size_t end, std::atomic<long long>& totalSum) {
    long long localSum = 0;
    for (size_t i = start; i < end; ++i) {
        localSum += arr[i];
    }
    totalSum += localSum; // Cập nhật tổng chung một cách an toàn
}

int main() {
    const size_t ARRAY_SIZE = 100000000;  // 100 triệu phần tử
    const size_t THREAD_COUNT = std::thread::hardware_concurrency(); // Số luồng tối đa của CPU
    std::vector<int> arr(ARRAY_SIZE, 1); // Khởi tạo mảng toàn số 1 (tổng mong đợi = ARRAY_SIZE)

    // Tính tổng bằng 1 luồng (đơn luồng)
    auto startTime = std::chrono::high_resolution_clock::now();
    long long singleThreadSum = 0;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        singleThreadSum += arr[i];
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> singleThreadTime = endTime - startTime;
    std::cout << "Single-thread sum: " << singleThreadSum
        << " | Time: " << singleThreadTime.count() << " sec\n";

    //Tính tổng bằng nhiều luồng (đa luồng)
    std::atomic<long long> multiThreadSum(0);
    std::vector<std::thread> threads;
    size_t chunkSize = ARRAY_SIZE / THREAD_COUNT;

    startTime = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < THREAD_COUNT; ++i) {
        size_t start = i * chunkSize;
        size_t end = (i == THREAD_COUNT - 1) ? ARRAY_SIZE : start + chunkSize;
        threads.emplace_back(partialSum, std::cref(arr), start, end, std::ref(multiThreadSum));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> multiThreadTime = endTime - startTime;

    std::cout << "Multi-thread sum: " << multiThreadSum
        << " | Time: " << multiThreadTime.count() << " sec\n";

    // So sánh hiệu suất
    std::cout << "Speedup factor: " << singleThreadTime.count() / multiThreadTime.count() << "x\n";

    return 0;
}

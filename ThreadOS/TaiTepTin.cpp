#include <iostream>
#include <thread>
#include <vector>
#include<chrono>
#include<mutex>

std::mutex cout_mutex;

void dowLoadFile(int fileIndex) {
    auto start = std::chrono::high_resolution_clock::now();

    //Gỉa lập thời gian.
    int dowLoadTime = 1 + rand() % 5;
    std::this_thread::sleep_for(std::chrono::seconds(dowLoadTime));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    //Dùng mutex để tránh xung đột khi in
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout<<"File "<<fileIndex<<" dowload in "<<elapsed.count()<<" second.\n";

}

int main(){
    int num;
    std::cout<<"Enter the number of files to dowload: "; std::cin >> num;

    std::vector<std::thread> threads;
    //create and run num thread to dowload N file.
    for(int i = 1; i<= num; i++){
        threads.emplace_back(dowLoadFile, i);
    }
    for(auto& thread: threads){
        thread.join();
    }

    std::cout<<"All dowload completed!\n";
}
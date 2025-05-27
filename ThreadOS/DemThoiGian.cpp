#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


int time_remaining; // Thời gian con lại
std::mutex time_mutex;

void countDown() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex>lock(time_mutex);
        if (time_remaining > 0)
            --time_remaining;
        else break;
    }
}

void displayTime() {
    while (true) {
        {
            std::lock_guard<std::mutex> lock(time_mutex);
            if (time_remaining <= 0)
                break;
        }
        std::cout << "Thoi gian con lai la: " << time_remaining << " giay" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Dem nguoc hoang thanh!" << std::endl;
    }
}

int main() {

    std::cout << "Nhập số giây để đếm ngược: ";
    std::cin >> time_remaining;

    std::thread countdown_thread(countDown);
    std::thread display_thread(displayTime);

    countdown_thread.join();
    display_thread.join();
    
    return 0;
}

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <semaphore>
#include <vector>
#include <chrono>

enum class RwTurn {
    READER,
    WRITER,
};

std::counting_semaphore countSem(3);
std::shared_mutex dataMutex;
int data = 0;
std::mutex readingMutex;
int reading = 0;
RwTurn whoTurn = RwTurn::READER;

void writer(int timeWrite) {
    std::unique_lock<std::shared_mutex> data_lock(dataMutex, std::defer_lock);

    whoTurn = RwTurn::WRITER;

    data_lock.lock();

    std::cout << "\n-------------------------------" << std::endl;
    std::cout << "THREAD " << std::this_thread::get_id() << " IS WRITING" << std::endl;
    std::cout << "Data is: " << ++data << std::endl;
    std::cout << reading << " people is in read room" << std::endl;
    std::cout << "-------------------------------\n\n" << std::endl;
    std::cout << "Thread " << std::this_thread::get_id() << " finish writing" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(timeWrite));
    
    whoTurn = RwTurn::READER;
    
    data_lock.unlock();
}

void reader(int timeRead) {
    countSem.acquire();

    std::unique_lock<std::mutex> reading_lock(readingMutex, std::defer_lock);
    std::shared_lock<std::shared_mutex> data_lock(dataMutex, std::defer_lock);

    while (whoTurn == RwTurn::WRITER)
        continue;

    data_lock.lock();
    reading_lock.lock();
    reading++;

    std::cout << "Thread " << std::this_thread::get_id() << " enter read room" << std::endl;
    std::cout << reading << " people reading... data: " << data << std::endl;
    reading_lock.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(timeRead));

    reading_lock.lock();
    reading--;
    std::cout << "Thread " << std::this_thread::get_id() << " leaving read room, " << reading << " people remain...\n\n";

    if (reading == 0) {
        std::cout << "Thread " << std::this_thread::get_id() << " unlock data mutex" << std::endl;
        //data_lock.unlock();
    }
    reading_lock.unlock();
    countSem.release();

}


int main() {
    std::vector<std::thread> readThread;
    std::vector<std::thread> writeThread;

    readThread.push_back(std::thread(reader, 300));
    readThread.push_back(std::thread(reader, 100));

    writeThread.push_back(std::thread(writer, 100));

    readThread.push_back(std::thread(reader, 200));
    readThread.push_back(std::thread(reader, 100));
    readThread.push_back(std::thread(reader, 200));
    readThread.push_back(std::thread(reader, 100));

    writeThread.push_back(std::thread(writer, 300));

    readThread.push_back(std::thread(reader, 200));
    readThread.push_back(std::thread(reader, 100));

    for (int i = 0; i < readThread.size(); i++) {
        readThread[i].join();
    }

    for (int i = 0; i < writeThread.size(); i++) {
        writeThread[i].join();
    }

    return 0;
}
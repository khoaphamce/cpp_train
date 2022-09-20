#include <iostream>
#include <mutex>
#include <thread>
#include <semaphore>
#include <vector>
#include <chrono>

std::mutex writeReadMutex;
std::mutex readMutex;
std::counting_semaphore countSem(3);
int reading;

void writer(int timeWrite) {
    writeReadMutex.lock();
    
    std::cout << "\n-------------------------------" << std::endl;
    std::cout << "A HANDSOME BOY IS WRITING..." << std::endl;
    std::cout << "-------------------------------\n\n" << std::endl;
    std::cout << "Finish writing" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(timeWrite));
    
    writeReadMutex.unlock();
}

void reader(int timeRead) {
    countSem.acquire();

    //readMutex.try_lock();
    readMutex.lock();
    reading++;

    if (reading == 1)
        writeReadMutex.lock();
    countSem.release();

    printf("%d people reading...\n\n", reading);
    
    readMutex.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(timeRead));

    //countSem.acquire();
    readMutex.lock();

    reading--;
    std::cout << "Leaving reading room, " << reading << " people remain...\n\n";
    //countSem.release();

    if (reading == 0) {
        writeReadMutex.unlock();
    }
    readMutex.unlock();

}


int main() {
    std::vector<std::thread> readThread;
    std::vector<std::thread> writeThread;

    readThread.push_back(std::thread(reader, 3000));
    readThread.push_back(std::thread(reader, 3000));
    readThread.push_back(std::thread(reader, 3000));
    readThread.push_back(std::thread(reader, 3000));
    readThread.push_back(std::thread(reader, 3000));
    readThread.push_back(std::thread(reader, 3000));


    writeThread.push_back(std::thread(writer, 3000));
    writeThread.push_back(std::thread(writer, 3000));
    

    writeThread[0].join();

    readThread[0].join();
    readThread[1].join();

    readThread[2].join();
    readThread[3].join();

    writeThread[1].join();

    readThread[4].join();
    readThread[5].join();


    return 0;
}
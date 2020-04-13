// cout
#include <iostream>
// this_thread & thread
#include <thread>
// seconds
#include <chrono>

namespace th {
    void foo()
    {
        // simulate expensive operation
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    void bar()
    {
        // simulate expensive operation
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

int main()
{

    std::cout << "starting first helper...\n";
    std::thread helper1(th::foo);

    std::cout << "starting second helper...\n";
    std::thread helper2(th::bar);

    std::cout << "waiting for helpers to finish...\n";
    helper1.join();
    helper2.join();

    std::cout << "done!\n";
}

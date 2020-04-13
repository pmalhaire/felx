// cout
#include <iostream>
// this_thread & thread
#include <thread>
// seconds
#include <chrono>

#define DELAY 1

namespace th {
    void foo(std::shared_ptr<int> integer)
    {
        std::cout << "foo integer first @" << integer << ":" << *integer << std::endl;
        *integer = 2;
        std::cout << "foo integer second @" << integer << ":" << *integer << std::endl;
        // simulate expensive operation
        std::this_thread::sleep_for(std::chrono::seconds(DELAY));
    }

    void bar(std::shared_ptr<int> integer)
    {
        std::cout << "bar integer @" << integer << ":" << *integer << std::endl;
        // simulate expensive operation
        std::this_thread::sleep_for(std::chrono::seconds(DELAY));
    }
}

int main()
{

    auto integer = std::make_shared<int>(1);
    std::cout << "starting first helper...\n";
    std::thread helper1(th::foo, integer);

    std::cout << "starting second helper...\n";
    std::thread helper2(th::bar, integer);

    std::cout << "waiting for helpers to finish...\n";
    helper1.join();
    helper2.join();

    std::cout << "done!\n";
}

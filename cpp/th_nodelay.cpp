// cout
#include <iostream>
// this_thread & thread
#include <thread>
// mutex
#include <mutex>


namespace th {
    void foo(std::shared_ptr<int> integer, std::shared_ptr<std::mutex> m)
    {
        std::lock_guard<std::mutex> lk(*m);
        std::cout << "foo integer first @" << integer << ":" << *integer
            << "m:" << m << std::endl;
        *integer = 2;
        std::cout << "foo integer second @" << integer << ":" << *integer << std::endl;
    }

    void bar(std::shared_ptr<int> integer, std::shared_ptr<std::mutex> m)
    {
        std::lock_guard<std::mutex> lk(*m);
        std::cout << "bar integer @" << integer << ":" << *integer
            << "m:" << m << std::endl;
    }
}

int main()
{

    auto integer = std::make_shared<int>(1);
    auto m = std::make_shared<std::mutex>();
    std::cout << "starting first helper...\n";
    std::thread helper1(th::foo, integer, m);

    std::cout << "starting second helper...\n";
    std::thread helper2(th::bar, integer, m);

    std::cout << "waiting for helpers to finish...\n";
    helper1.join();
    helper2.join();

    std::cout << "done!\n";
}

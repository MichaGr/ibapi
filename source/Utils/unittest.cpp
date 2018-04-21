#include "Timestamp.h"

#include <chrono>

#include <iostream>
int main(int argc, char** argv)
{
    Timestamp timestamp(2018,4,18);
    Timestamp timestamp2(2018,4,18,5,35,32);

    std::cout << timestamp.getString() << std::endl;
    std::cout << timestamp2.getString() << std::endl;

    std::cout << "== " << (timestamp == timestamp2) << std::endl;
    std::cout << "< " << (timestamp < timestamp2) << std::endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000;++i)
    {}
    auto t2 = std::chrono::high_resolution_clock::now();
//    auto t3 = std::chrono::high_resolution_clock::from_time_t(t0);
    auto duration = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1,1000> > >(t2-t1);

    std::cout << duration.count() << "ms" <<std::endl;
}

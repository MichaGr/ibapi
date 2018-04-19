#include "Timestamp.h"

#include <iostream>
int main(int argc, char** argv)
{
    Timestamp timestamp(2018,4,18);
    Timestamp timestamp2(2018,4,18,5,35,32);

    std::cout << timestamp.getString() << std::endl;
    std::cout << timestamp2.getString() << std::endl;

    std::cout << "== " << (timestamp == timestamp2) << std::endl;
    std::cout << "< " << (timestamp < timestamp2) << std::endl;
}

/* This file shall invoke the getTime() function and print the output */

#include <iostream>
#include "time_manager.h"

int main() {

    int64_t epoch_time = getTime();
    if (epoch_time != 0) {
        std::cout << "epoch Time format : " << epoch_time << std::endl;
    }
    else {
        std::cout << "request refused" << std::endl;
    }
    return 0;

}

#include "rest.h"

#include <iostream>

Result Rest::perform(Engine&) {
    std::cout << "rest" << '\n';
    return success();
}

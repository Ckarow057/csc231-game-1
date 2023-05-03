#include "none.h"

#include <iostream>

None::None() : Weapon("none", 0) {}

void None::use(Engine&, Actor&, Actor&) {
    std::cout << "You bravely attack with nothing" << '\n';
}

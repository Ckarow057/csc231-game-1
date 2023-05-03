#include "attack.h"

#include <iostream>

#include "actor.h"

Attack::Attack(Actor& defender) : defender{defender} {}

Result Attack::perform(Engine&) {
    actor->attack(defender);
    std::cout << "attack worked" << '\n';
    return success();
}
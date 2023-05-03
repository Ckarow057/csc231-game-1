#include "cleaver.h"

#include <iostream>

#include "engine.h"
#include "hit.h"

Cleaver::Cleaver(int damage) : Weapon{"cleaver", damage} {}

void Cleaver::use(Engine& engine, Actor& attacker, Actor& defender) {
    std::cout << "swang" << '\n';

    engine.events.add(Hit{defender, 2});
}

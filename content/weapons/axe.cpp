#include "axe.h"

#include <iostream>

#include "engine.h"
#include "hit.h"

Axe::Axe(int damage) : Weapon{"axe", damage} {}

void Axe::use(Engine& engine, Actor& attacker, Actor& defender) {
    std::cout << "swang" << '\n';

    engine.events.add(Hit{defender, 2});
}

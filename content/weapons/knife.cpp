#include "knife.h"

#include <iostream>

#include "engine.h"
#include "hit.h"

Knife::Knife(int damage) : Weapon{"cleaver", damage} {}

void Knife::use(Engine& engine, Actor& attacker, Actor& defender) {
    std::cout << "swang" << '\n';

    engine.events.add(Hit{defender, damage});
}

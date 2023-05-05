#include "sword_big.h"

#include <iostream>

#include "engine.h"
#include "hit.h"

Sword_big::Sword_big(int damage) : Weapon{"sword_big", damage} {}

void Sword_big::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();

    std::cout << "swang" << '\n';

    engine.events.add(Hit{defender, damage});
}

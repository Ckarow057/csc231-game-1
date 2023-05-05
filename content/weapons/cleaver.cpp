#include "cleaver.h"

#include <iostream>

#include "engine.h"
#include "event.h"
#include "hit.h"

Cleaver::Cleaver(int damage) : Weapon{"cleaver", damage} {}

void Cleaver::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();

    std::cout << "swang" << '\n';
    engine.events.add(Hit{defender, damage});
}

#include "axe.h"

#include <iostream>

#include "chop.h"
#include "engine.h"
#include "hit.h"

Axe::Axe(int damage) : Weapon{"axe", damage} {}

void Axe::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Chop{sprite, direction, defender, damage});
}
#include "superstick.h"

#include <iostream>

#include "engine.h"
#include "explosion.h"
#include "fire.h"
#include "gas.h"
#include "hit.h"
#include "lightning.h"
#include "magic.h"
#include "randomness.h"
#include "swing.h"
#include "wonderstick.h"

Superstick::Superstick(int damage) : Weapon{"staff_red", damage} {}

void Superstick::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();

    engine.events.add(WonderStick{sprite, direction, defender, 0});

    int probability{randint(0, 6)};

    if (probability == 0) {
        engine.events.add(Lightning{defender.get_position(), 5});
    } else if (probability == 1) {
        engine.events.add(Fire{defender.get_position(), 2});
    } else if (probability == 2) {
        engine.events.add(Explosion{defender.get_position(), 4});
    } else if (probability == 3) {
        engine.events.add(Gas{defender.get_position(), 1});
    } else if (probability == 4) {
        engine.events.add(Magic{defender.get_position(), 2});
    } else if (probability == 5) {
        if (attacker.health <= attacker.max_health) {
            attacker.health += 2;
        }
    } else if (probability == 6) {
        if (defender.health <= defender.max_health) {
            defender.health += 1;
        }
    }
}

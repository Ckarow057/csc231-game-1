#include "wabbajack.h"

#include <iostream>

#include "cast.h"
#include "engine.h"
#include "explosion.h"
#include "fire.h"
#include "gas.h"
#include "hit.h"
#include "lightning.h"
#include "magic.h"
#include "randomness.h"
#include "swing.h"

Wabbajack::Wabbajack(int damage) : Weapon{"staff_red", damage} {}

void Wabbajack::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();

    engine.events.add(WonderStick{sprite, direction, defender, 0});

    int probability{randint(0, 5)};

    if (probability == 0) {
        engine.events.add(Lightning{defender.get_position(), 5});
    } else if (probability == 1) {
        engine.events.add(Explosion{defender.get_position(), 4});
    } else if (probability == 2) {
        engine.events.add(Gas{defender.get_position(), 1});
    } else if (probability == 3) {
        engine.events.add(Magic{defender.get_position(), 2});
    } else if (probability == 4) {
        if (attacker.health <= attacker.max_health) {
            attacker.health += 2;
        }
    } else if (probability == 5) {
        if (defender.health <= defender.max_health) {
            defender.health += 1;
        }
    }
}

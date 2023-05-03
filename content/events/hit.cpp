#include "hit.h"

#include <iostream>

#include "actor.h"
#include "die.h"
#include "engine.h"
#include "event.h"

Hit::Hit(Actor& actor, int damage) : actor{actor}, damage{damage} {}

void Hit::execute(Engine& engine) {
    actor.take_damage(damage);
    std::cout << "hit" << '\n';

    if (actor.health <= 0) {
        engine.events.add(Die{actor});
        std::cout << "is ded" << '\n';
    }
}
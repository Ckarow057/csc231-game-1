#include "hit.h"

#include <iostream>

Hit::Hit(Actor& actor, int damage) : actor{actor}, damage{damage} {}

void Hit::execute(Engine& engine) {
    actor.take_damage(damage);
    std::cout << "hit" << '\n';
    std::cout << damage << '\n';
    std::cout << actor.health << '\n';

    if (actor.health <= 0) {
        engine.events.add(Die{actor});
        std::cout << "is ded" << '\n';
    }
}
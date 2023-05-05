#include "thrust.h"

#include "engine.h"
#include "hit.h"

Thrust::Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{5},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {}

void Thrust::execute(Engine&) {
    sprite.shift += direction;
    if (direction.x == 1) {
        sprite.angle = 90;
    } else if (direction.x == -1) {
        sprite.flip = true;
        sprite.angle = 270;
    } else if (direction.y == 1) {
        sprite.angle = 0;
        sprite.shift += direction * -3;
    } else if (direction.y == -1) {
        sprite.angle = 180;
        sprite.shift += direction * -2;
    }
}

void Thrust::when_done(Engine& engine) {
    sprite = original;
    engine.events.add(Hit(defender, damage));
}
#include "wonderstick.h"

#include "engine.h"
#include "hit.h"

WonderStick::WonderStick(Sprite& sprite, Vec direction, Actor& defender,
                         int damage)
    : Event{4},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {
    sprite.shift.y -= (sprite.size.y) / 4;
    sprite.shift.x -= (sprite.size.x) / 2;

    if (direction == Vec{1, 0}) {
        sprite.angle = 15;
        sprite.shift.y += 1;
    } else if (direction == Vec{-1, 0}) {
        sprite.angle = -15;
        sprite.shift.y += 1;

    } else if (direction == Vec{0, 1}) {
        sprite.angle = 0;
        sprite.shift.y += 1;

        // this->direction = direction * -1;
    } else if (direction == Vec{0, -1}) {
        sprite.angle = 0;
        sprite.shift.y += 1;
    }
}

void WonderStick::execute(Engine&) {
    sprite.shift += direction * 1;
}

void WonderStick::when_done(Engine& engine) {
    sprite = original;
    engine.events.add(Hit(defender, damage));
}
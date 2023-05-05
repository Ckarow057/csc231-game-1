#include "swing.h"

#include <iostream>

#include "engine.h"
#include "hit.h"

Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{5},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {}

void Swing::execute(Engine&) {
    sprite.shift += direction;
    if (direction.x == 1) {
        sprite.angle += 30;
    } else if (direction.x == -1) {
        sprite.flip = true;
        sprite.angle += 330;
    } else if (direction.y == 1) {
        sprite.angle = 0;
        sprite.shift += direction * -4;
    } else if (direction.y == -1) {
        sprite.angle = 180;
        sprite.shift += direction * -2;
    }
    // sprite.angle += 33;
}

void Swing::when_done(Engine& engine) {
    sprite = original;
    engine.events.add(Hit(defender, damage));
}
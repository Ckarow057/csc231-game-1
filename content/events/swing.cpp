#include "swing.h"

#include <cmath>

#include "engine.h"
#include "hit.h"

constexpr int duration = 5;

Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{duration},
      sprite{sprite},
      original{sprite},
      defender{defender},
      damage{damage},
      starting_angle{sprite.angle} {
    if (direction == Vec{1, 0}) {
        starting_angle = 0;
        delta_angle = 135.0 / (duration - 1);

    } else if (direction == Vec{-1, 0}) {
        starting_angle = 0;
        delta_angle = -135.0 / (duration - 1);
    } else if (direction == Vec{0, 1}) {
        double sign = std::copysign(1.0, starting_angle);  // 15-> 1, -15 -> -1
        starting_angle = 75 * sign * -1;
        delta_angle = 90.0 / (duration - 1) * sign;
        sprite.shift.y -= 12;

    } else if (direction == Vec{0, -1}) {
        sprite.shift.x = 0;
        double sign = std::copysign(1.0, starting_angle);  // 15-> 1, -15 -> -1
        starting_angle = -135 * sign * -1;
        delta_angle = 90.0 / (duration - 1) * sign;
    }
}

void Swing::execute(Engine&) {
    sprite.angle = starting_angle + delta_angle * frame_count;
}

void Swing::when_done(Engine& engine) {
    sprite = original;
    engine.events.add(Hit(defender, damage));
}
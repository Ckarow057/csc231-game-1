#include "swing.h"

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
    sprite.angle += 33;
}

void Swing::when_done(Engine& engine) {
    sprite = original;
    engine.events.add(Hit(defender, damage));
}
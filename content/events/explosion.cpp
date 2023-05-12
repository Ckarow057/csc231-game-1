#include "explosion.h"

#include "engine.h"
#include "hit.h"

Explosion::Explosion(Vec position, int damage)
    : position{position}, damage{damage} {}

void Explosion::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_animated_sprite("explosion", 2);
        sprite.shift(Vec{0, 15});
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(
        position, sprite.get_sprite());  // draw current animation frame
                                         // if (frame_count % 2 == 0) {
    sprite.update();
    // }
}

void Explosion::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.actor) {
        engine.events.add(Hit(*tile.actor, damage));
    }
}

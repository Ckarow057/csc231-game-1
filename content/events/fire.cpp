#include "fire.h"

#include "engine.h"
#include "hit.h"

Fire::Fire(Vec position, int damage) : position{position}, damage{damage} {}

void Fire::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_animated_sprite("fire", 2);
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(
        position, sprite.get_sprite());  // draw current animation frame
                                         // if (frame_count % 2 == 0) {
    sprite.update();
    // }
}

void Fire::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.actor) {
        engine.events.add(Hit(*tile.actor, damage));
    }
}

#include "magic.h"

#include "engine.h"
#include "hit.h"

Magic::Magic(Vec position, int damage) : position{position}, damage{damage} {}

void Magic::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_animated_sprite("magic", 2);
        sprite.shift(Vec{0, 20});
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(
        position, sprite.get_sprite());  // draw current animation frame
                                         // if (frame_count % 2 == 0) {
    sprite.update();
    // }
}

void Magic::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.actor) {
        engine.events.add(Hit(*tile.actor, damage));
    }
}

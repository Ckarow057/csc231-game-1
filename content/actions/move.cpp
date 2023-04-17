#include "move.h"

#include <iostream>

#include "actor.h"
#include "engine.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;

    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_wall()) {
        return failure();
    }

    // actor->change_direction(actor->get_direction());
    actor->move_to(position);
    return success();
}

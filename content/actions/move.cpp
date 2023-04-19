#include "move.h"

#include <iostream>

#include "actor.h"
#include "engine.h"
#include "open_door.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;
    actor->get_direction();
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_wall()) {
        return failure();
    }
    if (tile.is_door()) {
        actor->change_direction(direction);
        return alternative(OpenDoor());
    }

    actor->change_direction(direction);
    actor->move_to(position);
    return success();
}

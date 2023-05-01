#include "move.h"

#include <iostream>

#include "actor.h"
#include "engine.h"
#include "open_door.h"
#include "rest.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;
    actor->get_direction();
    Tile& tile = engine.dungeon.tiles(position);
    actor->change_direction(direction);

    if (tile.is_wall()) {
        return failure();
    }

    // attacking if tile.actor
    if (tile.actor) {
        return alternative(Rest());
    }

    if (tile.is_door()) {
        return alternative(OpenDoor(position));
    }

    actor->move_to(position);
    return success();
}

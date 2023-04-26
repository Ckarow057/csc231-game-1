#include "open_door.h"

#include "actor.h"
#include "engine.h"
#include "move.h"

Result OpenDoor::perform(Engine& engine) {
    Vec direction = actor->get_direction();
    Vec position = actor->get_position() + direction;
    Tile& tile = engine.dungeon.tiles(position);
    Door& door = engine.dungeon.doors.at(position);
    tile.walkable = true;
    door.open();
    actor->move_to(position);
    return success();
}
#include "open_door.h"

#include "actor.h"
#include "engine.h"
#include "move.h"
#include "updatefov.h"

OpenDoor::OpenDoor(Vec position) : position{position} {}

Result OpenDoor::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    Door& door = engine.dungeon.doors.at(position);
    tile.walkable = true;
    door.open();
    actor->move_to(position);
    engine.events.add(UpdateFOV{});
    return success();
}
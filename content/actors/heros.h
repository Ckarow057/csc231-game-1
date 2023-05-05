#pragma once

#include "cleaver.h"
#include "close_door.h"
#include "herotype.h"
#include "knife.h"
#include "move.h"
#include "none.h"
#include "open_door.h"
#include "rest.h"
#include "sword_big.h"

namespace Heros {
// Reaction = std::function<std::unique_ptr<Action>()>
// std::unique_ptr do_stuff();
const std::unordered_map<std::string, Reaction> keybindings = {
    {"A",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"S",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"D",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"W",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"R", []() { return std::make_unique<Rest>(); }},
    {"E", []() { return std::make_unique<CloseDoor>(); }}

};
constexpr int default_speed{8};
const HeroType nobody{"necro", default_speed, 20,
                      std::make_shared<Sword_big>(3), keybindings};
};  // namespace Heros

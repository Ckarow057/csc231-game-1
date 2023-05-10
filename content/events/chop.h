#pragma once
#include "event.h"
#include "sprite.h"
#include "vec.h"

class Actor;

class Chop : public Event {
public:
    Chop(Sprite& sprite, Vec direction, Actor& defender, int damage);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite original;
    Actor& defender;
    int damage;
    double starting_angle, delta_angle;
};
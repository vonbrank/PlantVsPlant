#pragma once
#include <iostream>

#include "Atlas.h"

extern Atlas atlas_sunflower_idle_left;
extern Atlas atlas_sunflower_idle_right;
extern Atlas atlas_sunflower_run_left;
extern Atlas atlas_sunflower_run_right;

#include "Player.h"

class SunflowerPlayer : public Player
{
public:
    SunflowerPlayer()
    {
        animation_idle_left.set_atlas(&atlas_sunflower_idle_left);
        animation_idle_right.set_atlas(&atlas_sunflower_idle_right);
        animation_run_left.set_atlas(&atlas_sunflower_run_left);
        animation_run_right.set_atlas(&atlas_sunflower_run_right);

        animation_idle_left.set_interval(75);
        animation_idle_right.set_interval(75);
        animation_run_left.set_interval(75);
        animation_run_right.set_interval(75);

        size.x = 96;
        size.y = 96;
    }

    void on_update(int delta_time) override
    {
        Player::on_update(delta_time);
        std::cout << "sun flower is updating..." << std::endl;
    }
};

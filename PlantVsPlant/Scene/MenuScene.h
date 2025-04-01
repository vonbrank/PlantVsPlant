#pragma once
#include <iostream>

#include "Animation.h"
#include "Atlas.h"
#include "Scene.h"
#include "SceneManager.h"

extern SceneManager scene_manager;

extern Atlas atlas_peashooter_run_right;

class MenuScene : public Scene
{
public:
    void on_enter() override
    {
        std::cout << "enter main menu" << std::endl;
        animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);
        animation_peashooter_run_right.set_interval(75);
        animation_peashooter_run_right.set_loop(false);
        animation_peashooter_run_right.set_animation_finish_callback(
            []()
            {
                scene_manager.switch_to(SceneManager::SceneType::Game);
            }
        );
    }

    void on_update(int delta_time) override
    {
        std::cout << "main menu update" << std::endl;
        animation_peashooter_run_right.on_update(delta_time);
    }

    void on_draw() override
    {
        outtextxy(10, 10, _T("main menu draw content"));
        animation_peashooter_run_right.on_draw(100, 100);
    }

    void on_input(const ExMessage& msg) override
    {
        if (msg.message == WM_KEYDOWN)
        {
            scene_manager.switch_to(SceneManager::SceneType::Game);
        }
    }

    void on_exit() override
    {
        std::cout << "main menu exit" << std::endl;
    }

private:
    Animation animation_peashooter_run_right;
};

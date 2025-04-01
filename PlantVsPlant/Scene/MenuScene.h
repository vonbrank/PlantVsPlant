#pragma once
#include <iostream>

#include "Animation.h"
#include "Atlas.h"
#include "Camera.h"
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
        animation_peashooter_run_right.set_loop(true);
    }

    void on_update(int delta_time) override
    {
        std::cout << "main menu update" << std::endl;
        camera.on_update(delta_time);
        animation_peashooter_run_right.on_update(delta_time);
    }

    void on_draw() override
    {
        outtextxy(10, 10, _T("main menu draw content"));
        const Vector2& camera_position = camera.get_position();
        animation_peashooter_run_right.on_draw((int)(100 - camera_position.x), (int)(100 - camera_position.y));
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
    Camera camera;
    Animation animation_peashooter_run_right;
};

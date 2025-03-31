#pragma once
#include <iostream>
#include "Scene.h"
#include "SceneManager.h"

extern SceneManager scene_manager;

class GameScene : public Scene
{
public:
    void on_enter() override
    {
        std::cout << "enter game scene" << std::endl;
    }

    void on_update() override
    {
        std::cout << "game scene update" << std::endl;
    }

    void on_draw() override
    {
        outtextxy(10, 10, _T("game menu draw content"));
    }

    void on_input(const ExMessage& msg) override
    {
        if (msg.message == WM_KEYDOWN)
        {
            scene_manager.switch_to(SceneManager::SceneType::Menu);
        }
    }

    void on_exit() override
    {
        std::cout << "game scene exit" << std::endl;
    }
};

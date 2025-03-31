#pragma once
#include <iostream>

#include "Scene.h"
#include "SceneManager.h"

extern SceneManager scene_manager;

class MenuScene : public Scene
{
public:
    void on_enter() override
    {
        std::cout << "enter main menu" << std::endl;
    }

    void on_update() override
    {
        std::cout << "main menu update" << std::endl;
    }

    void on_draw() override
    {
        outtextxy(10, 10, _T("main menu draw content"));
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
};

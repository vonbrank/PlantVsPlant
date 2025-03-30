#pragma once
#include <iostream>
#include "SceneManager.h"

extern SceneManager scene_manager;

class SelectorScene : public Scene
{
    void on_enter() override
    {
        std::cout << "enter selector scene" << std::endl;
    }

    void on_update() override
    {
        std::cout << "selector scene update" << std::endl;
    }

    void on_draw() override
    {
        outtextxy(10, 10, _T("selector scene draw content"));
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
        std::cout << "selector scene exit" << std::endl;
    }
};

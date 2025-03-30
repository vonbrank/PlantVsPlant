#pragma once
#include <iostream>
#include "Scene.h"

class GameScene : public Scene
{
public:
    void on_enter() override
    {
        std::cout << "enter game menu" << std::endl;
    }

    void on_update() override
    {
        std::cout << "game menu update" << std::endl;
    }

    void on_draw() override
    {
        outtextxy(10, 10, _T("game menu draw content"));
    }

    void on_input(const ExMessage& msg) override
    {
    }

    void on_exit() override
    {
        std::cout << "game menu exit" << std::endl;
    }
};

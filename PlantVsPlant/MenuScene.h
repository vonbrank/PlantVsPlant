#pragma once
#include <iostream>

#include "Scene.h"

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
    }

    void on_exit() override
    {
        std::cout << "main menu exit" << std::endl;
    }
};

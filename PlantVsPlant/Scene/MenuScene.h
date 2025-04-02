#pragma once
#include <iostream>

#include "Animation.h"
#include "Atlas.h"
#include "Camera.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Timer.h"

extern SceneManager scene_manager;

extern IMAGE img_menu_background;

class MenuScene : public Scene
{
public:
    void on_enter() override
    {
        mciSendString(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
    }

    void on_update(int delta_time) override
    {
    }

    void on_draw(const Camera& camera) override
    {
        putimage(0, 0, &img_menu_background);
    }

    void on_input(const ExMessage& msg) override
    {
        if(msg.message == WM_KEYUP)
        {
            mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
            scene_manager.switch_to(SceneManager::SceneType::Selector);
        }
    }

private:
};

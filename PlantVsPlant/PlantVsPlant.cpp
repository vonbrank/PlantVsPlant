#include <graphics.h>

#include "Atlas.h"
#include "Scene/GameScene.h"
#include "Scene/MenuScene.h"
#include "Scene/Scene.h"
#include "SceneManager.h"
#include "util.h"
#include "Scene/SelectorScene.h"

Scene* menu_scene;
Scene* game_scene;
Scene* selector_scene = nullptr;

SceneManager scene_manager;

void flip_atlas(Atlas& src, Atlas& dst)
{
    dst.clear();
    for (int i = 0; i < src.get_size(); i++)
    {
        IMAGE img_flipped;
        flip_image(src.get_image(i), &img_flipped);
        dst.add_image(img_flipped);
    }
}

int main(int argc, char* argv[])
{
    ExMessage msg;
    const int FPS = 60;

    initgraph(1280, 720);

    BeginBatchDraw();

    menu_scene = new MenuScene();
    game_scene = new GameScene();
    selector_scene = new SelectorScene();
    scene_manager.set_current_scene(menu_scene);

    while (true)
    {
        DWORD frame_start_time = GetTickCount();

        while (peekmessage(&msg))
        {
            scene_manager.on_input(msg);
        }

        scene_manager.on_update();

        cleardevice();
        scene_manager.on_draw();
        FlushBatchDraw();

        DWORD frame_end_time = GetTickCount();
        DWORD frame_delta_time = frame_end_time - frame_start_time;
        if (frame_end_time < 1000 / FPS)
        {
            Sleep(1000 / FPS - frame_delta_time);
        }
    }

    EndBatchDraw();

    return 0;
}

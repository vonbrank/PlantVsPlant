#pragma once
#include <functional>

#include "Atlas.h"
#include "util.h"

class Animation
{
public:
    Animation() = default;
    ~Animation() = default;

    void reset()
    {
        timer = 0;
        index_frame = 0;
    }

    void set_atlas(Atlas* new_atlas)
    {
        reset();
        atlas = new_atlas;
    }

    void set_loop(bool flag)
    {
        is_loop = flag;
    }

    void set_interval(int ms)
    {
        interval = ms;
    }

    int get_index_frame()
    {
        return index_frame;
    }

    IMAGE* get_frame()
    {
        return atlas->get_image(index_frame);
    }

    bool check_finished()
    {
        if (is_loop)
        {
            return false;
        }

        return (index_frame == atlas->get_size() - 1);
    }

    void on_update(int delta_time)
    {
        timer += delta_time;
        if (timer >= interval)
        {
            timer = 0;
            index_frame++;
            if (index_frame >= atlas->get_size())
            {
                index_frame = is_loop ? 0 : atlas->get_size() - 1;
                if (!is_loop && animation_finish_callback)
                {
                    animation_finish_callback();
                }
            }
        }
    }

    void on_draw(int x, int y) const
    {
        putimage_alpha(x, y, atlas->get_image(index_frame));
    }

    void set_animation_finish_callback(std::function<void()> callback)
    {
        animation_finish_callback = callback;
    }

private:
    int timer = 0;
    int interval = 0;
    int index_frame = 0;
    bool is_loop = true;
    Atlas* atlas = nullptr;
    std::function<void()> animation_finish_callback;
};

#pragma once
#include <graphics.h>

#include "Animation.h"
#include "Camera.h"
#include "PlayerID.h"

class Player
{
public:
    Player() = default;
    ~Player() = default;

    virtual void on_update(int delta_time)
    {
        int direction = is_right_key_down - is_left_key_down;

        if (direction != 0)
        {
            is_facing_right = direction > 0;
        }

        current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;

        current_animation->on_update(delta_time);
    }

    virtual void on_draw(const Camera& camera)
    {
        if (current_animation)
        {
            current_animation->on_draw(camera, (int)position.x, (int)position.y);
        }
    }

    virtual void on_input(const ExMessage& msg)
    {
        switch (msg.message)
        {
        case WM_KEYDOWN:
            switch (id)
            {
            case PlayerID::P1:
                switch (msg.vkcode)
                {
                case 0x41: // 'A'
                    is_left_key_down = true;
                    break;
                case 0x44: // 'D'
                    is_right_key_down = true;
                    break;
                }
                break;
            case PlayerID::P2:
                switch (msg.vkcode)
                {
                case VK_LEFT: // '<-'
                    is_left_key_down = true;
                    break;
                case VK_RIGHT: // '->'
                    is_right_key_down = true;
                    break;
                }
                break;
            default:
                break;
            }
            break;
        case WM_KEYUP:
            switch (id)
            {
            case PlayerID::P1:
                switch (msg.vkcode)
                {
                case 0x41: // 'A'
                    is_left_key_down = false;
                    break;
                case 0x44: // 'D'
                    is_right_key_down = false;
                    break;
                }
                break;
            case PlayerID::P2:
                switch (msg.vkcode)
                {
                case VK_LEFT: // '<-'
                    is_left_key_down = false;
                    break;
                case VK_RIGHT: // '->'
                    is_right_key_down = false;
                    break;
                }
                break;
            default:
                break;
            }
            break;
        default: break;
        }
    }

    void set_id(PlayerID id)
    {
        this->id = id;
    }

    void set_position(int x, int y)
    {
        position.x = x;
        position.y = y;
    }

protected:
    Vector2 position;

    Animation animation_idle_left;
    Animation animation_idle_right;
    Animation animation_run_left;
    Animation animation_run_right;
    Animation* current_animation = nullptr;

    PlayerID id = PlayerID::P1;

    bool is_left_key_down = false;
    bool is_right_key_down = false;

    bool is_facing_right = true;
};

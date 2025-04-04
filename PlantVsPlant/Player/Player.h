#pragma once
#include <graphics.h>

#include "Animation.h"
#include "Camera.h"
#include "Platform.h"
#include "PlayerID.h"

extern std::vector<Platform> platform_list;

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
            float distance = direction * run_velocity * delta_time;
            on_run(distance);
        }

        current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;

        current_animation->on_update(delta_time);

        move_and_collide(delta_time);
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
                case 0x57: // 'W'
                    on_jump();
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
                case VK_UP: // '↑'
                    on_jump();
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

    virtual void on_run(float distance)
    {
        position.x += distance;
    }

    virtual void on_jump()
    {
        if (velocity.y != 0)
        {
            return;
        }

        velocity.y += jump_velocity;
    }

protected:
    void move_and_collide(int delta_time)
    {
        velocity.y += gravity * delta_time;
        position += velocity * (float)delta_time;

        if (velocity.y > 0)
        {
            for (const Platform& platform : platform_list)
            {
                const Platform::CollisionShape& shape = platform.shape;
                bool is_collide_x = (max(position.x + size.x, shape.right) - min(position.x, shape.left) <= size.x + (
                    shape.right - shape.left));
                bool is_collide_y = (shape.y >= position.y && shape.y <= position.y + size.y);

                if (is_collide_x && is_collide_y)
                {
                    float delta_pos_y = velocity.y * delta_time;
                    float last_tick_foot_pos_y = position.y + size.y - delta_pos_y;
                    if (last_tick_foot_pos_y <= shape.y)
                    {
                        position.y = shape.y - size.y;
                        velocity.y = 0;

                        break;
                    }
                }
            }
        }
    }

protected:
    const float run_velocity = 0.55f;
    const float gravity = 1.6e-3f;
    const float jump_velocity = -0.85f;

protected:
    Vector2 size;
    Vector2 position;
    Vector2 velocity;

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

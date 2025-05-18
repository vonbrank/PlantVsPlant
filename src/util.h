#pragma once

#include <graphics.h>

#pragma comment(lib, "Msimg32.lib")

#include "Camera.h"

inline void putimage_alpha(int x, int y, IMAGE* img)
{
    if (img == nullptr)
    {
        return;
    }
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(
        GetImageHDC(NULL), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h,
        {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA}
    );
}

inline void putimage_alpha(const Camera& camera, int x, int y, IMAGE* img)
{
    if (img == nullptr)
    {
        return;
    }
    int w = img->getwidth();
    int h = img->getheight();
    const Vector2& pos_camera = camera.get_position();
    AlphaBlend(
        GetImageHDC(NULL), (int)(x - pos_camera.x), (int)(y - pos_camera.y), w, h,
        GetImageHDC(img), 0, 0, w, h,
        {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA}
    );
}

inline void putimage_alpha(int x, int y, int width, int height, IMAGE* img, int src_x, int src_y)
{
    if (img == nullptr)
    {
        return;
    }
    int w = width > 0 ? width : img->getwidth();
    int h = height > 0 ? height : img->getheight();
    AlphaBlend(
        GetImageHDC(NULL), x, y, w, h,
        GetImageHDC(img), src_x, src_y, w, h,
        {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA}
    );
}

inline void flip_image(IMAGE* src, IMAGE* dst)
{
    int width = src->getwidth();
    int height = src->getheight();
    Resize(dst, width, height);
    DWORD* src_buffer = GetImageBuffer(src);
    DWORD* dst_buffer = GetImageBuffer(dst);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index_src = y * width + x;
            int index_dst = y * width + (width - x - 1);
            dst_buffer[index_dst] = src_buffer[index_src];
        }
    }
}


inline void line(const Camera& camera, int x1, int y1, int x2, int y2)
{
    const Vector2& pos_camera = camera.get_position();
    line((int)(x1 - pos_camera.x), (int)(y1 - pos_camera.y), (int)(x2 - pos_camera.x), (int)(y2 - pos_camera.y));
}

inline void sketch_image(IMAGE* src, IMAGE* dst)
{
    int w = src->getwidth();
    int h = src->getheight();
    Resize(dst, w, h);
    DWORD* src_buffer = GetImageBuffer(src);
    DWORD* dst_buffer = GetImageBuffer(dst);
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int idx = y * w + x;
            dst_buffer[idx] = BGR(RGB(255, 255, 255)) | (src_buffer[idx] & 0xFF000000);
        }
    }
}
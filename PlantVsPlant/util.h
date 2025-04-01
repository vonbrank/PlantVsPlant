#pragma once

#include <graphics.h>

#pragma comment(lib, "Msimg32.lib")

inline void putimage_alpha(int x, int y, IMAGE* img)
{
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(
        GetImageHDC(NULL), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h,
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

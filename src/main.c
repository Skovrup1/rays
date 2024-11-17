#include <stdint.h>
#include <stdio.h>

#include "vec3.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

const uint32_t i_width = 256;
const uint32_t i_height = 256;
const uint32_t channels = 3;

#define SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int main() {
    uint8_t buf[i_width * i_height * channels];

    for (uint32_t j = 0; j < i_height; j++) {
        for (uint32_t i = 0; i < i_width; i++) {
            float r = (float)i / (i_width - 1);
            float g = (float)j / (i_height - 1);
            float b = 0.0;

            uint32_t ir = 255.99 * r;
            uint32_t ig = 255.99 * g;
            uint32_t ib = 255.99 * b;

            uint32_t idx = (i + j * i_width) * channels;
            buf[idx + 0] = ir;
            buf[idx + 1] = ig;
            buf[idx + 2] = ib;
        }
    }

    stbi_write_png("image.png", i_width, i_height, channels, buf, i_width * channels);

    return 0;
}

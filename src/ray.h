#pragma once

#include "vec3.h"

typedef struct ray_t {
    vec3_t origin;
    vec3_t dir;
} ray_t;

vec3_t ray_at(ray_t r, float t) {
    vec3_t rt = vec3_mul_scalar(r.dir, t);
    return vec3_add(r.origin, rt);
} 

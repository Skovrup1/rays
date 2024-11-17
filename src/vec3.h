#pragma once

#include <math.h>

typedef struct vec3_t {
    union {
        float data[3];
        struct {
            float x, y, z;
        };
        struct {
            float r, g, b;
        };
    };
} vec3_t;

vec3_t vec3_zero() { return (vec3_t){.x = 0.f, .y = 0.f, .z = 0.f}; }

vec3_t vec3_sub(vec3_t a, vec3_t b) {
    vec3_t result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

vec3_t vec3_add(vec3_t a, vec3_t b) {
    vec3_t result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

vec3_t vec3_mul(vec3_t a, vec3_t b) {
    vec3_t result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    return result;
}

vec3_t vec3_div(vec3_t a, vec3_t b) {
    vec3_t result;
    result.x = a.x / b.x;
    result.y = a.y / b.y;
    result.z = a.z / b.z;
    return result;
}

vec3_t vec3_mul_scalar(vec3_t v, float s) {
    vec3_t result;
    result.x = v.x * s;
    result.y = v.y * s;
    result.z = v.z * s;
    return result;
}

vec3_t vec3_div_scalar(vec3_t v, float s) {
    vec3_t result;
    result.x = v.x / s;
    result.y = v.y / s;
    result.z = v.z / s;
    return result;
}

void vec3_add_equal(vec3_t *a, vec3_t *b) {
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}

void vec3_sub_equal(vec3_t *a, vec3_t *b) {
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
}

void vec3_mul_equal(vec3_t *a, vec3_t *b) {
    a->x *= b->x;
    a->y *= b->y;
    a->z *= b->z;
}

void vec3_div_equal(vec3_t *a, vec3_t *b) {
    a->x *= b->x;
    a->y *= b->y;
    a->z *= b->z;
}

void vec3_mul_equal_scalar(vec3_t *v, float s) {
    v->x *= s;
    v->y *= s;
    v->z *= s;
}

void vec3_div_equal_scalar(vec3_t *v, float s) {
    v->x /= s;
    v->y /= s;
    v->z /= s;
}

float vec3_dot(vec3_t a, vec3_t b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3_t vec3_cross(vec3_t a, vec3_t b) {
    vec3_t result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

float vec3_length2(vec3_t v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

float vec3_length(vec3_t v) {
    return sqrt(vec3_length2(v));
}

vec3_t vec3_unit(vec3_t v) {
    return vec3_div_scalar(v, vec3_length(v));
}

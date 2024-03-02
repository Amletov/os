#ifndef BITMAP_H
#define BITMAP_H

#include "shared.h"
#include <math.h>
#include <stdlib.h>

#define MAP_OUT_OF_RANGE -1
#define MAP_NULL -2

/**
 * @brief Structure representing a bitmap.
 */
typedef struct bitmap {
  u8 *maps;     /**< Pointer to the array of bits */
  i32 capacity; /**< Maximum number of elements in the bitmap */
} bitmap_t;

/**
 * @brief Creates a new bitmap with the specified capacity.
 *
 * @param capacity Maximum number of elements in the bitmap.
 * @return Pointer to the newly created bitmap.
 */
bitmap_t *create_bitmap(i32 capacity) {
  bitmap_t *bitmap = (bitmap_t *)malloc(sizeof(bitmap_t));
  bitmap->capacity = capacity;
  bitmap->maps = (u8 *)calloc(ceil(capacity / sizeof(u8)), sizeof(u8));

  return bitmap;
}

/**
 * @brief Locks the specified element in the bitmap.
 *
 * @param bitmap Pointer to the bitmap structure.
 * @param index Index of the element to lock.
 * @return 0 if successful, MAP_NULL if the bitmap pointer is NULL,
 * MAP_OUT_OF_RANGE if the index is out of range.
 */
int lock_bitmap_element(bitmap_t *bitmap, int index) {
  if (bitmap->maps == NULL) {
    return MAP_NULL;
  }
  if (index < 0 || index >= bitmap->capacity) {
    return MAP_OUT_OF_RANGE;
  }

  int map_index = index / (sizeof(u8) * 8);
  i8 in_map_index = index % (sizeof(u8) * 8);
  bitmap->maps[map_index] |= 1 << in_map_index;

  return 0;
}

/**
 * @brief Unlocks the specified element in the bitmap.
 *
 * @param bitmap Pointer to the bitmap structure.
 * @param index Index of the element to unlock.
 * @return 0 if successful, MAP_NULL if the bitmap pointer is NULL,
 * MAP_OUT_OF_RANGE if the index is out of range.
 */
int unlock_bitmap_element(bitmap_t *bitmap, int index) {
  if (bitmap->maps == NULL) {
    return MAP_NULL;
  }
  if (index < 0 || index >= bitmap->capacity) {
    return MAP_OUT_OF_RANGE;
  }

  int map_index = index / (sizeof(u8) * 8);
  i8 in_map_index = index % (sizeof(u8) * 8);
  bitmap->maps[map_index] &= ~(1 << in_map_index);

  return 0;
}

/**
 * @brief Checks if the specified element in the bitmap is locked.
 *
 * @param bitmap Pointer to the bitmap structure.
 * @param index Index of the element to check.
 * @return 1 if the element is locked, 0 if it is unlocked, MAP_NULL if the
 * bitmap pointer is NULL, MAP_OUT_OF_RANGE if the index is out of range.
 */
int is_bitmap_element_locked(bitmap_t *bitmap, int index) {
  if (bitmap->maps == NULL) {
    return MAP_NULL;
  }
  if (index < 0 || index >= bitmap->capacity) {
    return MAP_OUT_OF_RANGE;
  }

  int map_index = index / (sizeof(u8) * 8);
  i8 in_map_index = index % (sizeof(u8) * 8);

  return (bitmap->maps[map_index] & (1 << in_map_index)) != 0;
}

#endif
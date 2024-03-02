#ifndef SUPERBLOCK_H
#define SUPERBLOCK_H

#include "shared.h"
#define MAGIC_NUMBER 1337

/**
 * @brief Structure representing a superblock of a file system.
 */
typedef struct superblock
{
    u16 block_size;             /**< Size of one block */
    u64 total_blocks;           /**< Total size of the file system in blocks */
    u32 total_inodes;           /**< Total number of inodes */
    char name[12];              /**< Name of the file system */
    u32 first_block;            /**< Number of the first block */
    u64 free_blocks;            /**< Free storage space in bytes */
    u32 first_bitmap_block;     /**< Size of the bitmap for free/allocated blocks */
    u32 first_bitmap_inode;     /**< Size of the bitmap for free/allocated inodes */
    u32 first_inode_block;      /**< Number of the first inode block */
    u32 magic_number;           /**< Magic number to identify the file system */
} superblock_t;


#endif 
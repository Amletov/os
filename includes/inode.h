#ifndef INODE_H
#define INODE_H

#include "shared.h"

#define I_DIR 128
#define I_SYS 64

/**
 * @brief Structure representing an inode in a file system.
 */
typedef struct inode
{
    u32 id;                 /**< Inode ID */
    u16 mode;               /**< Permissions */
    u16 uid;                /**< Owner ID */
    u32 size;               /**< Size of the file */
    u64 mtime;              /**< Modification time */
    u64 ctime;              /**< Creation time */
    u32 file_blocks;        /**< Number of blocks occupied by the file */
    u32 adresses[9];        /**< Array of block addresses */
} inode_t;

/**
 * @brief Sets the permissions of the inode.
 *
 * @param inode Pointer to the inode structure.
 * @param owner_permissions Permissions for the owner.
 * @param others_permissions Permissions for others.
 * @return 0 on success, -1 if an error occurs.
 */
int set_inode_mode(inode_t *inode, int owner_permissions, int others_permissions);

/**
 * @brief Sets the directory flag for the inode.
 *
 * @param inode Pointer to the inode structure.
 */
void set_inode_dir_flag(inode_t *inode);

/**
 * @brief Sets the system flag for the inode.
 *
 * @param inode Pointer to the inode structure.
 */
void set_inode_system_flag(inode_t *inode);

/**
 * @brief Displays the contents of the inode.
 *
 * @param inode Pointer to the inode structure.
 */
void display_inode(inode_t *inode);

#endif
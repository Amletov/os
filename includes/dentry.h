#ifndef DENTRY_H
#define DENTRY_H

/**
 * @brief Structure representing a directory entry (dentry).
 */
typedef struct dentry
{
    int inode_id;           /**< Inode ID of the directory entry */
    int parent_inode_id;    /**< Inode ID of the parent directory */
    char name[12];          /**< Name of the directory entry */
} dentry_t;

/**
 * @brief Creates a new directory entry (dentry) with the specified parameters.
 *
 * @param inode_id Inode ID of the directory entry.
 * @param parent_inode_id Inode ID of the parent directory.
 * @param dentry_name Name of the directory entry.
 * @return The newly created directory entry.
 */
dentry_t create_dentry(int inode_id, int parent_inode_id, char *dentry_name);


#endif
/**
 * @file	bst.h
 * @author	Simone Arcari, Gabriele Ortolani
 *
 * @abstract	header file
 * @discussion	This file contains the definitions of the structs and functions
 *		needed to work with binary search tree data structures.
 */



#ifndef BFS_H_
#define BFS_H_



typedef char* data_t;	// in this case data_t is a string

/**
 * @typedef	bst_t
 *		Contains all node properties. Each node stores information and 
 *		has pointers to be linked to the other nodes to form a tree 
 *		structure and in particular store the key value. 
 *
 * @field	data	information that the node stores
 * @field	parent	link to the parent node
 * @field	child	link to the first child node
 * @field	sibling	link to the right brother node
 * @field	key	unique reference of the node (integer)
*/
typedef struct bst {
	data_t  value;
	struct bst *parent;
	struct bst *left;
	struct bst *right;
	int key;
}bst_t;



/* FUNCTIONS FOR THE TREE STRUCTURE */

bst_t *Tree(data_t val, int k);

bst_t *insert_left(bst_t *P, bst_t *T);
bst_t *insert_right(bst_t *P, bst_t *T);
bst_t *insert(bst_t *P, bst_t *T);

void delete_left(bst_t *T);
void delete_right(bst_t *T);

bst_t *lookup(bst_t *T, int k);
bst_t *lookupRic(bst_t *T, int k);

bst_t *min(bst_t *T);
bst_t *max(bst_t *T);

bst_t *successor(bst_t *T);
bst_t *predecessor(bst_t *T);

void successor_ord_key(bst_t *T);
void predecessor_ord_key(bst_t *T);

#endif /*BFS_H_*/

/**
 * @file	bst.c
 * @author	Simone Arcari, Gabriele Ortolani
 *
 * @discussion	This file contains the source code of the functions
 *		needed to work with binary search tree data structures.
 */



#include <stdio.h>
#include <stdlib.h>
#include "bst.h"



bst_t *Tree(data_t val, int k) {
	
	bst_t *new = malloc(sizeof(bst_t));
	
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->key = k;
	new->value = val;
	
	return new;
}

bst_t *insert_left(bst_t *P, bst_t *T) {
	
	if(P->left == NULL) {
		T->parent = P;
		P->left = T;
		return T;
	}
	
	return NULL;
}

bst_t *insert_right(bst_t *P, bst_t *T) {
	
	if(P->right == NULL) {
		T->parent = P;
		P->right = T;
		return T;
	}
	
	return NULL;
}

bst_t *insert(bst_t *P, bst_t *T) {

	if(P==NULL || T==NULL)
		return NULL;
	
	if(T->key < P->key) {
		if(P->left == NULL)
			return insert_left(P, T);
			
		return insert(P->left, T);
	}else {
		if(P->right == NULL)
			return insert_right(P, T);

		return insert(P->right, T);
	}
}

void delete_left(bst_t *T) {

	if(T->left != NULL) {
	
		delete_left(T->left);
		delete_right(T->left);
		
		free(T->left);
		T->left = NULL;
	}
}

void delete_right(bst_t *T) {

	if(T->right != NULL) {
	
		delete_left(T->right);
		delete_right(T->right);
		
		free(T->right);
		T->right = NULL;
	}
}

bst_t *lookup(bst_t *T, int k){
/*
	@descr: This function return the node that you search with given key
*/
	bst_t *current = T;
	while (current !=NULL && current->key != k){
		if (k < (current->key)){
			current = current->left;
		}else {
			current = current->right;
		}
	}
	return current;
} 

bst_t *lookupRic(bst_t *T, int k){
/*
	@descr: this function return recursively the node that you search with 
		given key
*/
	if (T !=NULL && T->key != k){
		return T;
	}else if(k < T->key){
		return lookupRic(T->left, k);
	}else{
		return lookupRic(T->right, k);
	}
}

bst_t *min(bst_t *T) {
/*
	@descr: this function return the node with the minor key
*/

	while (T->left != NULL){
		T=T->left;
	}
	return T;
}


bst_t *max(bst_t *T) {

	while (T->right != NULL){
		T=T->right;
	}
	return T;
}
	
bst_t *successor(bst_t *T) {
/*
	CASE 1: if T has a right child: the successor is the least of the right 
	subtree.
	
	CASE 2: if T does not have a right child: you rise through the parent, 
	the successor is the first avo such for which T is in the left under 
	tree.
*/
	if (T == NULL) 
		return NULL;
	
	if (T->right != NULL){		// CASE 1
		return min(T->right);
	}else{
		bst_t *P = T->parent;
		while(P != NULL && T==P->right){	// CASE 2
			T = P;//increase 1
			P = P->parent;//increase 2
		}
		return P;
	}
}

bst_t *predecessor(bst_t *T) {
/*
	CASE 1: if T has a left child: the predecessor is the most of the right 
	subtree.
	
	CASE 2: if T does not have a left child: you rise through the parent, 
	the predecessor is the first avo such for which T is in the right under 
	tree.
*/
	if (T == NULL) 
		return NULL;
	
	if (T->left != NULL){		// CASE 1
		return max(T->left);
	}else{
		bst_t *P = T->parent;
		while(P != NULL && T==P->left){ 	// CASE 2
			T = P;//increase 1
			P = P->parent;//increase 2
		}
		return P;
	}
}

void successor_ord_key(bst_t *T) {

	bst_t *current = min(T);
	while (current != NULL){
		printf("key: %d\tvalue: %s\n",current->key,current->value);
		current =  successor(current);
	}
}

void predecessor_ord_key(bst_t *T) {

	bst_t *current = max(T);
	while (current != NULL){
		printf("key: %d\tvalue: %s\n",current->key,current->value);
		current =  predecessor(current);
	}
}

void link(bst_t *p, bst_t *u, int x) {

	if(u != NULL)
		u->parent = p;
	
	if(p != NULL) {
		if(x < p->key)
			p->left = u;
		else
			p->right = u;
	}
}

bst_t *remove_node(bst_t *T, int x) {

	bst_t *u = lookup(T, x);
	
	if (u != NULL) { /* case 3 */
		if(u->left != NULL && u->right != NULL) {
			
			bst_t *s = successor(u);
			
			u->key = s->key;
			u->value = s->value;
			x = s->key;
			
			u = s;
		}
		
		bst_t *t;
		if(u->left != NULL && u->right == NULL) 
			t = u->left;	// case 2 only sx child
		else
			t = u->right;	// case 2 only dx child
		
		link(u->parent, t, x);
		
		if(u->parent == NULL) {
			T = t;
			T->parent = NULL;
		}
		
		free(u);
	}

	return T;
}

void pre_order(bst_t *T) {
/*
	@descr: visita tutti i nodi dell'albero 
	@param T: puntatore ad un nodo (albero)
*/
	if(T!=NULL) {
		printf("data: %s\n", T->value);
		pre_order(T->left);
		pre_order(T->right);
	}
}

void in_order(bst_t *T) {
/*
	@descr: visita tutti i nodi dell'albero
	@param: puntatore ad un nodo (albero)
*/
	if(T!=NULL) {
		in_order(T->left);
		printf("data: %s\n", T->value);
		in_order(T->right);
	}
}

void post_order(bst_t *T) {
/*
	@descr: visita tutti i nodi dell'albero
	@param: puntatore ad un nodo (albero)
*/
	if(T!=NULL) {
		post_order(T->left);
		post_order(T->right);
		printf("data: %s\n", T->value);
	}
}

/**
 * @file	main.c
 * @author	Simone Arcari, Gabriele Ortolani
 *
 * @abstract	main file
 * @discussion	This file contains some examples of use of the binary search 
 *		tree (bst) library.
 */



#include <stdio.h>
#include <stdlib.h>
#include "bst.h"



int main(void){
	
	/* make some value */
	data_t val1 = "grandson1";
	data_t val2 = "son1";
	data_t val3 = "grandson2";
	data_t val4 = "father";
	data_t val5 = "grandson3";
	data_t val6 = "son2";
	data_t val7 = "grandson4";
	
	/* make some node */
	bst_t *A = Tree(val1, 1);
	bst_t *B = Tree(val2, 2);
	bst_t *C = Tree(val3, 3);
	bst_t *D = Tree(val4, 4);
	bst_t *E = Tree(val5, 5);
	bst_t *F = Tree(val6, 6);
	bst_t *G = Tree(val7, 7);

	/* make tree */
	insert(D,F);
	insert(D,E);
	insert(D,B);
	insert(D,C);
	insert(D,A);
	insert(D,G);
	
	printf("print the keys in ascending order:\n");
	successor_ord_key(D);
	puts("");
	
	printf("print the keys in descending order:\n");
	predecessor_ord_key(D);
	puts("");
	
	printf("remove the root (key = 4);\n");
	printf("and print the keys in ascending order:\n");
	D = remove_node(D,4);
	successor_ord_key(D);
	
	return 0;
}

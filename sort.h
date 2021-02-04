#ifndef _SORT_H_
#define _SORT_H_
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* ========== Print functions ========== */

/* Prints an array of integer */
void print_array(const int *array, size_t size);

/* Prints a list of integers */
void print_list(const listint_t *list);


/* ========== Sorting algorithms ========== */

/* 0 - Bubble sort */
void bubble_sort(int *array, size_t size);

/* 1 - List sort */
void insertion_sort_list(listint_t **list);
void node_swapper(listint_t *to_front, listint_t *to_back);

/* 2 - Selection sort */
void selection_sort(int *array, size_t size);

/* 3 - Quick sort */
void quick_sort(int *array, size_t size);

/* 100 - Shell Sort */
void shell_sort(int *array, size_t size);

/* 101-cocktail_sort_list */
void cocktail_sort_list(listint_t **list);

/* 103-merge_sort */
void merge_sort(int *array, size_t size);

/* 104-heap_sort */
void heap_sort(int *array, size_t size);

/* 107-quick_sort_hoare */
void quick_sort_hoare(int *array, size_t size);

#endif

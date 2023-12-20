#ifndef DECK_H
#define DECK_H

#include <stdio.h>

/**
 * enum kind_e - asd
 *
 * @SPADE: 0
 * @HEART: 1
 * @CLUB: 2
 * @DIAMOND: 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointsdfe
 * @prev: Psdflist
 * @next: Pofsdthe list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * struct card_s - Pasd
 *
 * @value: das
 * @kind: Kidas
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

void sort_deck(deck_node_t **deck);
int less_than(const card_t *a, const card_t *b);
void cocktail_sort_list(deck_node_t **list);

#endif

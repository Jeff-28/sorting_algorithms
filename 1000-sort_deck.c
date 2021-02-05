#include "deck.h"

/**
 * swap - swaps card's positions
 * @deck: pointer to deck of cards
 * @card: pointer to a card
 *
 * Return: nothing
 */
void swap(deck_node_t **deck, deck_node_t *card)
{
	card->next->prev = card->prev;
	if (card->prev)
		card->prev->next = card->next;
	else
		*deck = card->next;
	card->prev = card->next;
	card->next = card->next->next;
	if (card->next)
		card->next->prev = card;
	card->prev->next = card;
}
/**
 * get_idx - returns the unique index of the card
 * @str: string representation of the card's value
 *
 * Return: index of the card
 */
int get_idx(const char *str)
{
	int i;
	char *card[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
					"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, card[i]) == 0)
			return (i);
	}
	return (i);
}
/**
 * sort_deck - sorts a deck of 52 cards, from Ace to King
 *				and from Spades to Diamonds
 * @deck: pointer to deck of cards
 *
 * Return: nothing
 */
void sort_deck(deck_node_t **deck)
{
	int card1, card2, flag = 1;
	deck_node_t *temp;

	if (!deck || !*deck)
		return;
	temp = *deck;
	while (flag)
	{
		flag = 0;
		while (temp->next)
		{
			card1 = get_idx(temp->card->value) + 13 * temp->card->kind;
			card2 = get_idx(temp->next->card->value) + 13 * temp->next->card->kind;
			if (card1 > card2)
			{
				swap(deck, temp);
				flag = 1;
			}
			else
				temp = temp->next;
		}
		if (flag == 0)
			break;
		flag = 0;
		while (temp->prev)
		{
			card1 = get_idx(temp->card->value) + 13 * temp->card->kind;
			card2 = get_idx(temp->prev->card->value) + 13 * temp->prev->card->kind;
			if (card1 < card2)
			{
				swap(deck, temp->prev);
				flag = 1;
			}
			else
				temp = temp->prev;
		}
	}
}

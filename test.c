#include <stdio.h>
#include <stdlib.h>
typedef struct s_eleman
{
	char *isim;
	int maas;
	struct s_eleman *next;
} t_eleman;

void add_list_eleman(t_eleman *eleman, char *isim, int maas)
{
	while(eleman->next != NULL)
		eleman = eleman->next;
	t_eleman *newlist;

	newlist = malloc(sizeof(t_eleman));
	newlist->isim = isim;
	newlist->maas = maas;
	newlist->next = NULL;
	eleman->next = newlist;
}

void print_all_eleman(t_eleman *eleman)
{
	while(eleman != NULL)
	{
		printf("İsim: %s // Maas: %d\n", eleman->isim, eleman->maas);
		eleman = eleman->next;
	}
}

int main(void)
{
	t_eleman *list;
	list = malloc(sizeof(t_eleman));
	list->isim = "Talha";
	list->maas = 5000;
	list->next = NULL;
	add_list_eleman(list, "Ahmet", 5000);
	add_list_eleman(list, "Almet2", 3000);
	print_all_eleman(list);
}
#pragma once
#include <stdio.h>

typedef void (*destroy_node_data)(void *data);

struct klist_node {
	void *data;
	char *key;
	destroy_node_data destroy_data;
	struct klist_node *prev;
	struct klist_node *next;
};

struct klist {
	struct klist_node *first;
	struct klist_node *last;
	int mode;
	int size;
};

struct klist *klist_init(void);
void *klist_get_first(struct klist *list);
void klist_add_first(struct klist *list, void *data, const char *data_key, destroy_node_data destroy_data);
void klist_add_last(struct klist *list, void *data, const char *data_key, destroy_node_data destroy_data);
void *klist_remove_first(struct klist *list);
void *klist_find_element_with_key(struct klist *list, char *data_key);
int klist_remove_element(struct klist *list, void *data);
int klist_delete_element(struct klist *list, void *data);

void klist_destroy(struct klist *list);

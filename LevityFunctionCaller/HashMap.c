//
//  HashMap.c
//  LevityFunctionCaller
//
//  Created by 褚晓敏 on 11/21/15.
//  Copyright © 2015 Levity. All rights reserved.
//

#include "HashMap.h"

UInt hash(const char *key) {
	UInt sum = 0x72814;
	Int16 c;
	
	while ((c = *key++) != 0) {
		sum ^= c;
		sum += c;
	}
	
	return sum;
}

HashMap *HashMapNew(UInt buckets, VoidFunc dataDestroy) {
	HashMap *new = (HashMap *)malloc(sizeof(HashMap));
	if (new == NULL) {
		return NULL;
	}
	new->array = (HashElement **)malloc(sizeof(HashElement *) * buckets);
	if (new->array == NULL) {
		free(new);
		return NULL;
	}
	new->count = 0;
	new->buckets = buckets;
	new->dataDestroy = dataDestroy;
	return new;
}

void HashMapDestroy(HashMap *self) {
	for (UInt i = 0; i < self->buckets; i++) {
		if (self->array[i] != NULL) {
			while (self->array[i] != NULL) {
				HashElement *temp = self->array[i];
				self->array[i] = temp->next;
				if (self->dataDestroy != NULL) {
					self->dataDestroy(temp->data);
				}
				free(temp);
			}
		}
	}
	free(self->array);
	free(self);
}

UInt HashMapInsert(HashMap *self, void *data, const char *key) {
	UInt index = hash(key);
	HashElement *new = (HashElement *)malloc(sizeof(HashElement));
	if (new == NULL) {
		return -1;
	}
	new->data = data;
	new->next = NULL;
	strcpy(new->key, key);
	if (self->array[index] == NULL) {
		self->array[index] = new;
		return 0;
	}
	HashElement *temp = self->array[index];
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new;
	return 0;
}

void *HashMapLookUp(HashMap *self, const char *key) {
	UInt index = hash(key);
	if (self->array[index] == NULL) {
		return NULL;
	}
	for (HashElement *temp = self->array[index]; temp != NULL; temp = temp->next) {
		if (strcmp(temp->key, key) == 0) {
			return temp->data;
		}
	}
	return NULL;
}
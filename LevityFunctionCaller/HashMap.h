//
//  HashMap.h
//  LevityFunctionCaller
//
//  Created by 褚晓敏 on 11/21/15.
//  Copyright © 2015 Levity. All rights reserved.
//

#ifndef HashMap_h
#define HashMap_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <strings.h>
#include "TypeRenaming.h"

typedef struct HashElement_ {
	void *data;
	char key[31];
	struct HashElement_ *next;
} HashElement;

typedef struct HashMap_ {
	HashElement **array;
	UInt buckets, count;
} HashMap;

UInt hash(const char *key);

HashMap *HashMapNew(UInt buckets);

void HashMapDestroy(HashMap *self);

UInt HashMapInsert(HashMap *self, void *data, const char *key);

void *HashMapLookUp(HashMap *self, const char *key);

#endif /* HashMap_h */

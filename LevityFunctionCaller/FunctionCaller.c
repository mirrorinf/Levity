//
//  FunctionCaller.c
//  LevityFunctionCaller
//
//  Created by 褚晓敏 on 11/22/15.
//  Copyright © 2015 Levity. All rights reserved.
//

#include "FunctionCaller.h"

LevityCallerEnvironment *LevityCallerEnvironmentNew(UInt functionTableSize) {
	LevityCallerEnvironment *new = (LevityCallerEnvironment *)malloc(sizeof(LevityCallerEnvironment));
	if (new == NULL) {
		return NULL;
	}
	new->functions = HashMapNew(functionTableSize, NULL);
	if (new->functions == NULL) {
		free(new);
		return NULL;
	}
	return new;
}

void LevityCallerEnvironmentDestroy(LevityCallerEnvironment *self) {
	HashMapDestroy(self->functions);
	free(self);
}

void LevityCallerEnvironmentFunctionRegist(LevityCallerEnvironment *self, VoidSFunc func, const char *identifier) {
	HashMapInsert(self->functions, func, identifier);
}

void *LevityCallerEnvironmentFunctionCall(LevityCallerEnvironment *self, const char *func, void *data) {
	VoidSFunc work = (VoidSFunc)HashMapLookUp(self->functions, func);
	if (work == NULL) {
		return NULL;
	}
	void *result = work(data);
	return result;
}
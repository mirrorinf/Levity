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
}

void LevityCallerEnvironmentDestroy(LevityCallerEnvironment *self);

void LevityCallerEnvironmentFunctionRegist(LevityCallerEnvironment *self, VoidSFunc func, const char *identifier);

void LevityCallerEnvironmentFunctionCall(LevityCallerEnvironment *self, const char *func);
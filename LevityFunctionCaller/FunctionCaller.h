//
//  FunctionCaller.h
//  LevityFunctionCaller
//
//  Created by 褚晓敏 on 11/22/15.
//  Copyright © 2015 Levity. All rights reserved.
//

#ifndef FunctionCaller_h
#define FunctionCaller_h

#include <stdio.h>
#include "HashMap.h"

typedef struct LevityCallerEnvironment_ {
	HashMap *functions;
} LevityCallerEnvironment;

LevityCallerEnvironment *LevityCallerEnvironmentNew(UInt functionTableSize);

void LevityCallerEnvironmentDestroy(LevityCallerEnvironment *self);

void LevityCallerEnvironmentFunctionRegist(LevityCallerEnvironment *self, VoidSFunc func, const char *identifier);

void *LevityCallerEnvironmentFunctionCall(LevityCallerEnvironment *self, const char *func, void *data);

#endif /* FunctionCaller_h */

//
//  FileManager.c
//  LevityChief
//
//  Created by 褚晓敏 on 11/21/15.
//  Copyright © 2015 Levity. All rights reserved.
//

#include "FileManager.h"

void initTheSourceFile(FILE *source) {
	fprintf(source, "#include <stdio.h>\n#include <stdlib.h>\n");
	fprintf(source, "#include <string.h>\n#incldue <unistd.h>\n");
	fprintf(source, "#include \"Project.h\"\n");
	fprintf(source, "int main() {\n");
}

void enclosingTheSourceFile(FILE *source) {
	fprintf(source, "\nreturn 0;\n}");
}
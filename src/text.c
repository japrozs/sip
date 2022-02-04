#include <text.h>
#include <utils.h>

#define MAX 8196

char *get_main_src(char *name){
	char *str = malloc(sizeof(char) * MAX);

	sprintf(str, 
		"#include <%s.h>\n"
		"\n"
		"int main(int argc, char **argv){\n"
		"	printf(\"hello, universe!\\n\");\n"
		"\n"
		"	return 0;\n"
		"}\n",
		name
	);

	return str;
}

char *get_header_src(char *name){
	char *str = malloc(sizeof(char) * MAX);
	
	sprintf(str, 
		"#ifndef %s_H\n"
		"#define %s_H\n\n"
		"#include <stdio.h>\n\n"
		"#endif // %s_H\n",
		name,
		name,
		name
	);

	return str;
}

char *get_make_src(char *name){
	char *str = malloc(sizeof(char) * MAX);

	sprintf(str, 
		"CC = gcc\n"
		"CFLAGS = -Wall -pedantic -I include -g \n"
		"SRC = $(wildcard *.c src/*.c src/**/*.c src/**/**/*.c)\n"
		"HEAD = $(wildcard include/*.h include/**/*.h)\n"
		"OBJ = $(SRC:.c=.o)\n"
		"EXEC = bin/%s\n"
		"\n"
		"all: clean $(OBJ) $(EXEC) $(HEAD)\n"
		"\n"
		"$(EXEC): $(OBJ)\n"
		"	$(CC) $^ -o $@\n"
		"	rm -rf src/*.o\n"
		"	rm -rf src/**/*.o\n"
		"\n"
		"%%.o: %%.cpp\n"
		"	$(CC) $(CFLAGS) $^ -o $@\n"
		"\n"
		"clean:\n"
		"	rm -rf *.o src/*.o src/**/*.o $(EXEC)\n",
		name
	);

	return str;
}

char *get_git_src(char *name){
	char *str = malloc(sizeof(char) * MAX);

	sprintf(str, 
		"# Prerequisites\n"
		"*.d\n"
		"\n"
		"# Object files\n"
		"*.o\n"
		"*.ko\n"
		"*.obj\n"
		"*.elf\n"
		"\n"
		"# Linker output\n"
		"*.ilk\n"
		"*.map\n"
		"*.exp\n"
		"\n"
		"# Precompiled Headers\n"
		"*.gch\n"
		"*.pch\n"
		"\n"
		"# Libraries\n"
		"*.lib\n"
		"*.a\n"
		"*.la\n"
		"*.lo\n"
		"\n"
		"# Shared objects (inc. Windows DLLs)\n"
		"*.dll\n"
		"*.so\n"
		"*.so.*\n"
		"*.dylib\n"
		"\n"
		"# Executables\n"
		"*.exe\n"
		"*.out\n"
		"*.app\n"
		"*.i*86\n"
		"*.x86_64\n"
		"*.hex\n"
		"\n"
		"# Debug files\n"
		"*.dSYM/\n"
		"*.su\n"
		"*.idb\n"
		"*.pdb\n"
		"\n"
		"# Kernel Module Compile Results\n"
		"*.mod*\n"
		"*.cmd\n"
		".tmp_versions/\n"
		"modules.order\n"
		"Module.symvers\n"
		"Mkfile.old\n"
		"dkms.conf\n"
	);

	return str;
}

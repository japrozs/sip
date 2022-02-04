#include <sip.h>
#include <unistd.h>
#include <sys/stat.h>
#include <new.h>
#include <dirent.h>
#include <errno.h>
#include <text.h>

#define MAXBUF 4096

void make_dir(char *name){
	DIR* dir = opendir(name);
	if(dir){
		fprintf(stderr, "Error :: Directory \"%s\" already exists!\n", name);
		exit(EXIT_FAILURE);
	}

	// create the directory
	int ret = mkdir(name, 0777);
	if(ret != 0){
		printf("Couldn't create directory '%s'\n", name);
		printf("%s\n", strerror(ret));
		exit(EXIT_FAILURE);
	}
}

void new_module(char *name){
	// check if a directory exists
	make_dir(name);

	// Create the folder
	char bin[MAXBUF];
	char include[MAXBUF];
	char src[MAXBUF];

	sprintf(bin, "./%s/bin/", name);
	sprintf(include, "./%s/include/", name);
	sprintf(src, "./%s/src/", name);

	make_dir(src);
	make_dir(bin);
	make_dir(include);

	// Create the files
	char header_file[MAXBUF];
	char main_file[MAXBUF];
	char makefile[MAXBUF];
	char gitignore[MAXBUF];

	sprintf(header_file, "./%s/include/%s.h", name, name);
	sprintf(main_file, "./%s/src/main.c", name);
	sprintf(makefile, "./%s/Makefile", name);
	sprintf(gitignore, "./%s/.gitignore", name);

	printf("%s\n", header_file);
	printf("%s\n", main_file);
	printf("%s\n", makefile);
	printf("%s\n", gitignore);

	FILE *header = fopen(header_file, "w");
	FILE *main = fopen(main_file, "w");
	FILE *make = fopen(makefile, "w");
	FILE *git = fopen(gitignore, "w");

	fputs(get_header_src(name), header);
	fputs(get_main_src(name), main);
	fputs(get_make_src(name), make);
	fputs(get_git_src(name), git);

	fclose(header);
	fclose(main);
	fclose(make);
	fclose(git);
}

#include <sip.h>

int main(int argc, char **argv){
	if(argc == 1){
		printf("hello message!\n");
		exit(EXIT_SUCCESS);
	}else if(argc < 4){
		char *cmd = argv[1];
		char *name = argv[2];
		if(strcmp(cmd, "new") == 0){
			new_module(name);
		}
	}else{
		perror("error : unknown number of arguments!\n");
	}

	return 0;
}

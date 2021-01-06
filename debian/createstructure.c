#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Support functions
char* path();
char* connect_strings(char* first, char* second);
int exist (int argc, char **argv, char *item);
int min(int a, int b);

// Global variables
bool verbose = false;

int main(int argc, char **argv)
{
	if (argc == 1 || exist(argc, argv, "-h") || exist(argc, argv, "--help"))
	{
		printf("---Help---\n");
	}
		
	if (exist(argc, argv, "-v") || exist(argc, argv, "--verbose"))
	{
		printf("---Verbose---\n");
		verbose = true;
		printf("Enabled verbose\n");
	}
		
	if (exist(argc, argv, "-V") || exist(argc, argv, "--version"))
	{
		printf("---Version---\n");
		if (verbose)
			system("pip3 show createstructure");
		else
			system("pip3 freeze | grep createstructure");		
	}
	
	if (exist(argc, argv, "-l") || exist(argc, argv, "--login"))
		printf("Login\n");
		
	if (exist(argc, argv, "-t") || exist(argc, argv, "--token"))
		printf("Token\n");
		
	for(int i = 0; i < argc; ++i)
		printf("%d. %s\n", i, argv[i]);
	
	// Get wanted path
	char* p = path();
	
	// Delate last results if exists
	system(connect_strings("sed -i '/alias createstructure/d' ", p));

	// Create file puntator
	FILE *pAlias;
	pAlias = fopen(p, "a+");
	
	// Print on my file
	fprintf(pAlias, "alias createstructure='echo hiii'\n");
	
	// End
	printf("Done\n");
	fclose(pAlias);
	return 0;
}

char* path()
{
	// Get home path
	char* home = getenv("HOME");

	// Save additional part of the path
	char* path = "/.bash_aliases";
	
	// Return the final path variable
	return connect_strings(home, path);
}

char* connect_strings(char* first, char* second)
{
	char* final = malloc(strlen(first) + strlen(second) + 1);
	strcpy(final, first);
	strcat(final, second);
	
	return final;
}

int exist (int argc, char **argv, char *item)
{
	for (int i = 0; i < argc; ++i)
		if (strncmp(argv[i], item, min(strlen(argv[i]), strlen(argv[i]))) == 0)
			return i;
			
	return 0;
}

int min(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
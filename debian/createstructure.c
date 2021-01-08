#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Support functions
int exist (int argc, char **argv, char *item);
int min(int a, int b);
char* connect_strings(char* first, char* second);
char* read_by_terminal(char* input);
char* choppy(char *s);
void check_pip_package_version();
void get_setup();

// Action functions
void help();
void set_verbose();
void version();
void login();
void createstructure();

// Global variables
bool verbose = false;
char* TOKEN;
char* SOURCES;
char* ORGANIZATION_NAME;
char* IGNORE;

int main(int argc, char **argv)
{
	if (exist(argc, argv, "-h") || exist(argc, argv, "--help"))
	{
		help(argc, argv);
		return 0;
	}	
	if (exist(argc, argv, "-v") || exist(argc, argv, "--verbose"))
	{
		set_verbose();
		//return 0;
	}
		
	if (exist(argc, argv, "-V") || exist(argc, argv, "--version"))
	{
		version();
		return 0;
	}
	
	if (exist(argc, argv, "-l") || exist(argc, argv, "--login"))
	{
		login();
		return 0;
	}

	// check_pip_package_version(); // Not necessary
	get_setup();
	createstructure();	// Run core

	// End
	return 0;
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

char* connect_strings(char* first, char* second)
{
	char* final = malloc(strlen(first) + strlen(second) + 1);
	strcpy(final, first);
	strcat(final, second);
	
	return final;
}

char* read_by_terminal(char* input)
{
	FILE *cmd = popen(input, "r");
    char *result = malloc(1024); // max return size
    char *result2 = malloc(1024); // max return size
	result2 = "";
    while (fgets(result, sizeof(result), cmd) !=NULL)
        result2 = connect_strings(result2, result);
	pclose(cmd);
	return choppy(result2);
}

char* choppy(char *s)
{
    char *n = malloc( strlen( s ? s : "\n" ) );
    if( s )
        strcpy( n, s );
    n[strlen(n)-1]='\0';
    return n;
}

void check_pip_package_version()
{
	if(read_by_terminal("dpkg -s createstructure | grep -i version | sed 's/Version: //'") != read_by_terminal("pip3 freeze | grep createstructure | sed 's/createstructure==//'"))
	{
		char* install_string = connect_strings("pip3 install createstructure==", read_by_terminal("dpkg -s createstructure | grep -i version | sed 's/Version: //'"));

		if (verbose)
			system(install_string);
		else
			read_by_terminal(install_string);
	}
}

void get_setup()
{
	TOKEN = read_by_terminal("cat /etc/createstructure.conf | grep 'token' | sed 's/token=//' | sed 's/token= //'");
	SOURCES = read_by_terminal("cat /etc/createstructure.conf | grep 'sources' | sed 's/sources=//' | sed 's/sources= //'");
	ORGANIZATION_NAME = read_by_terminal("cat /etc/createstructure.conf | grep 'organization_name' | sed 's/organization_name=//' | sed 's/organization_name= //'");
	IGNORE = read_by_terminal("cat /etc/createstructure.conf | grep 'ignore' | sed 's/ignore=//' | sed 's/ignore= //'");
}

void help(int argc, char **argv)
{
	if (exist(argc, argv, "-v") || exist(argc, argv, "--verbose"))
	{
		printf("---Help---\n");
		printf("Open man...\n");
	}
	system("man createstructure");
}

void set_verbose()
{
	printf("---Verbose---\n");
	verbose = true;
	printf("Enabled verbose\n");
}

void version()
{
	if (verbose)
		printf("---Version---\n");

	if (verbose)
		system("apt-cache policy createstructure");
	else
		system("dpkg -s createstructure | grep -i version | sed 's/Version: //'");		
}

void login()
{
	char TEMP_TOKEN[50] = {'\0'};
	char TEMP_SOURCES[200] = {'\0'};
	char TEMP_ORGANIZATION_NAME[100] = {'\0'};
	char TEMP_IGNORE[100] = {'\0'};

	if (verbose)
		printf("---Login---\n");
	printf("\u2753 Insert your token: ");
	scanf("%50s", TEMP_TOKEN);

	printf("\u2753 Insert your sources (format [item1,item2,...]): ");
	scanf("%200s", TEMP_SOURCES);

	printf("\u2753 Insert your organization name or 'p' if you want to use your personal account: ");
	scanf("%100s", TEMP_ORGANIZATION_NAME);
	if (TEMP_ORGANIZATION_NAME[0] == 'p')
		TEMP_ORGANIZATION_NAME[0] = '\0';

	printf("\u2753 Insert the folder to ignore (format [item1,item2,...]): ");
	scanf("%100s", TEMP_IGNORE);

	if (verbose)
		printf("\n---Infos---\n\u2139 TOCKEN: %s\n\u2139 SOURCES: %s\n\u2139 ORGANIZATION_NAME (empty if you will use your personal account): %s\n\u2139 IGNORE: %s\n", &TEMP_TOKEN, &TEMP_SOURCES, &TEMP_ORGANIZATION_NAME, &TEMP_IGNORE);

	// Save insert options
	char execution_string[2048] = {'\0'};
	sprintf(execution_string, "sudo echo 'token=%s\nsources=%s\norganization_name=%s\nignore=%s' > /etc/createstructure.conf", TEMP_TOKEN, TEMP_SOURCES, TEMP_ORGANIZATION_NAME, TEMP_IGNORE);
	system(execution_string);

	if (verbose)
		printf("%s", "Configuration saved");
}

void createstructure()
{
	if (verbose)
		printf("---Run-code---\n");

	// Compose my string
	char execution_string[2048] = {'\0'};
	sprintf (execution_string, "python3 -c \"exec(\\\"from create_structure import create_structure;create_structure()\\\")\" -t=%s -s=%s -o=%s -i=%s %s", TOKEN, SOURCES, ORGANIZATION_NAME, IGNORE, (verbose ? "-v" : ""));

	printf("%s\n", execution_string);
	system(execution_string);
}
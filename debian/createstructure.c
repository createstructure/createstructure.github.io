#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
//#include <Python.h>
// gcc -std=c99 -ggdb3 -O0 -pedantic-errors -Wall -Wextra -fpie $(python3-config --cflags --embed) -o 'createstructure.out' 'createstructure.c' $(python3-config --embed --ldflags) && ./createstructure.out

// Definitions
#define MALLOC_MAX_SIXE 1024
#define SUCCESS (char *)haystack
#define FAILURE (void *)NULL
#define UBUNTU
//#define WINDOWS

// Support functions
void delay(int milliseconds);
int exist(int argc, char** argv, char* item);
int min(int a, int b);
char* connect_strings(char* first, char* second);
char* read_by_terminal(char* input);
char* choppy(char* s);
void check_pip_package_version();
void get_setup();
char *str_replace(char *haystack, size_t haystacksize, const char *oldneedle, const char *newneedle); // By: https://stackoverflow.com/questions/4408170/for-string-find-and-replace
static bool locate_forward(char **needle_ptr, char *read_ptr, const char *needle, const char *needle_last);
static bool locate_backward(char **needle_ptr, char *read_ptr, const char *needle, const char *needle_last);

// Action functions
void help();
void set_verbose();
void version();
void login();
void createstructure();

// Global variables
bool verbose = false;
char* TOKEN;
//char* SOURCES;
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

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
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
    char *result = malloc(MALLOC_MAX_SIXE); // max return size
    char *result2 = malloc(MALLOC_MAX_SIXE); // max return size
	result2 = "";
    while (fgets(result, sizeof(result), cmd) !=NULL)
        result2 = connect_strings(result2, result);
	pclose(cmd);
	return choppy(result2);
}

char* choppy(char *s)
{
    char *n = malloc(MALLOC_MAX_SIXE); // max return size
    if( s )
        strcpy( n, s );
	if(n[strlen(n)-1] == "\n")
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

char *str_replace(char *haystack, size_t haystacksize,
                    const char *oldneedle, const char *newneedle)
{
    size_t oldneedle_len = strlen(oldneedle);
    size_t newneedle_len = strlen(newneedle);
    char *oldneedle_ptr;    // locates occurences of oldneedle
    char *read_ptr;         // where to read in the haystack
    char *write_ptr;        // where to write in the haystack
    const char *oldneedle_last =  // the last character in oldneedle
        oldneedle +
        oldneedle_len - 1;

    // Case 0: oldneedle is empty
    if (oldneedle_len == 0)
        return SUCCESS;     // nothing to do; define as success

    // Case 1: newneedle is not longer than oldneedle
    if (newneedle_len <= oldneedle_len) {
        // Pass 1: Perform copy/replace using read_ptr and write_ptr
        for (oldneedle_ptr = (char *)oldneedle,
            read_ptr = haystack, write_ptr = haystack;
            *read_ptr != '\0';
            read_ptr++, write_ptr++)
        {
            *write_ptr = *read_ptr;
            bool found = locate_forward(&oldneedle_ptr, read_ptr,
                        oldneedle, oldneedle_last);
            if (found)  {
                // then perform update
                write_ptr -= oldneedle_len;
                memcpy(write_ptr+1, newneedle, newneedle_len);
                write_ptr += newneedle_len;
            }
        }
        *write_ptr = '\0';
        return SUCCESS;
    }

    // Case 2: newneedle is longer than oldneedle
    else {
        size_t diff_len =       // the amount of extra space needed
            newneedle_len -     // to replace oldneedle with newneedle
            oldneedle_len;      // in the expanded haystack

        // Pass 1: Perform forward scan, updating write_ptr along the way
        for (oldneedle_ptr = (char *)oldneedle,
            read_ptr = haystack, write_ptr = haystack;
            *read_ptr != '\0';
            read_ptr++, write_ptr++)
        {
            bool found = locate_forward(&oldneedle_ptr, read_ptr,
                        oldneedle, oldneedle_last);
            if (found) {
                // then advance write_ptr
                write_ptr += diff_len;
            }
            if (write_ptr >= haystack+haystacksize)
                return FAILURE; // no more room in haystack
        }

        // Pass 2: Walk backwards through haystack, performing copy/replace
        for (oldneedle_ptr = (char *)oldneedle_last;
            write_ptr >= haystack;
            write_ptr--, read_ptr--)
        {
            *write_ptr = *read_ptr;
            bool found = locate_backward(&oldneedle_ptr, read_ptr,
                        oldneedle, oldneedle_last);
            if (found) {
                // then perform replacement
                write_ptr -= diff_len;
                memcpy(write_ptr, newneedle, newneedle_len);
            }
        }
        return SUCCESS;
    }
}

// locate_forward: compare needle_ptr and read_ptr to see if a match occured
// needle_ptr is updated as appropriate for the next call
// return true if match occured, false otherwise
static inline bool
locate_forward(char **needle_ptr, char *read_ptr,
        const char *needle, const char *needle_last)
{
    if (**needle_ptr == *read_ptr) {
        (*needle_ptr)++;
        if (*needle_ptr > needle_last) {
            *needle_ptr = (char *)needle;
            return true;
        }
    }
    else
        *needle_ptr = (char *)needle;
    return false;
}

// locate_backward: compare needle_ptr and read_ptr to see if a match occured
// needle_ptr is updated as appropriate for the next call
// return true if match occured, false otherwise
static inline bool
locate_backward(char **needle_ptr, char *read_ptr,
        const char *needle, const char *needle_last)
{
    if (**needle_ptr == *read_ptr) {
        (*needle_ptr)--;
        if (*needle_ptr < needle) {
            *needle_ptr = (char *)needle_last;
            return true;
        }
    }
    else
        *needle_ptr = (char *)needle_last;
    return false;
}


void get_setup()
{
	if (verbose)
		puts("\u2139 Getting setup");

#ifdef UBUNTU
	TOKEN = read_by_terminal("cat ~/createstructure.conf | grep 'token' | sed 's/token=//' | sed 's/token= //'");
	//SOURCES = read_by_terminal("cat ~/createstructure.conf | grep 'sources' | sed 's/sources=//' | sed 's/sources= //'");
	ORGANIZATION_NAME = read_by_terminal("cat ~/createstructure.conf | grep 'organization_name' | sed 's/organization_name=//' | sed 's/organization_name= //'");
	IGNORE = read_by_terminal("cat ~/createstructure.conf | grep 'ignore' | sed 's/ignore=//' | sed 's/ignore= //'");
#endif // UBUNTU
#ifdef WINDOWS
    char* TO_DELATE = read_by_terminal("powershell -command \"& {echo ''}\"");
	TOKEN = read_by_terminal("powershell -command \"& {get-content $Env:HOMEDRIVE\\Progra~1\\createstructure\\createstructure.conf | where { $_ -match 'token'} | %{$_ -replace 'token=',''} | %{$_ -replace 'token= ',''} }\"");
	TOKEN = str_replace(TOKEN, sizeof(TOKEN), TO_DELATE, "");
	//SOURCES = read_by_terminal("powershell -command \"& {get-content $Env:HOMEDRIVE\\Progra~1\\createstructure\\createstructure.conf | where { $_ -match 'sources'} | %{$_ -replace 'sources=',''} | %{$_ -replace 'sources= ',''} }\"");
    //SOURCES = str_replace(SOURCES, sizeof(SOURCES), TO_DELATE, "");
    ORGANIZATION_NAME = read_by_terminal("powershell -command \"& {get-content $Env:HOMEDRIVE\\Progra~1\\createstructure\\createstructure.conf | where { $_ -match 'organization_name'} | %{$_ -replace 'organization_name=',''} | %{$_ -replace 'organization_name= ',''} }\"");
	ORGANIZATION_NAME = str_replace(ORGANIZATION_NAME, sizeof(ORGANIZATION_NAME), TO_DELATE, "");
	IGNORE = read_by_terminal("powershell -command \"& {get-content $Env:HOMEDRIVE\\Progra~1\\createstructure\\createstructure.conf | where { $_ -match 'ignore'} | %{$_ -replace 'ignore=',''} | %{$_ -replace 'ignore= ',''} }\"");
	IGNORE = str_replace(IGNORE, sizeof(IGNORE), TO_DELATE, "");
#endif // WINDOWS
	TOKEN = choppy(TOKEN);
	ORGANIZATION_NAME = choppy(ORGANIZATION_NAME);
	IGNORE = choppy(IGNORE);
}

void help(int argc, char **argv)
{
	if (exist(argc, argv, "-v") || exist(argc, argv, "--verbose"))
	{
		printf("---Help---\n");
#ifdef UBUNTU
		printf("Open man...\n");
#endif // UBUNTU
	}
#ifdef UBUNTU
	system("man createstructure");
#endif // UBUNTU
#ifdef WINDOWS
	printf("%s\n\t%s\n\n%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n%s\n\t%s\n\n%s\n\t%s",
        "NAME",
            "createstructure",
        "SYNOPSIS",
            "createstructure - runs the creator",
            "createstructure [-h | --help] - Help",
            "createstructure [-v | --verbose] - You will see more infos",
            "createstructure [-V | --version] - Show you the version",
            "createstructure [-l | --login] - Do the login (NEEDS ADMINISTRATOR RIGHTS)",
        "DESCRIPTION",
            "With this programm you can easily create a repository on GitHub with a basic template, personalized for your use.",
        "AUTHORS",
            "Castellani Davide: owner"
            );
#endif // WINDOWS
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
#ifdef UBUNTU
		system("apt-cache policy createstructure");
#endif // UBUNTU
#ifdef WINDOWS
		system("choco outdated | find \"createstructure\"");
#endif // WINDOWS
	else
#ifdef UBUNTU
		system("dpkg -s createstructure | grep -i version | sed 's/Version: //'");
#endif // UBUNTU
#ifdef WINDOWS
		system("choco outdated | find \"createstructure|\"");
#endif // WINDOWS
}

void login()
{
	char TEMP_AUTO[50] = {'\0'};
	char *TEMP_TOKEN_AUTO = "";
	char TEMP_TOKEN[50] = {'\0'};
	//char TEMP_SOURCES[200] = {'\0'};
	char TEMP_ORGANIZATION_NAME[100] = {'\0'};
	char TEMP_IGNORE[100] = {'\0'};

	if (verbose)
		printf("---Login---\n");

	printf("\u2753 Want you use auto-gen token (Max 1 PC for user): ");
	scanf("%50s", TEMP_AUTO);

	if (!strcmp(TEMP_AUTO, "Y") || !strcmp(TEMP_AUTO, "y") || !strcmp(TEMP_AUTO, "Yes") || !strcmp(TEMP_AUTO, "yes"))
	{
		// Auto-generate token
		char TEMP_CODE[50] = {'\0'};

#ifdef UBUNTU
		system("sensible-browser 'https://github.com/login/oauth/authorize?client_id=9cf3c3790cc8c718aada&scope=user%20repo%20admin:org'");
#endif // UBUNTU
#ifdef WINDOWS
		system("powershell -command \"& {Start-Process 'https://github.com/login/oauth/authorize?client_id=9cf3c3790cc8c718aada&scope=user%20repo%20admin:org'}\"");
#endif // WINDOWS

		printf("\u2753 Insert given token: ");
	}
	else
	{
		printf("\u2753 Insert your token: ");
	}
	scanf("%50s", TEMP_TOKEN);

	//printf("\u2753 Insert your sources (format [item1,item2,...]): ");
	//scanf("%200s", TEMP_SOURCES);

	printf("\u2753 Insert your organization name or 'p' if you want to use your personal account: ");
	scanf("%100s", TEMP_ORGANIZATION_NAME);
	if (TEMP_ORGANIZATION_NAME[0] == 'p')
		TEMP_ORGANIZATION_NAME[0] = '\0';

	printf("\u2753 Insert the folder to ignore (format [item1,item2,...]): ");
	scanf("%100s", TEMP_IGNORE);

	if (verbose)
		//printf("\n---Infos---\n\u2139 TOCKEN: %s%s\n\u2139 SOURCES: %s\n\u2139 ORGANIZATION_NAME (empty if you will use your personal account): %s\n\u2139 IGNORE: %s\n", &TEMP_TOKEN, TEMP_TOKEN_AUTO, &TEMP_SOURCES, &TEMP_ORGANIZATION_NAME, &TEMP_IGNORE);
		printf("\n---Infos---\n\u2139 TOCKEN: %s%s\n\u2139 ORGANIZATION_NAME (empty if you will use your personal account): %s\n\u2139 IGNORE: %s\n", choppy(&TEMP_TOKEN), choppy(TEMP_TOKEN_AUTO), choppy(&TEMP_ORGANIZATION_NAME), choppy(&TEMP_IGNORE));

	// Save insert options
	char execution_string[2048] = {'\0'};

#ifdef UBUNTU
	//sprintf(execution_string, "sudo echo 'token=%s%s\nsources=%s\norganization_name=%s\nignore=%s' > ~/createstructure.conf", TEMP_TOKEN, TEMP_TOKEN_AUTO, TEMP_SOURCES, TEMP_ORGANIZATION_NAME, TEMP_IGNORE);
	sprintf(execution_string, "echo 'token=%s%s' > ~/createstructure.conf; echo 'organization_name=%s' >> ~/createstructure.conf; echo 'ignore=%s' >> ~/createstructure.conf", choppy(TEMP_TOKEN), choppy(TEMP_TOKEN_AUTO), choppy(TEMP_ORGANIZATION_NAME), choppy(TEMP_IGNORE));
	printf("echo 'token=%s%s' > ~/createstructure.conf; echo 'organization_name=%s' >> ~/createstructure.conf; echo 'ignore=%s' >> ~/createstructure.conf", choppy(TEMP_TOKEN), choppy(TEMP_TOKEN_AUTO), choppy(TEMP_ORGANIZATION_NAME), choppy(TEMP_IGNORE));
#endif // UBUNTU
#ifdef WINDOWS
	//sprintf(execution_string, "echo token=%s%s > %HOMEDRIVE%\\Progra~1\\createstructure\\createstructure.conf && echo sources=%s >> %HOMEDRIVE%\\Progra~1\\createstructure\\createstructure.conf && echo organization_name=%s >> %HOMEDRIVE%\\Progra~1\\createstructure\\createstructure.conf && echo ignore=%s >> %HOMEDRIVE%\\Progra~1\\createstructure\\createstructure.conf", TEMP_TOKEN, TEMP_TOKEN_AUTO, TEMP_SOURCES, TEMP_ORGANIZATION_NAME, TEMP_IGNORE);
	sprintf(execution_string, "echo token=%s%s > %HOMEDRIVE%\\Progra~1\\createstructure\\createstructure.conf && echo organization_name=%s >> %HOMEDRIVE%\\Progra~1\\createstructure\\createstructure.conf && echo ignore=%s >> %HOMEDRIVE%\\Progra~1\\createstructure\\createstructure.conf", TEMP_TOKEN, TEMP_TOKEN_AUTO, TEMP_ORGANIZATION_NAME, TEMP_IGNORE);
#endif // WINDOWS

	if (verbose)
		printf("%s", execution_string);
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
#ifdef UBUNTU
	//sprintf (execution_string, "python3 -c \"exec(\\\"from createstructure import createstructure;createstructure()\\\")\" -t=%s -s=%s -o=%s -i=%s %s", TOKEN, SOURCES, ORGANIZATION_NAME, IGNORE, (verbose ? "-v" : ""));
	sprintf (execution_string, "python3 -c \"exec(\\\"from createstructure import createstructure;createstructure()\\\")\" -t=%s -o=%s -i=%s %s", TOKEN, ORGANIZATION_NAME, IGNORE, (verbose ? "-v" : ""));
#endif // UBUNTU
#ifdef WINDOWS
	//sprintf (execution_string, "python.exe -c \"exec(\\\"from createstructure import createstructure;createstructure()\\\")\" -t=%s -s=%s -o=%s -i=%s %s", TOKEN, SOURCES, ORGANIZATION_NAME, IGNORE, (verbose ? "-v" : ""));
	sprintf (execution_string, "python.exe -c \"exec(\\\"from createstructure import createstructure;createstructure()\\\")\" -t=%s -o=%s -i=%s %s", TOKEN, ORGANIZATION_NAME, IGNORE, (verbose ? "-v" : ""));
#endif // WINDOWS

    if (verbose)
        printf("%s\n", execution_string);
	system(execution_string);
}

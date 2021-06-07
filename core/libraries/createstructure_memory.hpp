/* createstructure_memory library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_MEMORY
// If not imported yet
#define CREATESTRUCTURE_MEMORY

// Dependencies
#include <bits/stdc++.h>
#include "sys/types.h"
#include "sys/sysinfo.h"

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Declared functions
long long int totalMemory();
long long int usedMemory();
long long int freeMemory();
double percentageMemory();
bool okMemory();

// Function(s)
long long int totalMemory() {
        /* Total Memory: return the total amount of RAM
         *
         * output:
         *      - the total amount of RAM
         */
        // Local varible(s)
	struct sysinfo memInfo;

	// Get info struct
	sysinfo (&memInfo);

	// Return
	return memInfo.totalram * memInfo.mem_unit;
}

long long int usedMemory() {
        /* Used Memory: return the used amount of RAM
         *
         * output:
         *      - the used amount of RAM
         */
        // Local varible(s)
	struct sysinfo memInfo;

	// Get info struct
	sysinfo (&memInfo);

	// Return
	return (memInfo.totalram - memInfo.freeram) * memInfo.mem_unit;
}

long long int freeMemory() {
        /* Free Memory: return the free amount of RAM
         *
         * output:
         *      - the free amount of RAM
         */
        // Local varible(s)
	struct sysinfo memInfo;

	// Get info struct
	sysinfo (&memInfo);

	// Return
	return memInfo.freeram * memInfo.mem_unit;
}

double percentageMemory() {
        /* Percentage Memory: return the percentage of the use of RAM
         *
         * output:
         *      - the percentage of the use of RAM
         */
	// Return
	return (double) usedMemory() / (double) totalMemory() * 100;
}

bool okMemory() {
        /* OK Memory: return if it's ok to run another docker (if percentage memory is under the 90%)
         *
         * output:
         *      - if it's ok to run another docker (if percentage memory is under the 90%)
         */
	// Return
	return percentageMemory() < 90;
}

#endif

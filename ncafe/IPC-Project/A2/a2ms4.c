#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void printSectionHeader(const char*);

int main(void) {
	printSectionHeader("ZFC");
	ContactManagerSystem();
	return 0;
}

// Display specified test section header
void printSectionHeader(const char* testName)
{
    printf("\n");
    printf("------------------------------------------\n");
    printf("Testing: %s\n", testName);
    printf("------------------------------------------\n");
}

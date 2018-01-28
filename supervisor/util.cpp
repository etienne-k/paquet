#include "util.h"

void Util::printHexDump(const char * description, void * address, int length)
{
	int i;
	unsigned char buff[17];
	unsigned char *pc = (unsigned char*)address;

	// Output description if given.
	if (description != 0x0)
		printf ("%s (%d bytes):\n", description, length);

	if (length == 0)
	{
		printf("  ZERO LENGTH\n");
		return;
	}
	if (length < 0)
	{
		printf("  NEGATIVE LENGTH: %i\n", length);
		return;
	}

	// Process every byte in the data.
	for (i = 0; i < length; i++)
	{
		// Multiple of 16 means new line (with line offset).

		if ((i % 16) == 0) {
			// Just don't print ASCII for the zeroth line.
			if (i != 0)
				printf("  %s\n", buff);

			// Output the offset.
			printf("  %04x ", i);
		}

		// Now the hex code for the specific character.
		printf(" %02x", pc[i]);

		// And store a printable ASCII character for later.
		if ((pc[i] < 0x20) || (pc[i] > 0x7e))
			buff[i % 16] = '.';
		else
			buff[i % 16] = pc[i];
		buff[(i % 16) + 1] = '\0';
	}

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0)
	{
        printf("   ");
        i++;
    }

    // And print the final ASCII bit.
    printf("  %s\n", buff);
}
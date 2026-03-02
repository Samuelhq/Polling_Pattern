#include <stdio.h>
#include <conio.h>	// for _kbhit command
#include <Windows.h>


// Create states for the state machine
typedef enum { WAITING_FOR_NFC_TAG, CHECKING_PREMISSIONS, DOOR_UNLOCK_COMMAND, DOOR_LOCK_COMMAND } state_list;

// Define the initial state
state_list state = WAITING_FOR_NFC_TAG;

int random_number;

int main(void) {

	int choice = 0;

	while (1) {
		/*printf("Enter your choice: 1 - Coffee, 2 - Tea\n");
		scanf_s("%d", &choice);*/

		switch (state) {
		case WAITING_FOR_NFC_TAG:		// Waiting for NFC tag
			printf("Please present your NFC Tag. When ready, hit any key.\n");
			_getch();	// Wait for any keyboard input
			state = CHECKING_PREMISSIONS;
			break;
		case CHECKING_PREMISSIONS:		// Checking permission of scanned tag
			printf("Checking Permission...\n");
			random_number = rand() % 2;
			if (random_number == 0) {
				printf("Access Denied\n");
				Sleep(1000);
				state = WAITING_FOR_NFC_TAG;
			}
			else {
				printf("Access Granted\n");
				Sleep(1000);
				state = DOOR_UNLOCK_COMMAND;
			}
			break;
		case DOOR_UNLOCK_COMMAND:		// Unlock door
			printf("Unlocking Door\n");
			printf("...\n");
			Sleep(3000);
			state = DOOR_LOCK_COMMAND;
			break;
		case DOOR_LOCK_COMMAND:			// Lock door
			printf("Locking Door\n");
			printf("...\n");
			Sleep(3000);
			state = WAITING_FOR_NFC_TAG;
			break;
		default:	// Bad input
			printf("Please enter 1 or 2\n");
		}
	}

	return 0;
}
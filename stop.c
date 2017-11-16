#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

struct sigaction old_action;

void sig_fn(int sig_no)
{
	printf("\nCtrl-C is pressed. Try Again.\n");
	sigaction(SIGINT, &old_action, NULL);
}

int main()
{
	struct sigaction action;

	memset(&action, 0, sizeof(action));

	while (1) {
		action.sa_handler = &sig_fn;
		sigaction(SIGINT, &action, &old_action);

		pause();
	}

	return 0;
}
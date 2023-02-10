#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0);
}

int catch_signal(int sig, void (*handler)(int)) {
   struct sigaction action;
   action.sa_handler = handler;
   sigemptyset(&action.sa_mask);
   action.sa_flags = 0;

   return sigaction (sig, &action, NULL);
}

void times_up() {
   puts("\nTIME's UP!");
   raise(SIGINT);
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

int main()
{
    // solution 1
   catch_signal(SIGALRM, times_up);
   catch_signal(SIGINT, end_game);

   srand(time(0));

   while(1) {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];

      alarm(5);

      printf("\nWhat is %d times %d: ", a, b);
      fgets(txt, 4, stdin);
      int answer = atoi(txt);

      if(answer == a * b)
         score++;
      else
         printf("\nWrong! Score: %d\n", score);
    }

    // solution 2
    // Creating first child
    int n1 = fork();

    // Creating second child. First child also executes this line and creates grandchild.
    int n2 = fork();

    if (n1 > 0 && n2 > 0)
    {
        printf("parent\n");
        printf("%d %d \n", n1, n2);
        printf("   my id is %d \n", getpid());
        printf("   my parentid is %d \n", getppid());
    }
    else if (n1 == 0 && n2 > 0)
    {
        printf("\nFirst child\n");
        printf("%d %d \n", n1, n2);
        printf("   my id is %d  \n", getpid());
        printf("   my parentid is %d \n", getppid());
    }
    else if (n1 > 0 && n2 == 0)
    {
        printf("\nsecond child\n");
        printf("%d %d \n", n1, n2);
        printf("   my id is %d  \n", getpid());
        printf("   my parentid is %d \n", getppid());
    }
    else {
        printf("\nthird child\n");
        printf("%d %d \n", n1, n2);
        printf("   my id is %d \n", getpid());
        printf("   my parentid is %d \n", getppid());
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
    pid_t a, b, c, d, e, f, g, h, i;
    b = fork();
    if (b == 0)
    {
        printf("B is child of A and has pid %d and parent pid %d \n", getpid(), getppid());
        d = fork();
        if (d == 0)
        {
            printf("D is child of B and has pid %d and parent pid %d \n", getpid(), getppid());
            h = fork();

            if (h == 0)
            {
                printf("H is child of D and has pid %d and parent pid %d \n", getpid(), getppid());
                i = fork();
                if (i == 0)
                {
                    printf("I is child of H and has pid %d and parent pid %d \n", getpid(), getppid());
                }
            }
        }
        else
        {
            e = fork();
            if (e == 0)
            {
                printf("E is child of B and has pid %d and parent pid %d \n", getpid(), getppid());
                f = fork();
            }
            else
            {
                f = fork();
                if (f == 0)
                {
                    printf("F is child of B and has pid %d and parent pid %d \n", getpid(), getppid());
                }
            }
        }
    }
    else
    {
        c = fork();
        if (c == 0)
        {
            printf("C is child of A and has pid %d and parent pid %d \n", getpid(), getppid());
            g = fork();
            if (g == 0)
            {
                printf("G is child of C and has pid %d and parent pid %d \n", getpid(), getppid());
            }
        }
        else
        {
            printf("A is parent of B, C, D, E, F, G, H, I and has pid %d \n", getpid());
        }
    }
    for (int i = 0; i < 3; i++)
        wait(NULL);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int frames, windowSize;
    int transmissions = 0;
    printf("Enter no. of frames to send: ");
    scanf("%d", &frames);
    printf("Enter the window size: ");
    scanf("%d", &windowSize);
    int i = 1;

    while (i <= frames)
    {
        int ackFrames = 0;
        for (int j = i; j < i + windowSize && j <= frames; j++)
        {
            printf("Sending frame: %d\n", j);
            transmissions++;
        }

        for (int j = i; j < i + windowSize && j <= frames; j++)
        {
            int flag = rand() % 2;
            if (!flag)
            {
                printf("Acknowledgement for frame %d received\n", j);
                ackFrames++;
                
            }
            else
            {
                printf("Frame %d not received\n", j);
                printf("Retransmitting all frames in the window\n");
                break;
            }
        }
        printf("\n");
        i += ackFrames;
    }
    printf("Total no. of transmissions: %d\n", transmissions);

    return 0;
}


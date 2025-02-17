#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define packetCount 10

int main()
{
    srand(time(0));
    int packets[packetCount], i, rate, bucketSize, remainingSize = 0, timeToTransmit, clk, op;

    for (i = 0; i < packetCount; ++i)
        packets[i] = (rand() % 6 + 1) * 10;

    printf("\nEnter the Output rate:");
    scanf("%d", &rate);
    printf("Enter the Bucket Size:");
    scanf("%d", &bucketSize);

    i = 0;
    while (i < packetCount || remainingSize > 0)
    {
        if (i < packetCount)
        {
            if ((packets[i] + remainingSize) > bucketSize)
                printf("Bucket capacity exceeded! Packet %d overflow\n", packets[i]);
            else
            {
                remainingSize += packets[i];
                printf("\n\nIncoming Packet size: %d", packets[i]);
                printf("\nBytes remaining to transmit in bucket: %d", remainingSize);
            }
            ++i;
        }

        timeToTransmit = (rand() % 4 + 1) * 10;
        printf("\nTime till next incoming packet: %d units\n", timeToTransmit);

        for (clk = 10; clk <= timeToTransmit; clk += 10)
        {
            sleep(1);
            if (remainingSize)
            {
                if (remainingSize <= rate)
                    op = remainingSize, remainingSize = 0;
                else
                    op = rate, remainingSize -= rate;

                printf("\n%d Bytes transmitted", op);
                printf("\nTime till next packet arrives: %d units\n", timeToTransmit - clk);
                printf("Bytes Remaining to Transmit in Bucket: %d\n", remainingSize);
            }
            else
            {
                printf("\nTime till next packet arrives: %d units", timeToTransmit - clk);
                printf("\nNo packets to transmit!\n");
            }
        }
    }
}

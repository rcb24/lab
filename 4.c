#include <stdio.h>
#include <stdlib.h>

void divide(int div[], int divisor[], int rem[], int divisor_bits, int tot_length);

int main()
{
    int data_bits, divisor_bits, tot_length;

    printf("Enter number of data bits: ");
    scanf("%d", &data_bits);

    int data[data_bits];
    printf("Enter data bits: ");
    for (int i = 0; i < data_bits; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("Enter number of bits in divisor: ");
    scanf("%d", &divisor_bits);

    int divisor[divisor_bits];
    printf("Enter Divisor bits: ");
    for (int i = 0; i < divisor_bits; i++)
    {
        scanf("%d", &divisor[i]);
    }

    tot_length = data_bits + divisor_bits - 1;

    int div[tot_length];
    int rem[tot_length];
    int crc[tot_length];

    for (int i = 0; i < data_bits; i++)
    {
        div[i] = data[i];
    }

    for (int i = data_bits; i < tot_length; i++)
    {
        div[i] = 0;
    }

    printf("Dividend (after appending 0's): ");
    for (int i = 0; i < tot_length; i++)
    {
        printf("%d", div[i]);
    }
    printf("\n");

    for (int j = 0; j < tot_length; j++)
    {
        rem[j] = div[j];
    }

    divide(div, divisor, rem, divisor_bits, tot_length);

    for (int i = 0; i < tot_length; i++)
    {
        crc[i] = div[i] ^ rem[i];
    }

    printf("CRC code: ");
    for (int i = 0; i < tot_length; i++)
    {
        printf("%d", crc[i]);
    }
    printf("\n");

    int received_crc[tot_length];
    printf("Enter CRC code of %d bits: ", tot_length);
    for (int i = 0; i < tot_length; i++)
    {
        scanf("%d", &received_crc[i]);
    }

    for (int j = 0; j < tot_length; j++)
    {
        rem[j] = received_crc[j];
    }

    divide(received_crc, divisor, rem, divisor_bits, tot_length);

    for (int i = 0; i < tot_length; i++)
    {
        if (rem[i] != 0)
        {
            printf("Error\n");
            break;
        }
        if (i == tot_length - 1)
        {
            printf("No Error\n");
        }
    }

    return 0;
}

void divide(int div[], int divisor[], int rem[], int divisor_bits, int tot_length)
{
    int cur = 0;
    while (1)
    {
        for (int i = 0; i < divisor_bits; i++)
        {
            rem[cur + i] = rem[cur + i] ^ divisor[i];
        }

        while (rem[cur] == 0 && cur != tot_length - 1)
        {
            cur++;
        }

        if ((tot_length - cur) < divisor_bits)
        {
            break;
        }
    }
}
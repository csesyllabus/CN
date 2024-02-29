// leaky bucket
#include <stdio.h>

int main()
{
    int incoming, outgoing, bucket_size, n, store = 0;

    printf("Enter the bucket size, outgoing rate, and number of inputs: ");
    scanf("%d %d %d", &bucket_size, &outgoing, &n);

    while (n > 0)
    {
        printf("Enter the incoming packet size: ");
        scanf("%d", &incoming);
        printf("Incoming packet size is %d\n", incoming);

        if (incoming <= (bucket_size - store))
        {
            store += incoming;
            printf("Bucket buffer size %d out of %d\n", store, bucket_size);
        }
        else
        {
            int overflow = incoming - (bucket_size - store);
            printf("Dropped %d packets\n", overflow);
            store = bucket_size; // Bucket is full
            printf("Bucket buffer %d out of %d\n", store, bucket_size);
        }

        store -= outgoing;
        if (store < 0)
            store = 0; // Bucket cannot have negative packets

        printf("After outgoing %d packets left out of %d in buffer\n", store, bucket_size);

        n--;
    }

    return 0;
}

/*
output :-
enter the bucket size,outgoing, rate no of inputs: 50 6 60
enter the incoming packet size: 100
incoming packet size is 100
dropped 50 no of packets
bucket buffer 0 out of 50
after outgoing -6 packets left out of 50 in buffer
*/

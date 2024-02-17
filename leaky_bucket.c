// leaky bucket
#include <stdio.h>
int main()
{
    int incoming, outgoing, buck_size, n, store;
    printf("enter the bucket size,outgoing, rate no of inputs: ");
    scanf("%d%d%d", &buck_size, &outgoing, &n);
    while (n != 0)
    {
        printf("enter the incoming packet size: ");
        scanf("%d", &incoming);
        printf("incoming packet size is %d\n", incoming);
        if (incoming <= (buck_size - store))
        {
            store = store + incoming;
            printf("buct buffer size %d out of %d\n", store, buck_size);
        }
        else
        {
            printf("dropped %d no of packets\n", incoming - (buck_size - store));
            printf("bucket buffer %d out of %d\n", store, buck_size);
        }
        store = store - outgoing;
        printf("after outgoing %d packets left out of %d in buffer\n", store, buck_size);
        n--;
    }
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
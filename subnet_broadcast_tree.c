#include <stdio.h>

int main()
{
    unsigned int compad[4];
    unsigned int mask[4];
    unsigned int netaddr[4];
    int i;

    printf("Enter the IP address: \n");
    scanf("%u.%u.%u.%u", &compad[3], &compad[2], &compad[1], &compad[0]);
    printf("Enter the subnet mask: ");
    scanf("%u.%u.%u.%u", &mask[3], &mask[2], &mask[1], &mask[0]);

    for (i = 0; i < 4; i++)
    {
        netaddr[i] = compad[i] & mask[i];
    }

    printf("\nNetwork address is :\n");
    printf("%u.%u.%u.%u\n", netaddr[3], netaddr[2], netaddr[1], netaddr[0]);

    printf("Subnet mask is:\n");
    printf("%u.%u.%u.%u\n", mask[3], mask[2], mask[1], mask[0]);

    printf("IP address is :\n");
    printf("%u.%u.%u.%u\n", compad[3], compad[2], compad[1], compad[0]);

    return 0;
}
/*
OUTPUT

Enter the IP address:
192.168.101.226
Enter the subnet mask: 255.255.255.8

Network address is :
192.168.101.0
Subnet mask is:
255.255.255.8
IP address is :
192.168.101.226
*/

#include <stdio.h>
void main()
{
    unsigned int compad[4];
    unsigned int mask[4];
    unsigned int netaddr[4];
    int i, n;
    printf("enter the ip address \n");
    scanf("%u%*c%u%*c%u%*c%u%*c", &compad[3], &compad[2], &compad[1], &compad[0]);
    printf("enter the subnet address:");
    scanf("%u%*c%u%*c%u%*c%u%*c", &mask[3], &mask[2], &mask[1], &mask[0]);
    for (i = 0; i < n; i++)
    {
        netaddr[i] = compad[i] & mask[i];
    }
    printf("\n network address is :\n");
    printf("%u%u%u%u", netaddr[3], netaddr[2], netaddr[1], netaddr[0]);
    printf("subnet address is:\n");
    printf("%u%u%u%u", mask[3], mask[2], mask[1], mask[0]);
    printf("ip address is :\n");
    printf("%u%u%u%u", compad[3], compad[2], compad[1], compad[0]);
}

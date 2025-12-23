#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int unique_digits(int n)
{
    int a[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int r, pos = 0;
    while(n)
    {
        r = n % 10;
        if(a[r] == -1) a[r] = pos;
        else return a[r];
        pos++;
        n = n / 10;
    }
    return -1;
}

int main()
{
    int pos, st, end, i, x, y;
    scanf("%d %d", &st, &end);
    for(i = st; i < end; i++)
    {
        pos = unique_digits(i);
        if(pos == -1)
        {
            printf("%d ", i);
            continue;
        }
        x = (int)pow(10, pos);
        y = i % x;
        i = i + (x - y) - 1;
    }
    printf("\n");
    return 0;
}
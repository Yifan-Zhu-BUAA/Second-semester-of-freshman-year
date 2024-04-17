#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start,stop;
    double duration;
    start = clock();
    sleep(1);
    stop = clock();
    duration = ((double)(stop-start))/CLK_TCK;
    printf("%f\n%d",duration,CLK_TCK);

}
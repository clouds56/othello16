#include "gamti.h"

static struct timeval st;

int get_time()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return (now.tv_sec-st.tv_sec)*1000+(now.tv_usec-st.tv_usec)/100;
}

void reset_time()
{
    gettimeofday(&st, NULL);
}

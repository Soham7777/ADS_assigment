#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "header.h"

int main()
{
    Darray *buf_one;

    buf_one = initialize_array(5);

    assert(buf_one != NULL);
    assert(buf_one->c_size == 0);
    assert(buf_one->t_size == 5);

    assert(pixels_data(buf_one,1,0,0,1,0.5));
    assert(pixels_data(buf_one,0,255,0,1,0.4));
    assert(pixels_data(buf_one,0,0,255,0,0.015));
    assert(pixels_data(buf_one,0,0,255,0,1));

   // printf("%d",buf_one->arr[0].g);

    //count number of pixel red, green,blue pixel
    assert(count_red(buf_one)==1);
    assert(count_green(buf_one)==1);
    assert(count_blue(buf_one)==2);

    //opacity set_unset

   /* assert(opacity_set(buf_one,1));
    assert(opacity_set(buf_one,0));*/


    //high intensity
    //printf("%f",high_intensity(buf_one));

    assert(high_intensity(buf_one) == 4.000000);

    return 0;
}

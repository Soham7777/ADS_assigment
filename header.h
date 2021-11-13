#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define FAIL 0
#define SUCCESS 1
#define FULL -1
#define INIT 1

typedef struct pixel{

    unsigned short int r,g,b;
    unsigned short int opacity;
    float intensity;

}Pixel;

struct _array_{
    Pixel *arr;
    unsigned int c_size,t_size;
    int trans_status;
};

typedef struct _array_ Darray;

Darray *initialize_array(int size);

int pixels_data(Darray *buf,int red,int green,int blue,int opacity,float intensity);

int count_red(Darray *buf);

int count_green(Darray * buf);

int count_blue(Darray * buf);

int opacity_set(Darray *buf,int val);

float high_intensity(Darray * buf);


#endif // HEADER_H_INCLUDED

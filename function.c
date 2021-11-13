#include "header.h"

Darray *initialize_array(int size)
{
    Darray *buffer;

    buffer = (Darray *)malloc(sizeof(Darray)); //dynamically allocating memory

    if (NULL == buffer)
    {
        buffer -> trans_status  = FAIL;
        return buffer;
    }

    buffer->c_size = 0; //initialize to 0

    buffer->t_size = size;

    buffer->arr = (Pixel *)malloc(sizeof(Pixel)*size); //allocate memory for array

    if(buffer->arr == NULL){ //checking for memory allocation

        buffer->trans_status = FAIL;
        return buffer;
    }

    buffer->trans_status = INIT; //success
    return buffer;
}


int pixels_data(Darray *buf,int red,int green,int blue,int opacity,float intensity){

    if (buf == NULL){
        return FAIL;
    }

    if(buf->c_size == buf->t_size){
        return FULL;
    }
    int i;
    i = buf->c_size;

    buf->arr[i].r = red;
    buf->arr[i].g = green;
    buf->arr[i].b = blue;
    buf->arr[i].opacity = opacity;
    buf->arr[i].intensity = intensity;

    buf->c_size++;

    return SUCCESS;

}



int count_red(Darray *buf){

    int i;
    int r=0;

    for(i=0; i<=buf->c_size; i++){

    if(buf->arr[i].b == 0 && buf->arr[i].g==0 && buf->arr[i].r>0)
        r++;    //incrementing count
    }
    return r;

}

int count_green(Darray * buf)       // count number of GREEN pixel
{
    int i;
    int g=0;
    for(i=0; i<=buf->c_size; i++){

    if(buf->arr[i].b == 0 && buf->arr[i].r==0 && buf->arr[i].g > 0)
        g++;    //incrementing green
    }
    return g;

}



int count_blue(Darray * buf)       // count number of BLUE pixel
{
    int i;
    int b=0;
    for(i=0; i<=buf->c_size; i++){

    if(buf->arr[i].r == 0 && buf->arr[i].g==0)
        b++;
    }
    return b;

}


//function to set or unset opacity

int opacity_set(Darray *buf,int val)
{
    int i;
    if(val==1)
    {
        for(i=0; i<=buf->c_size; i++)
        {
            buf->arr[i].opacity=1;

        }
        return SUCCESS;
    }
    else if(val==0)
    {
        for(i=0; i<=buf->c_size; i++)
        {
            buf->arr[i].opacity=0;
        }
        return SUCCESS;
    }
    return FAIL;
}

//highest intensity pixel

float high_intensity(Darray *buf)
{
    int i,j = 0;

    float high = buf->arr[0].intensity;

    for(i=1; i<=buf->c_size; i++)
    {
        if(buf->arr[i].intensity>high)
        {
            j=i;                            //highest pixel
            high=buf->arr[i].intensity; // changing in original array
        }
    }
    return j;
}


/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Collection of statistical functions
 *
 * This file includes a set of functions for calculating mean, median, etc.
 *
 * @author Atharva Lele <itsatharva@gmail.com> 
 * @date 27th April 2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main()
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_statistics(test, SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char array[], int size)
{
        print_array(array, size);
        unsigned char median = find_median(array, size);
        unsigned char mean = find_mean(array, size);
        unsigned char min = find_min(array, size);
        unsigned char max = find_max(array, size);

        printf("Min: %d\n", min);
        printf("Max: %d\n", max);
        printf("Mean: %d\n", mean);
        printf("Median: %d\n", median);
}

void print_array(unsigned char array[], int size)
{
        int i;
        for (i = 0; i < size; i++) {
                printf("%d ", array[i]);
        }
        printf("\n");
}

void sort(unsigned char array[], int size)
{
        int i, j;
        unsigned char temp;

        for (i = 0; i < size-1; i++) {
                for (j = 0; j < size-i-1; j++) {
                        if (array[j] > array[j+1]) {
                                temp = array[j];
                                array[j] = array[j+1];
                                array[j+1] = temp;
                        }
                }
        }
}

unsigned char find_median(unsigned char array[], int size)
{
        unsigned char temp[size];
        unsigned char median;
        int i;

        for (i = 0; i < size; i++) {
                temp[i] = array[i];
        }

        // Array needs to be sorted in order to find the median
        // Use a temporary array in order to not disturb the original
        sort(temp, size);

        if (size % 2 != 0) {
                median = temp[(size+1)/2];
        } else {
                median = (temp[size/2] + temp[(size+1)/2]) / 2;
        }

        return median;
}

unsigned char find_mean(unsigned char array[], int size)
{
        unsigned char mean;
        unsigned long sum = 0;
        int i;

        for (i = 0; i < size; i++) {
                sum += array[i];
        }

        mean = sum / size;

        return mean;
}

unsigned char find_min(unsigned char array[], int size)
{
        unsigned char min = array[0];
        int i;

        for (i = 0; i < size; i++) {
                if (array[i] < min) {
                        min = array[i];
                }
        }

        return min;
}

unsigned char find_max(unsigned char array[], int size)
{
        unsigned char max = array[0];
        int i;

        for (i = 0; i < size; i++) {
                if (array[i] > max) {
                        max = array[i];
                }
        }

        return max;
}
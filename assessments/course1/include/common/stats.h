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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

/*
 * @brief median(): find median value from given array
 * 
 * @param array: unsigned char: input array
 * @param size: int: size of input array
 * 
 * @return median: unsigned char: returns calculated median
 */
unsigned char find_median(unsigned char array[], int size);

/*
 * @brief mean(): find mean value from given array
 *
 * @param array: unsigned char: input array
 * @param size: int: size of input array
 *
 * @return mean: unsigned char: returns calculated mean
 */
unsigned char find_mean(unsigned char array[], int size);

/*
 * @brief min(): find minimum value from given array
 * 
 * @param array: unsigned char: input array
 * @param size: int: size of input array
 * 
 * @return min: unsigned char: minimum value from array
 */
unsigned char find_min(unsigned char array[], int size);

/*
 * @brief max(): find maximum value from given array
 * 
 * @param array: unsigned char: input array
 * @param size: int: size of input array
 * 
 * @return max: unsigned char: maximum value from array
 */
unsigned char find_max(unsigned char array[], int size);

/*
 * @brief print_array(): print the input array
 * 
 * @param array: unsigned char: input array
 * @param size: int: size of input array
 * 
 * @return void
 */
void print_array(unsigned char array[], int size);

/*
 * @brief print_statistics(): prints all calclulated statistics
 * 
 * Mean, Median, Min, Max
 * 
 * @param array: unsigned char: input array
 * @param size: int: size of input array
 * 
 * @return void
 */
void print_statistics(unsigned char array[], int size);

/*
 * @brief sort(): sort the array in ascending order
 * 
 * 
 * @param array: unsigned char: input array
 * @param size: int: size of input array
 * 
 * @return void
 */
void sort(unsigned char array[], int size);

#endif /* __STATS_H__ */

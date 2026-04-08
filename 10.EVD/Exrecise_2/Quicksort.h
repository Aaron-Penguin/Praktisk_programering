#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

namespace func{
int partition(double array[], int index_array[], int low, int high);

void quicksort_recru(double array[], int index_array[], int low, int high);

std::vector<int> quicksort(double array[], int lenth);

}

#endif
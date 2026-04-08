#include <utility>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Quicksort.h"

namespace func{

int partition(double array[], int index_array[], int low, int high){
    int pivot_val = array[high];

    int i = low;
    
    for (int j= low; j < high; ++j){
        if (array[j] <= pivot_val){
            
            std::swap(array[i], array[j]);
            std::swap(index_array[i], index_array[j]);
            i++;
        }
   }
   std::swap(array[i], array[high]);
   std::swap(index_array[i], index_array[high]); 
   return i;
}


void quicksort_recru(double array[], int index_array[], int low, int high){
    if (low < high){
        int pivot_index = partition(array, index_array, low, high);
        
        quicksort_recru(array, index_array, low, pivot_index - 1);
        quicksort_recru(array, index_array, pivot_index + 1, high);
    }
};


std::vector<int> quicksort(double array[], int lenth){

    std::vector<int> index_array(lenth);
    for(int k=0;k<lenth;++k){
        index_array[k]=k;}

    quicksort_recru(array, index_array.data(), 0, lenth-1);
    return index_array; // moves efficiently
}

}






// for (int i=0; i < lenth; ++i){       // Buble sort algorithme takes O(n^2) computation time.
//     for (int j=0; j < lenth - 1; ++j){
//         if (arr[j] > arr[j+1]){
//             int temp = arr[j];

//             arr[j] = arr[j+1];
//             arr[j+1] = temp;
//         }
//     }
// }
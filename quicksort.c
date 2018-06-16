#include <iostream>
#include <vector>

#include <time.h>

/* Function to print an vector */
void printArray(std::vector<int> arr){
  
  for (int i=0; i < arr.size(); i++)
    std::cout << arr[i] << " ";

  std::cout << std::endl;
}

void makeRandomArray(std::vector<int> &arr, int a, int b){

  time_t t;
  
  /* Intializes random number generator */
  srand((unsigned) time(&t));
  
  for(int i= 0 ; i < arr.size() ; i++ ) {  

    arr[i] =  a + rand() % b ;
    
  }
}

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int sortPivot( std::vector<int> &arr, int leftIndex, int rightIndex){

  int pivotIndex = rightIndex; // last position
  int pivot = arr[pivotIndex];

  #ifdef DEBUG
  std::cout << "leftIndex: " << leftIndex << std::endl;
  std::cout << "rightIndex: " << rightIndex << std::endl;
  std::cout << "pivotIndex: " << pivotIndex << std::endl;
  #endif
  
  int left = leftIndex;
  int right = pivotIndex -1;
  
  #ifdef DEBUG
  std::cout << "left: " << left << std::endl;
  std::cout << "right: " << right << std::endl;
  #endif
  
  while (left <= right){
    
    while (arr[left] < pivot){
      left++;
    }
    
    while (arr[right] > pivot){
      right--;
    }

    #ifdef DEBUG
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;
    #endif

    if (left <= right){
      swap(&arr[left],&arr[right]);

      #ifdef DEBUG
      printArray(arr);
      #endif
      
      left++;
      right--;
    }
    
  }
  
  swap(&arr[left],&arr[pivotIndex]);
  
  pivotIndex = left;
  
  return pivotIndex;
}
 
void quicksort( std::vector<int> &arr, int leftIndex, int rightIndex){
  
  int pivotIndex = -1;
  
  if(leftIndex < rightIndex){

    pivotIndex = sortPivot(arr, leftIndex, rightIndex);
    
    // split array in left n right partittion
    //left
    quicksort(arr, leftIndex, pivotIndex - 1);
    //right
    quicksort(arr, pivotIndex + 1, rightIndex);  
  }
}

int main(int argc, char **argv){

  int size = 7;
  std::vector<int> arr(size);
  
  makeRandomArray(arr, 0, 50);
  
  int leftIndex = 0;
  int rightIndex = size-1;
  
  std::cout << "size of array: " << size << std::endl;
  std::cout << "Original array: " << std::endl;

  printArray(arr);
  
  quicksort(arr, leftIndex, rightIndex);

  std::cout << "Sorted array:" << std::endl;
  printArray(arr);
  
  return 1;
}

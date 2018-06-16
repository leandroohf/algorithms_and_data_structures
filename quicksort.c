#include <iostream>
#include <vector>

#include <time.h>

/* Function to print vector */
void printArray(std::vector<int> arr){
  
  for (int i=0; i < arr.size(); i++)
    std::cout << arr[i] << " ";

  std::cout << std::endl;
}

// Fill vector with random integers between a and b. 
void makeRandomArray(std::vector<int> &arr, int a, int b){

  time_t t;
  
  /* Initializes random number generator */
  srand((unsigned) time(&t));
  
  for(int i= 0 ; i < arr.size() ; i++ ) {  

    arr[i] =  a + rand() % b ;
    
  }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int movePivotToPosition( std::vector<int> &arr, int beginPartition, int endPartition){
  
  int pivotIndex = endPartition; // last position
  int pivot = arr[pivotIndex];

  #ifdef DEBUG
  std::cout << "beginPartition: " << beginPartition << std::endl;
  std::cout << "endPartition: " << endPartition << std::endl;
  std::cout << "pivotIndex: " << pivotIndex << std::endl;
  #endif
  
  int left = beginPartition;
  int right = pivotIndex -1;
  
  #ifdef DEBUG
  std::cout << "left: " << left << std::endl;
  std::cout << "right: " << right << std::endl;
  #endif
  
  while (left <= right){

    // Find left elements large than pivot
    while (arr[left] < pivot){
      left++;
    }

    // Find right elements smaller than pivot
    while (arr[right] > pivot){
      right--;
    }

    #ifdef DEBUG
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;
    #endif

    // Swap left and right
    if (left <= right){
      swap(&arr[left],&arr[right]);

      #ifdef DEBUG
      printArray(arr);
      #endif
      
      left++;
      right--;
    }
    
  }

  // Put pivot in its position
  swap(&arr[left],&arr[pivotIndex]);
  
  pivotIndex = left;
  
  return pivotIndex;
}
 
void quicksort( std::vector<int> &arr, int beginPartition, int endPartition){
  
  int pivotIndex = -1;
  
  if(beginPartition < endPartition){

    pivotIndex = movePivotToPosition(arr, beginPartition, endPartition);
    
    // split array in left n right partittion
    //left
    quicksort(arr, beginPartition, pivotIndex - 1);
    //right
    quicksort(arr, pivotIndex + 1, endPartition);  
  }
}

int main(int argc, char **argv){

  int size = 7;
  std::vector<int> arr(size);
  
  makeRandomArray(arr, 0, 50);
  
  int beginPartition = 0;
  int endPartition = size-1;
  
  std::cout << "size of array: " << size << std::endl;
  std::cout << "Original array: " << std::endl;

  printArray(arr);
  
  quicksort(arr, beginPartition, endPartition);

  std::cout << "Sorted array:" << std::endl;
  printArray(arr);
  
  return 1;
}

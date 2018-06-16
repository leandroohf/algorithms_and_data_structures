
My notes and code about the main algorithm and data structures

#  Quicksort
  
  **WIP**

  * Quciksort use divide to conqueror approach
  * Works with the concepst of pivot: The pivot can be any of your
    choice, but for efficiency is better to choose wise. See discuss
    later. 
  * Split the array in two parts
    * left: all elements are smaller than pivot
    * right: all elements are bigger than the pivot
    
  *The lagorithm makes sure that eventhough each partition is not full
  sorted, the elements are in the correct order in relation to the
  pivot. That is the power of the quicksort, it is never necessary to
  compare elements form the left partition to element of the right
  partion and this reduze a lot the over all number of comparison.*
     
  <img src="images/quick_sort_pivot.png" width="200"/>
   
  * quicksort utilizes recurssion in the two parts of the arrays

  <img src="images/quick_sort_recursion.png" width="200"/>
  
  Quicksort is not always the best algorithm. When the array is
  already order or almost order he perform like buble sort $O(n^2)$.
  
  * Space oreder: $O(n)$
  * Order
    * worst: $O(n^ 2)$
    * average: $O(n log(n))$
    * best: $O(n log(n))$

  Quicksort can be even optimize by running the recursive calls in
  parallel.

  refs:
  * https://medium.com/basecs/pivoting-to-understand-quicksort-part-1-75178dfb9313
  * https://medium.com/basecs/pivoting-to-understand-quicksort-part-2-30161aefe1d3
  
### Code

   To compile the code 

   ```sh
   g++ -Wall quicksort.c -o quick
   
   # With debug information
   g++ -g -DDEBUG -Wall quicksort.c -o quick
   ```

   To run:
   
   ```sh
   # Create and random array of size 7 and sort it  
   ./quick
   ```

# Merge Sort

    **TODO**
    
# Binary Serach

    **TODO**

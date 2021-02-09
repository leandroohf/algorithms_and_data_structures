
My notes and code about the main algorithm and data structures.

#  Quicksort

  * Quciksort utilizes the divide to conqueror approach
  * Works with the concept of pivot: The pivot can be any of your
    choice, but for efficiency is better to choose wisely. See discuss
    later.
  * Split the array in two parts
    * left: all elements are smaller than pivot
    * right: all elements are bigger than the pivot
  
  *The algorithm makes sure that even though each partition is not
  fully sorted, the elements are in the correct order in relation to
  the pivot. That is the power of the quicksort, it is never necessary
  to compare elements from the left partition with the elements of the
  right partition and this reduces to the overall number of
  comparison.* Because of that the quicksort performance can be
  affected by the choice of the pivot. If the pivot split small
  partitions left or right either way, the algorithm will still make
  many comparisons.
       
  <img src="images/quick_sort_pivot.png" width="200"/>
   
  * quicksort utilizes recurssion in the two parts of the arrays

  <img src="images/quick_sort_recursion.png" width="200"/>
    
  Quicksort is not always the best algorithm. When the array is
  already ordered or almost ordered it performs like **bubble** sort
  $O(n^2)$.

  * Space order: $O(1)$  
  
      Quicksort operates directly on the inputted data by swapping
      elements, and only needs a tiny bit of extra space in
      memory — usually a constant amount of space.
  
  * Order  
    * worst: $O(n^ 2)$
    
        The array is ordered or almost ordered
    
    * average: $O(n log(n))$
        
    * best: $O(n log(n))$

  Quicksort can be even optimize by running the recursive calls in
  parallel (reduce the time by half)).

  refs:
  * https://medium.com/basecs/pivoting-to-understand-quicksort-part-1-75178dfb9313
  * https://medium.com/basecs/pivoting-to-understand-quicksort-part-2-30161aefe1d3
  
### Code

See: [here](quicksort.c)

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

<img src="images/quicksort_terminal.png" width="400"/>

# Merge Sort

See notebook: [Sorting algorithms](./sorting.ipynb)
    
# Binary Search

See notebook: [Binary Search](./binary_search.ipynb)

# Binary Tree and Binary Search Tree

See notebook: [Binary Search_Tree](./binary_search_tree.ipynb)

# Graph

See notebook: [Graph](./graph.ipynb)


# Notes

The author believes that share code and knowledge is awesome.  Feel
free to share and modify this piece of code. But don't be impolite and
remember to cite the author and give him his credits.


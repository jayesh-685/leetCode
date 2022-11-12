one way is to calculate next smaller element and prev smaller element separately using 2 passes.
otherwise, when calculating prev smaller element, for element i when you pop the greater elements on stack, for the element on top of stack the next smaller element is the element i and the prev smaller element is the next element on the stack so we can calculate the area for each bar in one pass.
​
after traversing over the whole array we will still have some elements left so to calculate area for those we will traverse till i=n
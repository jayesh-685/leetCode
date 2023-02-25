2 ways:
​
first consider min elements of all the lists and find the range. then find the min amongst the considered elements and replace it with the second min element from that list, and find the range again.
use a pq for the implementation
​
second approach is merge all the lists together. use a array of pair to track of which lists a particular element belongs to. then use slinding window technique.
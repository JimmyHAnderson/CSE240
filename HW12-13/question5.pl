/* Class: CSE240 */
/* Compiler used: SWISH */
/* Assignment Info: question5 */
/* Time for Completion: 10 minutes */
/* Question 5 */
/* Facts */
isort([], []). %defines the base case of the sorting algorithm
isort([First|Tail], Sorted) :- %sorts a nonempty list and will recursively sort the tail of the list and insert the first elemented into the sorted tail using inser
    isort(Tail, SortedTail),
    insert(First, SortedTail, Sorted).

insert(X, [], [X]). %case where the list is empty which will return [X]
insert(X, [Y|Tail], [X,Y|Tail]) :- X =< Y. %case where X is less than or equal to Y
insert(X, [Y|Tail], [Y|SortedTail]) :- X > Y, insert(X, Tail, SortedTail). %case where X is greater than Y
/* test case 
 ?- isort([8, 3, 4, 12, 25, 4, 6, 1, 9, 22, 6], Sorted). returns 
 Sorted = [1, 3, 4, 4, 6, 6, 8, 9, 12, 22, 25]
 */
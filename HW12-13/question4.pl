/* Class: CSE240 */
/* Compiler used: SWISH */
/* Assignment Info: question4 */
/* Time for Completion: 10 minutes */
/* Question 4 */
/* Facts */
my_flatten([], []). %base case when both lists are empty
my_flatten([X|Xs], Flat) :- %handles the case where the head of the list is a lit and will recursively flatten X to get XFlat then results into the final flattened list
    is_list(X),
    !,
    my_flatten(X, XFlat),
    my_flatten(Xs, XsFlat),
    append(XFlat, XsFlat, Flat).
my_flatten([X|Xs], [X|Flat]) :- %handles the case where the head of the list is not a list 
    my_flatten(Xs, Flat).


/* test case 
 ?- my_flatten([a, [b, [c, d], e]], X). returns X = [a, b, c, d, e]
 */

/* Class: CSE240 */
/* Compiler used: SWISH */
/* Assignment Info: question3 */
/* Time for Completion: 40 minutes */

/* Facts */
qsort2([],[]):- !. %base case which sorts an empty list and returns an empty list

qsort2([X], [X]). %case where it sorts a list with a single element

qsort2([Head|[Pivot|Tail]],Sorted):- %main part of the program which selects a pivot and splits the element into roughly equal subarrays
    split(Pivot,[Head|Tail],Less,Greater),
    qsort2(Less,SortedLess),
    qsort2(Greater,SortedGreater),
    append(SortedLess,[Pivot|SortedGreater],Sorted).

split(_,[],[],[]). %slip part of the code which will compare new pivot points in the subarrays and return a sorted array.
split(Pivot,[X|T],[X|Less],Greater):-
	X=<Pivot,split(Pivot,T,Less,Greater).
split(Pivot,[X|T],Less,[X|Greater]):-
	X>Pivot,split(Pivot,T,Less,Greater).
% ?- qsort2([8, 3, 4, 12, 25, 4, 6, 1, 9, 22, 6], Sorted) will return  Sorted = [1, 3, 4, 4, 6, 6, 8, 9, 12, 22, 25]

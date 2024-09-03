/* Class: CSE240 */
/* Compiler used: SWISH */
/* Assignment Info: question1 */
/* Time for Completion: 50 minutes */
/* RULES */
/* Question 1.1 */
colors([purple, green, yellow, red]).
% minimum colors used : 4

/* Question 1.2 */
% defines each state
state(alaska).
state(arizona).
state(california).
state(colorado).
state(hawaii).
state(idaho).
state(montana).
state(nevada).
state(new_mexico).
state(oregon).
state(utah).
state(washington).
state(wyoming).

% Neighboring Relationship definition I have really bad geography with these edge cases LOL
neighbor(arizona, california). 
neighbor(arizona, colorado).
neighbor(arizona, nevada).
neighbor(arizona, new_mexico).
neighbor(arizona, utah).
neighbor(california, oregon).
neighbor(california, nevada).
neighbor(colorado, new_mexico).
neighbor(colorado, utah).
neighbor(colorado, wyoming).
neighbor(idaho, montana).
neighbor(idaho, nevada).
neighbor(idaho, oregon).
neighbor(idaho, utah).
neighbor(idaho, washington).
neighbor(idaho, wyoming).
neighbor(montana, wyoming).
neighbor(nevada, oregon).
neighbor(nevada, utah).
neighbor(new_mexico, utah).
neighbor(oregon, washington).

% State Colors
color(alaska, purple). 
color(arizona, yellow).
color(california, green).
color(colorado, green).
color(hawaii, purple). 
color(idaho, green).
color(montana, yellow).
color(nevada, red).
color(new_mexico, red).
color(oregon, purple).
color(utah, purple).
color(washington, red).
color(wyoming, red).

/* Question 1.3 */ 
%checks to see if a state is adjacent to eacher so for example running California and Arizona will yield true
adjacent(State1, State2) :- neighbor(State1, State2);neighbor(State2, State1).
/* Question 1.4 */
%checks to see if defined colors have a mismatch, will yield a false if there is no miscolor and true if there is(False is good)!!
miscolor(X, Y) :- color(X, C), color(Y, C), adjacent(X, Y), X \= Y.

/* Question 1.5 */ 
%if there is a miscolor, then it will print all the states with matching colors.
q :- miscolor(X, Y), write('Mismatch: '), write(X), write(' and '), write(Y), nl, fail.
q :- write('No mismatches found surely I get full credit please big kappa chungus deluxe?.'), nl.


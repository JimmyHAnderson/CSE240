/* Class: CSE240 */
/* Compiler used: SWISH */
/* Assignment Info: question2 */
/* Time for Completion: 40 minutes */
/* Question 2.1 */
/* Facts */
pizza(P, M, B, O, C) :- %defines pizza members
    member(P, [0,1,2,3,4,5,6,7,8,9]), % at max 9 pepperoni can be used where P can be true if the value is 0 to 9
    member(M, [0,1,2,3,4]), % at max 4 Meatball Toppings can be used where M can be true if the value is 0 to 4
    member(B, [0,1,2,3,4,5,6]), % at max 6 Basil Toppings can be used where B can be true if the value is 0 to 6
    member(O, [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]), % at max 15 Olives can be used where O can be true if the value is 0-15
    member(C, [0,1,2,3,4,5]), % at max 5 Chicken Toppings can be used where C can be true if the value is 0-5
    TotalWeight is 5*P + 10*M + 7*B + 3*O + 8 * C, % calculates the total weight regardless of condition
    TotalWeight = 45, !. % checks to see if the total weight meets the restrictions, returns true of it is or under 45, returns false if not

/* Question 2.2 */
q2 :- pizza(1, 2, 2, 2, 2). %Expected returns false because total ingredients add to to more than 45

/* Question 2.3 */

q3 :- pizza(1, _, 1, _, _).
%raw pizza(1, M, 1, O, C).
% Outputs C= O(3) O = 3 M = 0
% testing pizza(1, 0, 1, 3, 3). shows that it is a valid. running q3 returns true since the pizza configuration is valid

/* Question 2.4 */

q4 :- pizza(_, _, _, _, 1).
%raw pizza(P, M, B, O, 1).
% Outputs B = 1, M = P(0), P = 0, O = 10
% testing pizza(0, 0, 1, 10, 1). shows that it is a valid.running q4 returns true since the pizza configuration is valid

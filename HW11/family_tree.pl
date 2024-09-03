
/* Class: CSE240 */
/* Compiler used: SWISH */
/* Assignment Info: family_tree.pl */
/* Time for Completion: 20 minutes */
/* Facts */

/* males */
male(abe).
male(jim).
male(rob).
male(mac).
male(ben).
male(bud).
male(kai).
male(tex).
male(roy).
male(lee).

/* females */
female(joy).
female(mia).
female(ana).
female(kim).
female(zoe).
female(mae).
female(amy).
female(val).
female(pam).
/* Database for family tree. It consists of facts and rules. */
/* The section in the highlighted box above has been completed for you */



father_of(abe, ana). /* abe is the father of ana */
father_of(abe, rob). /* abe is the father of rob */
father_of(abe, jim). /* abe is the father of jim */
father_of(jim, mac). /* jim is the father of mac */
father_of(jim, kim). /* jim is the father of kim */
father_of(bud, zoe).
father_of(bud, val).
father_of(bud, tex).
father_of(bud, roy).
father_of(ben, bud).
father_of(ben, amy).
father_of(kai, lee).
father_of(kai, pam).

mother_of(joy, rob). /* joy is the mother of rob */
mother_of(joy, jim). /* joy is the mother of jim */
mother_of(joy, ana). /* joy is the mother of ana */
mother_of(mia, mac). /* mia is the mother of mac */
mother_of(mia, kim). /* mia is the mother of kim */
mother_of(ana, zoe).
mother_of(ana, val).
mother_of(ana, tex).
mother_of(ana, roy).
mother_of(mae, amy).
mother_of(mae, bud).
mother_of(amy, lee).
mother_of(amy, pam).

/* Complete the facts given in the diagram above */


/* RULES */

/* Question 1.1 */
is_male(X) :-
male(X);
father_of(X, _).

/* Question 1.2 */

is_female(X):-female(X);mother_of(X,_).

/* Question 1.3 */

parent_of(X,Y):-father_of(X,Y);mother_of(X,Y),male(X);female(X).

/* Question 1.4 */
sibling_of(X,Y):-parent_of(Z,X),parent_of(Z,Y),not(X=Y).

/* Question 1.5 */
grandmother_of(X,Z):-parent_of(X,Y),parent_of(Y,Z),female(X).
grandfather_of(X,Z):-parent_of(X,Y),parent_of(Y,Z),male(X).

/* Question 1.6 */

descendent_of(X,Y):-parent_of(Y,X).
descendent_of(X,Y) :- parent_of(Y, Z), descendent_of(Z,X).
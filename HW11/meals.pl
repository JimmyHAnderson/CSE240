/* Class: CSE240 */
/* Compiler used: SWISH */
/* Assignment Info: meals.pl */
/* Time for Completion: 30 minutes */

/* Facts */

/* Question 2.1 */

/* entre*/
entre(lunch,sandwhich).
entre(dinner,spaghetti).

/* side*/
side(lunch,chips).
side(lunch,lemonade).
side(dinner,bread).
side(dinner,greentea).

/* ingredient*/
ingredient(chips,potato).
ingredient(chips,salt).
ingredient(lemonade,lemon).
ingredient(lemonade,sugar).
ingredient(bread,egg).
ingredient(bread,flour).
ingredient(greentea,green).
ingredient(greentea,tea).

/* Question 2.2 */
meal(X,Y):-
    entre(X,Y);
    side(X,Y).

/* Question 2.3 */
shoppinglist(X,Y):-
    side(X,Z),
    ingredient(Z,Y).
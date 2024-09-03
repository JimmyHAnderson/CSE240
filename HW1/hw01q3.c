#include <stdio.h>

int main() {
    char ch = '+';
    int a = 10, b = 20;
    double f;

    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %f ", (float)f);
        break;
    case '-':
        f = a - b;
        printf("f = %f ", (float)f);
        break;
    case '*':
        f = a * b;
        printf("f = %f ", (float)f);
        break;
    case '/':
        f = a / b;
        printf("f = %f ", (float)f);
        break;
    default:
        printf("invalid operator ");
    }

    ch = '-';
    printf("ch = %c ", ch);

    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %f ", (float)f);
        break;
    case '-':
        f = a - b;
        printf("f = %f ", (float)f);
        break;
    case '*':
        f = a * b;
        printf("f = %f ", (float)f);
        break;
    case '/':
        f = a / b;
        printf("f = %f ", (float)f);
        break;
    default:
        printf("invalid operator ");
    }

    ch = '*';
    printf("ch = %c ", ch);

    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %f ", (float)f);
        break;
    case '-':
        f = a - b;
        printf("f = %f ", (float)f);
        break;
    case '*':
        f = a * b;
        printf("f = %f ", (float)f);
        break;
    case '/':
        f = a / b;
        printf("f = %f ", (float)f);
        break;
    default:
        printf("invalid operator ");
    }

    ch = '/';
    printf("ch = %c ", ch);

    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %f ", (float)f);
        break;
    case '-':
        f = a - b;
        printf("f = %f ", (float)f);
        break;
    case '*':
        f = a * b;
        printf("f = %f ", (float)f);
        break;
    case '/':
        f = a / b;
        printf("f = %f ", (float)f);
        break;
    default:
        printf("invalid operator ");
    }

    ch = '%';
    printf("ch = %c ", ch);

    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %f ", (float)f);
        break;
    case '-':
        f = a - b;
        printf("f = %f ", (float)f);
        break;
    case '*':
        f = a * b;
        printf("f = %f ", (float)f);
        break;
    case '/':
        f = a / b;
        printf("f = %f ", (float)f);
        break;
    default:
        printf("invalid operator ");
    }

    return 0;
}
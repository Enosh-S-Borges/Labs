/* 9.b. Develop a menu driven program to convert infix expression to prefix and evaluate the prefix expression. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack structure for characters (operators)
typedef struct CharStack 
{
    int top;
    char arr[MAX];
} CharStack;

// Stack structure for integers (evaluation)
typedef struct IntStack 
{
    int top;
    int arr[MAX];
} IntStack;

int precedence(char op);
int isOperator(char ch);
void pushChar(CharStack *s, char ch);
char popChar(CharStack *s);
char peekChar(CharStack *s);
void pushInt(IntStack *s, int val);
int popInt(IntStack *s);
void infixToPrefix(char infix[], char prefix[]);
int evaluatePrefix(char prefix[]);

int main() 
{
    char infix[MAX], prefix[MAX];
    int choice;
    do {
        printf("\n===== Menu =====\n");
        printf("1. Convert Infix to Prefix\n");
        printf("2. Evaluate Prefix Expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPrefix(infix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;
            case 2:
                printf("Enter prefix expression: ");
                scanf("%s", prefix);
                printf("Prefix Evaluation Result: %d\n", evaluatePrefix(prefix));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 3);
    return 0;
}

int precedence(char op) 
{
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

int isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void pushChar(CharStack *s, char ch) 
{
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = ch;
}

char popChar(CharStack *s) 
{
    if (s->top == -1) 
        return '\0';
    return s->arr[s->top--];
}

char peekChar(CharStack *s) 
{
    if (s->top == -1) 
        return '\0';
    return s->arr[s->top];
}

void pushInt(IntStack *s, int val) 
{
    if (s->top == MAX - 1) 
        return;
    s->arr[++s->top] = val;
}

int popInt(IntStack *s) 
{
    if (s->top == -1) 
        return 0;
    return s->arr[s->top--];
}

void infixToPrefix(char infix[], char prefix[]) 
{
    int len = strlen(infix);
    char reversed[MAX], tempPrefix[MAX];
    CharStack s;
    s.top = -1;
    int k = 0;
    //Step 1: Reverse
    for (int i = 0; i < len; i++) 
    {
        char ch = infix[len - i - 1];
        if (ch == '(') 
            ch = ')';
        else if (ch == ')') 
            ch = '(';
        reversed[i] = ch;
    }
    reversed[len] = '\0';

    // Step 2: Convert reversed infix to postfix (temporary prefix)
    k = 0;
    for (int i = 0; i < len; i++) 
    {
        char ch = reversed[i];
        if (isdigit(ch)) 
            tempPrefix[k++] = ch;
        else if (ch == '(') 
            pushChar(&s, ch);
        else if (ch == ')') 
        {
            while (s.top != -1 && peekChar(&s) != '(') 
            {
                tempPrefix[k++] = popChar(&s);
            }
            popChar(&s); 
        } 
        else if (isOperator(ch)) 
        {
            while (s.top != -1 && precedence(peekChar(&s)) > precedence(ch)) 
            {
                tempPrefix[k++] = popChar(&s);
            }
            pushChar(&s, ch);
        }
    }
    while (s.top != -1) {
        tempPrefix[k++] = popChar(&s);
    }
    tempPrefix[k] = '\0';

    // Step 3: Reverse the temporary prefix to get final prefix
    int tlen = strlen(tempPrefix);
    for (int i = 0; i < tlen; i++) 
        prefix[i] = tempPrefix[tlen - i - 1];
    prefix[tlen] = '\0';
}

int evaluatePrefix(char prefix[]) 
{
    IntStack s;
    s.top = -1;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) 
    {
        char ch = prefix[i];
        if (isdigit(ch)) 
            pushInt(&s, ch - '0');
        else if (isOperator(ch)) 
        {
            int val1 = popInt(&s);
            int val2 = popInt(&s);
            int res;
            switch(ch) 
            {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                case '^': res = (int)pow(val1, val2); break;
            }
            pushInt(&s, res);
        }
    }
    return popInt(&s);
}
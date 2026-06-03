#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 501

typedef enum { NUMBER, OPERATOR } TokenType;
typedef struct {
    TokenType type;
    union {
        long long value;
        char op;
    } data;
} Token;

char op_stack[MAX_SIZE];
int op_top = -1;

void op_push(char op) {
    if (op_top < MAX_SIZE - 1) op_stack[++op_top] = op;
}
char op_pop() {
    return (op_top >= 0) ? op_stack[op_top--] : '\0';
}
char op_peek() {
    return (op_top >= 0) ? op_stack[op_top] : '\0';
}
int is_op_stack_empty() {
    return op_top == -1;
}

long long value_stack[MAX_SIZE];
int value_top = -1;

void value_push(long long val) {
    if (value_top < MAX_SIZE - 1) value_stack[++value_top] = val;
}
long long value_pop() {
    return (value_top >= 0) ? value_stack[value_top--] : 0;
}

int get_precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

long long power(long long base, long long exp) {
    if (exp < 0) return 0;
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}

int main() {
    char expression[MAX_SIZE];
    long long variables[26] = {0};
    int is_set[26] = {0}; 

    scanf(" %s", expression);

    int paren_count = 0;
    for (int i = 0; expression[i] != '\0'; ++i) {
        if (expression[i] == '(') {
            paren_count++;
        } else if (expression[i] == ')') {
            paren_count--;
        }
        if (paren_count < 0) {
            printf("emf\n");
            return 0;
        }
    }
    if (paren_count != 0) {
        printf("emf\n");
        return 0;
    }

    char var_name;
    long long value;
    while (scanf(" %c=%lld", &var_name, &value) == 2) {
        if (isupper(var_name)) {
            variables[var_name - 'A'] = value;
            is_set[var_name - 'A'] = 1;
        }
    }

    Token rpn_queue[MAX_SIZE];
    int rpn_count = 0;
    int error_flag = 0;

    for (int i = 0; expression[i] != '\0'; ++i) {
        char c = expression[i];
        if (isalpha(c)) {
            if (!is_set[c - 'A']) { error_flag = 1; break; }
            rpn_queue[rpn_count].type = NUMBER;
            rpn_queue[rpn_count++].data.value = variables[c - 'A'];
        } else if (strchr("+-*/^", c)) {
            while (!is_op_stack_empty() && op_peek() != '(' &&
                   (get_precedence(op_peek()) > get_precedence(c) ||
                    (get_precedence(op_peek()) == get_precedence(c) && c != '^'))) {
                rpn_queue[rpn_count].type = OPERATOR;
                rpn_queue[rpn_count++].data.op = op_pop();
            }
            op_push(c);
        } else if (c == '(') {
            op_push(c);
        } else if (c == ')') {
            while (!is_op_stack_empty() && op_peek() != '(') {
                rpn_queue[rpn_count].type = OPERATOR;
                rpn_queue[rpn_count++].data.op = op_pop();
            }
            op_pop(); 
        }
    }
    while (!is_op_stack_empty()) {
        rpn_queue[rpn_count].type = OPERATOR;
        rpn_queue[rpn_count++].data.op = op_pop();
    }
    
    if (error_flag) { printf("emf\n"); return 0; }

    for (int i = 0; i < rpn_count; ++i) {
        Token token = rpn_queue[i];
        if (token.type == NUMBER) {
            value_push(token.data.value);
        } else {
            if (value_top < 1) { error_flag = 1; break; }
            long long val2 = value_pop();
            long long val1 = value_pop();
            
            switch (token.data.op) {
                case '+': value_push(val1 + val2); break;
                case '-': value_push(val1 - val2); break;
                case '*': value_push(val1 * val2); break;
                case '/':
                    if (val2 == 0) { error_flag = 1; break; }
                    value_push(val1 / val2); 
                    break;
                case '^': value_push(power(val1, val2)); break;
            }
        }
        if (error_flag) break;
    }

    if (error_flag || value_top != 0) {
        printf("emf\n");
    } else {
        printf("%lld\n", value_stack[0]);
    }

    return 0;
}
char* removeStars(char* s) {

    char* stack = malloc(strlen(s)+1);
    int top = 0 ; 

    while (*s != '\0'){

        if (*s =='*'){
            top--;
        }

        else {
            stack[top++]=*s;
        }

        s++;
    }
    stack[top] = '\0';

    return stack;
    
}
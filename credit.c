#include <stdio.h>

int oddcase(long long num){
    long long i = num;
    int sum = 0;
    int n = 0;
    while (i > 9){
        i = i /10;
        n = i % 10 * 2;
        while(n > 0){
            sum = sum + n % 10;
            n = n /10;
        }
        i = i / 10;
    }
    i = num;
    while (i > 0){
        sum = sum + i % 10;
        i = i / 100;
    }
    return sum;
}

int evencase(long long num){
    long long i = num;
    int sum = 0;
    int n = 0;
    while (i > 9){
        n = i % 10 * 2;
        while(n > 0){
            sum = sum + n % 10;
            n = n /10;
        }
        i = i / 100;
    }
    i = num;
    while (i > 0){
        sum = sum + i % 10;
        i = i / 100;
    }
    return sum;
}

int main(void) {
    long long number = 0;
    int length = 0;
    long long lenghtcheck = 0;
retry:
    length = 0;
    printf("Enter the number of your card: ");
    scanf("%lld", &number);
    lenghtcheck = number;
    if(number < 0){
        goto retry;
    }
    while(lenghtcheck > 0){
        lenghtcheck = lenghtcheck / 10;
        length++;
    }
    switch(length){
        case 13:
        case 15:
        case 16:
            break;
        default:
            printf("Number is invalid\n");
            length = 0;
            goto retry;
    }
    if(length % 2 == 0){
        lenghtcheck = oddcase(number);
    } else {
        lenghtcheck = evencase(number);
    }
    while(number > 9){
        number = number / 10;
    }
    switch (number){
        case 3:
            printf("Your card is : American express\n");
            break;
        case 4:
            printf("Your card is : Visa\n");
            break;
        case 5:
            printf("Your card is : MasterCard\n");
            break;
        default:
            printf("Card is not Legit\n");
            goto retry;
    }
}

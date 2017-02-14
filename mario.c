#include <stdio.h>
#include <cstdlib>

int get_int(void){
    int i = 0;
    bool flag = true;
    char a[5] = { 0 };
    while(flag){
        printf("Give me integer: ");
        gets(a);
        bool numb = true;
        for(i = 0; a[i] != 0; i++){
            if(a[i] < '0' || a[i] > '9'){
                numb = false;
            }
            
        }
        if(numb){
            i = atoi(a);
            flag = false;
        }
    }
    return i;
}

void hash(int n){
    for(int i = 0; i < n; i++){
        printf("#");
    }
}
void space(int n){
    for(int i=0; i<n; i++){
        printf(" ");
    }
}

void building(int n){
    for(int i = 1; i < n + 1; i++){
        space(n - i);
        hash(i);
        space(2);
        hash(i);
        printf("\n");
    }
}

int main(void){
    char c = 0;
    bool check = true;
    bool flag = true;
    while(flag){
       int i = get_int();
        building(i);
        while(check){
            printf("Build again?\nY/N: ");
            if(c != 0){
                c = 0;
            }
            c = getchar();
            switch(c){
                case 'y':
                case 'Y':
                    check = false;
                    break;
                case 'n':
                case 'N':
                    check = false;
                    flag = false;
                    break;
                default:
                    break;
            }
        }
    }
}

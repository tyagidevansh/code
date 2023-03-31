//bubble sort

#include <stdio.h>

void sort(int array[], int n)
{   printf("A or D?");
    char a;
    scanf(" %c", &a);
    
    if(a == 'A'){
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j < n-1; j++){
                if(array[j] > array[j+1]){
                    int temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                } 
            }
        }
    }

    
    else if(a == 'D'){
        for(int i = 0; i< n-1; i++){
            for(int j = 0; j < n-1; j++){
                if(array[j] < array[j+1]){
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                } 
            }
        }
    }



}

void print(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}

int main(){
    int n;
    printf("How many elements in your in the array? ");
    scanf("%d", &n);
    int array[n];

    printf("Enter the elements of your array:\n");
    for(int i = 0; i< n; i++){
        scanf("%d", &array[i]);
    }

    sort(array,n);
    print(array, n);
    
    return 0;

}
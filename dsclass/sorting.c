#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n);
void selectionSort(int *arr, int n);
void insertionSort(int *arr, int n);
void recursionSort(int *arr, int n);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    //int n = 7, i;
    //int arr[7] = {};

    
    // This pointer will hold the
    // base address of the block created
    int* arr;
    int n, i;
 
    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    arr = (int*)malloc(n * sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        printf("Enter the elements of the array\n");
        for (i = 0; i < n; i++) 
            scanf("%d", arr + i);
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; i++)
            printf("%d, ", arr[i]);
    }
    
        
    insertionSort(arr, n);
    
    // Print the elements of the sorted array
    printf("\nThe elements of the sorted array are: ");
    for (i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void bubbleSort(int *arr, int n){
    //i loops through the array
    for (int i = 0; i < n; i++){
        //j loops from 0 to n - i - 1
        //the largest value is bubbled to the top of the array
        for(int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr +j, arr +j +1);
            }
        }
    }
}


void selectionSort(int *arr, int n){
    //i loops through the array
    for (int i = 0; i < n; i++){
        int pos = i;
        //j loops from i + 1 to n
        //the position of the least value is noted and swapped at the end
        for(int j = i + 1; j < n; j++){
            if (arr[pos] > arr[j]){
                pos = j;
            }
        }
        swap(arr + i, arr + pos);
    }
}

void insertionSort(int *arr, int n){
    for (int i = 1; i < n; i++) {
        int j = i;
        //j moves down the array starting from i
        //ith element is moved left step by step until 
        //elements to the left are no longer bigger than arr[i]
        //hence the elements to the left of i will always be sorted
        while (j > 0 && arr[j] < arr[j-1]){
            swap(arr + j, arr + j -1);
            j--;
        }
    }
}

void recursionSort(int *arr, int n){
    int mid = n/2;
    if (mid != 0){
        recursionSort(arr, mid);
        recursionSort(arr + mid, n - mid);
    }else{
        return;
    }
    
    //now we merge the two sorted arrays
    int copy[n];
    int temp = 0;
    int l = 0;
    int r = mid;

    //in each iteration of this loop we are filling one value in the sorted array
    while ((l < mid) && (r <  n)){
        if(arr[l] <= arr[r]){
            copy[temp] = arr[l];
            l++;
            temp++;
        }else{
            copy[temp] = arr[r];
            r++;
            temp++;
        }
    }

    //we have to fill the remaining values in the array
    while (l < mid){
            copy[temp] = arr[l];
            l++;
            temp++;
    }
    while (r < n){
            copy[temp] = arr[r];
            r++;
            temp++;
    }

    //copying the temp array back to the original array
    for(int i = 0; i < n; i++)
        arr[i] = copy[i];
}

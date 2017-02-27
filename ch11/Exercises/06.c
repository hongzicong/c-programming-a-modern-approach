#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
    int a[10] = {38, 4, 38, 84, 65, 9, 5, 14, 76, 49};
    int largest = 0, second_largest = 0, i;

    printf("Array contents: ");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n");

    find_two_largest(a, sizeof(a) / sizeof(a[0]), &largest, &second_largest);
    printf("Largest: %d, Second Largest: %d\n", largest, second_largest);
    return 0;
}

/* finds the two largest values in an array */
void find_two_largest(int a[],int n,int *largest,int *second_largest){
	
	int m;//max
	*largest=a[0];
	*second_largest=a[0];
	
	for(int i=1;i<n;i++){
		if(a[i]>*largest){
			*largest=a[i];
			m=i;
		}
	}
	
	for(int i=1;i<n;i++){
		if(i!=m&&a[i]>*second_largest){
			*second_largest=a[i];
		}
	}
}


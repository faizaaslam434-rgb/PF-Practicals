#include <stdio.h>
#include <stdlib.h>
void CountFrequency(int arr[],int size){
    int count;
    int visit[size];

    for (int i = 0; i < size; i++)
        visit[i] = 0;

     for(int i=0;i<size;i++){
        if (visit[i]==1)
            continue;
        count=0;
        for(int j=0;j<size;j++){
            if (arr[i]==arr[j]){
            count++;
            visit[j]=1;
            }
        }
        printf("%d repeats %d times\n",arr[i],count);
    }
}

int main(){
    int n;
    printf("Enter length of random array.");
    scanf("%d",&n);
    int array1[n];

    for(int i=0;i<n;i++){
        array1[i]=rand()%11;
    }

for(int i=0;i<n;i++)
    printf("%d ",array1[i]);
    printf("\n");

CountFrequency(array1, n);
}
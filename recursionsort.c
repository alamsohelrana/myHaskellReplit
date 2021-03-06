#include<stdio.h>

int arr[] = {78,67,56,45,34,23};
int n = sizeof(arr) / sizeof(arr[0]);
int *recursionsort();
int getMin();

int main(){
	
	printf("Array Length calculated %d \n",n);
	printf("smallest element is %d \n",getMin(arr,n));
		
	printf("unsorted array is  : ");
	int q;
	for(q=0;q<n;q++){
		printf(" %d",arr[q]);
	}
	printf("\n");
		
	int *mysortedarr;
	mysortedarr = recursionsort(arr,n);
	printf("sorted array is    : ");
	int m;
	for(m=0;m<n;m++){
		printf(" %d",mysortedarr[m]);
	}
	printf(" ");
	return 0;
}

int getMin(int arr[],int length){
	
	if(length == 1){
		return arr[0];
	}
	else{
		int newarr[length - 1] ;
		int i;
		for(i=1;i<length;i++){
			newarr[i-1] = arr[i];
		}
		
		int newmin = getMin(newarr,(length - 1));
		if(newmin > arr[0]){
			return arr[0];
		}
		else{
			return newmin;
		}
	}
}

int *recursionsort(int arr[],int length){
	if(length==1){
		return arr;
	}
	else{
		int minimum = getMin(arr,length);
		int newarr[length - 1] ; 
		int i,j=0;
		for(i=0;i<length;i++){
			if(arr[i]==minimum){
				int temp = arr[0];
				arr[0] = minimum;
				arr[i]= temp ;
			}
			else{
				newarr[j]=arr[i];
				j++;
			}
		}
		
		int *reducedsortedarr;
		reducedsortedarr = recursionsort(newarr,(length - 1));

		int k;
		for(k=1;k<length;k++){
			arr[k]=reducedsortedarr[k-1];
		}
		
		return arr;
	}
}


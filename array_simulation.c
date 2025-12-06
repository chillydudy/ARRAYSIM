#include <stdio.h>
#include <stdlib.h>

int *arr;
int current_size=0;
int max_size;

void display_array(){
	int i;
	printf("\nCurrent Array Status:\n");
	printf("Index: ");
	for(i=0;i<current_size;i++){
		printf("[%d]\t",i);
	}
	printf("\nValue: ");
	for(i=0;i<current_size;i++){
		printf(" %d \t",arr[i]);
	}
	printf("\n---------------------------------------------\n");
}

void insert_element(){
	int val,pos,i;
	
	if(current_size>=max_size){
		printf("Error: Array is full! Cannot insert.\n");
		return;
	}
	
	printf("Enter value to insert: ");
	scanf("%d",&val);
	printf("Enter index (0 to %d): ",current_size);
	scanf("%d",&pos);

	if(pos<0 || pos>current_size){
		printf("Error: Invalid index.\n");
		return;
	}

	for(i=current_size;i>pos;i--){
		arr[i]=arr[i-1];
	}

	arr[pos]=val;
	current_size++;
	
	printf("Success! Inserted %d at index %d.\n",val,pos);
	display_array();
}

void delete_element(){
	int pos,i;
	
	if(current_size==0){
		printf("Error: Array is empty! Nothing to delete.\n");
		return;
	}
	
	printf("Enter index to delete (0 to %d): ",current_size-1);
	scanf("%d",&pos);

	if(pos<0 || pos>=current_size){
		printf("Error: Invalid index.\n");
		return;
	}

	for(i=pos;i<current_size-1;i++){
		arr[i]=arr[i+1];
	}

	current_size--;
	
	printf("Success! Deleted element at index %d.\n",pos);
	display_array();
}

void search_element(){
	int target,i;
	
	printf("Enter value to search for: ");
	scanf("%d",&target);

	for(i=0;i<current_size;i++){
		if(arr[i]==target){
			printf("Found %d at Index %d!\n",target,i);
			return;
		}
	}
	printf("Value %d not found in the array.\n",target);
}

void sort_array(){
	int i,j,temp;
	
	for(i=0;i<current_size-1;i++){
		for(j=0;j<current_size-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("Array sorted successfully!\n");
	display_array();
}

void reverse_array(){
	int start=0;
	int end=current_size-1;
	int temp;

	if(current_size<2){
		printf("Not enough elements to reverse.\n");
		return;
	}
	
	while(start<end){
		temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
	}
	printf("Array reversed successfully!\n");
	display_array();
}

void swap_elements(){
	int i1,i2,temp;
	
	if(current_size<2){
		printf("Not enough elements to swap.\n");
		return;
	}
	
	printf("Enter first index (0 to %d): ",current_size-1);
	scanf("%d",&i1);
	printf("Enter second index (0 to %d): ",current_size-1);
	scanf("%d",&i2);

	if(i1<0 || i1>=current_size || i2<0 || i2>=current_size){
		printf("Error: Invalid index(es).\n");
		return;
	}

	temp=arr[i1];
	arr[i1]=arr[i2];
	arr[i2]=temp;

	printf("Success! Swapped values at index %d and %d.\n",i1,i2);
	display_array();
}

int main(){
	int choice;
	
	printf("Enter total array capacity: ");
	scanf("%d",&max_size);
	arr=(int*)malloc(max_size*sizeof(int));
	
	if(arr==NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}

	while(1){
		printf("\n=== ARRAY MENU ===\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sort\n");
		printf("5. Reverse\n");
		printf("6. Swap Two Elements\n");
		printf("7. Exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);

		switch(choice){
			case 1: insert_element(); break;
			case 2: delete_element(); break;
			case 3: search_element(); break;
			case 4: sort_array(); break;
			case 5: reverse_array(); break;
			case 6: swap_elements(); break;
			case 7: return 0;
			default: printf("Invalid choice.\n");
		}
	}
	return 0;
}

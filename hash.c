#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int hash(char *key){
	int h=0;
	int i=0;
	int length=strlen(key);
	while(*key!='\0'){
		hash_value += (int)(*(key+i));
	} 
	index = hash_value % HASH_TABLE_SIZE;
	return index;
}
void print_hash_table(char *table[]){
	int count_link = 0;
	if(table != NULL && key != NULL)
	{	
		int index = hash(key);
		struct hash_element *temp;
		struct hash_element *hold;
		temp = table[index];
		hold = temp;
		if(temp == NULL)
		{
			table[index] = (struct hash_element*)(malloc(sizeof(struct hash_element)));
			if(table[index] == NULL)
			{
				printf("malloc() failed\n");
				return -1;
			}
			table[index]->str = key;			
		}
		else
		{
			while(temp != NULL)
			{
				hold = temp;
				count_link++;
				temp = temp->next;
			}			
			temp = (struct hash_element*)(malloc(sizeof(struct hash_element)));
			if(temp == NULL)
			{
				printf("malloc() failed\n");
				return -1;
			}
			temp->str = key;
			hold->next  = temp;

		}


	}
	return count_link;
}

void print_hash_table(struct hash_element *table[])
{
	int count_link = 0;
	printf("\n# Print all the elements in the hash table # \n");
	for(int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		if(table[i] != NULL)
		{
			struct hash_element *temp = table[i];
			while(temp != NULL)
			{
				
				printf("\nHash element at index = %d\n",  i);
				printf("Pointer: %p, count_link = %d\n", temp, count_link);
				count_link++;
				printf("String: %s\n", temp->str);				
				temp  = temp->next;
			}
			count_link = 0;
		}
	}
}
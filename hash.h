#define HASH_TABLE_SIZE 1087 //take a prime number
struct hash_element{
	char *str;
	struct hash_table *next;
	
};
int hash(char *key);
void print_hash_table(char *table[]);
int add_to_hash_table(char *hash_table[];char *key);
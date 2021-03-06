// 2**16 = 65536
// 2*16 + 32 + 128 = 65696
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REC_LEN (128)
#define MAX_NAME_LEN (32)

struct record{
	char record_name[MAX_NAME_LEN]; // 32
	char record_buf[MAX_REC_LEN];   // 128
	void (*print)(struct record *r);
	unsigned short record_len;
};

void default_print_record(struct record *r)
{
	printf("record: %s\n", r->record_buf);
}

struct record *newRecord(char *name/*32*/, char *str/*128*/)
{
	struct record *rec = 0x0;

	rec = malloc(sizeof(struct record));
	if(!rec) return 0x0;


	if(strlen(name) >= MAX_NAME_LEN){
		free(rec);
		return 0x0;print
	}
	strcpy(rec->record_name, name);

	rec->record_len = strlen(str);
	if(rec->record_len >= MAX_REC_LEN){
		free(rec);
		return 0x0;
	}

	rec->print = default_print_record;
	strncpy(rec->record_buf, str, strlen(str));
	return rec;
}

void printDay()
{
	char *cmd = "/bin/date";
        printf("Program started at:\n");
	system(cmd);
}

int main(int argc, char **argv)
/*
1 - program name
2 - record_name   - 32 
3 - record        - 128
*/
{
	struct record *my_record;

	if(argc < 3)
		return -1;
	
	printDay();
	my_record = newRecord(argv[1], argv[2]);
	if(my_record)
		my_record->print(my_record);
	return 0;
}


// ("x" * 65421
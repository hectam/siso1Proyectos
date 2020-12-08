#define BLOCK_SIZE 512
#define ROWS 80

extern void printString(str);
char *str;

extern void readString(line);
char line[ROWS];

extern void syscall_readSector(buffer,sector);
char buffer[BLOCK_SIZE];
int sector;

extern void finished(void);

void main()
{
	char str[ROWS], buffer[BLOCK_SIZE];
	syscall_printString("Enter a line: ");
	syscall_readString(str);
	syscall_printString("\r\n");
	syscall_printString(str);
	syscall_printString("\r\n");
	syscall_printString("Reading sector 30 from floppy\r\n");
	syscall_readSector(buffer, 30);
	syscall_printString(buffer);
	
	finished();
}

void finished() {
	syscall_printString("\r\nDone!");
	while(1);
}
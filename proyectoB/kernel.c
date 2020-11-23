

#define Back 0x08
#define RT 0x0D
#define Clear 0x20

extern void printChar(ch);
char ch;

extern char readChar(void);

extern void readString(line);
char line[80];

extern int minim( x , y);
int x; int y;

extern int may( x , y);
int x; int y;

extern void printString(chrs);
char *chrs;

extern void readSector(buff,sec);
char *buff;
int sec;

extern void makeInterrupt21(void);

extern void loadProgram(void);

extern void infinite(void);

char *text;
char *space;
char buffer[80];
char buf[512];

void main(){
    /*
    char *text = "Hola Mundo\0";
    char *space = "\r\n\0";
    char buffer[80];
    char buf[512];

    printString(text);
    printString(space);


    readString(buffer);
	printString(space);
	printString(buffer);

    
    readSector(buf, 30);
    printString(buf);
    */

    makeInterrupt21();
	loadProgram();
    infinite();

    
}

void infinite(){
    while(1);
}

void readString(char line[80]) {
	char chr;
	int i;
	char checker = 0;
	for( i = 0; i < 80 - 1 ;)
	{
		chr = readChar();
		switch(chr){
			case Back:
				printChar(Back);
				printChar(Clear);
				i--;
				i = may(0,i);
				break;
			case RT:
				checker = 1;
				break;
			default:
				line[i] = chr;
				i++;
		}
		printChar(chr);
		line[i] = '\0';
		if(checker)
			break;
	}
}

int minim(int x , int y) {
	return x < y ? x : y;
}

int may(int x , int y) {
	return x > y ? x : y;
}

void printString(char *chr) {
	int i = 0;
	while(chr[i] != '\0') {
		printChar(chr[i]);
		i++;
	}
}



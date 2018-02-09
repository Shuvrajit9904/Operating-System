#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/syscall.h> 
#include <unistd.h>
#include <fcntl.h>

/*********************************************************************
 *
 * These C functions use patterns and functionality often found in
 * operating system code. Your job is to implement them. Of course you
 * should write test cases. However, do not hand in your test cases
 * and (especially) do not hand in a main() function since it will
 * interfere with our tester.
 *
 * Additional requirements on all functions you write:
 *
 * - you may not refer to any global variables
 *
 * - you may not call any functions except those specifically
 *   permitted in the specification
 *
 * - your code must compile successfully on CADE lab Linux
 *   machines when using:
 *
 * /usr/bin/gcc -O2 -fmessage-length=0 -pedantic-errors -std=c99 -Werror -Wall -Wextra -Wwrite-strings -Winit-self -Wcast-align -Wcast-qual -Wpointer-arith -Wstrict-aliasing -Wformat=2 -Wmissing-include-dirs -Wno-unused-parameter -Wshadow -Wuninitialized -Wold-style-definition -c assign1.c 
 *
 * NOTE 1: Some of the specifications below are specific to 64-bit
 * machines, such as those found in the CADE lab.  If you choose to
 * develop on 32-bit machines, some quantities (the size of an
 * unsigned long and the size of a pointer) will change. Since we will
 * be grading on 64-bit machines, you must make sure your code works
 * there.
 *
 * NOTE 2: You should not need to include any additional header files,
 * but you may do so if you feel that it helps.
 *
 * HANDIN: submit your finished file, still called assign1.c, in Canvas
 *
 *
 *********************************************************************/

/*********************************************************************
 *
 * byte_sort()
 *
 * specification: byte_sort() treats its argument as a sequence of
 * 8 bytes, and returns a new unsigned long integer containing the
 * same bytes, sorted numerically, with the smaller-valued bytes in
 * the lower-order byte positions of the return value
 * 
 * EXAMPLE: byte_sort (0x0403deadbeef0201) returns 0xefdebead04030201
 *
 *********************************************************************/

unsigned long byte_sort (unsigned long arg)
{
	// long arg=0x0403deadbeef0201;
	unsigned int temp[8] = {0};
	int i=7, j;
	unsigned long res = 0x0000000000000000;		
	// printf("The given unsigned long integer is:");
	// printf("%lx \n", arg );

	//  test = test << 8 ;
	//  printf("Mask: %lu \n", test & arg );

	/* Divides the integer into 8 blocks of 2 digit each */

	while(arg>0)
	{
		temp[i--]=arg%256;
		arg=arg/256;
		
	}

/*	for(i = 0; i < 8; i++)
	{
		printf("\n temp array: %02x",temp[i] );
	}
	printf("\n");
*/
	/* Sorts(inefficiently) the array of 8 integers in ascending order*/

	for(i =0;i<8;i++)
	{
		for(j=0;j<7-i;j++)
		{
			if (temp[j] > temp[j+1])
			{
				int a =temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=a;
			}
		}
	}

/*	for (int i = 0; i < 8; ++i)
	{
		printf("%02x\n", temp[i]);
	} */

	/* Print the sorted array in reverse order */
	for (int i = 7; i >= 0; i--)
	{
		res = res | temp[i];
		//printf("res: %lx \n", res );
		if (i != 0)
		{			
			res = res << 8;
		}
		
		
	}

	
/*	for(i = 0; i < 8; i++)
	{
		printf("\n temp array: %02x",temp[i] );

	}
	printf("\n");
*/  
    return res;
}

/*
int main()
{
	unsigned long p;
	p = byte_sort (0x0403deadbeef0201);
	// p = byte_sort (0x00000000000000ff);
	printf("0x%16lx \n",p );
	return 0;
}
*/

/*********************************************************************
 *
 * nibble_sort()
 *
 * specification: nibble_sort() treats its argument as a sequence of 16 4-bit
 * numbers, and returns a new unsigned long integer containing the same nibbles,
 * sorted numerically, with smaller-valued nibbles towards the "small end" of
 * the unsigned long value that you return
 *
 * the fact that nibbles and hex digits correspond should make it easy to
 * verify that your code is working correctly
 * 
 * EXAMPLE: nibble_sort (0x0403deadbeef0201) returns 0xfeeeddba43210000
 *
 *********************************************************************/

unsigned long nibble_sort (unsigned long arg)
{
  // long arg=0x0403deadbeef0201;
	unsigned int temp[16] = {0};
	int i=15, j;
	unsigned long res = 0x0000000000000000;		
	// printf("The given unsigned long integer is:");
	// printf("%lx \n", arg );

	//  test = test << 8 ;
	//  printf("Mask: %lu \n", test & arg );

	/* Divides the integer into 8 blocks of 2 digit each */

	while(arg>0)
	{
		temp[i--]=arg%16;
		arg=arg/16;
		
	}

/*	for(i = 0; i < 8; i++)
	{
		printf("\n temp array: %02x",temp[i] );
	}
	printf("\n");
*/
	/* Sorts(inefficiently) the array of 8 integers in ascending order*/

	for(i =0;i<16;i++)
	{
		for(j=0;j<15-i;j++)
		{
			if (temp[j] > temp[j+1])
			{
				int a =temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=a;
			}
		}
	}

/*	for (int i = 0; i < 8; ++i)
	{
		printf("%02x\n", temp[i]);
	} */

	/* Print the sorted array in reverse order */
	for (int i = 15; i >= 0; i--)
	{
		res = res | temp[i];
		//printf("res: %lx \n", res );
		if (i != 0)
		{			
			res = res << 4;
		}
		
		
	}

	
/*	for(i = 0; i < 8; i++)
	{
		printf("\n temp array: %02x",temp[i] );

	}
	printf("\n");
*/  
    return res;
  
}

/*
int main()
{
	unsigned long p;
	p = nibble_sort (0x0403deadbeef0201);
//	// p = byte_sort (0x00000000000000ff);
	printf("0x%16lx \n",p );
	return 0;
}
*/


/*********************************************************************
 *
 * name_list()
 *
 * specification: allocate and return a pointer to a linked list of
 * struct elts
 *
 * - the first element in the list should contain in its "val" field the first
 *   letter of your first name; the second element the second letter, etc.;
 *
 * - the last element of the linked list should contain in its "val" field
 *   the last letter of your first name and its "link" field should be a null
 *   pointer
 *
 * - each element must be dynamically allocated using a malloc() call
 *
 * - if any call to malloc() fails, your function must return NULL and must also
 *   free any heap memory that has been allocated so far; that is, it must not
 *   leak memory when allocation fails
 *  
 *********************************************************************/

struct elt {
  char val;
  struct elt *link;
};

static void free_heap(struct elt* head){
	
}

struct elt* create(char name_ch)
{
	struct elt * new_node = (struct elt *)malloc(sizeof(struct elt));
	if (new_node == NULL)
	{
		return NULL;
	}

	new_node -> val = name_ch;
	new_node -> link = NULL;

	return new_node;
}


struct elt *name_list (void)
{
	char my_name[] = "shuvrajit" ;
	struct elt* head = create(my_name[0]);
	struct elt* iter = head;
	if (head == NULL)
	{
		return NULL;
	}
	for(int i = 1; i < sizeof(my_name)/sizeof(char); ++i)
	{
		iter -> link = create(my_name[i]);
				
		if (iter -> link == NULL)
		{
			while (head != NULL){
					struct elt* next = head->link;
					free_heap(head);
					head = next;
				}
				return NULL;
		}
		
		iter = iter -> link;

	}

	return head;

}

/*
int main()
{
	struct elt* call_name = name_list();
	while(call_name != NULL)
	{
		printf("%c\n",call_name ->val );
		call_name = call_name -> link;
	}
	return 0;
}
*/

/*********************************************************************
 *
 * convert()
 *
 * specification: depending on the value of "mode", print "value" as
 * octal, binary, or hexidecimal to stdout, followed by a newline
 * character
 *
 * extra requirement 1: output must be via putc()
 *
 * extra requirement 2: print nothing if "mode" is not one of OCT,
 * BIN, or HEX
 *
 * extra requirement 3: all leading/trailing zeros should be printed
 *
 * EXAMPLE: convert (HEX, 0xdeadbeef) should print
 * "00000000deadbeef\n" (including the newline character but not
 * including the quotes)
 *
 *********************************************************************/

enum format_t {
  OCT = 66, BIN, HEX
};

void convert (enum format_t mode, unsigned long value)
{
	unsigned long mask;
	int i, j = 0, shift;
	unsigned char result[64];
	switch(mode){
		case HEX:
		mask= 0x000000000000000F;
		shift=4;
		break;
		case OCT:
		mask=0x0000000000000007;
		shift=3;
		break;
		case BIN:
		mask=0x0000000000000001;
		shift=1;
		break;
		default:
		return;
	}

	for(i=0;i<64;i+=shift)
	{		
		result[j] = (value >>i ) & mask;		
		
		if((unsigned int)result[j] > 9){
			//printf("%x\t", result[j]);
			result[j]+= 'a' - 10;
			//printf("%x\n", result[j]);
		}
		else
			result[j]+='0';

		j++;
	}

	for(i=j-1;i>=0;i--)
	{
		putc(result[i],stdout);
	}
	putc('\n', stdout);
}

/*
int main()
{	
	convert (OCT, 0xdeadbeef);
	return 0;
}
*/

/*********************************************************************
 *
 * draw_me()
 *
 * this function creates a file called me.txt which contains an ASCII-art
 * picture of you (it does not need to be very big). the file must (pointlessly,
 * since it does not contain executable content) be marked as executable.
 * 
 * extra requirement 1: you may only call the function syscall() (type "man
 * syscall" to see what this does)
 *
 * extra requirement 2: you must ensure that every system call succeeds; if any
 * fails, you must clean up the system state (closing any open files, deleting
 * any files created in the file system, etc.) such that no trash is left
 * sitting around
 *
 * you might be wondering how to learn what system calls to use and what
 * arguments they expect. one way is to look at a web page like this one:
 * http://blog.rchapman.org/post/36801038863/linux-system-call-table-for-x86-64
 * another thing you can do is write some C code that uses standard I/O
 * functions to draw the picture and mark it as executable, compile the program
 * statically (e.g. "gcc foo.c -O -static -o foo"), and then disassemble it
 * ("objdump -d foo") and look at how the system calls are invoked, then do
 * the same thing manually using syscall()
 *
 *********************************************************************/

static void error(int fd)
{ 
  syscall(3, fd);
  syscall(87, "me.txt");
  syscall(60);
}

void draw_me (void)
{ 
	char my_face[] = "O( ͡°ʖ ͡°)O\n" ;  //Create my face
	int fd = syscall(2, "me.txt", O_CREAT | O_RDWR, 0755); //Open
	if(fd < 0)
	{
		return;
	}
	int write_err = syscall(1, fd, my_face, sizeof(my_face)-1);
	if (write_err == -1)
	{
		error(fd);
	}
	if (write_err < sizeof(my_face)-1)
	{
		error(fd);
		draw_me();
		return;
	}
	if (syscall(3, fd) == -1)
	{
		syscall(87, "me.txt");
  		syscall(60);
	}		
}

/*
int main()
{
	draw_me();
	return 0;
}
*/
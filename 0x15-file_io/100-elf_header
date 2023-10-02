#include "main.h"

void print_elf_address(char *e_ptr);
void print_elf_type(char *e_ptr);
void print_elf_osabi(char *e_ptr);
void print_elf_version(char *e_ptr);
void print_elf_data(char *e_ptr);
void print_elf_magic(char *e_ptr);
void print_elf_class(char *e_ptr);
int check_if_elf(char *e_ptr);
int main(int argc, char *argv[]);

/**
 * print_elf_address - prints the entry point address of the ELF file
 * @e_ptr: pointer to the ELF header
 * Return: void
 */
void print_elf_address(char *e_ptr)
{
	int x, str;
	char elf_class;

	printf("  Entry point address:               0x");

	elf_class = e_ptr[4] + '0';
	if (elf_class == '1')
	{
		str = 26;
		printf("80");
		for (x = str ; x >= 22; x--)
		{
			if (e_ptr[x] > 0)
				printf("%x", e_ptr[x]);
			else if (e_ptr[x] < 0)
				printf("%x", 256 + e_ptr[x]);
		}
		if (e_ptr[7] == 6)
			printf("00");
	}
	if (elf_class == '2')
	{
		str = 26;
		for (x = str ; x > 23; x--)
		{
			if (e_ptr[x] >= 0)
				printf("%02x", e_ptr[x]);
			else if (e_ptr[x] < 0)
				printf("%02x", 256 + e_ptr[x]);
		}
	}
	printf("\n");
}

/**
 * print_elf_type - prints the type of ELF file
 * @e_ptr: pointer to the ELF header
 * Return: void
 */
void print_elf_type(char *e_ptr)
{
	char elftype = e_ptr[16];

	if (e_ptr[5] == 1)
		elftype = e_ptr[16];
	else
		elftype = e_ptr[17];

	printf("  Type:                              ");
	if (elftype == 0)
		printf("NONE (No file type)\n");
	else if (elftype == 1)
		printf("REL (Relocatable file)\n");
	else if (elftype == 2)
		printf("EXEC (Executable file)\n");
	else if (elftype == 3)
		printf("DYN (Shared object file)\n");
	else if (elftype == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", elftype);
}

/**
 * print_elf_osabi - prints the operating system and ABI info
 * @e_ptr: pointer to the ELF header
 * Return: void
 */
void print_elf_osabi(char *e_ptr)
{
	char elfosabi = e_ptr[7];

	printf("  OS/ABI:                            ");
	if (elfosabi == 0)
		printf("UNIX - System V\n");
	else if (elfosabi == 2)
		printf("UNIX - NetBSD\n");
	else if (elfosabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", elfosabi);
	printf("  ABI Version:                       %d\n", e_ptr[8]);
}

/**
 * print_elf_version - prints the version info of the ELF file
 * @e_ptr: pointer to the ELF header
 * Return: void
 */
void print_elf_version(char *e_ptr)
{
	int elfversion = e_ptr[6];

	printf("  Version:                           %d", elfversion);
	if (elfversion == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_elf_data - prints the data encoding info of the ELF file
 * @e_ptr: pointer to the ELF header
 * Return: void
 */
void print_elf_data(char *e_ptr)
{
	char elfdata = e_ptr[5];

	printf("  Data:                              2's complement");
	if (elfdata == 1)
		printf(", little endian\n");
	if (elfdata == 2)
		printf(", big endian\n");
}

/**
 * print_elf_magic - prints magic bytes of the ELF file
 * @e_ptr: pointer to the ELF header
 * Return: void
 */
void print_elf_magic(char *e_ptr)
{
	int x = 0;

	printf("  Magic:  ");
	for (x = 0 ; x < 16; x++)
		printf(" %02x", e_ptr[x]);
	printf("\n");
}

/**
 * print_elf_class - prints the class of the ELF file
 * @e_ptr: pointer to the ELF header
 * Return: void
 */
void print_elf_class(char *e_ptr)
{
	char elfclass = e_ptr[4] + '0';

	if (elfclass == '0')
		exit(98);
	printf("ELF Header:\n");
	print_elf_magic(e_ptr);

	if (elfclass == '1')
		printf("  Class:                             ELF32\n");
	if (elfclass == '2')
		printf("  Class:                             ELF64\n");

	print_elf_data(e_ptr);
	print_elf_version(e_ptr);
	print_elf_osabi(e_ptr);
	print_elf_type(e_ptr);
	print_elf_address(e_ptr);
}

/**
 * check_if_elf - checks if it is an elf file
 * @e_ptr: ppinter to the ELF header
 * Return: 1 if it is an ELF file and 0 if not
 */
int check_if_elf(char *e_ptr)
{
	int x = (int)e_ptr[0];
	char E = e_ptr[1];
	char L = e_ptr[2];
	char F = e_ptr[3];

	if (x == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);
	return (0);
}

/**
 * main - main function of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on code success
 */
int main(int argc, char *argv[])
{
	int fd, result;
	char e_ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}
	lseek(fd, 0, SEEK_SET);
	result = read(fd, e_ptr, 27);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}
	if (!check_if_elf(e_ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}
	print_elf_class(e_ptr);
	close(fd);
	return (0);
}

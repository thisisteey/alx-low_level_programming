section .data
	fmt db "Hello, Holberton", 10, 0

section .text
	extern printf
	global main

main:
	mov rdi, fmt
	xor rax, rax
	call printf

	mov rax, 60
	xor rdi, rdi
	syscall

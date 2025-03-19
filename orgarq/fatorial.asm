	.data
	
	.text
	.globl main
	.align 2
main:	
	li a7, 5
	ecall
	add t0, zero, a0
	addi t1, zero, 1
loop:
	ble t0, zero, end_loop
	mul t1, t1, t0
	addi t0, t0, -1
	j loop
end_loop:
	li a7, 1
	add a0, zero, t1
	ecall
	li a7 10
	ecall
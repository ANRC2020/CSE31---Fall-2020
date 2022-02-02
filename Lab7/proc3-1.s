	.data
x:	.word 5
y:	.word 10
p:	.word 0
q:	.word 0
	.text
	
MAIN:	la $t0, x
		lw $s0, 0($t0)		# s0 = x
		la $t0, y
		lw $s1, 0($t0)		# s1 = y
		
		jal SUM
		
		add $a0, $s0, $s1
		add $a0, $a0, $v0
		
		li $v0, 1		#Prints answer
		syscall
		j END
		
		
SUM:	addi $sp, $sp, -16
		sw $s0, 12($sp)
		sw $s1, 8($sp)
		sw $a0, 4($sp)
		sw $ra, 0($sp)

		la $t1, p
		lw $s2, 0($t1)
		
		addi $s0, $s0, 1
		addi $s1, $s1, 1
		
		jal SUB
		
		move $v0, $s7
		
		subi $s0, $s0, 2
		subi $s1, $s1, 2
		
		jal SUB
		
		move $v1, $s7

		lw $ra, 0($sp)
		lw $a0, 4($sp)
		lw $s1, 8($sp)
		lw $s0, 12($sp)
		
		addi $sp, $sp, 16

		add $v0, $v0, $v1	

		jr $ra		


SUB:	sub $s7, $s1, $s0
		jr $ra

END:	li $v0, 10
		syscall

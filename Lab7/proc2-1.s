		.data
x:		.word 5
y:		.word 10
m:		.word 15
b:		.word 2

		.text
MAIN:	la $t0, x
		lw $s0, 0($t0)		# s0 = x
		la $t0, y
		lw $s1, 0($t0)		# s1 = y
		
		# Prepare to call sum(x)
		#add $a0, $zero, $s0	# Set a0 as input argument for SUM
		jal SUM
		
		add $s1, $s1, $s0
		add $s1, $s1, $s2
		move $a0, $s1
		
		li $v0, 1		#Prints answer
		syscall
		j END
		
SUM:     	addi $sp, $sp, -12
		sw $s0, 8($sp)
		sw $a0, 4($sp)
		sw $ra, 0($sp)
		
		la $t1, m
		lw $s2, 0($t1)
		add $s0, $s0, $s2 
		
		add $a0, $s0, $a0
		jal SUB
		lw $a0, 4($sp)
		
		add $v0, $a0, $v0
		
		lw $ra, 0($sp)
		lw $a0, 4($sp)
		lw $s0, 8($sp)
		addi $sp, $sp, 12
		
		add $t7, $v0, $s0
		move $s2, $t7
		
		jr $ra		

SUB:	la $t0, b
		addi $sp, $sp -4
		sw $s0, 0($sp)		# Backup s0 from SUM
		lw $s0, 0($t0)		# s0 = b
		sub $v0, $a0, $s0
		lw $s0, 0($sp)		# Restore s0 from SUM
		addi $sp, $sp 4
		jr $ra

		
END:	li $v0, 10		
		syscall

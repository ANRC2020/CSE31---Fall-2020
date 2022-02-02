	.data
get: 	.asciiz "Please enter an integer: "
	.text
	
main:		li $v0, 4
		la $a0, get
		syscall
		
		subu $a0, $a0, $a0
		
		li $v0, 5 
		syscall
		
		move $s0, $v0
		move $a1, $s0
		
		jal recursion
		
		li $v0, 1
		syscall
		
		li $v0, 10
		syscall
		
		

recursion:	subu $sp, $sp, 8
		sw $ra, ($sp)
		sw $a1, 4($sp)
		
		bne $a1, 10, equal11
		li $v0, 2
		j end_recur
		
equal11:	bne $a1, 11, else
		li $v0, 1
		j end_recur

else:		addi $a1, $a1, 2
		jal recursion
		
		subi $a1, $a1, 1
		jal recursion
		
		lw $t0, 4($sp)
		add $a0, $a0, $t0
		
		lw $ra, 0($sp)
		lw $a1, 4($sp)
		addu $sp, $sp, 8

		jr $ra
		
end_recur:	lw $ra, 0($sp)
		lw $a1, 4($sp)
		addu $sp, $sp, 8
		add $a0, $a0, $v0
		
		jr $ra

.data

n:      .word 25

str1: .asciiz "Less than\n"

str2: .asciiz "Less than or equal to\n"

str3: .asciiz "Greater than\n"

str4: .asciiz "Greater than or equal to\n"

true1: .asciiz "1\n"

false1: .asciiz "0\n"

.text

           

main: 		li $v0, 5
		syscall	
		add $t1, $t1, $v0
		
		#Get user input
		
		la      $t2, n
		lw	$t2, 0($t2)
		
		#Stores values of n from memory into registers
		
		#slt $t3,$t1,$t2
		slt $t3,$t2,$t1
		
		#checks if $t1 > $t2
		#Stores 0 for false and 1 for true at $t3
		
		addi $s0, $s0, 1
		
#		beq $t3, 1, less_than
		
		
#		j greater_than_or_equal
		
		
#less_than: 	la $a0, str1
#		li	$v0, 4	
#		syscall 
#		li $v0, 10
#		syscall 
		
#greater_than_or_equal: 	la $a0, str4
#		li	$v0, 4	
#		syscall
#		li $v0, 10
#		syscall
		
		beq $t3, 0, less_than_or_equal
		
		j greater_than
		
greater_than: 	la $a0, str3 
		li	$v0, 4	
		syscall 
		li $v0, 10
		syscall
		
less_than_or_equal: 	la $a0, str2
			li $v0, 4
			syscall
			li $v0, 10
			syscall
			
true: 	la $a0, true1
	li $v0, 4
	syscall
	li $v0, 10
	syscall
	
false:	la $a0, false1
	li $v0, 4
	syscall
	li $v0, 10
	syscall

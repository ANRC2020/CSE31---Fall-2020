.data 
pos_sum:.word 0
neg_sum:.word 0

pos_mes:.asciiz "Sum of positive numbers is: "
neg_mes:.asciiz "Sum of negative numbers is: "
get_mes:.asciiz "Please enter a number: "
nex_lin:.asciiz "\n"
check: .asciiz "check"

.text
	
main:	la      $s1, pos_sum
	lw	$s1, 0($s1)
	
	la      $s2, neg_sum
	lw	$s2, 0($s2)
	
	j sum
	

sum:	la	$a0, get_mes
	li	$v0, 4
	syscall
	
	li $v0, 5
	syscall
	
	beq $v0, 0, finish
	
	bgt $v0, 0, positive 
	
	blt $v0, 0, negative 
	
positive:	add $s1, $s1, $v0 
		sw  $s1, pos_sum
		j sum

negative:	add $s2, $s2, $v0 
		sw  $s2, neg_sum
		j sum

finish:		li	$v0, 4
		la	$a0, nex_lin	
		syscall
	
		li	$v0, 4
		la	$a0, pos_mes	
		syscall


		li 	$v0, 1
		lw 	$a0, pos_sum
		syscall
		
		
		li	$v0, 4
		la	$a0, nex_lin	
		syscall
		
		
		
		li	$v0, 4
		la	$a0, neg_mes	
		syscall
		
		li 	$v0, 1
		lw 	$a0, neg_sum
		syscall
		
		li	$v0, 10
		syscall 
		
		
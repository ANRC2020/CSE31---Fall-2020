.data 

original_list: .space 100 
sorted_list: .space 100

str0: .asciiz "Enter size of list (between 1 and 25): "
str1: .asciiz "Enter one list element: "
str2: .asciiz "Content of original list: "
str3: .asciiz "Enter a key to search for: "
str4: .asciiz "Content of sorted list: "
strYes: .asciiz "Key found!"
strNo: .asciiz "Key not found!"
space: .asciiz " "

.text 

#This is the main program.
#It first asks user to enter the size of a list.
#It then asks user to input the elements of the list, one at a time.
#It then calls printList to print out content of the list.
#It then calls inSort to perform insertion sort
#It then asks user to enter a search key and calls bSearch on the sorted list.
#It then prints out search result based on return value of bSearch
main:
	addi $sp, $sp -8
	sw $ra, 0($sp)
	li $v0, 4 
	la $a0, str0 
	syscall 
	li $v0, 5	#read size of list from user
	syscall
	move $s0, $v0	#s0 = size of list
	move $t0, $0	#t0 cleared
	la $s1, original_list	#s1 = address of original_list
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 	# "Enter one list element: "
	sll $t1, $t0, 2	#t1 = t0 * 4
	add $t1, $t1, $s1 #t1 = t1 + s1; set t1 = to original_list's address + offset where offset is enough for t0 elements 
	li $v0, 5	
	syscall	#read elements from user
	sw $v0, 0($t1)	#store input in original list -> OL address -> input 1 -> input 2 -> ... -> input n
	addi $t0, $t0, 1 #increment t0 by one
	bne $t0, $s0, loop_in #if t0 < s0 <-> i < n, repeat loop_in
	#/////////////// noting below this is executed until all values are in original_list
	move $a0, $s1	#else a0 = address of original_list
	move $a1, $s0	#a1 = number of inputs
	
	jal inSort	#Call inSort to perform insertion sort in original list
	
	sw $v0, 4($sp)
	li $v0, 4 
	la $a0, str2 
	syscall 
	la $a0, original_list
	move $a1, $s0
	jal printList	#Print original list
	li $v0, 4 
	la $a0, str4 
	syscall 
	lw $a0, 4($sp)
	jal printList	#Print sorted list
	
	li $v0, 4 
	la $a0, str3 
	syscall 
	li $v0, 5	#read search key from user
	syscall
	move $a3, $v0	#a3 = user input
	lw $a0, 4($sp)	#a0 = address of sorted list; a1 = number of inputs in the list
	jal bSearch	#call bSearch to perform binary search
	
	beq $v0, $0, notFound
	li $v0, 4 
	la $a0, strYes 
	syscall 
	j end
	
notFound:
	li $v0, 4 
	la $a0, strNo 
	syscall 
end:
	lw $ra, 0($sp)
	addi $sp, $sp 8
	li $v0, 10 
	syscall
	
	
#printList takes in a list and its size as arguments. 
#It prints all the elements in one line.
printList:
	#Your implementation of printList here
	
	#$a0 = address of original_list
	#$a1 = size of list
	addi $sp, $sp, -8
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	
	move $t0, $a0 #address of list
	move $t1, $a1 #size of list
	move $t2, $zero 
	#addi $t2, $t2, 1 #counter = 1
	move $t3, $zero #offset
	move $t4, $zero #stores current value
	la $t5, original_list
	
	beq $t5, $t0, while
	j while3
	
while:
	beq $t2, $t1, done
	lw $t4, original_list($t3)
	addi $t3, $t3, 4
	addi $t2, $t2, 1
	#prints out number
	li $v0, 1     
	move $a0, $t4
	syscall
	#prints out space
	li $v0, 4
	la $a0, space
	syscall 
	
	j while
	
while3:	beq $t2, $t1, done
	lw $t4, sorted_list($t3)
	addi $t3, $t3, 4
	addi $t2, $t2, 1

	#prints out number
	li $v0, 1     
	move $a0, $t4
	syscall

	#prints out space
	li $v0, 4
	la $a0, space
	syscall 

	j while3

done:	
	#prints "\n"
	li $v0, 11
	la $a0, 10
	syscall

	lw $a0, 4($sp)
	lw $ra, 0($sp)
	addi $sp, $sp, 8
	
	jr $ra
	
#inSort takes in a list and it size as arguments. 
#It performs INSERTION sort in ascending order and returns a new sorted list
#You may use the pre-defined sorted_list to store the result
inSort:
	#Your implementation of inSort here
	#a0 = address of original_list
	#a1 = number of items in the list
	
	move $t0, $a0
	move $t1, $a1
	move $t2, $zero
	move $t3, $a1
	sll $t3, $t3, 2 
	move $t4, $zero
	
copy:
	lw $t4, original_list($t2)
	sw $t4, sorted_list($t2)
	
	beq $t2, $t3, next
	addi $t2, $t2, 4
	j copy

next:
	move $t0, $a0	#address of original_list
	move $t1, $a1	#number of items in the list
	move $t2, $zero
	addi $t2, $t2, -1	#position from 0 to n - 1
while1:
	addi $t2, $t2, 1
	beq $t2, $t1, done1
	move $t3, $t2 #counter variable
	
	while2:
		beq $t3, $zero, while1
		
		sll $s1, $t3, 2
		
		move $t4, $zero
		lw $t7, sorted_list($s1)
		add $t4, $t4, $t7 #t4 = current value
		
		move $t5, $t3
		addi $t5, $t5, -1 #t5 = counter - 1
		
		sll $s2, $t5, 2
		
		move $t6, $zero
		lw $t7, sorted_list($s2)
		add $t6, $t6, $t7 #t6 = value before value stored in t4
		
		bgt $t6, $t4, swap
		j while1
		
	swap:
		sw $t6, sorted_list($s1)
		sw $t4, sorted_list($s2)	#swap values in list
		
		addi $t3, $t3, -1	#decrement counter
		
		j while2

done1:	
	jr $ra

#bSearch takes in a list, its size, and a search key as arguments.
#It performs binary search RECURSIVELY to look for the search key.
#It will return a 1 if the key is found, or a 0 otherwise.
#Note: you MUST NOT use iterative approach in this function.
bSearch:
	#Your implementation of bSearch here
bprep:
	addi $sp, $sp, -20
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	sw $s2, 12($sp)
	sw $s3, 16($sp)
	
	move $s0, $a3	#s0 = number to look for
	move $s1, $zero	#s1 = lower bound
	move $s2, $zero	#s2 = midpoint
	move $s3, $a1	
	addi $s3, $s3, -1	#s3 = upper bound/#number of inputs
	#v0 = found()/not found indicator(0)
	
	jal rec
	
	j recend
rec:
	addi $sp, $sp, -20
	
	sw $ra, 0($sp)	
	sw $s0, 4($sp)	#s0 = number to look for
	sw $s1, 8($sp)	#s1 = lower bound
	sw $s2, 12($sp)	#s2 = midpoint
	sw $s3, 16($sp)	#s3 = upper bound/#number of inputs
	
	#base condition
	move $t3, $s3
	sll $t3, $t3, 2
	lw $t0, sorted_list($t3)
	
	beq $s0, $t0, found
	
	move $t3, $s1
	sll $t3, $t3, 2
	lw $t0, sorted_list($t3)
	
	beq $s0, $t0, found
	
	bne $s1, $s3, cont
	bne $s0, $t0, notfound 
	j found
	
cont:
	move $t4, $zero 
	addi $t4, $s1, 1
	
	bne $t4, $s3, midpoint
	j notfound
	
found:
	move $v0, $zero
	addi $v0, $v0, 1
	
	lw $s3, 16($sp)
	lw $s2, 12($sp)
	lw $s1, 8($sp)
	lw $s0, 4($sp)
	lw $ra, 0($sp)

	addi $sp, $sp, 20

	jr $ra
	
notfound:
	move $v0, $zero
	
	lw $s3, 16($sp)
	lw $s2, 12($sp)
	lw $s1, 8($sp)
	lw $s0, 4($sp)
	lw $ra, 0($sp)

	addi $sp, $sp, 20

	jr $ra
	
midpoint:
	#calculate midpoint
	add $s2, $s1, $s3
	srl $s2, $s2, 1
	sll $t2, $s2, 2
	lw $t1, sorted_list($t2)
	
	ble $s0, $t1, lessthanorequalto	
	
	bgt $s0, $t1  greaterthanorequalto
	
lessthanorequalto:
	move $s3, $s2
	jal rec
	j recend
	
greaterthanorequalto:
	move $s1, $s2
	jal  rec
	j recend

recend:
	lw $s3, 16($sp)
	lw $s2, 12($sp)
	lw $s1, 8($sp)
	lw $s0, 4($sp)
	lw $ra, 0($sp)
	
	addi $sp, $sp, 20
	
	jr $ra

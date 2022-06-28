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
strSpace: .asciiz " "
strnLine: .asciiz "\n"


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
	move $s0, $v0
	move $t0, $0
	la $s1, original_list
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5	#read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	move $a0, $s1
	move $a1, $s0
	
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
	move $a3, $v0
	lw $a0, 4($sp)
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
	addi $sp, $sp -4
	sw $a0, 0($sp)
	move $t0,$0
print:
	sll $t1, $t0, 2
	add $t4, $t1, $a0
	lw $a0, 0($t4)
	li $v0,1
	syscall
	li $v0, 4 
	la $a0, strSpace
	syscall 
	addi $t0,$t0,1
	lw $a0, 0($sp)
	bne $t0,$a1,print
	li $v0, 4
	la $a0, strnLine
	syscall
	sw $a0, 0($sp)
	addi $sp, $sp 4
	jr $ra
	
	
#inSort takes in a list and it size as arguments. 
#It performs INSERTION sort in ascending order and returns a new sorted list
#You may use the pre-defined sorted_list to store the result
inSort:
	#Your implementation of inSort here
	addi $sp, $sp -8
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s1, $0
	la $s1, sorted_list
	move $t0, $0
Copy:	sll $t1, $t0, 2
	add $t4, $t1, $a0
	add $t3, $t1, $s1
	lw $t2, 0($t4)
	sw $t2, 0($t3)
	addi $t0, $t0, 1
	bne $t0, $a1, Copy
	move $s2, $0
	move $t4, $0
	move $t5, $0
Sort:	addi $s2, $s2,1
	add $s3, $s2,$0
	beq $a1,$s2, end2
While:	
	sll $t4, $s3, 2
	add $t4, $t4, $s1
	lw $t7, 0($t4)
	#srl $t5, $s3, 2
	addi $t5, $t4, -4
	lw $t6, 0($t5)
	sgt $t1, $t6, $t7
	sgt $t0, $s3,$zero
	beq $s3, $zero, Sort
	addi $s3,$s3,-1
	bne $t0, $t1, Sort
	sw $t6, 0($t4)
	sw $t7, 0($t5)
	j While
	#addi $s3,$s3,-1
	

end2:	move $v0,$s1
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	addi $sp, $sp 8
	jr $ra
	
	
#bSearch takes in a list, its size, and a search key as arguments.
#It performs binary search RECURSIVELY to look for the search key.
#It will return a 1 if the key is found, or a 0 otherwise.
#Note: you MUST NOT use iterative approach in this function.
bSearch:
	#Your implementation of bSearch here
	move $v0, $zero
	move $t0,$zero
	addi $sp, $sp -12
	sw $ra, 8($sp)
	addi $t0,$zero,2
	add $t3, $a1,$a2
	div $t3,$t0
	mflo $s0
	sll $t4, $s0, 2
	add $t4, $t4, $a0
	lw $t5, 0($t4)
	bne $a3, $t5, key_not_mid
	addi $v0,$zero,1
	j end_recur
key_not_mid:	beq $a1,$a2,end_recur
		sgt $t1, $a3,$t5
		beq $t1,$zero,key_finding_notgreater
		move $a2, $a1
		addi $s0,$s0,1
		move $a1,$s0
		jal bSearch
		j end_recur
key_finding_notgreater:	move $a1, $s0
			move $a2, $zero
			jal bSearch
			j end_recur
						
end_recur:	lw $ra, 8($sp)
		#lw $a1, 4($sp)
		addi $sp, $sp, 12
		jr $ra
		
	

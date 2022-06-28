	.data
#n:      .word 13
#m:		.word 20
#str1: .asciiz "I love CSE31!"
str: .asciiz "Enter an integer to add: "
str1: .asciiz "\n"
str2: .asciiz "Sum of even numbers is: "
str3: .asciiz "Sum of odd numbers is: "
	.text
main:		la $a0,str
		li $v0,4
		syscall
		li $v0,5
		syscall
		move $s0,$v0
		addi $a1, $s0,0
		bne $s0,$zero, decision
		#j decision
		j finish
decision:	slt $t0, $s0, $zero
		beq $t0, $zero, positive
		#bne $t0,$zero, negative
negative:	beq $a1,-1,oddADD
		addi $a1, $a1, 2
		beq $a1,$zero,evenADD
		beq $a1,-1,oddADD
		#slt $t0, $a1, $zero
		#bne $t0,$zero, negative
		j negative
		#j main

positive:	beq $a1,1,oddADD
		addi $a1, $a1, -2
		beq $a1,$zero,evenADD
		beq $a1,1,oddADD
		#slt $t0, $s0, $zero
		#beq $t0, $zero, positive
		j positive
		#j main
	

 	
evenADD:	add $s1,$s0,$s1
		j main
oddADD:		add $s2,$s0,$s2
		j main
finish:		la	$a0,str1
		li 	$v0, 4
		syscall
		la	$a0,str2
		li 	$v0, 4
		syscall
		addi    $a0, $s1, 0
		li      $v0, 1		# you will be asked about the purpose of this line for syscall 
		syscall
		la	$a0,str1
		li 	$v0, 4
		syscall
		la	$a0,str3
		li 	$v0, 4
		syscall
		addi    $a0, $s2, 0
		li      $v0, 1		# you will be asked about the purpose of this line for syscall 
		syscall
		li $v0, 10		
		syscall	

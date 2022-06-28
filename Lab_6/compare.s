        .data
n:      .word 25
str: .asciiz "Enter an integer to compare: "
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"
m:	.word 20
        .text
        
main:		la     	$t3, n
		lw      $t3, 0($t3)
		la	$a0,str
		li 	$v0, 4
		syscall
		li $v0,5
		syscall
		move $s0,$v0
		#j compare
compare:	add $t2,$s0,$zero
		j secondcompare #comment this to make it behave before #7 and #8 implementation
		slt $t1,$t2,$t3
		bne $t1,$zero,lessthan
		#beq $t1,$zero,greaterthanequal
greaterthanequal:	la	$a0,str4
			li 	$v0, 4
			syscall
			j finish
lessthan:	la	$a0,str1
		li 	$v0, 4
		syscall
		j finish

secondcompare: 	slt $t1,$t3,$t2
		bne $t1,$zero,greaterthan
		#beq $t1,$zero,lessthanequal
lessthanequal:	la	$a0,str2
		li 	$v0, 4
		syscall
		j finish
greaterthan:	la	$a0,str3
		li 	$v0, 4
		syscall
		j finish


finish:	li      $v0, 10		
		syscall	
		

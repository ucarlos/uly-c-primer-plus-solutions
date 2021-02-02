	.file	"program4.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"The following message will prompt you to enter in some information."
	.align 8
.LC1:
	.string	"For student %d, please enter their first and last names.\n"
.LC2:
	.string	"%s %s"
	.align 8
.LC3:
	.string	"Now enter their scores for Physics, Math and History."
.LC4:
	.string	"%lf %lf %lf"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	call	puts
	movl	$0, -164(%rbp)
	jmp	.L2
.L3:
	movl	-164(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	-160(%rbp), %rcx
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$16, %rax
	addq	%rcx, %rax
	leaq	4(%rax), %rcx
	leaq	-160(%rbp), %rsi
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rsi, %rax
	movq	%rcx, %rdx
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$.LC3, %edi
	call	puts
	leaq	-160(%rbp), %rcx
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$48, %rax
	addq	%rcx, %rax
	leaq	8(%rax), %rcx
	leaq	-160(%rbp), %rsi
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$40, %rax
	addq	%rsi, %rax
	leaq	8(%rax), %rsi
	leaq	-160(%rbp), %rdi
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$32, %rax
	addq	%rdi, %rax
	addq	$8, %rax
	movq	%rsi, %rdx
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$120, %rax
	movsd	(%rax), %xmm1
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$112, %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$104, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	.LC5(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	-164(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$96, %rax
	movsd	%xmm0, (%rax)
	addl	$1, -164(%rbp)
.L2:
	cmpl	$1, -164(%rbp)
	jle	.L3
	leaq	-160(%rbp), %rax
	leaq	72(%rax), %rcx
	leaq	-160(%rbp), %rax
	movl	$72, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	print_structure
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
.LC7:
	.string	"clear"
	.align 8
.LC8:
	.string	"Name: %s %s\nGrade Average: %.2f\n\n"
.LC10:
	.string	"The class average is %.2f"
	.text
	.globl	print_structure
	.type	print_structure, @function
print_structure:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$.LC7, %edi
	call	system
	jmp	.L7
.L8:
	movq	-16(%rbp), %rax
	movq	64(%rax), %rdx
	movq	-16(%rbp), %rax
	leaq	20(%rax), %rcx
	movq	-16(%rbp), %rax
	movq	%rdx, -48(%rbp)
	movsd	-48(%rbp), %xmm0
	movq	%rcx, %rdx
	movq	%rax, %rsi
	movl	$.LC8, %edi
	movl	$1, %eax
	call	printf
	movq	-16(%rbp), %rax
	movsd	64(%rax), %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addq	$72, -16(%rbp)
.L7:
	movq	-16(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jbe	.L8
	movsd	-8(%rbp), %xmm0
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	$.LC10, %edi
	movl	$1, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	print_structure, .-print_structure
	.section	.rodata
	.align 8
.LC5:
	.long	0
	.long	1074266112
	.align 8
.LC9:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

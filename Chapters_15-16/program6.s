	.file	"program6.c"
	.globl	menu_options
	.section	.rodata
	.align 8
.LC0:
	.string	"f)Change Font\ts)Change Size\ta) Change Alignment\nb)Toggle Bold\ti)Toggle Italics\tu)Toggle Underline\nq)Quit\n"
	.data
	.align 8
	.type	menu_options, @object
	.size	menu_options, 8
menu_options:
	.quad	.LC0
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
	subq	$16, %rsp
	movb	$1, -16(%rbp)
	movzbl	-15(%rbp), %eax
	andl	$-16, %eax
	orl	$12, %eax
	movb	%al, -15(%rbp)
	movzbl	-15(%rbp), %eax
	andl	$-49, %eax
	movb	%al, -15(%rbp)
	movzbl	-15(%rbp), %eax
	andl	$-65, %eax
	movb	%al, -15(%rbp)
	movzbl	-15(%rbp), %eax
	andl	$127, %eax
	movb	%al, -15(%rbp)
	movzbl	-14(%rbp), %eax
	andl	$-2, %eax
	movb	%al, -14(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %edi
	call	main_menu
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.string	"Id\tSize\tAlignment\tBold\tItalic\tUnderline"
.LC2:
	.string	"%u\t%u\t"
.LC3:
	.string	"Center\t\t"
.LC4:
	.string	"Left\t\t"
.LC5:
	.string	"Right\t\t"
.LC6:
	.string	"On\t\t"
.LC7:
	.string	"Off\t\t"
.LC8:
	.string	"On\n\n"
.LC9:
	.string	"Off\n\n"
	.text
	.globl	display_font_attributes
	.type	display_font_attributes, @function
display_font_attributes:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -16(%rbp)
	movl	$.LC1, %edi
	call	puts
	movzbl	-15(%rbp), %eax
	andl	$15, %eax
	movzbl	%al, %edx
	movzbl	-16(%rbp), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movzbl	-15(%rbp), %eax
	andl	$48, %eax
	cmpb	$32, %al
	je	.L4
	movzbl	-15(%rbp), %eax
	andl	$48, %eax
	cmpb	$16, %al
	jne	.L5
	movl	$.LC3, %eax
	jmp	.L7
.L5:
	movl	$.LC4, %eax
	jmp	.L7
.L4:
	movl	$.LC5, %eax
.L7:
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movzbl	-15(%rbp), %eax
	andl	$64, %eax
	testb	%al, %al
	je	.L8
	movl	$.LC6, %eax
	jmp	.L9
.L8:
	movl	$.LC7, %eax
.L9:
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movzbl	-15(%rbp), %eax
	andl	$-128, %eax
	testb	%al, %al
	je	.L10
	movl	$.LC6, %eax
	jmp	.L11
.L10:
	movl	$.LC7, %eax
.L11:
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movzbl	-14(%rbp), %eax
	andl	$1, %eax
	testb	%al, %al
	je	.L12
	movl	$.LC8, %eax
	jmp	.L13
.L12:
	movl	$.LC9, %eax
.L13:
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	display_font_attributes, .-display_font_attributes
	.section	.rodata
.LC10:
	.string	"clear"
	.align 8
.LC11:
	.string	"Press the appropriate key to select an option."
.LC12:
	.string	"%c"
	.text
	.globl	main_menu
	.type	main_menu, @function
main_menu:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC10, %edi
	call	system
	movl	-48(%rbp), %eax
	movl	%eax, %edi
	call	display_font_attributes
	movl	$.LC11, %edi
	call	puts
	movq	menu_options(%rip), %rax
	movq	%rax, %rdi
	call	puts
	leaq	-17(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC12, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movzbl	-17(%rbp), %eax
	movsbl	%al, %eax
	subl	$97, %eax
	cmpl	$20, %eax
	ja	.L15
	movl	%eax, %eax
	movq	.L17(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L17:
	.quad	.L16
	.quad	.L18
	.quad	.L15
	.quad	.L15
	.quad	.L15
	.quad	.L19
	.quad	.L15
	.quad	.L15
	.quad	.L20
	.quad	.L15
	.quad	.L15
	.quad	.L15
	.quad	.L15
	.quad	.L15
	.quad	.L15
	.quad	.L15
	.quad	.L21
	.quad	.L15
	.quad	.L22
	.quad	.L15
	.quad	.L23
	.text
.L19:
	movq	$change_font, -16(%rbp)
	jmp	.L24
.L22:
	movq	$change_size, -16(%rbp)
	jmp	.L24
.L16:
	movq	$change_alignment, -16(%rbp)
	jmp	.L24
.L18:
	movq	$change_bold, -16(%rbp)
	jmp	.L24
.L20:
	movq	$change_italic, -16(%rbp)
	jmp	.L24
.L23:
	movq	$change_underline, -16(%rbp)
	jmp	.L24
.L21:
	movl	$0, %edi
	call	exit
.L15:
	movq	$main_menu, -16(%rbp)
	nop
.L24:
	movl	-48(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %edi
	call	*%rax
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L25
	call	__stack_chk_fail
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main_menu, .-main_menu
	.section	.rodata
	.align 8
.LC13:
	.string	"Enter the new font id. The number must be in between 0 and 255."
.LC14:
	.string	"%u"
.LC15:
	.string	"Returning to main menu."
	.text
	.globl	change_font
	.type	change_font, @function
change_font:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC10, %edi
	call	system
	call	clear_buffer
	movq	$main_menu, -16(%rbp)
	movl	$.LC13, %edi
	movl	$0, %eax
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %eax
	cmpl	$255, %eax
	jbe	.L27
	movl	-20(%rbp), %eax
	movzbl	%al, %eax
	movl	%eax, -20(%rbp)
.L27:
	movl	-20(%rbp), %eax
	movb	%al, -48(%rbp)
	movl	$.LC15, %edi
	call	puts
	movl	$1, %edi
	call	sleep
	movl	-48(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %edi
	call	*%rax
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L28
	call	__stack_chk_fail
.L28:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	change_font, .-change_font
	.section	.rodata
	.align 8
.LC16:
	.string	"Enter the new font size. The number must in between 0 and 128."
	.text
	.globl	change_size
	.type	change_size, @function
change_size:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC10, %edi
	call	system
	call	clear_buffer
	movq	$main_menu, -16(%rbp)
	movl	$.LC16, %edi
	movl	$0, %eax
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %eax
	cmpl	$127, %eax
	jbe	.L30
	movl	-20(%rbp), %eax
	andl	$127, %eax
	movl	%eax, -20(%rbp)
.L30:
	movl	-20(%rbp), %eax
	andl	$15, %eax
	andl	$15, %eax
	movl	%eax, %edx
	movzbl	-47(%rbp), %eax
	andl	$-16, %eax
	orl	%edx, %eax
	movb	%al, -47(%rbp)
	movl	$.LC15, %edi
	call	puts
	movl	$1, %edi
	call	sleep
	movl	-48(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %edi
	call	*%rax
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L31
	call	__stack_chk_fail
.L31:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	change_size, .-change_size
	.section	.rodata
	.align 8
.LC17:
	.string	"Choose Alignment: Left(0)\tCenter(1)\tRight(2)"
	.align 8
.LC18:
	.string	"Invalid Alignment number. Try again."
	.text
	.globl	change_alignment
	.type	change_alignment, @function
change_alignment:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC10, %edi
	call	system
	call	clear_buffer
	movq	$main_menu, -16(%rbp)
	movl	$.LC17, %edi
	call	puts
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	jmp	.L33
.L34:
	movl	$.LC18, %edi
	movl	$0, %eax
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
.L33:
	movl	-20(%rbp), %eax
	cmpl	$2, %eax
	ja	.L34
	movl	-20(%rbp), %eax
	andl	$3, %eax
	andl	$3, %eax
	sall	$4, %eax
	movl	%eax, %edx
	movzbl	-47(%rbp), %eax
	andl	$-49, %eax
	orl	%edx, %eax
	movb	%al, -47(%rbp)
	movl	$.LC15, %edi
	call	puts
	movl	$1, %edi
	call	sleep
	movl	-48(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %edi
	call	*%rax
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L35
	call	__stack_chk_fail
.L35:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	change_alignment, .-change_alignment
	.section	.rodata
.LC19:
	.string	"Bold Options:\tOn(1)\tOff(0)"
	.align 8
.LC20:
	.string	"Invalid Number. Defaulting to Off."
	.text
	.globl	change_bold
	.type	change_bold, @function
change_bold:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC10, %edi
	call	system
	call	clear_buffer
	movq	$main_menu, -16(%rbp)
	movl	$.LC19, %edi
	movl	$0, %eax
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %eax
	testl	%eax, %eax
	jne	.L37
	movl	-20(%rbp), %eax
	cmpl	$1, %eax
	je	.L38
.L37:
	movl	$.LC20, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -20(%rbp)
.L38:
	movl	-20(%rbp), %eax
	andl	$1, %eax
	andl	$1, %eax
	sall	$6, %eax
	movl	%eax, %edx
	movzbl	-47(%rbp), %eax
	andl	$-65, %eax
	orl	%edx, %eax
	movb	%al, -47(%rbp)
	movl	$.LC15, %edi
	call	puts
	movl	$1, %edi
	call	sleep
	movl	-48(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %edi
	call	*%rax
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L39
	call	__stack_chk_fail
.L39:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	change_bold, .-change_bold
	.section	.rodata
.LC21:
	.string	"Italics Options:\tOn(1)\tOff(0)"
	.align 8
.LC22:
	.string	"Invalid number. Defaulting to Off."
	.text
	.globl	change_italic
	.type	change_italic, @function
change_italic:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC10, %edi
	call	system
	call	clear_buffer
	movq	$main_menu, -16(%rbp)
	movl	$.LC21, %edi
	movl	$0, %eax
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %eax
	testl	%eax, %eax
	jne	.L41
	movl	-20(%rbp), %eax
	cmpl	$1, %eax
	je	.L42
.L41:
	movl	$.LC22, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -20(%rbp)
.L42:
	movl	-20(%rbp), %eax
	andl	$1, %eax
	sall	$7, %eax
	movl	%eax, %edx
	movzbl	-47(%rbp), %eax
	andl	$127, %eax
	orl	%edx, %eax
	movb	%al, -47(%rbp)
	movl	$.LC15, %edi
	call	puts
	movl	$1, %edi
	call	sleep
	movl	-48(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %edi
	call	*%rax
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L43
	call	__stack_chk_fail
.L43:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	change_italic, .-change_italic
	.section	.rodata
	.align 8
.LC23:
	.string	"Underline options:\tOn(1)\tOff(0)"
	.align 8
.LC24:
	.string	"Invalid number. Defaulting on Off."
	.text
	.globl	change_underline
	.type	change_underline, @function
change_underline:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC10, %edi
	call	system
	call	clear_buffer
	movq	$main_menu, -16(%rbp)
	movl	$.LC23, %edi
	movl	$0, %eax
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-20(%rbp), %eax
	testl	%eax, %eax
	jne	.L45
	movl	-20(%rbp), %eax
	cmpl	$1, %eax
	je	.L46
.L45:
	movl	$.LC24, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -20(%rbp)
.L46:
	movl	-20(%rbp), %eax
	andl	$1, %eax
	andl	$1, %eax
	movl	%eax, %edx
	movzbl	-46(%rbp), %eax
	andl	$-2, %eax
	orl	%edx, %eax
	movb	%al, -46(%rbp)
	movl	$.LC15, %edi
	call	puts
	movl	$1, %edi
	call	sleep
	movl	-48(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %edi
	call	*%rax
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L47
	call	__stack_chk_fail
.L47:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	change_underline, .-change_underline
	.globl	clear_buffer
	.type	clear_buffer, @function
clear_buffer:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	nop
.L50:
	call	getchar
	movb	%al, -1(%rbp)
	cmpb	$10, -1(%rbp)
	je	.L51
	cmpb	$-1, -1(%rbp)
	jne	.L50
.L51:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	clear_buffer, .-clear_buffer
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

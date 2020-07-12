	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"%d%f%c"
.LC1:
	.string	"%d %d %d\n"
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	-13(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movzbl	-13(%rbp), %eax
	movsbl	%al, %edx
	movss	-12(%rbp), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L2:
	cmpl	$9, -4(%rbp)
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits

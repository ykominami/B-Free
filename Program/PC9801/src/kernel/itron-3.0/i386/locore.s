/* locore.s --- ������֥�ǽ񤫤ʤ���Фʤ�ʤ��ؿ������
 *              �ѿ��������.
 *
 *
 */


.text

.globl		_get_cr0, _get_cr2, _get_cr3, _load_task_register
.globl		_flush_tlb
.globl		_resume, _resume0
.globl		_set_task_registers

/*************************************************************************
 * get_cr0 --- ����ȥ�����쥸���� 0 �����Ƥ��֤���
 *
 * ������	�ʤ�
 *
 * ���͡�	����ȥ�����쥸���� 0 �����Ƥ��֤���
 *
 * ������	����ȥ�����쥸���� 0 �����Ƥ��֤���
 *
 */
_get_cr0:
		mov	%cr0, %eax
		ret

/*************************************************************************
 * get_cr2 --- ����ȥ�����쥸���� 2 �����Ƥ��֤���
 *
 * ������	�ʤ�
 *
 * ���͡�	����ȥ�����쥸���� 2 �����ơ�
 *
 * ������	����ȥ�����쥸���� 2 �����Ƥ��֤���
 *
 */
_get_cr2:
		mov	%cr2, %eax
		ret

/*************************************************************************
 * get_cr3 --- ����ȥ�����쥸���� 3 �����Ƥ��֤���
 *
 * ������	�ʤ�
 *
 * ���͡�	����ȥ�����쥸���� 3 �����ơ�
 *
 * ������	����ȥ�����쥸���� 3 �����Ƥ��֤���
 *
 */
_get_cr3:
		mov	%cr3, %eax
		ret


/*************************************************************************
 * set_cr3 --- ����ȥ�����쥸���� 3 �����Ƥ����ꤹ�롣
 *
 * ������	����ȥ�����쥸���� 3 �����ơ�
 *
 * ���͡�	�ʤ�
 *
 * ������	����ȥ�����쥸���� 3 �����Ƥ����ꤹ�롣
 *
 */
_set_cr3:
		movl	4(%esp),%eax		/* ������ CR3 �����Ƥ򥹥��å� */
						/* ������Ф� */
		movl	%eax,%cr3		/* ���ꤹ�롣*/
		ret


/*************************************************************************
 * load_task_register --- �������������ȥ쥸�����Υ�����
 *
 * ������	�����ǥ��󥰤��륿�����������ȥ쥸�����ؤΥ��쥯��
 *
 * ���͡�	�ʤ�
 *
 * ������	ltr ��¹Ԥ��롣
 *
 */
string1:
		.ascii "load_task_register: arg = 0x%x\n"
		.align 2
_load_task_register:
		pushl	%ebp
		movl	%esp,%ebp
/*
		pushl	8(%ebp)
		pushl	$string1
		call	_printf
*/
		movl	8(%ebp),%eax
		ltr	%eax
		leave
		ret


/*************************************************************************
 * resume --- �����ǻ��ꤷ���ץ��������ڤ괹���롣
 *
 * ������	�ڤ괹����ץ������� TSS �򤵤����쥯��
 *
 * ���͡�	�ʤ�
 *
 * ������	�������Ϥ��줿���쥯���� TSS jump ���롣
 *		���η�̥ץ��������ڤ괹���롣
 *
 */
LC0:
		.ascii "resume: arg = 0x%x\n"
		.align 2
offset:		.long	0x0000
selector:	.word	0x0000

_resume:
#if 0
		pushl	%ebp
		movl	%esp, %ebp
		movl	8(%ebp), %edx
		pushl	%edx
		pushl	$LC0
		call	_printf
		leave
		ret
#endif
		cli
		pushl	%ebp
		movl	%esp, %ebp
		movl	8(%ebp), %edx
		movw	%dx, (selector)
		lea	offset, %eax		/* */
		movl	%cr3, %ebx		/* TLB ����å����ե�å��夹�� */
		movl	%ebx, %cr3
/*
 *		�ץ������ڤ괹��
 *		ljmp	far (%ax)
 */
_resume0:
		.byte	0xff
		.byte	0x28
		leave
		sti
		ret

/*************************************************************************
 * flush_tlb	--- �ڡ����Ѵ�����å����ե�å��夹�롣
 *
 * ������	�ʤ�
 *
 * ���͡�	�ʤ�
 *
 * ������	cr3 �����Ƥ� get ����Ʊ���� put ���롣
 *
 */
_flush_tlb:
		pushl	%eax
		movl	%cr3, %eax
		movl	%eax, %cr3
		popl	%eax
		ret


_set_task_registers:
		ret
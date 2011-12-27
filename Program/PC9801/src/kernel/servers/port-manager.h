/*

B-Free Project ������ʪ�� GNU Generic PUBLIC LICENSE �˽����ޤ���

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* @(#) $Header: /cvsroot/bfree-info/B-Free/Program/PC9801/src/kernel/servers/port-manager.h,v 1.1 2011/12/27 17:13:36 liu1 Exp $ */

/*
 * $Log: port-manager.h,v $
 * Revision 1.1  2011/12/27 17:13:36  liu1
 * Initial Version.
 *
 * Revision 1.2  1995-09-21 15:51:49  night
 * �������ե��������Ƭ�� Copyright notice ������ɲá�
 *
 * Revision 1.1  1995/03/18  14:12:46  night
 * �ǽ����Ͽ
 *
 *
 */

/* 
 *  �ݡ��ȥޥ͡�����˴ؤ��빽¤�Τ�����������
 *
 *  �ݡ��ȥޥ͡�������Ф����׵�����륿�����ϡ����Υإå��ե������
 *  �󥯥롼�ɤ��٤��Ǥ��롣
 *  ����������å������˴ؤ���饤�֥�� libport.a ��Ȥ����ˤϡ���
 *  �ˤ��Υإå��ե�����򻲾Ȥ��ʤ��Ƥ�褤��
 *  libport.a �饤�֥�꤬��Ŭ���ʽ�����ԤäƤ���롣
 *
 */

#ifndef __PORT_MANAGER_H__
#define __PORT_MANAGER_H__


/*
 * ��å����������פ����
 * �ݡ��ȥޥ͡�������Ф��ƥ�å������Хåե�����Ͽ/����/���Ȥ���Ȥ�
 * �ˤϡ����Υ�å����������פ�Ȥä�ư��μ������ꤹ�롣
 */
#define NULL_PORT	0	/* ���⤷�ʤ� */
#define REGIST_PORT	1	/* ��å������Хåե�����Ͽ */
#define UNREGIST_PORT	2	/* ��å������Хåե������� */
#define FIND_PORT	3	/* ��å������Хåե��λ��� */



/*
 * ��Ͽ����Ȥ��˻��Ѥ���̾���κ���Ĺ
 */
#define PORT_NAME_LEN	40


/*
 * ��Ͽ���륨��ȥ�κ����
 */
#define MAX_PORT_ENTRY	100


/*
 * ITRON (�濴��) ��ˡ����餫������ݤ��Ƥ�����å�������������뤿��
 * �˻��Ѥ����å������Хåե��Ѥ��ΰ衣
 * �׵�����Ĥ��ѤΥ�å������Хåե��� cre_mbf �����ƥॳ�����Ȥä�
 * ��������Ȥ��ˤ����ͤ���Ѥ��롣
 */
#define MAX_MSG_ENTRY	1


/*
 * ��å������Υإå���ʬ�����
 * �ݡ��ȥޥ͡�������Ф������������å������ϡ����ι�¤�Τǵ��ꤷ��
 * ����ǡ�����ǽ�ˤĤ��롣
 */
struct port_message_header_t
{
  W	type;	/* REGIST_PORT/UNREGIST_PORT/FIND_PORT �Τ����줫���� */
		/* ������(�⤷���ϡ�NULL_PORT �����뤳�Ȥ⤢�뤬���ݡ� */
		/* �ȥޥ͡�����ϡ�NULL_PORT �Υ�å������Ͻ��������� */
		/* ñ��̵�뤹�롣                                     */

  W	size;	/* ��å������Υ����������롣�������ˤϤ��Υإå���ʬ */
		/* �����롣					      */

  ID	rport;	/* �������뤿��Υ�å������Хåե����ݡ��ȥޥ͡�����  */
		/* ���Ф��ƥ�å����������ä��Ȥ��˻Ȥä���å������Х�*/
		/* �ե��������ˤϻ��Ѥ��ʤ� (¾�Υ�������Ʊ����å���  */
		/* ���Хåե�����Ѥ��뤿��)���������ꡢrport �ǻ��� */
		/* ������å������Хåե�����Ѥ��롣                  */
};


/*
 * ��å������Хåե����̤��뤿��ˤĤ���̾���η�
 */
typedef B	PORT_NAME[PORT_NAME_LEN + 1];


/*
 * ��å�������Ͽ������Ԥ��Ȥ��˻��Ѥ��빽¤��
 */
struct regist_port_t
{
  PORT_NAME	name;	/* �ݡ��Ȥ�̾���� ����̾���ϥ����ƥ॰�����Х� */
			/* �Ǥʤ���Ф����ʤ����⤷�����Ǥ�Ʊ��̾����  */
			/* ��Ͽ����Ƥ����Ȥ��ˤϥ��顼�Ȥʤ롣        */

  ID		port;	/* ��Ͽ�����å������Хåե��� ID �����롣��� */
			/* �������Хåե��� ID �ϡ����Ǥ���Ͽ����Ƥ�   */
			/* �Ƥ⹽��ʤ����ݡ��ȥޥ͡�������ä˥�å��� */
			/* ���Хåե�����ʣ������Ͽ����Ƥ��뤫�Υ����� */
			/* ���ϹԤ�ʤ���                               */
  			/* ��ǰ�ʤ��顢�ݡ��ȥޥ͡�����ϡ���å�����   */
			/* �ݡ��Ȥ�Ŭ���˳�����Ƥ뤳�ȤϤ��ʤ���       */

  ID		task;	/* �ݡ��ȥޥ͡�������Ф��ƥꥯ�����Ȥ����ä� */
			/* �������� ID �������ͤϡ��������Ȥ��˼��� */
			/* ���뤿��˻��Ѥ��롣����ϡ���Ͽ���������� */
			/* �Ȥ��̤Υ������������˥�å������Хåե��� */
			/* ��������뤳�Ȥ��ɤ�����˻��Ѥ��뤿��� */
			/* �ͤǤ��롣                                 */
};


/*
 * ��å������Хåե������ý�����Ԥ��Ȥ��˻��Ѥ��빽¤��
 */
struct unregist_port_t
{
  PORT_NAME name;	/* ��Ͽ�ơ��֥뤫�����ä����å������Хåե� */
			/* ��̾������Ͽ����Ȥ��˻��Ѥ���̾������ꤹ */
			/* �롣*/

  ID task;		/* ���ý������׵ᤷ���������� ID �������ͤϡ� */
			/* ��å������Хåե�����Ͽ������������Ʊ���� */
			/* �������ɤ�����Ƚ�̤��뤿��˻��Ѥ��롣     */
};


/*
 * ��å������Хåե��� ID �򸡺�����Ȥ��˻��Ѥ��빽¤��
 */
struct find_port_t
{
  PORT_NAME	name;	/* ��������ݡ��Ȥ�̾��; ��å������Хåե��� */
			/* ��Ͽ����Ȥ��˻��Ѥ���̾������ꤹ�롣     */
};



/*
 * ��å�����������ʬ�����
 */
union port_message_body_t
{
  struct regist_port_t		regist;		/* ��Ͽ����Ȥ��˻��� */
  				                /* �������         */

  struct unregist_port_t	unregist;	/* ��Ͽ�����ä���Ȥ� */
						/* �˻��Ѥ������   */

  struct find_port_t		find;		/* ��Ͽ������å����� */
						/* �Хåե��򸡺����� */
						/* �Ȥ��˻��Ѥ������*/
};


/*
 * �ݡ��ȥޥ͡�����������å�����
 */
struct port_manager_msg_t
{
  struct port_message_header_t	hdr;	/* ��å������Υإå���ʬ���� */
					/* ����ʬ�ˤ�äƥ�å������� */
					/* ����ξ��󤬷�ޤäƤ��롣 */

  union port_message_body_t	body;	/* ��å��������Ρ�union ���� */
					/* ������Ƥ��뤳�Ȥ���ʬ���� */
					/* �褦�ˡ���å��������Τϡ� */
					/* ��å������μ��ऴ�Ȥ˰ۤʤ� */
					/* �������ȤʤäƤ��롣*/
};


/*
 * �ݡ��ȥޥ͡����㤫������������顼�ֹ�
 * �ݡ��ȥޥ͡�������׵�����ä��Ȥ��ˤϡ�������˻��ꤷ���ͤΤɤ줫
 * ��ɬ���֤롣
 */
typedef enum port_manager_error_t
{
  E_PORT_OK,			/* ���� */

  E_PORT_DUPLICATION,		/* ��Ͽ���褦�Ȥ�����å������Хåե� */
				/* ��̾���Ϥ��Ǥ���Ͽ����Ƥ��롣     */

  E_PORT_NOTFOUND,		/* ��Ͽ�ơ��֥뤫�鸡�����褦�Ȥ������ */
				/* �������Хåե���¸�ߤ��ʤ��ä���     */

  E_PORT_FULL,			/* ��Ͽ���뤿��ζ�������ȥ꤬�ʤ��� */
				/* ����                               */

  E_PORT_INVALID,		/* ��Ͽ�����������������׵��Ф����� */
				/* �������ۤʤäƤ��� (���¤Υ����å�) */

  E_PORT_SYSTEM			/* �����ƥॳ����ǥ��顼��ȯ�������� */
} PORT_MANAGER_ERROR;


/*
 * �ݡ��ȥޥ͡����㤫���������å�����
 * �ݡ��ȥޥ͡�������Ф��Ƥϡ������Ĥ���å������μ��ब���ä���
 * �����ϡ������ι�¤�ΤǤ��ޤ���
 *
 */
struct recv_port_message_t
{
  PORT_MANAGER_ERROR   	error;	/* �ݡ��ȥޥ͡�����ν���������˽��� */
				/* �����򼨤������顼�ֹ椬���롣�⤷�� */
				/* ���顼�Ȥʤä��Ȥ��ˤϡ���������  */
				/* port �ϡ���̣���ʤ��ʤ롣         */

  ID	port;			/* ��å������Хåե��� ID ��         */
                                /* ��Ͽ�����ǤϤ����ͤ��ä�ɬ�פȤ��� */
				/* ����������������Ͽ�����Ȥ��Υ�å��� */
				/* ���Хåե��� ID �����롣           */
				/* �ݡ��ȥޥ͡����㤫����Ͽ�����ä��� */
				/* �Ȥ��ˤ⡢Ʊ�ͤ���Ͽ�����Ȥ��Υ�� */
				/* �������Хåե��� ID �����롣 ���ä� */
				/* ����Ǥϥ�å������Хåե��ϻȤ��� */
				/* ���ʤ뤳�Ȥ��ͤ�����Τǡ���Ͽ�� */
				/* �������̣���ʤ��ͤǤ��롣       */
  			        /* ���֤����ͤ���Ѥ���Τϡ���å��� */
				/* ���Хåե� ID �򸡺���������ΤȤ� */
				/* ��������                           */
};


/*
 * �ǡ����١������ؿ���
 * <��Ͽ> <���> <���� (����)> �ν�����Ԥ���
 */
extern PORT_MANAGER_ERROR regist_database (PORT_NAME name, ID port, ID task);
extern PORT_MANAGER_ERROR unregist_database (PORT_NAME name, ID *port, ID task);
extern PORT_MANAGER_ERROR find_database (PORT_NAME name, ID *port);


#endif /* __PORT_MANAGER_H__ */
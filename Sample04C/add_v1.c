// �s�X�^�b�N�t���[���t
// alignment �ɒ���
// prologue code ���Ђƒi��������Ԃ� RSP�̖����� 0 �ƂȂ��Ă��邱��
// 
// FF08  ��P�����p�̗̈�i��������X�Ɋ֐����Ăяo���Ƃ��Ɏg�p�j <--- sub rsp, 0E8h ���s����� RSP
// FF10	 ��Q�����p�̗̈�i��������X�Ɋ֐����Ăяo���Ƃ��Ɏg�p�j
// FF18	 ��R�����p�̗̈�i��������X�Ɋ֐����Ăяo���Ƃ��Ɏg�p�j
// FF20	 ��S�����p�̗̈�i��������X�Ɋ֐����Ăяo���Ƃ��Ɏg�p�j
// FF28  �����ϐ��̈�                                             <--- lea rbp,[rsp+20h] ���s����� RBP
// ...
// FFF0  �ޔ�����RDI�̒l
// FFF8  �ޔ�����RBP�̒l
// 0000  �߂��A�h���X
// 0008  ��P�����p�̗̈�i�󂯎�����f�[�^���R�s�[�j
// 0010  ��Q�����p�̗̈�i�󂯎�����f�[�^���R�s�[�j
// 0018  ��R�����p�̗̈�i�󂯎�����f�[�^���R�s�[�j
// 0020  ��S�����p�̗̈�i�󂯎�����f�[�^���R�s�[�j

int add_v1(int a, int b, int c, int d, int e, int f)
{
	//�v�����[�O �R�[�h
	//44 89 4C 24 20       mov         dword ptr [rsp+20h],r9d  ; ��S����������̈ʒu�iRSP+20h�j�ɃR�s�[
	//44 89 44 24 18       mov         dword ptr [rsp+18h],r8d  ; ��R����������̈ʒu�iRSP+18h�j�ɃR�s�[
	//89 54 24 10          mov         dword ptr [rsp+10h],edx  ; ��Q����������̈ʒu�iRSP+10h�j�ɃR�s�[
	//89 4C 24 08          mov         dword ptr [rsp+08h],ecx  ; ��P����������̈ʒu�iRSP+08h�j�ɃR�s�[
	//55                   push        rbp                      ; ���W�X�^�ޔ� RBP
	//57                   push        rdi                      ; ���W�X�^�ޔ� RDI
	//48 81 EC E8 00 00 00 sub         rsp,0E8h                 ; �X�^�b�N�t���[�����`��
	//48 8D 6C 24 20       lea         rbp,[rsp+20h]            ; �Ăяo���̍ۂɎg�p����X�^�b�N�̈��
	return a + b + c + d + e + f;
	//8B 85 E8 00 00 00    mov         eax,dword ptr [rbp+E8h]  ; ����b �� EAX ���W�X�^�ɐݒ�
	//8B 8D E0 00 00 00    mov         ecx,dword ptr [rbp+E0h]  ; ����a �� ECX ���W�X�^�ɐݒ�
	//03 C8                add         ecx,eax                  ; ECX��ECX+EAX
	//8B C1                mov         eax,ecx                  ; EAX��ECX
	//03 85 F0 00 00 00    add         eax,dword ptr [rbp+F0h]  ; EAX��EAX+����c
	//03 85 F8 00 00 00    add         eax,dword ptr [rbp+F8h]  ; EAX��EAX+����d
	//03 85 00 01 00 00    add         eax,dword ptr [rbp+00h]  ; EAX��EAX+����e
	//03 85 08 01 00 00    add         eax,dword ptr [rbp+08h]  ; EAX��EAX+����f
	//�G�s���[�O �R�[�h
	//48 8D A5 C8 00 00 00 lea         rsp,[rbp+0C8h]           ; RSP�����̈ʒu�ɖ߂�
	//5F                   pop         rdi                      ; RDI �𕜋�
	//5D                   pop         rbp                      ; RBP �𕜋�
	//C3                   ret                                  ; �Ăяo�����ɖ߂�
}

; x64 �p�A�Z���u������T���v���v���O����
; �Z�~�R�����ȍ~�͍s���܂ŃR�����g�ƂȂ�
; namespace B {
; 	int div(int a, int b)
; 	{
; 		return a / b;
; 	}
; }
_TEXT           SEGMENT             ; �v���O�����R�[�h�p�Z�O�����g�J�n(TEXT�Z�O�����g)
PUBLIC          ?div@B@@YAHHH@Z     ; ?div@B@@YAHHH@Z �� public �ɂ���
?div@B@@YAHHH@Z PROC              ; ?div@B@@YAHHH@Z �葱���̋L�q�J�n
	            MOV  EAX, ECX       ; �]�� EAX             ����1����(ECX)
	            MOV  ECX, EDX       ; �]�� ECX             ����2����(EDX)
	            CDQ                 ; �ϊ� EDX:EAX         ��EAX(�����g���t��)
	            IDIV ECX            ; ���Z EAX(��), EDX(�])��EDX:EAX��ECX
	            RET                 ; �Ăяo�����ɖ߂�
?div@B@@YAHHH@Z ENDP              ; ?div@B@@YAHHH@Z �葱���̋L�q�I��
_TEXT           ENDS                ; �v���O�����R�[�h�p�Z�O�����g�I��
	            END                 ; �v���O�����L�q�I��

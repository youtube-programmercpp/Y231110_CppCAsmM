; x64 �p�A�Z���u������T���v���v���O����
; int add_v2(int a, int b, int c, int d, int e, int f);
;
; �s�X�^�b�N�t���[���t
; 0000  �߂��A�h���X <--- RSP
; 0008  ��P���� a �p�̗̈�
; 0010  ��Q���� b �p�̗̈�
; 0018  ��R���� c �p�̗̈�
; 0020  ��S���� d �p�̗̈�
; 0028  ��T���� e
; 0030  ��U���� f

PUBLIC add_v2
_TEXT  SEGMENT
add_v2 PROC
	   mov eax, ecx                  ; EAX��    ��P���� a
	   add eax, edx                  ; ECX��ECX+��Q���� b
	   add eax, r8d                  ; ECX��ECX+��R���� c
	   add eax, r9d                  ; ECX��ECX+��S���� d
	   add eax, dword ptr [rsp+28h]  ; EAX��EAX+��T���� e
	   add eax, dword ptr [rsp+30h]  ; EAX��EAX+��U���� f
	   ret                           ; �Ăяo�����ɖ߂�
add_v2 ENDP
_TEXT  ENDS
       END

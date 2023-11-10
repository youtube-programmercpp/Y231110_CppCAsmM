// 《スタックフレーム》
// alignment に注意
// prologue code がひと段落した状態で RSPの末尾が 0 となっていること
// 
// FF08  第１引数用の領域（ここから更に関数を呼び出すときに使用） <--- sub rsp, 0E8h 実行直後の RSP
// FF10	 第２引数用の領域（ここから更に関数を呼び出すときに使用）
// FF18	 第３引数用の領域（ここから更に関数を呼び出すときに使用）
// FF20	 第４引数用の領域（ここから更に関数を呼び出すときに使用）
// FF28  自動変数領域                                             <--- lea rbp,[rsp+20h] 実行直後の RBP
// ...
// FFF0  退避したRDIの値
// FFF8  退避したRBPの値
// 0000  戻り先アドレス
// 0008  第１引数用の領域（受け取ったデータをコピー）
// 0010  第２引数用の領域（受け取ったデータをコピー）
// 0018  第３引数用の領域（受け取ったデータをコピー）
// 0020  第４引数用の領域（受け取ったデータをコピー）

int add_v1(int a, int b, int c, int d, int e, int f)
{
	//プロローグ コード
	//44 89 4C 24 20       mov         dword ptr [rsp+20h],r9d  ; 第４引数を所定の位置（RSP+20h）にコピー
	//44 89 44 24 18       mov         dword ptr [rsp+18h],r8d  ; 第３引数を所定の位置（RSP+18h）にコピー
	//89 54 24 10          mov         dword ptr [rsp+10h],edx  ; 第２引数を所定の位置（RSP+10h）にコピー
	//89 4C 24 08          mov         dword ptr [rsp+08h],ecx  ; 第１引数を所定の位置（RSP+08h）にコピー
	//55                   push        rbp                      ; レジスタ退避 RBP
	//57                   push        rdi                      ; レジスタ退避 RDI
	//48 81 EC E8 00 00 00 sub         rsp,0E8h                 ; スタックフレームを形成
	//48 8D 6C 24 20       lea         rbp,[rsp+20h]            ; 呼び出しの際に使用するスタック領域と
	return a + b + c + d + e + f;
	//8B 85 E8 00 00 00    mov         eax,dword ptr [rbp+E8h]  ; 引数b を EAX レジスタに設定
	//8B 8D E0 00 00 00    mov         ecx,dword ptr [rbp+E0h]  ; 引数a を ECX レジスタに設定
	//03 C8                add         ecx,eax                  ; ECX←ECX+EAX
	//8B C1                mov         eax,ecx                  ; EAX←ECX
	//03 85 F0 00 00 00    add         eax,dword ptr [rbp+F0h]  ; EAX←EAX+引数c
	//03 85 F8 00 00 00    add         eax,dword ptr [rbp+F8h]  ; EAX←EAX+引数d
	//03 85 00 01 00 00    add         eax,dword ptr [rbp+00h]  ; EAX←EAX+引数e
	//03 85 08 01 00 00    add         eax,dword ptr [rbp+08h]  ; EAX←EAX+引数f
	//エピローグ コード
	//48 8D A5 C8 00 00 00 lea         rsp,[rbp+0C8h]           ; RSPを元の位置に戻す
	//5F                   pop         rdi                      ; RDI を復旧
	//5D                   pop         rbp                      ; RBP を復旧
	//C3                   ret                                  ; 呼び出し元に戻る
}

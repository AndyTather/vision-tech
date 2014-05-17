
PDXTransps.dll: dlldata.obj PDXTrans_p.obj PDXTrans_i.obj
	link /dll /out:PDXTransps.dll /def:PDXTransps.def /entry:DllMain dlldata.obj PDXTrans_p.obj PDXTrans_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del PDXTransps.dll
	@del PDXTransps.lib
	@del PDXTransps.exp
	@del dlldata.obj
	@del PDXTrans_p.obj
	@del PDXTrans_i.obj

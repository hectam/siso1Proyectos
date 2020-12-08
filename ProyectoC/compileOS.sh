bcc -ansi -c -o kernel.o kernel.c
as86 kernel.asm -o kernel_asm.o
ld86 -o kernel -d kernel.o kernel_asm.o
dd if=kernel of=floppya.img bs=512 conv=notrunc seek=3
dd if=message.txt of=floppya.img bs=512 count=1 seek=30 conv=notrunc

bcc -ansi -c -o test.o test.c
as86 os-api.asm -o os_api_asm.o
ld86 -o tstprg -d test.o os_api_asm.o
dd if=tstprg of=floppya.img bs=512 count=1 seek=11 conv=notrunc

bcc -ansi -c -o testB.o testB.c
as86 os-api.asm -o os_api_asm.o
ld86 -o tsttwo -d testB.o os_api_asm.o
dd if=tsttwo of=floppya.img bs=512 count=1 seek=29 conv=notrunc


bcc -ansi -c -o shell.o shell.c
as86 os-api.asm -o os-api.o
ld86 -o shell -d shell.o os-api.o

sudo bochs -f opsys.bxrc

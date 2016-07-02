#smartos

esp and ebp

gcc 分配栈帧的时候 默认大小是16字节的整数倍

eax ecx edx 调用者保护寄存器
ebx esi edi 被调用者保护寄存器

通过缓冲区溢出覆盖函数返回的地址  执行攻击代码

为了执行攻击代码，必须知道攻击代码在栈中的地址

安全措施：
    1.栈随机化，使程序启动后栈的位置不一样，在栈的开头分配一个随机空间。（linux中，更大类的技术，地址空间布局随机化）
    2.栈破坏检测，在程序状态和缓冲区之间加入一个特殊值，每次返回检测值是否被更改
    3.限制可执行区域代码

32位汇编器和64位不同
	as 通过--32 指定32位汇编
	gcc 通过-m32 制定32位编译
	ld  通过-m elf_i386 指定32位链接

设置ss的时候，所指定的segment discripter 必须为数据段，否则会出现错误

qemu 启动参数-s -S 进入调试模式
用gdb 打开kernel文件，运行target remote localhost：1234
gdb> file kernel
gdb> target remote localhost
gdb> b main
gdb> c

gdb 中 n 表示运行下一条指令，s 表示单步运行，finish/return 从单步中返回

为了实现键盘中断，除了正确设置pic和idt，还需要通过sti指令是可屏蔽中断有效，处理完中断之后也应该调用sti再次使能\

清屏的时候用的color 如果是0x00 则光标显示的时候是不会闪烁的







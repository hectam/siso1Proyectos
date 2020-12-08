int main()
{

    char buffer[13312];
    syscall_readFile("messag", buffer);
    syscall_printString(buffer);
    syscall_printString("Funciono!!");
    syscall_terminate();
}

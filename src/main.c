#include "vm.h"

int main()
{
    int program[] = {
        SET, 200, 20,
        SET, 30, 11,
        SET, 123234564, 61
    };
    int program_size = sizeof(program)/sizeof(program[0]);

    int status;

    vm_ *vm = init_vm();

    status = load_program(vm, program, program_size);
    if (status != 0) {
        printf("could not load program\n");
        return 1;
    }

    ram_dump(vm, 0);

    status = execute(vm);
    if (status != 0) {
        printf("error executing program\n");
        return 1;
    }
    ram_dump(vm, 0);

    printf("program executed\n");

    delete_vm(vm);

    return 0;
}

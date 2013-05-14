#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define SHOWHOST

int main(){
	struct utmp current_record;
	int utmpfd;
	int reclen = sizeof(current_record);

	if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1){
		perror(UTMP_FILE);
		exit(0)
	}
	while((utmpfd, &current_record, reclen) == reclen){
		show_info(&current_record);
	}
	close(utmpfd);
	return 0;
}
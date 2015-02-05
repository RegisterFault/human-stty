#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>

int main(int argc,char *argv[]){

	struct termios info;
	int fd;

	if(argc != 2
	   || (fd = open(argv[1],O_RDONLY)) <0
	   || tcgetattr(fd,&info) != 0){
		perror(NULL);
		exit(1);
	}
	char * IGNBRK_str = (info.c_iflag & IGNBRK) ? 
		"IGNBRK\t-- Ignore Break Condition" : 
		"-IGNBRK\t-- Don't Ignore Break Contition" ;
	char * BRKINT_str = (info.c_iflag & BRKINT) ? 
		"BRKINT\t-- Send Sigint on break and flush buffers" : 
		"-BRKINT\t-- Recieve Break as null byte unless PARMRK set, then 0x377 0x0 0x0" ;
	char * IGNPAR_str = (info.c_iflag & IGNPAR) ? 
		"IGNPAR\t-- Ignore parity and framing errors" : 
		"-IGNPAR\t-- Don't Ignore parity and framing errors" ;
	char * PARMRK_str = (info.c_iflag & PARMRK) ? 
		"PARMRK\t-- Prefix any character with a framing or parity error with 0x377 0x0" : 
		"-PARMRK\t-- Do not prefix framing or parity errors" ;
	char * INPCK_str = (info.c_iflag & INPCK) ? 
		"INPCK\t-- Enable Input parity checking" : 
		"-INPCK\t-- No input parity" ;
	char * ISTRIP_str = (info.c_iflag & ISTRIP) ? 
		"ISTRIP\t-- Strip the 8th bit of bytes" : 
		"-ISTRIP\t-- Dont strip 8th bit" ;
	char * INLCR_str = (info.c_iflag & INLCR) ? 
		"INLCR\t-- Translate NL to CR" : 
		"-INLCR\t-- No NL to CR translation" ;
	char * IGNCR_str = (info.c_iflag & IGNCR) ? 
		"IGNCR\t-- Ignore Carriage Return" : 
		"-IGNCR\t-- Don't ignore Carriage Return" ;
	char * ICRNL_str = (info.c_iflag & ICRNL) ? 
		"ICRNL\t-- Translate CR to NL" : 
		"-ICRNL\t-- No CR to NL translation" ;
	char * IUCLC_str = (info.c_iflag & IUCLC) ? 
		"IUCLC\t-- Map uppercase to lowercase" : 
		"-IUCLC\t-- No mapping ppercase to lowercase" ;
	char * IXON_str = (info.c_iflag & IXON) ? 
		"IXON\t-- XON/XOFF output flow control enabled" : 
		"-IXON\t-- XON/XOFF output flow control disabled" ;
	char * IXANY_str = (info.c_iflag & IXANY) ? 
		"IXANY\t-- Typing any character will restart stopped output" : 
		"-IXANY\t-- Stopped output not restarted by typing" ;
	char * IXOFF_str = (info.c_iflag & IXOFF) ? 
		"IXOFF\t-- XON/XOFF input flow control enabled" : 
		"-IXOFF\t-- XON/XOFF input flow control disabled" ;
	char * IMAXBEL_str = (info.c_iflag & IMAXBEL) ? 
		"IMAXBEL\t-- Ring bell when input is full" : 
		"-IMAXBEL\t-- Dont ring bell when input is full" ;
	char * IUTF8_str = (info.c_iflag & IUTF8) ? 
		"IUTF8\t-- Allow character erase when in cooked mode" : 
		"-IUTF8\t-- Dont allow character erase in cooked mode" ;
	char * baud_string;
	switch(info.c_cflag & B4000000){
	case B0:
		baud_string = "0";
		break;
	case B50:
		baud_string = "50";
		break;
	case B75:
		baud_string = "75";
		break;
	case B110:
		baud_string = "110";
		break;
	case B134:
		baud_string = "134";
		break;
	case B150:
		baud_string = "150";
		break;
	case B200:
		baud_string = "200";
		break;
	case B300:
		baud_string = "300";
		break;
	case B600:
		baud_string = "600";
		break;
	case B1200:
		baud_string = "1200";
		break;
	case B1800:
		baud_string = "1800";
		break;
	case B2400:
		baud_string = "2400";
		break;
	case B4800:
		baud_string = "4800";
		break;
	case B9600:
		baud_string = "9600";
		break;
	case B19200:
		baud_string = "19200";
		break;
	case B38400:
		baud_string = "38400";
		break;
	case B57600:
		baud_string = "57600";
		break;
	case B115200:
		baud_string = "115200";
		break;
	case B230400:
		baud_string = "230400";
		break;
	case B460800:
		baud_string = "460800";
		break;
	case B500000:
		baud_string = "500000";
		break;
	case B576000:
		baud_string = "576000";
		break;
	case B921600:
		baud_string = "921600";
		break;
	case B1000000:
		baud_string = "1000000";
		break;
	case B1152000:
		baud_string = "1152000";
		break;
	case B1500000:
		baud_string = "1500000";
		break;
	case B2000000:
		baud_string = "2000000";
		break;
	case B2500000:
		baud_string = "2500000";
		break;
	case B3000000:
		baud_string = "3000000";
		break;
	case B3500000:
		baud_string = "3500000";
		break;
	case B4000000:
		baud_string = "4000000";
		break;
	}
	char *char_size;
	switch(info.c_cflag & CSIZE){
	case CS5:
		char_size = "5";
		break;
	case CS6:
		char_size = "6";
		break;
	case CS7:
		char_size = "7";
		break;
	case CS8:
		char_size = "8";
		break;
	}
	char *ISIG_str = (info.c_lflag & ISIG) ?
		"ISIG\t-- Generate proper signal on recieving INTR,QUIT,SUSP,or DSUSP characters" :
		"-ISIG\t-- Do not generate signal upon recieving characters" ;
	char *ICANON_str = (info.c_lflag & ICANON) ?
		"ICANON\t-- Canonical mode enabled" :
		"-ICANON\t-- Canonical mode disabled" ;
	char *ECHO_str = (info.c_lflag & ECHO) ?
		"ECHO\t-- Echo input characters" :
		"-ECHO\t-- Dont echo input characters" ;
	char *ECHOE_str = (info.c_lflag & ECHOE) ?
		"ECHOE\t-- ERASE character erases previous character if in canonical mode. WERASE erases words" :
		"-ECHOE\t-- ignore [W]ERASE characters" ;
	char *ECHOK_str = (info.c_lflag & ECHOK) ?
		"ECHOK\t-- KILL character erases current line in canonical mode" :
		"-ECHOK\t-- ignore KILL character" ;
	char *ECHONL_str = (info.c_lflag & ECHONL) ?
		"ECHONL\t-- in canonical mode, echo NL character even if ECHO disabled" :
		"-ECHONL\t-- dont echo NL" ;
	char *NOFLSH_str = (info.c_lflag & NOFLSH) ?
		"NOFLSH\t-- Dont flush buffers when generating signals on INTR,QUIT,SUSP,or DSUSP" :
		"-NOFLSH\t-- Flush on generated signals" ;
	char *TOSTOP_str = (info.c_lflag & TOSTOP) ?
		"TOSTOP\t-- Send SIGTTOU to background processes writing to terminal" :
		"-TOSTOP\t-- Dont send SIGTTOU to background processes" ;
	char *IEXTEN_str = (info.c_lflag & IEXTEN) ?
		"IEXTEN\t-- Implementation defined input processing enabled" :
		"-IEXTEN\t-- Implementation defined input processing disabled" ;


	char *CSTOPB_str = (info.c_cflag & CSTOPB) ?
		"CSTOPB\t-- Use 2 stop bits" :
		"-CSTOPB\t-- Use 1 stop bit";
	char *CREAD_str = (info.c_cflag & CREAD) ?
		"CREAD\t-- Reciever enabled" :
		"-CREAD\t-- Reciever disabled";
	char *PARENB_str = (info.c_cflag & PARENB) ?
		"PARENB\t-- input/output parity enabled" :
		"-PARENB\t-- input/output parity disabled";
	char *PARODD_str = (info.c_cflag & PARODD) ?
		"PARODD\t-- Odd parity selected" :
		"-PARODD\t-- Even parity selected";
	char *HUPCL_str = (info.c_cflag & HUPCL) ?
		"HUPCL\t-- Modem control lines Hang up upon last process closed" :
		"-HUPCL\t-- No hangup generated upon process closure";
	char *CLOCAL_str = (info.c_cflag & CLOCAL) ?
		"CLOCAL\t-- Ignore modem control lines" :
		"-CLOCAL\t-- Use modem control lines";
	char *OPOST_str = (info.c_oflag & OPOST) ?
		"OPOST\t-- Implementation defined post-processing enabled" :
		"-OPOST\t-- Implemenation defined post-processing disabled";
	char *OLCUC_str = (info.c_oflag & OLCUC) ?
		"OLCUC\t-- map lowercase to uppercase on output" :
		"-OLCUC\t-- no lowercase to uppercase conversion";
	char *ONLCR_str = (info.c_oflag & ONLCR) ?
		"ONLCR\t-- map NL to CR-LF on output" :
		"-ONLCR\t-- no NL to CR-LF mapping ";
	char *OCRNL_str = (info.c_oflag & OCRNL) ?
		"OCRNL\t-- map CR to NL on output" :
		"-OCRNL\t-- no CR to NL mapping";
	char *ONOCR_str = (info.c_oflag & ONOCR) ?
		"ONOCR\t-- Don't output CR on column 0" :
		"-ONOCR\t-- map CR on column 0";
	char *ONLRET_str = (info.c_oflag & ONLRET) ?
		"ONLRET\t-- Don't output CR" :
		"-ONLRET\t-- Output CR";
	char *OFILL_str = (info.c_oflag & OFILL) ?
		"OFILL\t-- send fill characters for delay, instead of timed delay" :
		"-OFILL\t-- use timed delay instead of sending fill characters";
	char *OFDEL_str = (info.c_oflag & OFDEL) ?
		"OFDEL\t-- Fill character is DEL" :
		"-OFDEL\t-- Fill character is NUL";
	char *vtdly_str;
	switch(info.c_oflag & VTDLY){
	case VT0:
		vtdly_str = "Vertical Tab Delay: VT0";
		break;
	case VT1:
		vtdly_str = "Vertical Tab Delay: VT1";
	}
	char *VINTR_str = "VINTR";
	char VINTR_char = info.c_cc[VINTR];
	char *VQUIT_str = "VQUIT";
	char VQUIT_char = info.c_cc[VQUIT];
	char *VERASE_str = "VERASE";
	char VERASE_char = info.c_cc[VERASE];
	char *VKILL_str = "VKILL";
	char VKILL_char = info.c_cc[VKILL];
	char *VEOF_str = "VEOF";
	char VEOF_char = info.c_cc[VEOF];
	char *VTIME_str = "VTIME";
	char VTIME_char = info.c_cc[VTIME];
	char *VMIN_str = "VMIN";
	char VMIN_char = info.c_cc[VMIN];
	char *VSWTC_str = "VSWTC";
	char VSWTC_char = info.c_cc[VSWTC];
	char *VSTART_str = "VSTART";
	char VSTART_char = info.c_cc[VSTART];
	char *VSTOP_str = "VSTOP";
	char VSTOP_char = info.c_cc[VSTOP];
	char *VSUSP_str = "VSUSP";
	char VSUSP_char = info.c_cc[VSUSP];
	char *VEOL_str = "VEOL";
	char VEOL_char = info.c_cc[VEOL];
	char *VREPRINT_str = "VREPRINT";
	char VREPRINT_char = info.c_cc[VREPRINT];
	char *VDISCARD_str = "VDISCARD";
	char VDISCARD_char = info.c_cc[VDISCARD];
	char *VWERASE_str = "VWERASE";
	char VWERASE_char = info.c_cc[VWERASE];
	char *VLNEXT_str = "VLNEXT";
	char VLNEXT_char = info.c_cc[VLNEXT];
	char *VEOL2_str = "VEOL2";
	char VEOL2_char = info.c_cc[VEOL2];



	printf("Input Settings:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
		IGNBRK_str, BRKINT_str, IGNPAR_str, PARMRK_str,
		INPCK_str, ISTRIP_str, INLCR_str, IGNCR_str,
		ICRNL_str, IUCLC_str, IXON_str, IXANY_str,
		IXOFF_str, IMAXBEL_str, IUTF8_str);
	printf("Baud Rate: %s\n",baud_string);
	printf("Char Size: %s\n",char_size);
	printf("Mode bits:\n%s\n%s\n%s\n%s\n%s\n%s\n", 
	       CSTOPB_str, CREAD_str, PARENB_str, PARODD_str,
	       HUPCL_str, CLOCAL_str);
	printf("local mode flags:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
		ISIG_str, ICANON_str, ECHO_str, ECHOE_str,
		ECHOK_str, ECHONL_str, NOFLSH_str, TOSTOP_str, 
		IEXTEN_str);
	printf("output mode flags:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
	       OPOST_str, OLCUC_str, ONLCR_str, OCRNL_str,
	       ONOCR_str, ONLRET_str, OFILL_str, OFDEL_str, vtdly_str);
	printf("control characters:\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n%s\t= %x\n",
	       VINTR_str, VINTR_char, VQUIT_str, VQUIT_char, VERASE_str,
	       VERASE_char, VKILL_str, VKILL_char, VEOF_str, VEOF_char,
	       VTIME_str, VTIME_char, VMIN_str, VMIN_char, VSWTC_str,
	       VSWTC_char, VSTART_str, VSTART_char, VSTOP_str, VSTOP_char,
	       VSUSP_str, VSUSP_char, VEOL_str, VEOL_char, VREPRINT_str,
	       VREPRINT_char, VDISCARD_str, VDISCARD_char, VWERASE_str,
	       VWERASE_char, VLNEXT_str, VLNEXT_char, VEOL2_str, VEOL2_char);


return 0;
}

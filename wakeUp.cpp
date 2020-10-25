/********************************
While using my University's VMware servers to do my schoolwork, after about 5 minutes
of inactivity on the VMware host the host would enter sleep mode and I would have to login
again, which was very annoying when I would go get a drink of water or use the bathroom, or
just zone out like a moron. Changing the sleep settings on the VMware host would do nothing 
because the settings are reverted on restart, and I'd need to re-disable the sleep settings.
So, what this program does is every 3 minutes it sends a short Shift-key signal to the computer
to mimic touching the keyboard to keep the host awake while I am away. This application requires
no special permissions to run and uses only built-in C++ headers. It was written and compiled remotly 
on one of the VMware hosts. 

*********************************/
//#ifdef _WIN32
#include <windows.h>
//#include <winable.h>
#include <winuser.h>
#include <unistd.h>
//#else
//include <unisd.h>
//#endif
#include <iostream>
#include <vector>
//if system is a windows system, then compile using windows headers.
//otherwise, compile with linux headers. Currently linux is not supported.

#define TIME 180
//define the time as 180 seconds to sleep


void pressKey(void);
//define pressKey()


int main(){

	std::cout<<"Pressing shift key every 3 min to keep machine awake, press ctrl-c to stop"<<std::endl;
	//tell user what this program does
	while(true){
		//loop until syskill is received
		
		sleep(TIME);
		//sleep for 3 min
		pressKey();
		//press the shift key
		
	}
	
	return 0;
}

void pressKey(void){
	keybd_event(VK_SHIFT, 0, 0, 0);
	//press down on the shift key
	usleep(100);
	//sleep for 100 nanoseconds
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	//release the shift key
	
	return;
}

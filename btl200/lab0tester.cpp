/**************************************************************************/
/*                                                                        */
/*   Lab 0 - task 2 tester file                                           */
/*                                                                        */
/*   To compile: g++ lab0b.cpp lab0tester.cpp timer.cpp -std=c++0x        */
/*   You will also need:                                                  */
/*      * timer.h/timer.cpp                                               */
/*                                                                        */
/*   If you are testing in windows, change the #define PLATFORM line      */
/*   in timer.h                                                           */
/*                                                                        */
/**************************************************************************/

#include <iostream>
#include "timer.h"

unsigned long long sum(unsigned int n);

int main(void){
	Timer T;
	unsigned int args[15]={5,4,11,2,0,1,86,8,3,64,27,31,45,163,1234567890};
	unsigned long long answer[15]={15,10,66,3,0,1,3741,36,6,2080,378,496,
									1035,13366,762078938126809995};
    unsigned long long result;
    unsigned numCorrect=0;
	for(int i=0;i<15;i++){
		T.start();
		result=sum(args[i]);
		T.stop();
		if(result==answer[i]){
			numCorrect++;
		}
	}
	std::cout << "Total processing time: " << T.currtime() << std::endl;
	if(numCorrect==15){
		std::cout << "Congrats your function works" << std::endl;
		return 0;
	}
	else{
		std::cout << numCorrect;
		std::cout << " answers were correct.  Looks like you still have work to do";
		std::cout << std::endl;
		return 1;
	}
}
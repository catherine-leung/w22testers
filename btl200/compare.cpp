#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>

const int MAX=1000;
const int LINEWIDTH=1000;
/*function returns total number of integers read*/

size_t readLines(const char* fname, char* line[],int max){
	std::ifstream fp(fname);
	int rc=0;
	if(!fp){
		std::cout << "unable to open " << fname << std::endl;
		return 0;
	}
	else{
		size_t len;
		char currLine[LINEWIDTH];
		while(rc<max && fp.getline(currLine, LINEWIDTH, '\n')){
			len=strlen(currLine);
			line[rc]=new char[len+1];
			strcpy(line[rc],currLine);
			rc++;
		}
		fp.close();
	}
	return rc;

}

void cleanLines(char* line[],size_t numLines){
	for(size_t i=0;i<numLines;i++){
		delete [] line[i];
	}
}

size_t clearBlankLines(char* line[], size_t numLines){
	int j=0;
	for(int i=0;i<numLines;i++){
		if(strlen(line[i])!=0){
			line[j++]=line[i];
		}
		else{
			delete line[i];
			line[i]=nullptr;
		}
	}
	return j;
}
void removeBlanks(char* line){
	int i;
	int j=0;
	for(i=0;line[i]!='\0';i++){
		if(!isspace(line[i])){
			line[j++]=line[i];
		}
	}
	line[j]='\0';
}
void removeBlanks(char* line[], size_t numLines){
	for(int i=0;i<numLines;i++){
		removeBlanks(line[i]);
	}
}

int main(int argc, char* argv[]){
	char* answers[MAX];
	char* correct[MAX];
	int numAnswers=readLines("lab0c.txt",answers,MAX);
	int numCorrect=readLines("correct.txt",correct,MAX);
	int numSame=0;
	numAnswers=clearBlankLines(answers,numAnswers);
	removeBlanks(answers,numAnswers);

	for(int i=0;i<numAnswers;i++){
		std::cout << "Q" << i+1 << ": ";
		if(strcmp(answers[i],correct[i])==0){
			numSame++;
			std::cout << "correct" << std::endl;
		}
		else{
			std::cout << "this was not correct" << std::endl;
		}
	}
	cleanLines(answers,numAnswers);
	cleanLines(correct,numCorrect);
	if(numSame==numAnswers){
		std::cout << "congrats all your answers were correct" << std::endl;
		return 0;
	}
	else{
		std::cout << "You got: " << numSame << "/" << numAnswers << " correct" << std::endl;
		return 1;
	}

}
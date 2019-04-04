// a sample file of For - While convertion

#include <iostream> 
/*
Since now we use C++ instread, this is the header replacing <stdio.h> in C
	also, we use cout<< i << "Helloworld" << endl instread of printf. 
	It's more easy! right?

Here, cout means: "C++'s out function". cout << i ;  will send the thing in the right to the screen.
	And endl = "\n". endl literally means "end of the line".

	So cout << "Hello world" << endl;

	equals to

	cout << "Hello world\n";


	DON'T FORGET ; IN THE END OF THE LINE!!!

*/

using namespace std; 

/* 
	this line shall be included. If not, you have to change 

		cout << i << endl;

	into

		std::cout << i << std::endl;

	They are the same. But I don't want you type more character. So use this line to reduce your work.

*/

void forloop()
{
	for(int i = 0; i < 100; i ++)
	{
		cout << i << endl;
	}
}

void whileloop()
{
	while (1)  //That means your while loop will go forever, but...
	{			// you can find while loop have exactly same structure as For, as any func.
		cout << i << endl;
		if ( i == 100) break;   //break is the magic to skip out of any loop.
								//you can use break to out of For loop as well.
	}
}

/*
	So, from here, you can find the normal structure of While-For loop:

	while (true)    //or 1.
	{
		<The thing you wanna run here>


		if ( put a conditional statement here) break;
	}

*/


/*

	Bonus exercises!!!
	
	in line:36: if ( i == 100) break; 

	try to put it ahead of line 35:cout<< i << endl;

	Find out what's the difference!
*/


int main()
{
	whileloop();
}
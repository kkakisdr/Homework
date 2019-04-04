#include <stdio.h>

//Who's author?

//0.name your file briefly and end with .c/.cpp. Recommend you with cpp, which means C++.
//1.Notice your indent!!! normally a tab = 4 spaces. 
//2.DO NOT PUT MORE THAN ONE MAIN() IN A FILE.
//    ONE CANNOT HAVE MORE THAN ONE MOTHER or FATHER.
//3.The grammar for a normal function is exactly the same as main()
//4.A pair of { } shall start in a new line

//打印从1到122 每六个换一行  *hint:for里套for
//You did a great job! Thanks buddy. Not only the right answer but also using %6d to format it. Perfect.
//But keep in mind: DO NOT do too much work on detail. In programming, the idea is the first thing.
//But keep in mind: DO NOT do too much work on detail. In programming, the idea is the first thing.
void segment_1( )
{
  //Put int i into for loop. It's for the sake of safe
  //If not, you can access your i out of for loop - That's not what you want.

  int k = 1;
  int o = 1;
  for (int i = 0; i < 122; k = pow(2, o), o +=1) 

  {
      for (int j = 0; j < k; j ++)  //for的本质 判断<和加法
      {
        printf("%6d", i+1);
        i += 1;
      } //初始化j为0，当j小于6，执行花括号里的任务，每次完成任务让j+1
      
      printf("\n");//DO NOT USE % very often. It will waste a lot of calculation.
      //if (j == 6) j = 0; 
      // that will be better. 
      
      // Keep in mind: different operators will cost different time!!!
      // So, time complexity is a very important thing, which you shall be taught latter.
  }
}
 
 
 
// 打印从1到122 第一行打印一个 第二行两个 第三行三个
//不会啊 疯了
//Put any comments in header in English.
//TODO: infinite running; I will show you latter.
void segment_2()
{
  int k;
  int f;
  int num;

  num = 0;

  for (k = 0; k < 122; k++)
  {
  	printf("%d", k+1);
 	}
  printf("\n");
} 

//TODO: using TODO is a better way for mei xie wan
//TODO: unfinished. I will show you latter.
void segment_3() //没写完
{
  int k;
  int f = 0;
  int num;
	for (k = 0; k < 122; k++)
 	 {
  		printf("%d", k+1);

      if (f%2 == 1){
        printf("%10d", k+1);
      }
    }
}
/*
  	if (j%6 == 0){
  		printf("\n");
  	}
  }
   return 0;

  }
*/

int main()
{
    //printf("%f\n\n\n",pow(2, 3));
    segment_1();
}

//hw：打印从1到122 
//hw：打印从1到122 每六个换一行  *hint:for里套for
//hw: 打印从1到122 第一行打印一个 第二行两个 第三行三个  *hint:for里套for 可变长度
//打印从1到122 单数行打印10个 偶数行5个  *变量标记单数双数 if (a%2 == 0) print 五个 a+1 if (a%2 == 1) print 10个

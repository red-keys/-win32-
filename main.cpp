#include <iostream>
#include <windows.h>
using namespace std;

#define  KEY_DOWN(VK_NONAME)  ((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
/*
char c1[81] ="_______________________________________________________________________________ ";
char c2[81] ="|                         |                         |                         | ";
char c3[81] ="|                         |                         |                         | ";
char c4[81] ="|                         |                         |                         | ";
char c5[81] ="|        (*￣_￣*)        |         (╬▔皿▔)      |         (￣_￣|||)      | ";
char c6[81] ="|                         |                         |                         | ";
char c7[81] ="|                         |                         |                         | ";
char c8[81] ="|                         |                         |                         | ";
char c9[81] ="|                         |                         |                         | ";
char c10[81]=" ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ ";
char c11[81]="_______________________________________________________________________________ ";
char c12[81]="|                         |                         |                         | ";
char c13[81]="|                         |                         |                         | ";
char c14[81]="|                         |                         |       ■■              | ";
char c15[81]="|                         |                         |       ■                | ";
char c16[81]="|        (⊙_⊙)          |         (＞﹏＜)        |            ■           | ";
char c17[81]="|                         |                         |                         | ";
char c18[81]="|                         |                         |                         | ";
char c19[81]="|                         |                         |                         | ";
char c20[81]=" ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ ";
*/
void show();
void show1();
void show2();
void show3();
void show4();

struct diamonds
{
	char name;//方块S 方块L 方块I 方块O 方块T
	int type;//方块模式
	int point_x;//x坐标
	int point_y;//y坐标
	/*S方块模式1    □■     L方块模式1 ■			T方块模式1   ■□■       I方块模式1  ■        O方块模式1 □■          */
	/*            ■■                  □                         ■                     □                   ■■          */
	/*                                  ■■                                              ■                                 */
	/*S方块模式2  ■                                T方块模式2     ■                     ■                                 */
	/*            □■       L方块模式2     ■                     □■                                                      */
	/*              ■                  ■□■                     ■         I方块模式2 ■□■■                            */

	/*S方块模式3    ■■     L方块模式3 ■■        T方块模式3     ■                                                        */
	/*            ■□                    □                     ■□■                                                      */
	/*                                    ■                                                                                 */
	/*S方块模式4  ■                              T方块模式4       ■                                                        */
	/*            ■□       L方块模式4 ■□■                   ■□                                                      */
	/*              ■                  ■                         ■                                                        */
	/*                                                                                                                       */

};
void display(long line1[23],long line2[23]);
bool check_key(char k)//检测空格
{
	if(KEY_DOWN(k))
		return true;
	else
		return false;
}
/*
void chang()
{
	int i,j;

	for (i=1;i<26;i++)
	{
		char temp;
		temp=c5[i];
		c5[i]=c5[i+26];
		c5[i+26]=temp;
	}
}
*/
int main()
{
	int i=0,j;
	//show1();
	diamonds T;
	T.name='T';
	T.type=1;
	T.point_x=1;
	T.point_y=0;

	long line1[23]={0};
	long line2[23]={0};
	line1[0] = 7;
	line1[1] = 2;
	display(line1,line2);
	

	while (1)
	{
		/*
			VK_LEFT	    0x25	37	LEFT ARROW 键(←)
			VK_UP	    0x26	38	UP ARROW键(↑)
			VK_RIGHT	0x27	39	RIGHT ARROW键(→)
			VK_DOWN  	0x28	40	DOWN ARROW键(↓)
		*/
		if(check_key(32)==true)//空格键
		{
			if('T'==(T.name) || 'S'==(T.name) || 'L'==(T.name))
			{
				if ( T.point_x>0 && T.point_x<20 && T.point_y>0 && T.point_y<22 )
				{
					T.type=(T.type+1)%4;
					int temp[3][3];//用来存储逆时针旋转90°之后的结果 

					temp[0][0]=(line[T.point_y+1]&(1>>(T.point_x-1)))?1:0;
					temp[0][1]=(line[T.point_y+1]&(1>>T.point_x+1))?1:0;
					temp[0][2]=(line[T.point_y+1]&(1>>(T.point_x+1)))?1:0;

					temp[1][0]=(line[T.point_y]&(1>>(T.point_x-1)))?1:0;
					temp[1][1]=(line[T.point_y]&(1>>T.point_x))?1:0;
					temp[1][2]=(line[T.point_y]&(1>>(T.point_x+1)))?1:0;
					for(i=0;i<3;i++)//行
					{
						for (j=0;j<3;j++)//列
						{
							temp[i][j]=line;
						}
					}
					
				}
			}
			system("cls");
			display(line1,line2);
			Sleep(300);
		}
		if(KEY_DOWN(VK_UP))
		{
			if ('T'==(T.name) && 1==(T.type))
			{
				if (T.point_y-1>=0)
				{
					line1[T.point_y-1]=line1[T.point_y];
					line1[T.point_y]=line1[T.point_y+1];
					line1[T.point_y+1]=0;
					T.point_y-=1;
					system("cls");
					display(line1,line2);
				}
			}
			Sleep(300);
		}
		if(KEY_DOWN(VK_DOWN))
		{
			if ('T'==(T.name) && 1==(T.type))
			{
				if (T.point_y+1<22)
				{
					line1[T.point_y+2]=line1[T.point_y+1];
					line1[T.point_y+1]=line1[T.point_y];
					line1[T.point_y]=0;
					T.point_y+=1;
					system("cls");
					display(line1,line2);
				}
			}
			Sleep(300);
		}
		if(KEY_DOWN(VK_LEFT))
		{
			if ('T'==(T.name) && 1==(T.type))
			{
				if ((line1[T.point_y]&1)==0)
				{
					T.point_x-=1;
					line1[T.point_y]>>=1;
					line1[T.point_y+1]>>=1;
					system("cls");
					display(line1,line2);
				}
			}
			Sleep(300);
		}
		if(KEY_DOWN(VK_RIGHT))
		{
			if ('T'==(T.name) && 1==(T.type))
			{
				if ((line1[T.point_y]&(1<<19))==0)
				{
					T.point_x+=1;
					line1[T.point_y]<<=1;
					line1[T.point_y+1]<<=1;
					system("cls");
					display(line1,line2);
				}
			}
			Sleep(300);
		}
	}
	getchar();
}



void show1()
{
	system("cls");
	cout<<"      "<<endl;
	cout<<"■■■"<<endl;
	cout<<"  ■  "<<endl;
}
void show2()
{
	system("cls");
	cout<<"  ■  "<<endl;
	cout<<"  ■■"<<endl;
	cout<<"  ■  "<<endl;
}
void show3()
{
	system("cls");
	cout<<"  ■  "<<endl;
	cout<<"■■■"<<endl;
	cout<<"      "<<endl;
}
void show4()
{
	system("cls");
	cout<<"  ■  "<<endl;
	cout<<"■■  "<<endl;
	cout<<"  ■  "<<endl;
}

void display(long line1[23],long line2[23])
{
	int i,j;
	for(i=0;i<23;i++)
	{
		for (j=0;j<20;j++)
		{
			if (line1[i]&(1<<j))
			{
				cout<<"■";
			} 
			else
			{
				cout<<"  ";
			}
		}
		for (j=0;j<20;j++)
		{
			if(j==0)
			{
				if (line2[i]&(1<<j))
					cout<<"■"; 
				else
					cout<<"| ";
			}
			else
			{
				if (line2[i]&(1<<j))
					cout<<"■"; 
				else
					cout<<"  ";
			}
		}
	}
	cout<<"_______________________________________________________________________________";
}

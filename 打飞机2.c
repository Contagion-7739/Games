#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
enum
{
	BLACK = 0,
	BLUE,
	GREEN,
	GREENLIGHT,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GREY,
	BLUELIGHT,
	GREENLIGHT2,
	GREENLIGHTX,
	REDLIGHT,
	PURPLELIGHT,
	YELLOWLIGHT,
	WHITELIGHT 
};
char RandomTips[6][100]={
    "Shoot your enemies down as quick as possible,else there will be more.",
    "There is a way to shoot down the boss without being hurt,find it!",
    "If you can not shoot down one of your enemies for a long time,just avoid it.",
    "Do not shoot or let your enemies shoot @,it can fix your plane.",
    "You can not pause the game when you are fighting with a boss,so be careful.",
    "Always be away from #s,because it can cause more damage to your plane."
};
void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
}
char Grade[9][40] = 
{
	"Newcomer",
	"Pupil",
	"Amateur",
	"Specialist",
	"Expert",
	"Master",
	"Grandmaster",
	"International Grandmaster",
	"Legendary Grandmaster"
};
const int TIME_NUM=50;
int backup=5;
int talk(int dist)
{
    if(dist<=10)
    {
        printf("                       - lin_toto -\n");
        printf("Detected an enemy plane sending sources.All unit go and stop it.\n");
        return 1;
    }
    else if(dist<=20)
    {
        printf("                             - Headquarters -\n");
        printf("Command!Send fixing planes on the road.Calling Pilot14 and Autopilot,don't shoot it down.\n");
        return 1;
    }
    else if(dist<=30)
    {
        printf("            - Auto -\n");
        printf("Here is Autopliot.I'm going with you.\n");
        return 1;
    }
    if(dist%1000>=100 && dist%1000<=110)
    {
        switch(dist/1000)
        {
            case 1:
                printf("               - kkksc03 -\n");
                printf("Here is kkksc03.Everybody,get him away right now.\n");
                break;
            case 2:
                printf("                      - lzn -\n");
                printf("If they get the sources,we will be in danger!take him down right now!\n");
                break;
            case 3:
                printf("               - darkflames -\n");
                printf("Warning.The enemy is near to their headquarters!\n");
                break;
            case 4:
                printf("               - chen_zhe -\n");
                printf("We must take him down now.All units,do your best.\n");
                break;
            default:
                printf("\n\n");
        }
        return 1;
    }
    else if(dist%1000>=200 && dist%1000<=210)
    {
        printf("          - zcysky -\n");
        printf("The enemy is blowing up everything.\n");
        return 1;
    }
    else if(dist%1000>=215 && dist%1000<=225)
    {
        switch(dist/1000)
        {
            case 0:
                printf("                - lin_toto -\n");
                break;
            case 1:
                printf("                 - kkksc03 -\n");
                break;
            case 2:
                printf("                   - lzn -\n");
                break;
            case 3:
                printf("               - darkflames -\n");
                break;
            case 4:
                printf("                 - chen_zhe -\n");
                break;
        }
                printf("According to the report,the enemy is trying to escape.\n");
        return 1;
    }
    else if(dist%1000>=600 && dist%1000<=610)
    {
        printf("                     - yjjr -\n");
        printf("I'm requesting backup and I'm requesting backup now.\n");
        return 1;
    }
    else if(dist%1000>=615 && dist%1000<=625)
    {
        switch(dist/1000)
        {
            case 0:
                printf("  - lin_toto -\n");
                break;
            case 1:
                printf("  - kkksc03 -\n");
                break;
            case 2:
                printf("    - lzn -\n");
                break;
            case 3:
                printf(" - darkflames -\n");
                break;
            case 4:
                printf("  - chen_zhe -\n");
                break;
        }
                printf("Backup is coming.\n");
        backup=4;
        return 1;
    }
    printf("\n\n");
    return 0;
}
void explode()
{
    const int n=19;
    char a2[19][19][19]={
        {
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          " 
        },
        {
            "          ",
            "          ",
            "          ",
            "          ",
            "     +    ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          " 
        },
        {
            "          ",
            "          ",
            "          ",
            "     +    ",
            "    +#+   ",
            "     +    ",
            "          ",
            "          ",
            "          ",
            "          " 
        },
        {
            "          ",
            "          ",
            "     +    ",
            "    +#+   ",
            "   +###+  ",
            "    +#+   ",
            "     +    ",
            "          ",
            "          ",
            "          " 
        },
        {
            "          ",
            "     +    ",
            "    +#+   ",
            "   +###+  ",
            "  +#####+ ",
            "   +###+  ",
            "    +#+   ",
            "     +    ",
            "          ",
            "          " 
        },
        {
            "     +    ",
            "    +#+   ",
            "   +###+  ",
            "  +#####+ ",
            " +###+###+",
            "  +#####+ ",
            "   +###+  ",
            "    +#+   ",
            "     +    ",
            "          " 
        },
        {
            "    +#+   ",
            "   +###+  ",
            "  +#####+ ",
            " +###+###+",
            "+###+ +###",
            " +###+###+",
            "  +#####+ ",
            "   +###+  ",
            "    +#+   ",
            "     +    " 
        },
        {
            "   +###+  ",
            "  +#####+ ",
            " +###+###+",
            "+###+ +###",
            "###+   +##",
            "+###+ +###",
            " +###+###+",
            "  +#####+ ",
            "   +###+  ",
            "    +#+   " 
        },
        {
            "  +#####+ ",
            " +###+###+",
            "+###+ +###",
            "###+   +##",
            "##+     +#",
            "###+   +##",
            "+###+ +###",
            " +###+###+",
            "  +#####+ ",
            "   +###+  " 
        },
        {
            " +###+###+",
            "+###+ +###",
            "###+   +##",
            "##+     +#",
            "#+       +",
            "##+     +#",
            "###+   +##",
            "+###+ +###",
            " +###+###+",
            "  +#####+ " 
        },
        {
            "+####+###+",
            "####+ +###",
            "###+   +##",
            "##+     +#",
            "#+       +",
            "##+     +#",
            "###+   +##",
            "+###+ +###",
            " +###+###+",
            "  +#####+ " 
        },
        {
            "####+ +###",
            "###+   +##",
            "##+     +#",
            "#+       +",
            "+         ",
            "#+       +",
            "##+     +#",
            "###+   +##",
            "+###+ +###",
            " +###+###+" 
        },
        {
            "####+ +###",
            "###+   +##",
            "##+     +#",
            "#+       +",
            "+         ",
            "#+       +",
            "##+     +#",
            "###+   +##",
            "####+ +###",
            "+####+####" 
        },
        {
            "###+   +##",
            "##+     +#",
            "#+       +",
            "+         ",
            "          ",
            "+         ",
            "#+       +",
            "##+     +#",
            "###+   +##",
            "####+ +###" 
        },
        {
            "##+     +#",
            "#+       +",
            "+         ",
            "          ",
            "          ",
            "          ",
            "+         ",
            "#+       +",
            "##+     +#",
            "###+   +##" 
        },
        {
            "#+       +",
            "+         ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "+         ",
            "#+       +",
            "##+     +#" 
        },
        {
            "+         ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "+         ",
            "#+       +" 
        },
        {
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "+         " 
        },
        {
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          " 
        }
    };
    int i,j,k;
    for(i=0;i<n;i++)
    {
        system("cls");
        for(j=0;j<10;j++)
        {
            for(k=0;k<10;k++) printf("%c",a2[i][j][k]);
            printf("\n");
        }
        Sleep(40);
    }

}
int score=0,disscore=0,surscore=0;
void start()
{
    printf("**** Plane Combat Game(v10.0) ****\n");
    printf("Game was written by Xie Zihan\n");
    printf("Classic Mode:\n");
    printf("press W to move the plane up\n");
    printf("press S to move the plane down\n");
    printf("press K to move the plane faster,press J to move it slower\n");
    printf("press P to pause the game\n");
    printf("You will see some of the enemy planes,shoot them down\n");
    printf("If you touch their bullet or touch #,your HP will be reduced\n");
    printf("When your HP is or lower than zero,you will crash,and then,game over\n");
    printf("When your distance is divisible by 1000 an @ will appear,fly near it and press A to land on it\n");
    printf("After you land on @,you can upgrade your gun,and your plane will be fixed\n");
    printf("When your distance is divisible by 1024 a boss will appear\n");
    printf("After you shoot down 5 bosses you will win the game\n");
    printf("Random Tips:%s\n\n",RandomTips[rand()%6]);

    printf("choose the difficulty(hard+ --> enemies+):\n");
    printf("1.very easy\n");
    printf("2.easy\n");
    printf("3.normal\n");
    printf("4.hard\n");
    printf("5.super\n");
}
int resurvive_sum=0;
int resurvive()
{
    system("cls");
    if(score<1000*(resurvive_sum+1)) return 0;
    else
    {
        printf("Would you like to reduce %d of score to resurvive and get 4800 HP?(Yes:1,No:0)\n",1000*(resurvive_sum+1));
        printf("You've got %d of score\n",score);
        char c=getch();
        if(c=='0') return 0;
        else
        {
            resurvive_sum++;
            printf("resurvived!");
            score-=1000*resurvive_sum;
            return 1;
        }
    }
}
int sum=1,grade=1,dis=0;
int fight(int php)
{
    system("cls");
    char b[11][41]={
    "========================================",
    "                                        ",
    "                                       #",
    "                                     )##",
    ">>                                )#####",
    "                                     )##",
    "                                       #",
    "                                        ",
    "                                        ",
    "========================================"};
    int i,j,k;
    int chp=1000,p=4,cp=4;
    while(chp>0)
    {
//        dis++;
        for(i=0;i<10;i++)
        {
            for(j=0;j<40;j++) printf("%c",b[i][j]);
            printf("\n");
        }
        printf("your HP =%d\n",php);
        printf("boss's HP =%d",chp);float percent=php/4000.0;
        if(percent<0.1)
        {
            printf("very badly damaged");
            system("color 04");
        }
        else if(percent<0.25)
        {
            printf("badly damaged");
            system("color 0c");
        }
        else if(percent<0.5)
        {
            printf("damaged");
            system("color 06");
        }
        else if(percent<0.75)
        {
            printf("slightly damaged");
            system("color 0e");
        }
        else
        {
            printf("ok");
            system("color 0f");

        }
        b[cp-1][36]=b[cp][33]=b[cp+1][36]='=';
        b[cp-2][39]=b[cp-1][37]=b[cp-1][38]=b[cp-1][39]=b[cp][34]=b[cp][35]=b[cp][36]=b[cp][37]=b[cp][38]=b[cp][39]=b[cp+1][37]=b[cp+1][38]=b[cp+1][39]=b[cp+2][39]=' ';
        char c;
        Sleep(150);
        if(_kbhit())
        {
            c=getch();
            if(c=='w' && p>2)
            {
                b[p][0]=b[p][1]=' ';
                p--;
                if(cp>3) cp--;
                if(b[p][1]=='=') php-=20*sum;
                b[p][0]=b[p][1]='>';
            }
            if(c=='s' && p<7)
            { 
                b[p][0]=b[p][1]=' ';
                p++;
                if(cp<6) cp++;
                if(b[p][1]=='=') php-=20*sum;
                b[p][0]=b[p][1]='>';
            }
            if(c=='q') return 0;
            //if(c==' ')
            //{

            //}
        }
        b[p][2]='-';
        char a[10][40]={'\0'};
        for(i=0;i<10;i++)
            for(j=0;j<40;j++)
                a[i][j]=b[i][j];
        int l;
        b[cp-2][39]=b[cp-1][38]=b[cp-1][39]=b[cp][35]=b[cp][36]=b[cp][37]=b[cp][38]=b[cp][39]=b[cp+1][37]=b[cp+1][38]=b[cp+1][39]=b[cp+2][39]='#';
        b[cp-1][37]=b[cp][34]=b[cp+1][37]=')';
        for(i=1;i<9;i++)
            for(j=2;j<40;j++)
                if(b[i][j]=='-')
                {
                    a[i][j]=' ';
                    for(k=j+1;k<j+6 && k<40;k++)
                        if(b[i][k]==')' || b[i][k]=='#')
                        {
                            printf("\nhit");
                            chp-=10*grade;
                            break;
                        }
//                        else printf("%c",b[i][k]);
//                      else if(a[i][k]!=' ') break;
                    if(j+6<40 && b[i][j+6]!=')' && b[i][j+6]!='#') a[i][j+6]='-';
                }
                else if(b[i][j]=='=')
                {
                    if(j<5 && i==p) php-=20*sum;
                    else
                    {
                        a[i][j]=' ';
                        if(a[i][j-5]==' ') a[i][j-5]='=';
                    }
                }
        for(i=0;i<10;i++)
            for(j=0;j<40;j++)
                b[i][j]=a[i][j];
        if(php<=0)
        {
            if(resurvive()==0) break;
            else php=4800;
        }
        b[p][2]='>';
        b[cp-2][39]=b[cp-1][38]=b[cp-1][39]=b[cp][35]=b[cp][36]=b[cp][37]=b[cp][38]=b[cp][39]=b[cp+1][37]=b[cp+1][38]=b[cp+1][39]=b[cp+2][39]='#';
        b[cp-1][37]=b[cp][34]=b[cp+1][37]=')';
            for(i=1;i<9;i++) b[i][0]='\0';
            for(i=0;i<10;i++)
                for(j=0;j<39;j++) b[i][j]=b[i][j+1];
        b[cp-1][36]=b[cp][33]=b[cp+1][36]=' ';
        b[cp-1][37]=b[cp][34]=b[cp+1][37]=')';
        b[cp-2][38]=b[cp+2][38]=' ';
        system("cls");
    }
    backup=5;
    return php;
}
void boss_comein(int p)
{
	char a[7][10][40]={{
    "========================================",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"},
	{"========================================",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                      )|",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"},
	{"========================================",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                     )#|",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"},
	{"========================================",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                    )##|",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"},
	{"========================================",
    "                                       |",
    "                                       |",
    "                                      )|",
    "                                   )###|",
    "                                      )|",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"},
	{"========================================",
    "                                       |",
    "                                       |",
    "                                     )#|",
    "                                  )####|",
    "                                     )#|",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"},
	{"========================================",
    "                                       |",
    "                                      #|",
    "                                    )##|",
    "                                 )#####|",
    "                                    )##|",
    "                                      #|",
    "                                       |",
    "                                       |",
    "========================================"}};
    int i, j;
    for (i = 0;i < 7;i++)
    	a[i][p][0] = a[i][p][1] = 1;
    for (i = 0;i < 7;i++)
    {
    	Sleep(200);
    	system("cls");
    	for (j = 0;j < 10;j++)
    		puts(a[i][j]);
	}
}
void end(int score,int p)
{
    char a[10][40]={
    "========================================",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"};
    a[p][0]=a[p][1]='>';
    int i,j;
    while(a[p][2]!='|')
    {
        for(i=0;i<10;i++)
        {
            for(j=0;j<40;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
        score++;
        a[p][2]='>';
        for(i=1;i<9;i++) a[i][0]='\0';
        for(i=0;i<10;i++)
            for(j=0;j<39;j++) a[i][j]=a[i][j+1];
        for(i=1;i<9;i++)
            a[i][39]=' ';
        Sleep(200);
        system("cls");

    }
    system("cls");
    printf("--------------\n");
    printf("|  You Win!  |\n");
    printf("|score:%5d |\n",score);
    printf("--------------");
}
void play_classic()
{
	int talkflag=0,talkflag2=0;
    score=0;
    dis=0;
    int grade2=0;
    int hard[5]={10,7,5,3,2};
    char a[10][40]={
    "========================================",
    "                                       |",
    "                                       |",
    "                                       |",
    ">>                                     |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"};
    int p=4,i,j,k,fuel=1300,boost=1,tot=0,coin=0,php=4000, speed;
    int u[]={1,1,1,0,-1,-1,-1,0}; 
    int v[]={1,0,-1,-1,-1,0,1,1};
    srand((unsigned)time(NULL));
    int flag=0;
    start();
    int h;
    scanf("%d",&h);
    h--;
    int book=0,book2=0;
    int p2,p3;
    system("cls");
    printf("\n\n");
    int CurSurvivEnemies = 0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<40;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }
    for(k=3;k>0;k--)
    {
        printf("%d ",k);
        Sleep(999);
    }
    printf("Go!");
    Sleep(999);
	speed = 100;
        while(1)
        {
        	SetColor(WHITELIGHT, BLACK);
        system("cls");
//        for(i=1;i<9;i++)
//            for(j=1;j<40;j++)
//              if(a[i][j]!='=' && a[i][j]!='-') d[i][j]=a[i][j];
        if(!talkflag2) talkflag=talk(dis);
        else
            if(talkflag2>0)
            {
                printf("      - Auto -\n");
                printf("Pilot 14 hits the enemy!\n");
                talkflag2--;
            }
            else
            {
                printf("    - Auto -\n");
                printf("Pilot 14 was hitten!\n");
                talkflag2++;
            }
        for(i=0;i<10;i++)
        {
            for(j=0;j<40;j++)
                putchar(a[i][j]);
            printf("\n");
        }
        grade2=score-dis - (sum - 1) * 500;
        float percent=(float)php/4000.0;
 //       printf("bullet:%5d\n",bullet);
        printf("s c o r e :%06d\n",score);
        printf(" distance :%06d\n",dis);
//        printf("fuel:%5d\n",fuel);
        printf("c  o  i  n:%06d\n",coin);
        printf("H        P:%04d(%03d",php,(int)(percent*100+0.5));
		putchar('%');
        printf(")\n");
		printf("s p e e d :%04dkm/h\n", speed);
		printf("Enemies remaining :%02d", CurSurvivEnemies);
        int tmp;
        if (grade2 / 100 < 0)
        	tmp = 0;
        else if (grade2 / 100 > 7)
        	tmp = 8;
        else
        	tmp = grade2 / 100;
        printf("Grade:");
        switch (tmp)
        {
        	case 0:
        		SetColor(GREY, BLACK);
        		break;
        	case 1:
        		SetColor(GREEN, BLACK);
        		break;
        	case 2:
        		SetColor(GREENLIGHT2, BLACK);
        		break;
        	case 3:
        		SetColor(GREENLIGHTX, BLACK);
        		break;
        	case 4:
        		SetColor(BLUELIGHT, BLACK);
        		break;
        	case 5:
        		SetColor(YELLOWLIGHT, BLACK);
        		break;
        	case 6:
        		SetColor(YELLOW, BLACK);
        		break;
        	case 7:
        		SetColor(REDLIGHT, BLACK);
        		break;
        	case 8:
        		SetColor(RED, BLACK);
        		break;
		}
		printf("%s\n", Grade[tmp]);
		SetColor(WHITELIGHT, BLACK);
        printf("Rating:", grade2);
        switch (tmp)
        {
        	case 0:
        		SetColor(GREY, BLACK);
        		break;
        	case 1:
        		SetColor(GREEN, BLACK);
        		break;
        	case 2:
        		SetColor(GREENLIGHT2, BLACK);
        		break;
        	case 3:
        		SetColor(GREENLIGHTX, BLACK);
        		break;
        	case 4:
        		SetColor(BLUELIGHT, BLACK);
        		break;
        	case 5:
        		SetColor(YELLOWLIGHT, BLACK);
        		break;
        	case 6:
        		SetColor(YELLOW, BLACK);
        		break;
        	case 7:
        		SetColor(REDLIGHT, BLACK);
        		break;
        	case 8:
        		SetColor(RED, BLACK);
        		break;
		}
		printf("%d\n", grade2);
        if(percent<0.1)
        {
        	SetColor(15, 4);
            printf("very badly damaged");
            //system("color 04");
        }
        else if(percent<0.25)
        {
        	SetColor(15, 12);
            printf("badly damaged");
            //system("color 0c");
        }
        else if(percent<0.5)
        {
        	SetColor(0, 6);
            printf("damaged");
            //system("color 06");
        }
        else if(percent<0.75)
        {
        	SetColor(0, 14);
            printf("slightly damaged");
            //system("color 0e");
        }
        else
        {
        	SetColor(0, 15);
            printf("ok");
            //system("color 0f");

        }

        char c;
        Sleep(1000 - speed);
        if(_kbhit())
        {
            c=getch();
            if(c=='w' && p>1)
            {
                a[p][0]=a[p][1]=' ';
                p--;
                if(a[p][1]=='#' && boost==1)
                {
    //              explode();
    //              system("cls");
    //              printf("--------------\n");
    //              printf("|   CRASH!   |\n");
    //              printf("|μ?·?: %5d |\n",score);
    //              printf("--------------");
                    php-=200;
                }
//              if(a[p][1]=='X')
//              {
//                  fuel+=100*(score/1000+1);
//              }
//              if(a[p][1]=='B') bullet++;
                if(a[p][1]=='o') coin++;
                a[p][0]=a[p][1]='>';
            }
            if(c=='s' && p<8)
            {
                a[p][0]=a[p][1]=' ';
                p++;
                if(a[p][1]=='#' && boost==1)
                {
    //              explode();
    //              system("cls");
    //              printf("--------------\n");
    //              printf("|   CRASH!   |\n");
    //              printf("|μ?·?:%5d  |\n",score);
    //              printf("--------------");
                    php-=200;
                } 
                if(a[p][1]=='X')
                {
                    fuel+=100*(score/1000+1);
                }
                //if(a[p][1]=='B') bullet++;
                if(a[p][1]=='o') coin++;
                a[p][0]=a[p][1]='>';
            }

            if(c=='q')
            {
            	SetColor(15, 0);
                explode();
                system("cls");
                printf("--------------\n");
                printf("|   CRASH!   |\n");
                printf("|score:%5d |\n",score);
                printf("--------------");
                break;
            }
            if(c=='a' && (a[p][1]=='@'||a[p][2]=='@'||a[p-1][1]=='@'||a[p+1][1]=='@'||a[p-1][0]=='@'||a[p+1][0]=='@'))
            {
                php=4000;
                system("cls");
                while(1)
                {
                    printf("coin:%d\n",coin);
    //              printf("è?óí:%d\n",fuel);
                    //printf("×óμˉ:%d\n",bullet);
                    printf("Your choice:\n");
    //              printf("1.1o?òè?óí\n");
                    printf("1.upgrade gun\n");
                    printf("2.take off\n");
                    int usl;
                    scanf("%d",&usl);
                    if(usl==2) break;
    //              if(usl==1)
    //              {
    //                  printf("è?óí????:2coin/10L\n");
    //                  printf("1o?òêyá?(10μ?±?êy):");
    //                  int num;
    //                  scanf("%d",&num);
    //                  while(num%10!=0 || coin/2<num/10)
    //                  {
    //                      printf("ê?è?′í?ó,????D?ê?è?");
    //                      if(num%10!=0) printf("(è?óíêyá?·?10μ?±?êy)\n");
    //                      else printf("(?e±ò2?×?)\n");
    //                      scanf("%d",&num);
    //                  }
    //                  coin-=num/5;
    //                  fuel+=num;
    //              }
                    if(usl==1)
                    {
                        printf("price:20coin/1grade\n");
                        printf("upgrade grades:");
                        int num;
                        scanf("%d",&num);
                        while(coin<num*20)
                        {
                            printf("Not enough coins\n");
                            scanf("%d",&num);
                        }
                        coin-=num*20;
                        grade+=num;
                    }
                    else break;
                    system("cls"); 
                }
                continue;
            }
//            if(boost==2) tot--;
//            if(c=='b' && boost==1)
//            {
//                boost=2;
//                tot=10;
//            }
            if(c=='p')
            {
                printf("\npress any key to restart the game");
                getch();
            }
            if (dis > 5)
	            if (c == 'k' && speed <= 995) speed += 5;
	            else if (c == 'j' && speed >= 5) speed -= 5;
        }
        if(a[p][2]=='#') score++;
        a[p][2]='-';
//        if(boost==2 && tot==0)
//        {
//            boost=1;
//            for(i=1;i<9;i++)
//                for(j=0;j<40;j++)
//                    a[i][j]=' ';
//            a[p][0]=a[p][1]='>';
//        }
//      if(a[p][2]=='X') fuel+=100*(score/1000+1);
        //if(a[p][2]=='B') bullet++;
        if(a[p][2]=='o') coin++;
//      if(boost==2 && a[p][3]=='X') fuel+=100*(score/1000+1);
        //if(boost==3 && a[p][3]=='B') bullet++;
//        if(boost==3 && a[p][3]=='o') coin++;
        if(php<=0)
        {
            if(resurvive()==0)
            {
            	SetColor(15, 0);
                explode();
                system("cls");
                printf("--------------\n");
                printf("|   CRASH!   |\n");
                printf("|score:%5d |\n",score);
                printf("--------------");
                break;
            }
            else php=4800;
        }
//        score++;
        dis++;
//      fuel-=10*(score/1000+1)*boost;
//      if(fuel<0) fuel=0;
//      if(score%100==0)//éú3éè?óí 
//      {
//          p2=rand()%8+1;
//            a[p2][39]='X';
//            book=10;
//      }
//        if(book!=0)
//        {
//          a[p2][39]='X';
//            book--;
//        }
//        if(score%750==0)//éú3é×óμˉ 
//        {
//            p3=rand()%8+1;
//            a[p3][39]='B';
//            book2=10;
//        }
//        if(book2!=0)
//        {
//            a[p3][39]='B';
//            book2--;
//        }
        if(dis%1000==0)//éú3é???? 
        {
            int y=rand()%8+1;
            y=max(y,2);
            y=min(y,7);
            a[y][38]='@';
            for(i=0;i<8;i++)
            {
                a[y+u[i]][38+v[i]]=' ';
            }
        }
        if(dis%1024==0)
        {
            system("cls");
            for(i=1;i<9;i++) a[i][39]='=';
            int l;
            for(l=1;l<=8;l++)
            {
                for(i=0;i<10;i++)
                {
                    for(j=0;j<40;j++) printf("%c",a[i][j]);
                    printf("\n");
                }
                int b[10][40]={'\0'};
                for(i=0;i<10;i++)
                    for(j=0;j<40;j++)
                        b[i][j]=a[i][j];
            for(i=1;i<9;i++)
                for(j=2;j<40;j++)
                    if(a[i][j]=='-')
                    {
                        if(j>35)
                        {
                            b[i][j]=' ';
                            for(k=j+1;k<40;k++)
                            {
                                if(b[i][k]=='#') score++;
                                else if(b[i][k]=='<') score+=5;
                                b[i][k]=' ';
                            }
                        }
                        else
                        {
                            b[i][j]=' ';
                            for(k=j+1;k<j+6;k++)
                            {
                                if(b[i][k]=='#') score++;
                                else if(b[i][k]=='<') score+=5;
                                b[i][k]=' ';
                            }
                            b[i][j+6]='-';
                        }
                    }
                    else if(a[i][j]=='=')
                    {
                        b[i][j]=' ';
                        for(k=j;k>=j-5 && k>=0;k--)
                            if(b[i][k]=='#' || b[i][k]=='<') b[i][k]=' ';
                        if(j<5 && i==p) php-=20*sum;
                        else if(j>=5) b[i][j-5]='=';
                    }
            for(i=0;i<10;i++)
                for(j=0;j<40;j++)
                    a[i][j]=b[i][j];
                Sleep(200);
                system("cls");
            }
            boss_comein(p);
            php=fight(php);
            if(php<=0)
            {
            	SetColor(WHITELIGHT, BLACK);
                explode();
                system("cls");
                printf("--------------\n");
                printf("|   CRASH!   |\n");
                printf("|score:%5d |\n",score);
                printf("--------------");
                break;
            }
            score+=500;
            fuel+=1000;
            coin+=100;
            if(sum==5)
            {
                end(score,p);
                break;
            }
            sum++;
            for(i=1;i<9;i++)
                for(j=0;j<40;j++)
                    a[i][j]=' ';
            a[p][0]=a[p][1]='>';
        }
        char b[10][40]={'\0'};
        for(i=0;i<10;i++)
            for(j=0;j<40;j++)
                b[i][j]=a[i][j];
        int l;
        for(i=1;i<9;i++)
            for(j=2;j<40;j++)
                if(a[i][j]=='-')
                {
                    if(j>35)
                    {
                        b[i][j]=' ';
                        for(k=j+1;k<40;k++)
                        {
                            if(b[i][k]=='#') score++;
                            else if(b[i][k]=='<')
                            {
                                score+=5;
                                if(!talkflag)
                                {
                                    printf("      - Auto -\n");
                                    printf("Pilot 14 hits the enemy!\n");
                                    talkflag2=10;
                                }
                            }
                            if(b[i][k]=='#' || b[i][k]=='<') b[i][k]=' ';
                        }
                    }
                    else
                    {
                        b[i][j]=' ';
                        for(k=j+1;k<j+6;k++)
                        {
                            if(b[i][k]=='#') score++;
                            else if(b[i][k]=='<')
                            {
                                score+=5;
                                if(!talkflag)
                                {
                                    printf("      - Auto -\n");
                                    printf("Pilot 14 hits the enemy!\n");
                                    talkflag2=10;
                                }
                            }
                            if(b[i][k]=='#' || b[i][k]=='<') b[i][k]=' ';
                        }
                        b[i][j+6]='-';
                    }
                }
                else if(a[i][j]=='=')
                {
                    b[i][j]=' ';
                    for(k=j;k>=j-5 && k>=0;k--)
                        if(b[i][k]=='#' || b[i][k]=='<')
                        {
                            b[i][k]=' ';
                        }
                    if(j<5 && i==p)
                    {
                        php-=20*sum;
                        score-=5;
                        if(!talkflag)
                        {
                            printf("    - Auto -\n");
                            printf("Pilot 14 was hitten!\n");
                            talkflag2=-10;
                        }
                    }
                    else if(j>=5)
                        b[i][j-5]='=';
                }
        for(i=0;i<10;i++)
            for(j=0;j<40;j++)
                a[i][j]=b[i][j];
        for(i=1;i<9;i++)
            for(j=2;j<40;j++)
                if(a[i][j]=='<')
                {
                    if(i==1)
                    {
                        b[i][j]=' ';
                        b[i+1][j]='<';
                        b[i+1][j-1]='=';
                    }
                    else if(i==8)
                    {
                        b[i][j]=' ';
                        b[i-1][j]='<';
                        b[i-1][j-1]='=';
                    }
                    else
                    {
                        int sel=i-p;
                        if(sel<0)
                        {
                            b[i][j]=' ';
                            b[i+1][j]='<';
                            b[i+1][j-1]='=';
                        }
                        else
                        {
                            b[i][j]=' ';
                            b[i-1][j]='<';
                            b[i-1][j-1]='=';
                        }
                    }
                }
        for(i=0;i<10;i++)
            for(j=0;j<40;j++)
                a[i][j]=b[i][j];
        //for(l=1;l<=boost;l++)
        //{
        a[p][2]='>';
        for(i=1;i<9;i++) a[i][0]='\0';
        for(i=0;i<10;i++)
            for(j=0;j<39;j++) a[i][j]=a[i][j+1];
        for(i=1;i<9;i++)
            if(rand()%hard[h]==0 && i!=p2 && i!=p3)
                a[i][39]='#';
            else
                a[i][39]=' ';
        for(i=1;i<9;i++)
            if(rand()%50==0) a[i][39]='o';
        for(i=1;i<9;i++)
            if(rand()%(hard[h]*4*backup)==0)
            {
                a[i][39]='<';
                a[i][38]='=';
            }
        if (dis == 1) speed = 300;
        else if (dis == 2) speed = 450;
		else if (dis == 3) speed = 550;
		else if (dis == 4) speed = 625;
		else if (dis == 5) speed = 700; 
		CurSurvivEnemies = 0;
		for (i = 0;i < 10;i++)
			for (j = 0;j < 40;j++)
				if (a[i][j] == '<')
					CurSurvivEnemies++;
        //}
    }
}
void start_distance()
{
    printf("**** Plane Combat Game(v10.0) ****\n");
    printf("Game was writen by Xie Zihan\n");
	printf("Distance Mode:\n");
    printf("press W to move the plane up\n");
    printf("press S to move the plane down\n");
    printf("press K to move the plane faster,press J to move it slower\n");
    printf("press P to pause the game\n");
    printf("Do not hit #s by your plane,else you will crash immidiately\n");
    printf("If you are out of fuel,you will crash immidiately too\n");
    printf("You have only 50 bullets,so use them carefully,no automatic firing\n");
    printf("When your distance is divisible by 1000 an @ will appear,fly near it and press A to land on it\n");
    printf("After you land on @,you can buy fuel and bullets\n");
    printf("Hit 'X's to get fuel,hit 'B's to get bullets,hit 'o's to get coins\n");
    printf("Press B to get a boost, you can hit anything you want without crashing\n");
    printf("but boost will cost double fuel.Boost will last 10 rounds\n");
    printf("After the distance get to 7000 you will win the game\n");

    printf("choose the difficulty(hard+ --> enemies+):\n");
    printf("1.very easy\n");
    printf("2.easy\n");
    printf("3.normal\n");
    printf("4.hard\n");
    printf("5.super\n");
}
void play_distance()
{
	char a[10][40]={
    "========================================",
    "                                       |",
    "                                       |",
    "                                       |",
    ">>                                     |",
    "                                       |",
    "                                       |",
    "                                       |",
    "                                       |",
    "========================================"};
	int p=4,i,j,bullet=50,k,fuel=1300,boost=1,tot=0,coin=0, dis = 0;
	int hard[5] = {10, 7, 5, 3, 2};
    int u[]={1,1,1,0,-1,-1,-1,0}; 
    int v[]={1,0,-1,-1,-1,0,1,1};
    srand((unsigned)time(NULL));
    int score=0;
    start_distance();
    int h;
    scanf("%d",&h);
    h--;
    int book=0,book2=0, speed = 100;
    int p2,p3;
    while(1)
    {
        system("cls");
        for(i=0;i<10;i++)
        {
            for(j=0;j<40;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
        printf("bullets :%06d\n",bullet);
        printf("score   :%06d\n",score);
        printf("distance:%06d\n", dis);
        printf("fuel    :%06d\n",fuel);
        printf("coins   :%06d\n",coin);
        printf("speed   :%06dkm/h", speed);
        Sleep(1000 - speed);
        if (_kbhit())
    	{
        	char c=getch();
                if(c=='w' && p>1)
                {
                    a[p][0]=a[p][1]=' ';
                    p--;
                    if(a[p][1]=='#' && boost==1)
                    {
                            explode();
                            system("cls");
                            printf("--------------\n");
                            printf("|   CRASH!   |\n");
                            printf("|得分: %5d |\n",score);
                            printf("--------------");
                            break;
                    }
                    if(a[p][1]=='X')
                    {
                            fuel+=100*(score/1000+1);
                    }
                    if(a[p][1]=='B') bullet++;
                    if(a[p][1]=='o') coin++;
                    a[p][0]=a[p][1]='>';
                }
                if(c=='s' && p<8)
                {
                    a[p][0]=a[p][1]=' ';
                    p++;
                    if(a[p][1]=='#' && boost==1)
                    {
                            explode();
                            system("cls");
                            printf("--------------\n");
                            printf("|   CRASH!   |\n");
                            printf("|得分:%5d  |\n",score);
                            printf("--------------");
                            break;
                    } 
                    if(a[p][1]=='X')
                    {
                            fuel+=100*(score/1000+1);
                    }
                    if(a[p][1]=='B') bullet++;
                    if(a[p][1]=='o') coin++;
                    a[p][0]=a[p][1]='>';
                }
		        if(c==' ' && bullet>0)
		        {
		            if(a[p][2]=='#') score++;
		                a[p][2]='-';
		            bullet--;
		        }
		        if(c=='q')
		        {
                	explode();
                    system("cls");
                    printf("--------------\n");
                    printf("|   CRASH!   |\n");
                    printf("|score:%4d  |\n",score);
                    printf("--------------");
                    break;
                }
                if(c=='a' && (a[p][1]=='@'||a[p][2]=='@'||a[p-1][1]=='@'||a[p+1][1]=='@'||a[p-1][0]=='@'||a[p+1][0]=='@'))
                {
                        system("cls");
                        while(1)
                        {
                                printf("coins:%d\n",coin);
                                printf("fuel:%d\n",fuel);
                                printf("bullets:%d\n",bullet);
                                printf("What do you wish to do:\n");
                                printf("1.buy fuel\n");
                                printf("2.buy bullets\n");
                                printf("3.take off\n");
                                int usl;
                                scanf("%d",&usl);
                                if(usl==3) break;
                                if(usl==1)
                                {
                                        printf("The value of fuel:2coin/10L\n");
                                        printf("How much fuel do you wish to buy(divisble by 10):");
                                        int num;
                                        scanf("%d",&num);
                                        while(num%10!=0 || coin/2<num/10)
                                        {
                                                printf("ILLEGAL,input again");
                                                if(num%10!=0) printf("(can not divide by 10)\n");
                                                else printf("(not enough coins)\n");
                                                scanf("%d",&num);
                                        }
                                        coin-=num/5;
                                        fuel+=num;
                                }
                                if(usl==2)
                                {
                                        printf("The value of bullets:1coin/1bullet\n");
                                        printf("How many bullets do you wish to buy:");
                                        int num;
                                        scanf("%d",&num);
                                        while(coin<num)
                                        {
                                                printf("not enough coins\n");
                                                scanf("%d",&num);
                                        }
                                        coin-=num;
                                        bullet+=num;
                                }
                                system("cls"); 
                        }
                        continue;
                }
                if (c == 'j' && speed >= 500)
                	speed -= 5;
                if (c == 'k' && speed <= 1000)
                	speed += 5;
                
                if(c=='b' && boost==1)
                {
                        boost=2;
                        tot=10;
                }
                if(c == 'p')
                {
					printf("press any key to continue\n");
                    getch();
                }
				}
                if((a[p][2]=='#' || a[p][1]=='#' || fuel<=0) && boost==1)
                {
                        explode();
                        system("cls");
                        printf("--------------\n");
                        printf("|   CRASH!   |\n");
                        printf("|score:%4d  |\n",score);
                        printf("--------------");
                        break;
                }
				if(boost==2 && tot==0)
                {
                        boost=1;
                        for(i=1;i<9;i++)
                                for(j=0;j<40;j++)
                                        a[i][j]=' ';
                        a[p][0]=a[p][1]='>';
                }
				if(a[p][2]=='X') fuel+=100*(score/1000+1);
                if(a[p][2]=='B') bullet++;
                if(a[p][2]=='o') coin++;
                if(boost==2 && a[p][3]=='X') fuel+=100*(score/1000+1);
                if(boost==2 && a[p][3]=='B') bullet++;
                if(boost==2 && a[p][3]=='o') coin++;
				if(boost==2) tot--;
				score++;
                fuel-=10*(score/1000+1)*boost;
                if(fuel<0) fuel=0;
                if(score%(100*(score/1000+1))==0)//生成燃油 
                {
                    p2=rand()%8+1;
            		a[p2][39]='X';
            		book=10;
                }
		        if(book!=0)
		        {
                	a[p2][39]='X';
            		book--;
        		}
                if(score%750==0)//生成子弹 
                {
                    p3=rand()%8+1;
                    a[p3][39]='B';
            		book2=10;
                }
		        if(book2!=0)
		        {
                	a[p3][39]='B';
            		book2--;
        		}
                if(score%1000==0)//生成空母 
                {
                        int y=rand()%8+1;
                        y=max(y,2);
                        y=min(y,7);
                        a[y][38]='@';
                        for(i=0;i<8;i++)
                        {
                                a[y+u[i]][38+v[i]]=' ';
                        }
                }
                char b[10][40]={'\0'};
                for(i=0;i<10;i++)
                        for(j=0;j<40;j++)
                                b[i][j]=a[i][j];
                int l;
                for(i=1;i<9;i++)
                        for(j=2;j<40;j++)
                                if(a[i][j]=='-')
                                {
                                        if(j>35)
                                        {
                                                b[i][j]=' ';
                                                for(k=j+1;k<40;k++)
                                                {
                                                        if(b[i][k]=='#') score++;
                                                        b[i][k]=' ';
                                                }
                                        }
                                        else
                                        {
                                                b[i][j]=' ';
                                                for(k=j+1;k<j+6;k++)
                                                {
                                                        if(b[i][k]=='#') score++;
                                                        b[i][k]=' ';
                                                }
                                                b[i][j+6]='-';
                                        }
                                }
                for(i=0;i<10;i++)
                        for(j=0;j<40;j++)
                                a[i][j]=b[i][j];
                for(l=1;l<=boost;l++)
                {
                        a[p][2]='>';
                        for(i=1;i<9;i++) a[i][0]='\0';
                        for(i=0;i<10;i++)
                                for(j=0;j<39;j++) a[i][j]=a[i][j+1];
                        for(i=1;i<9;i++)
                                if(rand()%hard[h]==0 && i!=p2 && i!=p3)
                                        a[i][39]='#';
                                else
                                        a[i][39]=' ';
                        for(i=1;i<9;i++)
                                if(rand()%50==0) a[i][39]='o';
                }
			dis++;
            if (dis == 1) speed = 300;
            if (dis == 2) speed = 450;
            if (dis == 3) speed = 600;
            if (dis == 4) speed = 700;
            if (dis == 5) speed = 750;
            if (dis == 7000)
            {
            	end(score, p);
            	break;
			}
        }
}
int main()
{
	system("color 0f");
    while(1)
    {
    	printf("choose mode:\n");
    	printf("1:classic mode\n");
    	printf("2:distance mode\n");
    	char c = getch();
    	if (c == '1')
        	play_classic();
        else if (c == '2')
        	play_distance();
	    printf("\n1:Restart 0:Quit\n");
	    char c2=getch();
	    if(c2=='0') break;
	    system("cls");
    }
    return 0;
}

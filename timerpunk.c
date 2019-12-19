#include <stdio.h>
#include <ncurses.h> 
#include <string.h>

void figlet(int row,char *title);



int main(){

     WINDOW *sub1;
     WINDOW *sub2;
     WINDOW *sub3;
     WINDOW *start;	

	//Variables to center the screen
	 int len,indent,y,width;
	 
	 //hours,minutes,seconds
 	 int h;
         int m;
         int s;
	 int num; //here, a number is assigned depending on the condition of the timer
	 int ch;
	 
	 //for the start button
         int opcion;


    initscr();
	
	//Started with the color of the program
        start_color();
        init_pair(2,COLOR_BLACK,COLOR_GREEN);


	//Program logo
    	figlet(5,"figlet TimerPunk");


	 //Centering the sub-windows
	  getmaxyx(stdscr,y,width);
 	  len = 2;        //sub window width
          indent = width - len;
          indent /= 2; 		  //indent to center the window

	//created the sub-windows
	//1 and 2 are the width and length of the window
	 sub1 = subwin(stdscr,1,3,15,indent-4);
	 sub2 = subwin(stdscr,1,3,15,indent); 
	 sub3 = subwin(stdscr,1,3,15,indent+4);

	 start = subwin(stdscr,1,5,18,indent-1);
         wprintw(start,"start");


	 //Giving color to the sub-windows
	 wbkgd(sub1,COLOR_PAIR(2));
	 wrefresh(sub1);

         wbkgd(sub2,COLOR_PAIR(2));
	 wrefresh(sub2);

         wbkgd(sub3,COLOR_PAIR(2));
	 wrefresh(sub3);

         wbkgd(start,COLOR_PAIR(2));
	 wrefresh(start);


	//Entry is requested in each window
	//hours,minutes,seconds
	 wscanw(sub1,"%d",&h);
  	 wprintw(sub1,"%02d",h);
     	 wrefresh(sub1);
 
     	wscanw(sub2,"%d",&m);
     	wprintw(sub2,"%02d",m);
     	wrefresh(sub2);

     	wscanw(sub3,"%d",&s);
     	wprintw(sub3,"%02d",s);
     	wrefresh(sub3);

	//tengo que agregar condiciones
	//para verificar que sean numeros
	
   if(h > 0 && m > 0 && s > 0 ) //Solo para contar HORAS,MINUTOS,SEGUNDOS
        num  = 1;

    else if( h > 0 && m > 0) //Solo para contar HORAS Y MINUTOS
        num = 2;

    else if( h > 0 && s > 0) //Solo para contar HORAS y SEGUNDOS
        num = 3;

    else if(m > 0 && s > 0) //MINUTOS Y SEGUNDOS 
        num = 4 ;

    else if(h > 0 ) //Solo para contar HORAS
        num = 5;

    else if(m > 0 ) //Sola para MINUTOS
        num = 6;

    else if(s > 0) //Solo para SEGUNDOS
        num = 7;

	
	
	// verify that the user clicked on 'start'
	// if the program does follow the execution flow
do{
    refresh();
    opcion = getch();

    switch(opcion)
    {
            case 's':
                    wattron(start,A_REVERSE); //
                    wclear(start);
                    wprintw(start,"start");
                    wrefresh(start);

                    napms(300);
                    wattroff(start,A_REVERSE);
                    wclear(start);
                    wprintw(start,"start");
                    wrefresh(start);
			break;

            default:
                    break;
    }
}while(opcion != 's');


//Start of the switch for each timer run
switch(num)
	{
		//Horas,minutos,segundos 
		case 1:	   
			  for(s=s; s >= 0; s--)//Empieza desde los segundos
			  	{
			  		wclear(sub3);
					wprintw(sub3,"%02d",s);
					wrefresh(sub3);
					napms(1000);
				}

			  while(m-- > 0)//Despues los minutos
			  {
					wclear(sub2);
					wprintw(sub2,"%02d",m);
					wrefresh(sub2);
					napms(10);

					
					for(s=59; s >= 0; s--)
						{
							wclear(sub3);
							wprintw(sub3,"%02d",s);
							wrefresh(sub3);
							napms(1000);
						}
			  }

			while(h-- > 0)//Despues las horas
				{
						wclear(sub1);
                        wprintw(sub1,"%02d",h);
                       	wrefresh(sub1);
                        napms(1000);

              			 for(m=59; m >= 0; m--)
                            {
								wclear(sub2);
                                wprintw(sub2,"%02d",m);
                                wrefresh(sub2);
                                napms(1000);

                                for(s=59; s >= 0; s--)
                                	{

                                	wclear(sub3);
                                    wprintw(sub3,"%02d",s);
                                    wrefresh(sub3);
									napms(1000);
                                	}
                            }
                 }
			break;//Fin de el case 1 <---------------------------------------------


		//Horas y minutos
		case 2:
			while(m-- > 0)//Empieza desde los minutos
			{
				wclear(sub2);
				wprintw(sub2,"%02d",m);
				wrefresh(sub2);
				napms(1000);


				for(s=59; s >= 0; s--)
				{
					wclear(sub3);
					wprintw(sub3,"%02d",s);
					wrefresh(sub3);
					napms(1000);
				}
			}

			while(h-- > 0)//Despues las horas
			{
				wclear(sub1);
                wprintw(sub1,"%02d",h);
                wrefresh(sub1);
                napms(1000);

              			 for(m=59; m >= 0; m--)
                            {
								wclear(sub2);
                                wprintw(sub2,"%02d",m);
                                wrefresh(sub2);
                                napms(1000);

                                for(s=59; s >= 0; s--)
                                {

                                	wclear(sub3);
                                    wprintw(sub3,"%02d",s);
                                    wrefresh(sub3);
									napms(1000);
                                }
                            }
            }
			break; //Fin de el case 2 <-----------------------------------
					
		
		//Horas y Segundos			
		case 3:
			for(s=s; s >= 0; s--)
			{
				wclear(sub3);
                wprintw(sub3,"%02d",s);
                wrefresh(sub3);
				napms(1000);
			}

			while(h-- > 0)
          			{
						wclear(sub1);
                        wprintw(sub1,"%02d",h);
                       	wrefresh(sub1);
                        napms(1000);

              			 for(m=59; m >= 0; m--)
                            {
								wclear(sub2);
                                wprintw(sub2,"%02d",m);
                                wrefresh(sub2);
                                napms(1000);

                                for(s=59; s >= 0; s--)
                                	{

                                	wclear(sub3);
                                    wprintw(sub3,"%02d",s);
                                    wrefresh(sub3);
									napms(1000);
                                	}
                            }
                    }
			break;//Fin de el case 3 <------------------------------------

		
		//Minutos y Segundos
		case 4:
			for(s=s; s >= 0; s--) //Empieza en los segundos
			{
				wclear(sub3);
                wprintw(sub3,"%02d",s);
                wrefresh(sub3);
				napms(1000);
			}

			while(m-- > 0)//Despues desde los minutos
			{
				wclear(sub2);
				wprintw(sub2,"%02d",m);
				wrefresh(sub2);
				napms(1000);


				for(s=59; s >= 0; s--)
				{
					wclear(sub3);
					wprintw(sub3,"%02d",s);
					wrefresh(sub3);
					napms(1000);
				}
			}
		break; //Fin de el Case 4 <---------------------------------------

	
		//Horas		
		case 5:
			while(h-- > 0) //Empieza desde las horas
          			{
						wclear(sub1);
                        wprintw(sub1,"%02d",h);
                       	wrefresh(sub1);
                        napms(1000);

              			 for(m=59; m >= 0; m--)
                            {
								wclear(sub2);
                                wprintw(sub2,"%02d",m);
                                wrefresh(sub2);
                                napms(1000);

                                for(s=59; s >= 0; s--)
                                	{

                                	wclear(sub3);
                                    wprintw(sub3,"%02d",s);
                                    wrefresh(sub3);
									napms(1000);
                                	}
                            }
                    }
				break;//Fin de el case 5 <-------------------------------

		
		//Minutos
		case 6:
			while(m-- > 0)//Empieza desde los minutos
			{
				wclear(sub2);
				wprintw(sub2,"%02d",m);
				wrefresh(sub2);
				napms(1000);


				for(s=59; s >= 0; s--)
				{
					wclear(sub3);
					wprintw(sub3,"%02d",s);
					wrefresh(sub3);
					napms(1000);
				}
			}
		break; //Fin de el case 6 <--------------------------------------


		//Segundos
		case 7:
			while(s-- > 0)//Solo cuenta segundos
			{
				wclear(sub3);
				wprintw(sub3,"%02d",s);
				wrefresh(sub3);
				napms(1000);
			}
		break; //Fin de el case 7 <---------------------------------------



		default:
			break;

	}
//Fin de el switch <-----------------------------------------------------


    getch();
    endwin();


    return 0;
}



// This function puts the figlet output in the center
// and that of any command from the Row that is specified
// figlet is a program "sudo apt-get figlet" the start does not work if you do not have it
void figlet(int row,char *title)
{
    FILE *fp;
    char path[150];
	
    //popen saves the output of a command and stores it in a file and then you have to call it
    fp = popen(title, "r");

while (fgets(path, 150, fp) != NULL) //loop to read the	islands of the archive
{
    int len,indent,y,width;

    getmaxyx(stdscr,y,width); //maximum screen size

    len = strlen(path);
    indent = width - len;
    indent /= 2;

    mvprintw(row,indent,path); //move the cursor and print part by part

    row++; //counter to print on each row

    refresh();
}

    pclose(fp);
}



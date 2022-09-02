#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// ###################################################################
//function declaration of case 3 (player with friend/player)
void print_matrix(int a[][3]);
int win_condition(int [][3]);     
int match_draw(int [][3]);  
int change_in_matrix(int [][3],char,int);  
void already_booked_position(int [][3],char,int);  
int stop(int a[][3]);   

// ###################################################################
//function declaration of case 1 (play smart computer)

// void print_matrix(int [][3]);     //-->>
// int win_condition(int [][3]);
// int match_draw(int a[][3]);     //-------->>>>>
// int change_in_matrix(int [][3],char ,int);   /// --->>>>>>>
// void already_booked_position(int [][3],char ,int );  //---->>>>
// int stop(int [][3]);               /////------>>
int check_0_present_at_two_position_in_row_col_diag(int [][3]);
int put_automatic_X_at_third_empty_place(int [][3]);
int put_x_at_mid_if_empty(int [][3]);
int if_X_at_two_place_then_put_X_also_at_third(int [][3]);
int put_X_at_first_empty_place(int [][3]);
int print_position_choose_by_super_computer(int [][3],int);
//

// ###################################################################

//function declaration of case 2 (play Evil computer)
// int stop(int [][3]);    //yes
// void print_matrix(int [][3]);  //yes
// int change_in_matrix(int [][3],char ,int);  //yes
int check_0_present_at_two_position_in_row_col_diag_evil_pc(int [][3]);
// int put_x_at_mid_if_empty(int [][3]);  //yes
// int win_condition(int [][3]);  //yes
// int match_draw(int a[][3]);   //yes
// int if_X_at_two_place_then_put_X_also_at_third(int [][3]); //yes
// int put_X_at_first_empty_place(int [][3]);  //yes
// void already_booked_position(int [][3],char ,int );

//##########################################################################
// below are the function used in case 3   (play with friend )


void already_booked_position(int a[][3],char pos,int term)
{
  system("cls");
  print_matrix(a);
  if(term==0)
  {
  printf("Position already used\n Put 0 at d/f one position:\n");
  scanf("%d",&pos);
  change_in_matrix(a,pos,term);
  print_matrix(a);
  system("cls");
  }

  else
  {
  printf("Position already used\n Put X at d/f one position:\n");
  scanf("%d",&pos);
  change_in_matrix(a,pos,term);
  print_matrix(a);
  system("cls");
  }

}

void print_matrix(int a[][3]) //used to print the matrix
{
printf("\n--> SMART TIC TAC TOE GAME <--");   
printf("\n###############################\n\n");
printf("player 1 : 0\n");
printf("Player 2: X\n\n");
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
          {
            if(a[i][j]=='X')
            {
              printf("    %c     ",a[i][j]);
            if(j<2)
            printf("|");
            }

            else
            {
            printf("    %d     ",a[i][j]);
            if(j<2)
            printf("|");
            }
          }
         printf("\n"); 
       if(i<2)
       printf("----------|----------|----------\n");
   }
printf("\n\n###############################\n\n");

}
 
int change_in_matrix(int a[][3],char pos,int term) //used to make the change in matrix
{

if(pos >= '1' &&  pos <= '9')
{ 
   if(term==0)
{
     switch (pos)
  {
     case '1':
     {
     if(a[0][0]==0 || a[0][0]=='X')
     {
     already_booked_position(a,pos,term);
     break;
     }

     else
      a[0][0]=0;
     
      break;
     } 

      case '2':
      {
        if(a[0][1]==0 || a[0][1]=='X')
        {
        already_booked_position(a,pos,term);
        break;
        }

        else
        a[0][1]=0;

        break;
      }  

       case '3':
      {
       if(a[0][2]==0 || a[0][2]=='X')
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[0][2]=0;

      break;
      }
      

       case '4':
      {
        if(a[1][0]==0 || a[1][0]=='X')
         {
        already_booked_position(a,pos,term);
        break;
       }

        else
        a[1][0]=0;

        break;
      }  

       case '5':
      {
       if(a[1][1]==0 ||a[1][1]=='X')
       {
       already_booked_position(a,pos,term);
       break;
       }

      else
      a[1][1]=0;

      break;
      }

       case '6':
      {
       if(a[1][2]==0 ||a[1][2]=='X')
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[1][2]=0;

      break;
      }


       case '7':
       {
        if(a[2][0]==0 ||a[2][0]=='X')
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[2][0]=0;

      break;
       }


       case '8':
       {
        if(a[2][1]==0 || a[2][1]=='X')
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[2][1]=0;

      break;
      }

       case '9':
      {
       if(a[2][2]==0 || a[2][2]=='X')
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[2][2]=0;

      break;
      }
     
  }   

}


  else
  {
    switch(pos)
   { 
    case '1':
     {
     if(a[0][0]=='X' || a[0][0]== 0)
      {
        already_booked_position(a,pos,term);
        break;
       }

     else
      a[0][0]='X';
     
      break;
     } 

      case '2':
      {
        if(a[0][1]=='X' ||a[0][1]== 0)
         {
        already_booked_position(a,pos,term);
        break;
       }

        else
        a[0][1]='X';

        break;
      }  

       case '3':
      {
       if(a[0][2]=='X' || a[0][2]== 0)
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[0][2]='X';

      break;
      }
      

       case '4':
      {
        if(a[1][0]=='X' || a[1][0]== 0)
         {
        already_booked_position(a,pos,term);
        break;
       }

        else
        a[1][0]='X';

        break;
      }  

       case '5':
      {
       if(a[1][1]=='X' || a[1][1]== 0)
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[1][1]='X';

      break;
      }

       case '6':
      {
       if(a[1][2]=='X' || a[1][2]== 0)
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[1][2]='X';

      break;
      }


       case '7':
       {
        if(a[2][0]=='X' || a[2][0]== 0)
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[2][0]='X';

      break;
       }


       case '8':
       {
        if(a[2][1]=='X' || a[2][1]== 0)
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[2][1]='X';

      break;
      }

       case '9':
      {
       if(a[2][2]=='X' || a[2][2]==0)
       {
        already_booked_position(a,pos,term);
        break;
       }

      else
      a[2][2]='X';

      break;
      }
     
    }   
  }

  return 1;
}

else 
{

  system("cls");
  print_matrix(a);

  if(term==0)
  {
  fflush(stdin);

  if(pos >='0' && pos <='9')
  printf("You choose : %d ,a Invalid position\n",pos);
  else
  printf("You choose : %c ,a Invalid position\n",pos);

  printf("put 0 only, at position from 1 to 9\n");
  scanf("%c",&pos);
  change_in_matrix(a,pos,term);
  print_matrix(a);
  system("cls");
  }

  else
  {
  fflush(stdin);

  if(pos >='0' && pos <='9')
  printf("You choose : %d ,a Invalid position\n",pos);
  else
  printf("You choose : %c ,a Invalid position\n",pos);

  printf("put X only, at position from 1 to 9\n");
  scanf("%c",&pos);
  change_in_matrix(a,pos,term);
  print_matrix(a);
  system("cls");
  }

 return 1;
}

}

int stop(int a[][3])    //if don't have any empty poition to fill 0 or X
{
   for (int i = 0,temp=1; i < 3; i++)
    for (int j = 0; j < 3; j++)
       if(a[i][j]==temp)
          return 1;           //abhi stop nahi hoga(empty space is present to fill 0 and X)

       else
         temp++;   

 return 0;          //stop ho jayega (empty space is not present to fill 0 and X) 
   
}

int win_condition(int a[][3]) //used for checking  the winners
{
  int player_1=0,player_2=0;

   for(int i=0;i<3;i++)
   {
    //check for 0 present in row wise or not
     for (int j = 0; j < 3; j++)     
     {
        if(a[i][j]!='X' && a[i][j]!=0)  //means unused position me break karna
        {
         player_1=0;
          break;
        }

        else if(a[i][j]==0)      // if a position contain value 0 it means player_1 me changement kro usko 1 kardo
          player_1=1;

        else  //a[i][j] contain 'X' uspe bhi break 
        {
         player_1=0;
          break;
        }

     }
     
     if(player_1==1)
     {
     return 1;
     }
   }
     //check for X present in row wise or not
    for(int i=0;i<3;i++)
   { 
     for (int j = 0; j < 3; j++)        
     {
        if(a[i][j]!='X' && a[i][j]!=0)
        {
         player_2=0;
          break;
        }

        else if(a[i][j]=='X')
          player_2=1;

        else
        {
         player_2=0;
          break;
        }

     }
    
     if(player_2==1)
     {
     return 2;
     }
   }   
    
     //check for 0 present in column wise or not
    for(int i=0;i<3;i++)
   { 
     for (int j = 0; j < 3; j++)     
     {
        if(a[j][i]!='X' && a[j][i]!=0)
        {
         player_1=0;
          break;
        }

        else if(a[j][i]==0)
          player_1=1;

        else
        {
         player_1=0;
          break;
        }

     }
    
     if(player_1==1)
     {
     return 1;
     }
   }
     //check for X present in column wise or not
  for(int i=0;i<3;i++)
   {   
     for (int j = 0; j < 3; j++)        
     {
        if(a[j][i]!='X' && a[j][i]!=0)
        {
         player_2=0;
          break;
        }

        else if(a[j][i]=='X')
          player_2=1;

        else
        {
         player_2=0;
          break;
        }

     }
    
     if(player_2==1)
     {
     return 2;
     }
   } 
   

   
     //check for 0 present in diagonal wise or not  : In diagonal wise(row an column is equal)
     for(int i=0 ; i<3 ; i++)
   {
     for (int j = i; j < 3; j++)
     {
        if(a[i][j]!='X' && a[i][j]!=0)
        {
        player_1=0;
        break;
        }

        else if(a[i][j]==0)
        {
        player_1=1;
        break;
        }

        else
       {
        player_1=0;
        break;
       }

    }
    if(player_1==0)
    break;
   }
     if(player_1==1)
     {
      return 1;
     }
     

      //check for X present in diagonal wise or not  : In diagonal wise(row an column is equal)
  for(int i=0;i<3;i++)
  {    
     for (int j = i; j < 3; j++)
     {
        if(a[i][j]!='X' && a[i][j]!=0)
        {
          player_2=0;
          break;
        }

        else if(a[i][j]=='X')
        {
        player_2=1;
        break;
        }

        else
        {
          player_2=0;
          break;
        }
      }
    if(player_2==0)
    break;
  }   
     if(player_2==1)
     {
      return 2;
     }
    
   

  player_1=0,player_2=0;
   //check for 0 present in diagonal wise or not  : In diagonal wise(row an column is not equal)
   for (int i = 2; i >=0; i--)
   {
    for (int j = 2-i; j < 3; j++)
    {
      if (a[j][i]!='X' && a[j][i]!=0)
        {
      player_1=0;
      break;
      }
      
      else if(a[j][i]==0)
      {
      player_1=1;
      break;
      }

      else
      {
      player_1=0;
      break;
      }
    }
   if(player_1==0)
   break;

   } 
    if(player_1==1)
    {
      return 1;
    }

   //check for X present in diagonal wise or not  : In diagonal wise(row an column is not equal)
  for (int i = 2; i >=0; i--)
   {
    for (int j = 2-i; j < 3; j++)
    {
      if (a[j][i]!='X' && a[j][i]!=0)
        {
      player_2=0;
      break;
      }
      
      else if(a[j][i]=='X')
      {
      player_2=1;
      break;
      }

      else
      {
      player_2=0;
      break;
      }
    }
    if(player_2==0)
    break;
  }  
    if(player_2==1)
    {
      return 2;
    }

   
 
 return 0;   //if retrun 0 (you louse! matrix is  not empty)
}

int match_draw(int a[][3]) //for draw the match 
{
  if(stop(a)==0 && win_condition(a)==0)
  return 1;

  else
  return 0;

}

//##########################################################################
// below are the function used in case 1   (play with smart computer)


int print_position_choose_by_super_computer(int a[][3],int position) //used to print position choose by super computer
{
system("cls");     //for clear the screen
printf("\n");
print_matrix(a);
printf("Super Computer Puts X at position : %d\n",position);
}

int put_X_at_first_empty_place(int a[][3]) //used to put X at first empty place
{

for(int i=0;i<3;i++)
{
  for(int j=0;j<3;j++)
  {
    if(a[i][j]!='X' && a[i][j]!=0)  //a[i][j] me to na 'X' ho ,or na he 0 h0
      {
        int temp = a[i][j];  //temp is used to store the empty position  
             a[i][j]='X';   //so after that we can return it to used  print the task of super computer
             return temp; 
      }
  }
}

 return 0;    

}

int put_x_at_mid_if_empty(int a[][3]) // used to put_x_at_mid_if_empty
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (a[i][j]==0)
      {
        if (a[1][1]!=0 && a[1][1]!='X')
        {
          a[1][1]='X';
          return 5;
        }
      }
    }
  }
  return 0;
}

int check_0_present_at_two_position_in_row_col_diag(int a[][3]) //used to check 0 is present at two position in row col diag
{
    int temp_i=-1,temp_j=-1,count=0;
    //check for rows 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(a[i][j]==0)
            count++;
            
            else if (a[i][j]!='X')
            {
                temp_i=i;
                temp_j=j;
            }
            
        }
        if(count==2)
        {
           if(temp_i!=-1 && temp_j!=-1)
           {
           return (a[temp_i][temp_j]);
           }
        }
       count=0;  
      temp_i=-1 ;
      temp_j=-1 ;
    }

    //check for columns
   temp_i=-1,temp_j=-1,count=0;
  for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(a[j][i]==0)
            count++;
            
            else if (a[j][i]!='X')
            {
                temp_i=i;
                temp_j=j;
            }
        }
        if(count==2)
        {
          if(temp_i!=-1 && temp_j!=-1)
          {
           return (a[temp_j][temp_i]);
          }
        }   
      count=0;  
      temp_i=-1 ;
      temp_j=-1 ;   
    }

    // check for diagonals(for equal row and column)
   temp_i=-1,temp_j=-1,count=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
           if(i==j)
           {
            if(a[i][j]==0)
            count++;

            else if (a[i][j]!='X')
            {
                temp_i=i;
                temp_j=j;
            }
           }

           else
           break;
        }
    }
    if(count==2)
       {
          if(temp_i!=-1 && temp_j!=-1)
          {
           return (a[temp_i][temp_j]);
          }
        }   
    

    // check for diagonals(for not equal row and column)
    temp_i=-1,temp_j=-1,count=0;
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 2-i; j < 3; j++)
        {
            if(j==2-i)
            {
               if(a[i][j]==0)
            count++;

            else if (a[i][j]!='X')
            {
                temp_i=i;
                temp_j=j;
            }
              
            }    
            else
            break;  
            
        }
    }
    if(count==2)
       {
          if(temp_i!=-1 && temp_j!=-1)
          {
           return (a[temp_i][temp_j]);
          }
        }  
    

     return 0;    //if 0 is not present at 2 times in row ,column and diagonal

}

int put_automatic_X_at_third_empty_place(int a[][3]) //used to put_automatic_X_at_third_empty_place
{

     if(check_0_present_at_two_position_in_row_col_diag(a))
     {
         for (int i = 0,count=1; i < 3; i++)
         {
            for (int j = 0; j < 3; j++)
            {
                if(check_0_present_at_two_position_in_row_col_diag(a)== count)
                {
                  int temp=a[i][j];
                  a[i][j]='X';
                  return temp;
                }  

                else
                count++;
               
            }
         }
         

     }
     return 0;
}

int if_X_at_two_place_then_put_X_also_at_third(int a[][3]) //if_X_at_two_place_then_put_X_also_at_third
{
    int temp_i=-1,temp_j=-1,count=0;         
    //check for rows 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(a[i][j]=='X')
            count++;
            
            else if (a[i][j]!=0)
            {
                temp_i=i;
                temp_j=j;
            }
            
        }
        if(count==2)
        {
           if(temp_i!=-1 && temp_j!=-1)
           {
            int temp = a[temp_i][temp_j];
           a[temp_i][temp_j]='X';
           return temp;
           }
        }
      count=0;  
      temp_i=-1 ;
      temp_j=-1 ;
    }

 //check for columns
   temp_i=-1,temp_j=-1,count=0;
  for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(a[j][i]=='X')
            count++;
            
            else if (a[j][i]!=0)
            {
                temp_i=i;
                temp_j=j;
            }
        }
        if(count==2)
        {
           if(temp_i!=-1 && temp_j!=-1)
           {
             int temp = a[temp_j][temp_i];
           a[temp_j][temp_i]='X';
           return temp;
           }
        }  
      count=0;  
      temp_i=-1 ;
      temp_j=-1 ;  
    }

    // check for diagonals(for equal row and column)
   temp_i=-1,temp_j=-1,count=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
           if(i==j)
           {
            if(a[i][j]=='X')
            count++;

            else if (a[i][j]!=0)
            {
                temp_i=i;
                temp_j=j;
            }
           }

           else
           break;
        }
    }
    if(count==2)
        {
           if(temp_i!=-1 && temp_j!=-1)
           {
             int temp = a[temp_i][temp_j];
           a[temp_i][temp_j]='X';
           return temp;
           }
        }   
    

    // check for diagonals(for not equal row and column)
    temp_i=-1,temp_j=-1,count=0;
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 2-i; j < 3; j++)
        {
            if(j==2-i)
            {
               if(a[i][j]=='X')
            count++;

            else if (a[i][j]!=0)
            {
                temp_i=i;
                temp_j=j;
            }
              
            }    
            else
            break;  
            
        }
    }
    if(count==2)
        {
           if(temp_i!=-1 && temp_j!=-1)
           {
            int temp = a[temp_i][temp_j];
           a[temp_i][temp_j]='X';
           return temp;
           }
        }  
    




 return 0;
}


//##########################################################################
// below are the function used in case 2   (play with Evil computer)

int check_0_present_at_two_position_in_row_col_diag_evil_pc(int a[][3]) //used to check 0 is present at two position in row col diag
{
    int temp_i=-1,temp_j=-1,count=0,check=0;
    //check for rows 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(a[i][j]==0)
            count++;
            
            else if (a[i][j]!='X')
            {
                temp_i=i;
                temp_j=j;
            }
            
        }
        if(count==2)
        {
           if(temp_i!=-1 && temp_j!=-1)
           {
            a[temp_i][temp_j]='X';
            check=1;
           }
        }
       count=0;  
      temp_i=-1 ;
      temp_j=-1 ;
    }

    //check for columns
   temp_i=-1,temp_j=-1,count=0;
  for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(a[j][i]==0)
            count++;
            
            else if (a[j][i]!='X')
            {
                temp_i=i;
                temp_j=j;
            }
        }
        if(count==2)
        {
          if(temp_i!=-1 && temp_j!=-1)
          {
          a[temp_j][temp_i]='X';
          check=1;
          }
        }   
      count=0;  
      temp_i=-1 ;
      temp_j=-1 ;   
    }

    // check for diagonals(for equal row and column)
   temp_i=-1,temp_j=-1,count=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
           if(i==j)
           {
            if(a[i][j]==0)
            count++;

            else if (a[i][j]!='X')
            {
                temp_i=i;
                temp_j=j;
            }
           }

           else
           break;
        }
    }
    if(count==2)
       {
          if(temp_i!=-1 && temp_j!=-1)
          {
          a[temp_i][temp_j]='X';
          check=1;
          }
        }   
    

    // check for diagonals(for not equal row and column)
    temp_i=-1,temp_j=-1,count=0;
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 2-i; j < 3; j++)
        {
            if(j==2-i)
            {
               if(a[i][j]==0)
            count++;

            else if (a[i][j]!='X')
            {
                temp_i=i;
                temp_j=j;
            }
              
            }    
            else
            break;  
            
        }
    }
    if(count==2)
       {
          if(temp_i!=-1 && temp_j!=-1)
          {
          a[temp_i][temp_j]='X';
          check=1;
          }
        }  
    
    if(check)
    {
    // system("cls");
    // print_matrix(a);  
    return 1;
    }

    else
     return 0;    //if 0 is not present at 2 times in row ,column and diagonal

}



int main()
{

system("cls");
int choice;

printf("\n\n");
    printf("0 X 0 X 0 X 0 X 0 X 0 X 0 X 0 X 0 X 0 X \n\n");
    printf("  WELCOME TO SMART TIC TAC TOE GAME!");
    printf("\n\n0 X 0 X 0 X 0 X 0 X 0 X 0 X 0 X 0 X 0 X\n");
    printf("\n\n");
    
printf("Enter your choice");
printf("\n1. Want to play with Smart Computer");
printf("\n2. Want to play with Evil Computer");
printf("\n3. Want to play with Player");
printf("\n4. Exit");
printf("\n");
scanf("%d",&choice);
system("cls");

switch (choice)
{
case 1:
{
  printf("Press any key to start the Game!\n");
getch();       //to get character on screen
   
system("cls");   //for clear the screen
int a[3][3]={1,2,3,4,5,6,7,8,9},term;
char pos;
// a is matrix,pos is position from 1 to 9 ,term is 0 or X
char str[20];   //for enter the name of player
fflush(stdin);  //used to clear the buffer
printf("Enter player name\n");     //for enter name of the player
fgets(str,20,stdin);

int check=stop(a); 
//check wether matrix have empty poition or not  to fill 0 and X 
//(check = 1 means  space available to fill 0 and X ,check = 0 means space is not available to fill 0 and X)
 system("cls");     //for clear the screen

print_matrix(a);    //for print the matrix

while (check)
{
fflush(stdin);
printf("%s Puts 0 in place of : ",str);  //print the message on the screen
scanf("%c",&pos);           // enter the 0 by player 1 at position 0 to 9(given by player 1) 
term=0;                    // term to check wether 0 or X ,here term is 0
int temp_change_in_matrix= change_in_matrix(a,pos,term);  //puts 0 at the poistion given by player 1 

if(temp_change_in_matrix ==0)
{
  break;
}

system("cls");     //for clear the screen
print_matrix(a);    //for print the matrix

// (temp_if_X_at....) is name of variable used to stored the value returned by function -->(if_X_at_two_place....)
int temp_if_X_at_two_place_then_put_X_also_at_third = if_X_at_two_place_then_put_X_also_at_third(a);
// ( if_X_at_two... ) is the name of function in which we put the 'X' at that third empty position 
// in which  any first two position already have 'X' at any row ,column , equal and unequal diagonal
if(temp_if_X_at_two_place_then_put_X_also_at_third!=0)   //  (temp_if_X.. ) variable have 0 means no change made in matrix by super computer
print_position_choose_by_super_computer( a,temp_if_X_at_two_place_then_put_X_also_at_third); //used to print the position chenge by super computer

int check_win_condition = win_condition(a);
 if(check_win_condition)        //to check wether  player is win or not
  { 
   if(check_win_condition == 1)       //to check wether which player is win ,here win player 
    {
       printf("%s win the match",str);
       break;
    }
   
   else if(check_win_condition == 2)        //to check wether which player is win ,here Super computer
     {
    printf("\nOops! you loose the match\nSmart Computer win\n");
    break;
    }
  }

int check_match_draw = match_draw(a);

 if(check_match_draw)       //for check wether the match is draw or not
  {                     //(match draw means no one is win ,and empty space is not avilable to fill 0 and X )
   printf("\nThis Match is draw\n No one is win");
  break;
 } 

// (temp_check_0... ) is name of valiable used to stored the value returned by function -->(check_0_present_at....)
int temp_check_0_present_at_two_position_in_row_col_diag = check_0_present_at_two_position_in_row_col_diag(a);
// ( check_0_present_at... ) is the name of function in which used to check whether 0 is present at two  
// d/f position at any  same row ,column , equal and unequal diagonal in the matrix

// ( temp_put.. ) is name of valiable used to stored the value returned by function -->(put_automatic_X....)
int temp_put_automatic_X_at_third_empty_place = put_automatic_X_at_third_empty_place(a);
// ( put_automatic_X... ) is the name of function in which we put the 'X' at 3rd empty place in which first two
//place have the 0  at any  same row ,column , equal and unequal diagonal in the matrix
// basically it is used to stop the win by player ### player ke win position banne se rokega (uske 2 position ke 0 ke jagh apna ek X rakh dega)

if(temp_put_automatic_X_at_third_empty_place!=0)
print_position_choose_by_super_computer( a,temp_put_automatic_X_at_third_empty_place);

// ( temp_put_x_at_mid.. ) is name of valiable used to stored the value returned by function -->(put_x_at_mid_if_empty....)
int temp_put_x_at_mid_if_empty = put_x_at_mid_if_empty(a);
if(temp_put_x_at_mid_if_empty!=0)
print_position_choose_by_super_computer( a,temp_put_x_at_mid_if_empty);


int temp_put_X_at_first_empty_place;

if(temp_put_x_at_mid_if_empty == 0)       //mid pe 'X' na gya ho
{
  if(temp_put_automatic_X_at_third_empty_place == 0)   //autumatic third pe bhi 'X' na gya ho
    if(temp_if_X_at_two_place_then_put_X_also_at_third==0)  //'X' 2 position pe ho 3rd position pe na gya ho 
          {
            temp_put_X_at_first_empty_place = put_X_at_first_empty_place(a);  //tabhi first empty position pe 'X' jayega
            if(temp_put_X_at_first_empty_place!=0)
                print_position_choose_by_super_computer( a,temp_put_X_at_first_empty_place);
          }   
}

check_win_condition = win_condition(a);

 if(check_win_condition)        //to check wether player is win or not
  { 
   if(check_win_condition == 1)       //to check wether which player is win ,here win player 1
    {
       printf("%s win the match",str);
      break;
    }
   
   else if(check_win_condition == 2)        //to check wether which player is win ,here win player 2
     {
    printf("Opps! you loose the match\nSmart Computer win\n");
    break;
    }
  }

 if(check_match_draw)       //for check wether the match is draw or not
  {                     //(match draw means no one is win ,and empty space is not avilable to fill 0 and X )
   printf("\nThis Match is draw\n No one is win");
   break;
 } 
}


    break;
}    

case 2:
{
printf("Press any key to start the Game!\n");
getch();       //to get character on screen


system("cls");   //for clear the screen
int a[3][3]={1,2,3,4,5,6,7,8,9},term;
char pos;
// a is matrix,pos is position from 1 to 9 ,term is 0 or X
char str[20];   //for enter the name of player
fflush(stdin);  //used to clear the buffer
printf("Enter player name\n");     //for enter name of the player
fgets(str,20,stdin);

int check=stop(a); 
//check wether matrix have empty poition or not  to fill 0 and X 
//(check = 1 means  space available to fill 0 and X ,check = 0 means space is not available to fill 0 and X)
 system("cls");     //for clear the screen
print_matrix(a);    //for print the matrix

while (check)
{
fflush(stdin);
printf("%s Puts 0 in place of : ",str);  //print the message on the screen
scanf("%c",&pos);           // enter the 0 by player 1 at position 0 to 9(given by player 1) 
term=0;                    // term to check wether 0 or X ,here term is 0
int temp_change_in_matrix= change_in_matrix(a,pos,term);  //puts 0 at the poistion given by player 1 

if(temp_change_in_matrix ==0)
{
  break;
}

// (temp_if_X_at....) is name of variable used to stored the value returned by function -->(if_X_at_two_place....)
// int check_0_present_at_two_position_in_row_col_diag_evil_PC = check_0_present_at_two_position_in_row_col_diag_evil_pc(a);
int check_0_present_at_two_position_in_row_col_diag_evil_PC;

int temp_if_X_at_two_place_then_put_X_also_at_third = if_X_at_two_place_then_put_X_also_at_third(a);

if(temp_if_X_at_two_place_then_put_X_also_at_third == 0)
check_0_present_at_two_position_in_row_col_diag_evil_PC = check_0_present_at_two_position_in_row_col_diag_evil_pc(a);


system("cls");     //for clear the screen
print_matrix(a);    //for print the matrix


int check_win_condition = win_condition(a);
 if(check_win_condition)        //to check wether  player is win or not
  { 
   if(check_win_condition == 1)       //to check wether which player is win ,here win player 
    {
       printf("%s win the match",str);
       break;
    }
   
   else if(check_win_condition == 2)        //to check wether which player is win ,here Super computer
     {
    printf("\nOops! you loose the match\nEvil Computer win\n");
    break;
    }
  }
system("cls");     //for clear the screen
print_matrix(a);    //for print the matrix

int check_match_draw = match_draw(a);

 if(check_match_draw)       //for check wether the match is draw or not
  {                     //(match draw means no one is win ,and empty space is not avilable to fill 0 and X )
   printf("\nThis Match is draw\n No one is win");
  break;
 } 


// ( temp_put_x_at_mid.. ) is name of valiable used to stored the value returned by function -->(put_x_at_mid_if_empty....)
int temp_put_x_at_mid_if_empty = put_x_at_mid_if_empty(a);

system("cls");     //for clear the screen
print_matrix(a);    //for print the matrix

int temp_put_X_at_first_empty_place;

if(temp_put_x_at_mid_if_empty == 0)       //mid pe 'X' na gya ho
{
  if(check_0_present_at_two_position_in_row_col_diag_evil_PC == 0)   //autumatic third pe bhi 'X' na gya ho
    if(temp_if_X_at_two_place_then_put_X_also_at_third==0)  //'X' 2 position pe ho 3rd position pe na gya ho 
          {
            temp_put_X_at_first_empty_place = put_X_at_first_empty_place(a);  //tabhi first empty position pe 'X' jayega
          }   
}

system("cls");     //for clear the screen
print_matrix(a);    //for print the matrix

 check_win_condition = win_condition(a);

 if(check_win_condition)        //to check wether player is win or not
  { 
   if(check_win_condition == 1)       //to check wether which player is win ,here win player 1
    {
       printf("%s win the match",str);
      break;
    }
   
   else if(check_win_condition == 2)        //to check wether which player is win ,here win player 2
     {
    printf("Opps! you loose the match\nEvil Computer win\n");
    break;
    }
  }

 if(check_match_draw)       //for check wether the match is draw or not
  {                     //(match draw means no one is win ,and empty space is not avilable to fill 0 and X )
   printf("\nThis Match is draw\n No one is win");
   break;
 } 
system("cls");     //for clear the screen
print_matrix(a);    //for print the matrix

}

break;
}

case 3:
{
  printf("Press any key to start the Game!\n");
getch();       //to get character on screen

system("cls");   //for clear the screen
int a[3][3]={1,2,3,4,5,6,7,8,9},p0,p1,term,check;

char str1[20],str2[20];   //for enter the name of player
fflush(stdin);
printf("Enter player 1 name\n");   //player 1's name
fgets(str1,20,stdin);

printf("Enter player 2 name\n");   //player 2's name 
fgets(str2,20,stdin);

check=stop(a);      //check wether matrix have empty poition or not  to fill 0 and X 
//(check = 1 means  space available to fill 0 and X ,check = 0 means space is not available to fill 0 and X)
 system("cls");     //for clear the screen

print_matrix(a);    //for print the matrix

//in the loop
while (check)
{
  fflush(stdin);
  printf("%s Puts 0 in place of : ",str1);  
  scanf("%c",&p0);           // enter the 0 by player 1 at position 0 to 9(given by player 1) 
  term=0;                    // term to check wether 0 or X ,here term is 0
  change_in_matrix(a,p0,term);  //puts 0 at the poistion given by player 1 
  system("cls");     //for clear the screen
  print_matrix(a);     //for print resultant  the matrix

  if(win_condition(a))        //to check wether player is win or not
  { 
   if(win_condition(a)==1)       //to check wether which player is win ,here win player 1
    {
       printf("%s win the match",str1);
       break;
    }
   
   else if(win_condition(a)==2)        //to check wether which player is win ,here win player 2
     {
    printf("%s win the match",str2);
    break;
    }
  }

  if(match_draw(a))                  //for check wether the match is draw or not
 {                                  //match draw means :: not empty space to fill 0 or X and no one is win
   printf("\nThis Match is draw\n No one is win");
   break;
 }  
  

   system("cls");     //for clear the screen
  print_matrix(a);     //for print resultant  the matrix
  fflush(stdin);
  printf("%s Puts X in place of : ",str2);  
  scanf("%c",&p1);           // enter the X by player 2 at position 0 to 9(given by player 2) 
  term='X';                    // here ,term is put X 
  change_in_matrix(a,p1,term);  //puts X at the position given by player 2 
  system("cls");     //for clear the screen
  print_matrix(a);     //for print resultant  the matrix
  if(win_condition(a))     //to check wether player is win or not
  { 
   if(win_condition(a)==1)       //to check wether which player is win ,here win player 1
    {
       printf("%s win the match",str1);
       break;
    }
   
   else if(win_condition(a)==2)       //to check wether which player is win ,here win player 2
     {
    printf("%s win the match",str2);
    break;
    }
  }

 if(match_draw(a))       //for check wether the match is draw or not
  {                     //(match draw means no one is win ,and empty space is not avilable to fill 0 and X )
   printf("\nThis Match is draw\n No one is win");
   break;
 }  
  

   system("cls");     //for clear the screen
  print_matrix(a);     //for print resultant  the matrix
  check=stop(a);    //check wether matrix have empty poition or not  to fill 0 and X
                    //here check =1 means empty space available ,0 means not available
}




break;      // this is the break of case 
}

case 4:
{
system("cls");
printf("Thank you!\n");
printf("Press any key to Exit");
getch();
break;
}

default:
  printf("Invalid Choice\n");
    break;
}

    return 0;
}
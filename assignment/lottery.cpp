/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <2Dhif>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/

#include "lottery.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define 	UUID_LEN   40
#define 	MAX_TIP_LEN   17
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN + 1)
static FILE* fd;
static char separator;
static int drawingOfNumbers[TIP_SIZE];

bool 	init_lottery (const char *csv_file, char csv_separator)
{
  fd = fopen(csv_file, "r");
  separator = csv_separator;
  if(fd == 0)
  {
    return false;
  }
  return true;
}

bool get_tip(int tip_number, int tip[TIP_SIZE])
{
    if (tip_number < 0 || tip_number > 45) return false;
    int count = 0;
    char line[100];
    while ( fgets(line, 100, fd) != NULL)
    {
        if (count == tip_number)
        {
            if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
            count = 0;
            char str[2];
            str[0] = separator;
            str[1] = '\0';
            char* ptr = strtok(line, str);
            while(ptr != NULL && count < TIP_SIZE)
            {
                ptr = strtok(NULL, str);
                tip[count] = atoi(ptr);
                count++;
            }
            rewind(fd);
            return true;
        }
        else
        {
            count++;
        }
    }
  return false;
}


bool 	set_drawing (int drawing_numbers[TIP_SIZE])
{
  for (int i = 0; i < TIP_SIZE; i++) {
    if(drawing_numbers[i] <= 0 || drawing_numbers[i] > 45)
    {
      return false;
    }
    drawingOfNumbers[i] = drawing_numbers[i];
  }
  return true;

}
int 	get_tip_result (int tip_number)
{
  if(set_drawing(drawingOfNumbers) == false)
  {
    return -1;
  }
  return 0;

}
int 	get_right_tips_count (int right_digits_count)
{
  return 0;
}

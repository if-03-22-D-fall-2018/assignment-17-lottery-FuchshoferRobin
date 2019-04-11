/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
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

bool 	init_lottery (const char *csv_file, char csv_separator)
{
  fd = fopen(csv_file, "r");
  if(fd == 0)
  {
    return false;
  }
  return true;
}
bool 	get_tip (int tip_number, int tip[TIP_SIZE])
{
  if(tip_number > 45 && tip_number < 0)
  {
    return false;
  }
  fseek(fd, tip_number, SEEK_CUR);
  char buffer[MAX_LINE_LEN];
  fgets(buffer, MAX_LINE_LEN, fd);
  char str[2];
  str[0] = ',';
  str[1] = '\0';
  strtok(buffer, str);
  for (int i = 0; i < TIP_SIZE; i++) {
    tip[i] = atoi(strtok(NULL, str));
    if(tip[i] > 45 && tip[i] < 0)
    {
      return false;
    }
  }

  return true;


}
bool 	set_drawing (int drawing_numbers[TIP_SIZE])
{
  return false;
}
int 	get_tip_result (int tip_number)
{
  return 0;
}
int 	get_right_tips_count (int right_digits_count)
{
  return 0;
}

/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Sam Pickell


Hours to complete assignment (optional): 6 hours and 20 minutes


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, I completed the whole assignment successfully. I generated a log
file for device 5 that looks identicle to the one provided and proceeded
to generate logs for the rest of the devices.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
regex 1:
boost::regex start_up("[0-9]{4}-[0-9]{2}-[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9]"
"{2}:\\s[(]log[.]c[.]166[)]\\sserver\\sstarted\\s");

This was looking for the start up message. The date and time could be
anything, it just had to follow the format. The important part was
the log.c.166 portion, which had to be exactly that in order to be
the proper start up message.

regex 2:
boost::regex success("[0-9]{4}-[0-9]{2}-[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9]{2}"
"[.][0-9]{3}:INFO:oejs[.]AbstractConnector:Started\\sSelectChannelConnector@[0-"
"9]{1}[.][0-9]{1}[.][0-9]{1}[.][0-9]{1}:[0-9]{4}");

This was looking for the specific line indicating that the startup was
a success. Much like the first regex, so long as the date and time were
in the proper format, the specific string indicating that the start up
was a success was there, and the last bit containing some numbers
in a particular format were there, the line passed and indicated the
start up was a success.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
The first thing I did was figure out how to use regular expressions.
The trickiest part was figuring out when to use brackets, but once I
understood that part, I just followed the guidelines provided in the
powerpoint and assembling the rest of the regular expression made sense.
After that, I set up the file streams and got the input/output to work.
Then, I had to figure out how regex_match worked, and once I got that
working, the rest of the assignment was straightforward. The only remaining
hurdle was generating the amount of time required to boot. After playing
around with boost::posix I learned how to convert the date/time in a
string to a posix object that could act like integers and getting the
boot time was easy.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
No help this time.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
No serious problems occurred.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/


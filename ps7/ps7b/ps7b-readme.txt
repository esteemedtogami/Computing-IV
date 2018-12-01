/**********************************************************************
 *  readme.txt template                                                   
 *  PS7b: Kronos log parsing
 **********************************************************************/

Name: Sam Pickell


Hours to complete assignment (optional): 11 hours and 26 minutes


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, I completed the whole assignment. My report files match the samples
given and my code compiles and runs with no errors.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
  boost::regex services("Starting\\sService[.].*");

This regex is used to look for the service startup string.


  boost::regex service_success("Service\\sstarted\\ssuccessfully[.].*");

This regex is used to look to see if the service started successfully.


  boost::regex soft_start("[A-Z]{1}[a-z]{2}\\s[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9"
"]{2}.*Install\\sstarted\\s");

This regex is used to see if there was a software update startup string.


  boost::regex soft_orig("[A-Z]{1}[a-z]{2}\\s[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9"
"]{2}\\s[(]none[)]\\s/stagingarea/scripts/install-rollback[.]sh:\\sintouch-appl"
"ication-base-.*[.]armv6jel_vfp[.]rpm\\swas\\spreviously\\sinstalled[,]\\saddin"
"g\\srpm\\sto\\srollback\\slist");

This regex is used to grab the version of the software before the update.


  boost::regex soft_end("[A-Z]{1}[a-z]{2}\\s[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9"
"]{2}\\s[(]none[)]\\s/stagingarea/scripts/install-rollback[.]sh:\\sExitValue\\s"
"from\\sinstall\\scommand\\s:\\s0");

This regex is used to check that the software update has completed.


  boost::regex soft_new_ver("[A-Z]{1}[a-z]{2}\\s[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0"
"-9]{2}\\s[(]none[)]\\s/stagingarea/scripts/install-rollback[.]sh:\\sProcessing"
"\\s43\\sof\\s45\\sintouch-platform-base-.*[.]armv6jel_vfp[.]rpm ...");

This regex is used to grab the version of the software being installed.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
My first goal was to get the service output working. To do that, I made
a series of parallel vectors where one contained the names of all the services,
one contained the line number where the service started up, and the last
one contained the line number where the service completed. I used a combin-
ation of substr and find for strings in order to find out what service I
was working with. Once I determined the service, I used the service vector's
element to put the line information in the other two vectors, and used the
string containing the service complete line to grab the elapsed time and
output that. After that was working I started working on the Softload
portion of the assignment. This involved more use of substr and find and
more regexs than the previous section, but was otherwise the same idea.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
None this time.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
No serious problems occurred.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7b complete
 **********************************************************************/

Name: Sam Pickell
CS Login: spickell


Hours to complete assignment (optional):


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/



/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/



/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/


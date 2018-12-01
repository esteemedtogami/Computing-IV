1;3201;0c/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Sam Pickell
Login: spickell


Hours to complete assignment (optional): 16 hours and 32 minutes



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
 First you need to check if the place you're moving to in the matrix
 is a valid mathematical solution, and if it is, move to the cheapest
 location.


/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: atattat
       tattata

Expected output: atattat-
                 -tattata

What happened:	 atattat-
                 -tattat-
			


/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/
 16 GB


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 2
b = 4
largest N = 251

If I were limited to 8 GB of memory, 2 * 251^4 = 7938252002 (bytes). Any
larger N would be too large.

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************

Yes:

endgaps7:

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1      2,453,162           72,712           72,704             8            0
  2      2,577,480           76,816           76,800            16            0
  3      2,600,271           76,856           76,832            24            0
  4      2,600,666           77,056           77,024            32            0
  5      2,600,994           77,096           77,056            40            0
  6      2,603,025           77,136           77,088            48            0
  7      2,603,645           77,176           77,120            56            0
  8      2,604,265           77,216           77,152            64            0
  9      2,604,885           77,256           77,184            72            0

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt        118             0.661434            50.329
ecoli5000.txt        160             2.52215            200.508
ecoli7000.txt        194             4.9972             392.805
ecoli10000.txt       223             9.62697            801.082
ecoli20000.txt       3135            62.2125            3201.791
ecoli28284.txt       8394            155.398            segmentation fault

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 2
b = 4
largest N = 28284

28284 is where I got the segmentation fault

/**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
 I worked with Jeff Ma on this assignment and got a little help with
 my optdistance function from Mike Moran


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
 Nothing to report


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

CPU: 2.90 GHz x 4
Processor: Intel Core i7-3520M
Array method: NxM
OS: Ubuntu 16.04 64bit

#!/usr/bin/env python
import dspplot

data = [
6.0000000000001025e-05,
0.00020410140848826919,
0.00067726623747492269,
0.0016020078123390432,
0.0031820950003995088,
0.0057012766049161674,
0.0095202933203369124,
0.015071173410218108,
0.022847781830968972,
0.033391723478151163,
0.047272986937005018,
0.065065136158002454,
0.087315379137115331,
 0.11451041791643346,
 0.14703955786238146,
 0.18515706798220849,
  0.2289461821458848,
 0.27828736537927679,
 0.33283350429856501,
 0.39199449694692956,
 0.45493331408037974,
 0.52057499999999979,
 0.58762931339638536,
 0.65462683016356282,
 0.71996740523196567,
 0.78197899012652483,
 0.83898399876993068,
 0.88936977222328373,
 0.93165926872740035,
 0.96457793784151469,
 0.98711284651603415,
 0.99856050905592098,
 0.99856050905592098,
 0.98711284651603437,
  0.9645779378415148,
 0.93165926872740046,
 0.88936977222328384,
 0.83898399876993102,
 0.78197899012652528,
 0.71996740523196578,
 0.65462683016356327,
 0.58762931339638613,
 0.52057500000000023,
 0.45493331408038001,
    0.39199449694693,
 0.33283350429856556,
 0.27828736537927734,
 0.22894618214588497,
 0.18515706798220882,
  0.1470395578623816,
 0.11451041791643377,
0.087315379137115512,
0.065065136158002496,
0.047272986937005185,
0.033391723478151225,
   0.022847781830969,
0.015071173410218144,
0.009520293320336895,
0.0057012766049161908,
0.0031820950003994784,
0.0016020078123390648,
0.00067726623747494351,
0.00020410140848830562,
6.0000000000001025e-05,
]
dspplot.plot(data, freqresp=True, dots=True, padwidth=1024, log_freq=False, horizontal=False, normalized_freq=True, title='Blackman-Harris window', file='../svg/window_blackman_harris.svg')
